/*
 * <:copyright-BRCM:2013:DUAL/GPL:standard
 * 
 *    Copyright (c) 2013 Broadcom Corporation
 *    All Rights Reserved
 * 
 * Unless you and Broadcom execute a separate written software license
 * agreement governing use of this software, this software is licensed
 * to you under the terms of the GNU General Public License version 2
 * (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
 * with the following added to such license:
 * 
 *    As a special exception, the copyright holders of this software give
 *    you permission to link this software with independent modules, and
 *    to copy and distribute the resulting executable under terms of your
 *    choice, provided that you also meet, for each linked independent
 *    module, the terms and conditions of the license of that module.
 *    An independent module is a module which is not derived from this
 *    software.  The special exception does not apply to any modifications
 *    of the software.
 * 
 * Not withstanding the above, under no circumstances may you combine
 * this software in any way with any other Broadcom software provided
 * under a license other than the GPL, without Broadcom's express prior
 * written consent.
 * 
 * :> 
 */


#ifndef _RDPA_IP_FLOW_H_
#define _RDPA_IP_FLOW_H_

#include <bdmf_interface.h>
#include "rdpa_ip_class_basic.h"
#include "rdpa_cpu_basic.h"

/** \defgroup ip_class IP Flow Classification
 * IP flows are used for fast TCP/UDP routing and 5-tuple-based bridging.\n
 * IP flow classifier is invoked for routed and optionally for bridged packets.
 * The classifier identifies IP flows using 5-tuple key\n
 * { src_ip, dst_ip, protocol, src_port, dst_port }.\n
 * IP classifier supports IPv4 and IPv6 (fragmented packets are not supported).\n
 * IP flow classification results contain a number of optional information blocks:
 * - L2/3/4 header manipulation
 * - Forwarding decision
 * - QoS mapping information
 *
 * IP L4 filters configuration 
 *   - Applicable for Downstream traffic only
 *   - Forward / Host (Trap to CPU) / Drop  matching specific L4 protocol ID
 *   - Forward action is relevant for GRE and ESP protocols only 
 * @{
 */

/** The maximal value of L2 header size */ 
#define RDPA_L2_HEADER_SIZE	32

/** Number of router mac addressed */
#define RDPA_MAX_ROUTED_MAC 5

/** Defines pbit remarking operation */
typedef enum
{
    /** Copy pbit from DSCP */
    rdpa_pbit_act_dscp_copy  = 0,
    /** Copy pbit from Outer VLAN */
    rdpa_pbit_act_outer_copy = 1,
    /** Copy pbit from Inner VLAN */
    rdpa_pbit_act_inner_copy = 2
}
rdpa_pbit_remark_action;

/** VLAN offset from L2 SA MAC */
typedef enum
{
    rdpa_vlan_offset_12  = 0,
    rdpa_vlan_offset_16 = 4
}
rdpa_vlan_offset;

/* Actions of the optional mac modes */
typedef enum
{
    RDPA_IP_CLASS_PURE_MAC,
    RDPA_IP_CLASS_MC_IP,
    RDPA_IP_CLASS_PURE_IP,
    RDPA_IP_CLASS_US_WLAN
} rdpa_fc_bypass_value;

typedef uint32_t rdpa_fc_bypass; /**< Mask of \ref rdpa_fc_bypass_fields "flowcache bypass" modes */

/** IP classification bypass modes */
typedef enum
{
    RDPA_IP_CLASS_MASK_PURE_MAC = (1 << RDPA_IP_CLASS_PURE_MAC),  /**< In this mode pure mac packests are
                                                                    redirected in Ingress Classification flow */
    RDPA_IP_CLASS_MASK_MC_IP    = (1 << RDPA_IP_CLASS_MC_IP),     /**< In this mode packests with multicast
                                                                    destination IP are redirected in Ingress
                                                                    Classification flow */
    RDPA_IP_CLASS_MASK_PURE_IP  = (1 << RDPA_IP_CLASS_PURE_IP),   /**< In this mode pure IP packests are redirected
                                                                    in Ingress Classification flow */
    RDPA_IP_CLASS_MASK_US_WLAN  = (1 << RDPA_IP_CLASS_US_WLAN),   /**< In this mode packets from lan to wlan will
                                                                    not pass through flow cache */
} rdpa_fc_bypass_fields;

/** 5-tuple based IP flow classifaction result.\n
 * Each result determines L2/3/4 header manipulation, forwarding decision and QoS mapping information.\n
 */
typedef struct {
    rdpa_qos_method qos_method;                /**< QoS classification method flow / pbit. */
    rdpa_forward_action action;                /**< Forwarding action type. */
    rdpa_cpu_reason trap_reason;               /**< CPU trap reason in case forwarding action is ::rdpa_forward_action_host and ::rdpa_fc_action_forward is set. */
    rdpa_dscp dscp_value;                      /**< DSCP value if ::rdpa_fc_action_dscp_remark is set. */
    uint16_t nat_port;                         /**< TCP/UDP port replacemenet or GRE call id, the port direction is according to flow direction. */
    bdmf_ip_t nat_ip;                          /**< IP address replacement,the IP address direction is according to flow direction. */
    bdmf_ipv6_t ds_lite_src;                   /**< If set, DS-lite tunnel source address. */
    bdmf_ipv6_t ds_lite_dst;                   /**< If set, DS-lite tunnel destination address. */
    bdmf_object_handle policer_obj;            /**< Policer Object used if ::rdpa_fc_action_policer is set (supported for downstream traffic only).*/ 

    rdpa_if port;                              /**< Egress port. */
    uint32_t queue_id;                         /**< Egress queue id. */
    uint8_t wan_flow;                          /**< US Gem Flow or US LLID. */
    rdpa_vlan_offset ovid_offset;              /**< Outer VID offset. */
    rdpa_pbit_remark_action opbit_action;      /**< Outer pbit remarking value if ::rdpa_fc_action_opbit_remark is set. */
    rdpa_pbit_remark_action ipbit_action;      /**< Inner pbit remarking value if ::rdpa_fc_action_ipbit_remark is set. */
    int8_t l2_header_offset;                   /**< Offset of L2 header. */
    uint8_t l2_header_size;                    /**< Size of L2 header in bytes. */
    uint8_t l2_header_number_of_tags;          /**< Number of L2 tags. */
    rdpa_fc_action_vec_t action_vec;           /**< Enabled action to be performed on the matched packet. */
    uint8_t l2_header[RDPA_L2_HEADER_SIZE];    /**< L2 header at egress. */
    union {
        uint16_t wl_metadata;                  /**< wlan metadata. */
        struct {
#ifndef _BYTE_ORDER_LITTLE_ENDIAN_
            uint16_t reserved:4;
            uint16_t wlan_tx_priority:4;	   /**< wlan tx priority. */
            uint16_t wlan_chain_id:8;		   /**< wlan chain id. */
#else
            uint16_t wlan_chain_id:8;		   /**< wlan chain id. */
            uint16_t wlan_tx_priority:4;	   /**< wlan tx priority. */
            uint16_t reserved:4;
#endif
        };
    };
    bdmf_index service_q_id;                   /**< Service queue id, for none: service_q_id=-1 */
} rdpa_ip_flow_result_t;

/** 5-tuple based IP flow classifaction info (key + result).\n
 */
typedef struct {
    rdpa_ip_flow_key_t key;          /**< 5-tuple based IP flow key */
    rdpa_ip_flow_result_t result;    /**< 5-tuple based IP flow result */
} rdpa_ip_flow_info_t;


#define RDPA_MAX_L4_FILTERS  rdpa_l4_filter__num_of /**< Max number of L4 filter entries */

/** L4  filter */
typedef enum
{
    rdpa_l4_filter_icmp,                       /**< ICMP protocol */
    rdpa_l4_filter_first_reserved_prot = rdpa_l4_filter_icmp,
    rdpa_l4_filter_esp,                        /**< ESP protocol */
    rdpa_l4_filter_gre,                        /**< GRE protocol */
    rdpa_l4_filter_ah,                         /**< AH protocol */
    rdpa_l4_filter_last_reserved_prot = rdpa_l4_filter_ah,
    rdpa_l4_filter_user_def_0,                 /**< User defined l4 protocol  */
    rdpa_l4_filter_user_def_1,                 /**< User defined l4 protocol  */
    rdpa_l4_filter_user_def_2,                 /**< User defined l4 protocol  */
    rdpa_l4_filter_user_def_3,                 /**< User defined l4 protocol  */
    rdpa_l4_filter_non_tcp_udp_default_filter, /**< Default filter action for traffic that is non tcp/udp and none of other filters matches  */
    rdpa_l4_filter__num_of,                    /**< Number of l4 filters */
} rdpa_l4_filter_index;

/** IP L4 filter configuration.\n
 */
typedef struct 
{
    rdpa_forward_action action;     /**< Filter action. */
    uint8_t protocol;               /**< Standard well-defined IP protocols. For example, UDP(17) (see in.h in Linux kernel for more). */
} rdpa_l4_filter_cfg_t;

/** @} end of ip_class Doxygen group. */

#endif /* _RDPA_IP_FLOW_H_ */
