/*
    Copyright 2000-2010 Broadcom Corporation

    <:label-BRCM:2011:DUAL/GPL:standard
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation (the "GPL").
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    
    A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
    writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
    
    :>
*/

/**************************************************************************
* File Name  : boardparms.c
*
* Description: This file contains the implementation for the BCM63xx board
*              parameter access functions.
*
* Updates    : 07/14/2003  Created.
***************************************************************************/

/* Includes. */
#include "boardparms.h"
#include "bp_defs.h"
#include "bcmSpiRes.h"
#if !defined(_CFE_)
#include "6802_map_part.h"
#endif


/* Variables */
#if 0
/* Sample structure with all elements present in a valid order */
/* Indentation is used to illustrate the groupings where parameters can be repeated */
/* use bp_elemTemplate to use another structure but do not split the groups */   
static bp_elem_t g_sample[] = {
  {bp_cpBoardId,               .u.cp = "SAMPLE"},
  {bp_ulGpioOverlay,           .u.ul = 0;
  {bp_usGpioLedAdsl,           .u.us = 0},
  {bp_usGpioLedAdslFail,       .u.us = 0},
  {bp_usGpioSecLedAdsl,        .u.us = 0},
  {bp_usGpioSecLedAdslFail,    .u.us = 0},
  {bp_usGpioLedSesWireless,    .u.us = 0},
  {bp_usGpioLedWanData,        .u.us = 0},
  {bp_usGpioLedWanError,       .u.us = 0},
  {bp_usGpioLedBlPowerOn,      .u.us = 0},
  {bp_usGpioLedBlStop,         .u.us = 0},
  {bp_usGpioFpgaReset,         .u.us = 0},
  {bp_usGpioLedGpon,           .u.us = 0},
  {bp_usGpioLedGponFail,       .u.us = 0},
  {bp_usGpioLedMoCA,           .u.us = 0},
  {bp_usGpioLedMoCAFail,       .u.us = 0},
  {bp_usGpioLedEpon,           .u.us = 0},
  {bp_usGpioLedEponFail,       .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = 0},
  {bp_usExtIntrSesBtnWireless, .u.us = 0},
  {bp_usMocaType0,             .u.us = 0}, // first MoCA chip always for WAN
    {bp_usExtIntrMocaHostIntr, .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_usExtIntrMocaSBIntr0,  .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_usExtIntrMocaSBIntr1,  .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_pMocaInit,             .u.ptr = (void*)mocaCmdSeq;
  {bp_usMocaType1,             .u.us = 0}, // MoCA LAN
    {bp_usExtIntrMocaHostIntr, .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_usExtIntrMocaSBIntr0,  .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_usExtIntrMocaSBIntr1,  .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_pMocaInit,             .u.ptr = (void*)mocaCmdSeq;
  {bp_usAntInUseWireless,      .u.us = 0},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usGpioWirelessPowerDown, .u.us = 0},
  {bp_ucPhyType0,              .u.uc = 0}, // First switch
    {bp_ucPhyAddress,          .u.uc = 0},
    {bp_usConfigType,          .u.us = 0},
    {bp_ulPortMap,             .u.ul = 0},
    {bp_ulPhyId0,              .u.ul = 0},
      {bp_usDuplexLed,         .u.us = 0},
      {bp_usSpeedLed100,       .u.us = 0},
      {bp_usSpeedLed1000,      .u.us = 0},
      {bp_pPhyInit             .u.ptr = (void *)g_phyinit},
    {bp_ulPhyId1,              .u.ul = 0},
      {bp_usDuplexLed,         .u.us = 0},
      {bp_usSpeedLed100,       .u.us = 0},
      {bp_usSpeedLed1000,      .u.us = 0},
      {bp_pPhyInit             .u.ptr = (void *)g_phyinit},
    {bp_ulPhyId2,              .u.ul = 0},
    {bp_ulPhyId3,              .u.ul = 0},
    {bp_ulPhyId4,              .u.ul = 0},
    {bp_ulPhyId5,              .u.ul = 0},
      {bp_usPhyConnType        .u.us = 0},
      {bp_pPhyInit             .u.ptr = (void *)g_phyinit},
    {bp_ulPhyId6,              .u.ul = 0},
    {bp_ulPhyId7,              .u.ul = 0},
  {bp_ucPhyType1,              .u.uc = 0}, // Second switch
    {bp_ucPhyAddress,          .u.uc = 0},
    {bp_usConfigType,          .u.us = 0},
    {bp_ulPortMap,             .u.ul = 0},
    {bp_ulPhyId0,              .u.ul = 0},
      {bp_usDuplexLed,         .u.us = 0},
      {bp_usSpeedLed100,       .u.us = 0},
      {bp_usSpeedLed1000,      .u.us = 0},
    {bp_ulPhyId1,              .u.ul = 0},
      {bp_usDuplexLed,         .u.us = 0},
      {bp_usSpeedLed100,       .u.us = 0},
      {bp_usSpeedLed1000,      .u.us = 0},
    {bp_ulPhyId2,              .u.ul = 0},
    {bp_ulPhyId3,              .u.ul = 0},
    {bp_ulPhyId4,              .u.ul = 0},
    {bp_ulPhyId5,              .u.ul = 0},
    {bp_ulPhyId6,              .u.ul = 0},
    {bp_ulPhyId7,              .u.ul = 0},
  {bp_ucDspType0,              .u.uc = 0}, // First VOIP DSP
    {bp_ucDspAddress,          .u.uc = 0},
    {bp_usGpioLedVoip,         .u.us = 0},
    {bp_usGpioVoip1Led,        .u.us = 0},
    {bp_usGpioVoip1LedFail,    .u.us = 0},
    {bp_usGpioVoip2Led,        .u.us = 0},
    {bp_usGpioVoip2LedFail,    .u.us = 0},
    {bp_usGpioPotsLed,         .u.us = 0},
    {bp_usGpioDectLed,         .u.us = 0},
  {bp_ucDspType1,              .u.uc = 0}, // Second VOIP DSP
    {bp_ucDspAddress,          .u.uc = 0},
    {bp_usGpioLedVoip,         .u.us = 0},
    {bp_usGpioVoip1Led,        .u.us = 0},
    {bp_usGpioVoip1LedFail,    .u.us = 0},
    {bp_usGpioVoip2Led,        .u.us = 0},
    {bp_usGpioVoip2LedFail,    .u.us = 0},
    {bp_usGpioPotsLed,         .u.us = 0},
    {bp_usGpioDectLed,         .u.us = 0},
  {bp_ulAfeId0,                .u.ul = 0},
  {bp_ulAfeId1,                .u.ul = 0},
  {bp_usGpioExtAFEReset,       .u.us = 0},
  {bp_usGpioExtAFELDPwr,       .u.us = 0},
  {bp_usGpioExtAFELDMode,      .u.us = 0},
  {bp_usGpioAFEVR5P3PwrEn,     .u.us = 0},
  {bp_usGpioLaserDis,          .u.us = 0},
  {bp_usGpioLaserTxPwrEn,      .u.us = 0},
  {bp_usGpioEponOpticalSD,     .u.us = 0},
  {bp_usVregSel1P2,            .u.us = 0},
  {bp_ucVreg1P8                .u.uc = 0},
  {bp_usVregAvsMin             .u.us = 0},
  {bp_usGpioFemtoReset,        .u.us = 0},
  {bp_usSerialLEDMuxSel        .u.us = 0},
  {bp_usBatteryEnable          .u.us = 0},
  {bp_elemTemplate             .u.bp_elemp = g_sample2},
  {bp_usXdResetGpio            .u.us = 0},  // active low or high is derived from gpio details
    {bp_cpXdResetName          .u.cp = "some_name"},
    {bp_usXdResetReleaseOnInit .u.us = 1},
  {bp_usXdGpio                 .u.us = 0},
    {bp_usXdGpioInitState      .u.us = 1},
    {bp_cpXdGpioInfo           .u.cp = "decription of this gpio"},
    {bp_cpXdGpioInfoState0     .u.cp = "info on state=0"},
    {bp_cpXdGpioInfoState1     .u.cp = "info on state=1"},
  {bp_last}
};

#endif

#if !defined(_CFE_)
// MoCA init command sequence
// Enable RGMII_0 to MOCA. 1Gbps
// Enable RGMII_1 to GPHY. 1Gbps
BpCmdElem moca6802InitSeq[] = {
    { CMD_WRITE, SUN_TOP_CTRL_SW_INIT_0_CLEAR, 0x0FFFFFFF }, //clear sw_init signals

    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_0, 0x11110011 }, //pinmux, rgmii, 3450
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_1, 0x11111111 }, //rgmii
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_2, 0x11111111 }, //rgmii
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_3, 0x22221111 }, // enable sideband all,0,1,2, rgmii
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_4, 0x10000022 }, // enable sideband 3,4, host intr

    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_6, 0x00001100 }, // mdio, mdc

//    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_PAD_CTRL_2, 0x00555510 }, // set gpio 38,39,40 to PULL_NONE
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_PAD_CTRL_3, 0x2402 }, // Set GPIO 41 to PULL_UP

    { CMD_WRITE, SUN_TOP_CTRL_GENERAL_CTRL_NO_SCAN_0, 0x11 }, // , Use 2.5V for rgmii
    { CMD_WRITE, SUN_TOP_CTRL_GENERAL_CTRL_NO_SCAN_1, 0x3  }, // Disable GPHY LDO 
    { CMD_WRITE, SUN_TOP_CTRL_GENERAL_CTRL_NO_SCAN_5, 0x47 }, // set test_drive_sel to 16mA

    { CMD_WRITE, EPORT_REG_EMUX_CNTRL, 0x02 }, //  Select port mode. Activate both GPHY and MOCA phys.

    { CMD_WRITE, EPORT_REG_RGMII_0_CNTRL,  0x1 }, //  Enable rgmii0.
    { CMD_WRITE, EPORT_REG_RGMII_1_CNTRL,  0x0 }, //  Disable rgmii1.
#if defined(_BCM963138_) || defined(CONFIG_BCM963138) || defined(_BCM963148_) || defined(CONFIG_BCM963148)
    { CMD_WRITE, EPORT_REG_RGMII_0_RX_CLOCK_DELAY_CNTRL,  0xc0 }, // disable 2nd delay
#endif
    { CMD_WRITE, EPORT_REG_GPHY_CNTRL, 0x02A4C00F }, // Shutdown Gphy

    { CMD_WRITE, CLKGEN_PAD_CLOCK_DISABLE, 0x1 }, // Disable clkobsv output pin

    { CMD_WRITE, CLKGEN_LEAP_TOP_INST_CLOCK_DISABLE, 0x7 }, // Disable LEAP clocks

    { CMD_WRITE, PM_CONFIG,                0x4000 },   // disable uarts
    { CMD_WRITE, PM_CLK_CTRL,              0x1810c },  // disable second I2C port, PWMA and timers

    { CMD_END,  0, 0 }
};

#endif

#if defined(_BCM96838_) || defined(CONFIG_BCM96838)
//E8C reference design , 2L PCB, 4FE, 1xUSB, 1xWiFi, GPON, SIM CARD, NAND
static bp_elem_t g_bcm968380fhgu[] = {
  {bp_cpBoardId,               .u.cp = "968380FHGU"},  
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_72_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_47_AL},
  {bp_usExtIntrWifiOnOff ,     .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_71_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_4_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedGpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_LED_6_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usGpioLedUSB,            .u.us = BP_GPIO_53_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_11_AH},
  {bp_last}
};

//BCM968380FHGU_SI board.
static bp_elem_t g_bcm968380fhgu_si[] = {
  {bp_cpBoardId,               .u.cp = "968380FHGU_SI"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fhgu},
  {bp_last}
};

//E8C reference design, 2L PCB,  4GE, 1xUSB, 1xWiFi, GPON, SIM CARD, NAND
static bp_elem_t g_bcm968380fggu[] = {
  {bp_cpBoardId,               .u.cp = "968380FGGU"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fhgu},
  {bp_last}
};

static bp_elem_t g_bcm968380fggu_tri[] = {
  {bp_cpBoardId,               .u.cp = "968380FGGU_TRI"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x2f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId5,                .u.ul = 0x02 | BCM_WAN_PORT | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_ucPhyDevName,            .u.cp = "eth5"},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AL},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AL},
  {bp_usAePolarity,            .u.us = 1},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fhgu},
  {bp_last}
};

//E8C reference design, 4L PCB, 4GbE, 1xUSB, 1xWiFi, GPON, SIM CARD, NAND
static bp_elem_t g_bcm968380ffhg[] = {
  {bp_cpBoardId,               .u.cp = "968380FFHG"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fggu},
  {bp_last}
};

//E8C Reference design - 4L PCB, 4xGbE, 2xUSB, 2xWiFi, GPON, SIM CARD, 2xFXS
static bp_elem_t g_bcm968380gerg[] = {
  {bp_cpBoardId,               .u.cp = "968380GERG"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_47_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_39_AL},
#if defined(ZYXEL) && (ZYXEL==1)
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_48_AL},
#else
  {bp_usExtIntrWifiOnOff,      .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_48_AL},
#endif
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_4_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedGpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_LED_6_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
#if defined(ZYXEL) && (ZYXEL==1)
  {bp_usGpioLedUSB0,           .u.us = BP_LED_3_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedUSB1,           .u.us = BP_GPIO_42_AL},
#else
  {bp_usGpioLedUSB,            .u.us = BP_LED_3_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_11_AL},
#endif
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
#if defined(ZYXEL) && (ZYXEL==1)
#else
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
#endif
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
#if defined(ZYXEL) && (ZYXEL==1)
  {bp_usGpioLedInternetData,   .u.us = BP_LED_1_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_34_AL},
#endif
  {bp_last}
};

//BCM968380MGEG board.
static bp_elem_t g_bcm968380mgeg[] = {
  {bp_cpBoardId,               .u.cp = "968380MGEG"},
  {bp_usGpioLedEpon,           .u.us = BP_LED_5_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380gerg},
  {bp_last}
};

//BCM968380GERG_SI board.
static bp_elem_t g_bcm968380gerg_si[] = {
  {bp_cpBoardId,               .u.cp = "968380GERG_SI"},
  {bp_usSpiSlaveSelectNum,     .u.us = 2}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 4},  
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380gerg},
  {bp_last}
};

//BCM968380F SV Board, big 6838SV board , GPON
static bp_elem_t g_bcm968380fsv_g[] = {
  {bp_cpBoardId,               .u.cp = "968380FSV_G"},
//for Active Ethernet use
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_AE},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
//for active ethernet use
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_GMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
//for active ethernet use
  {bp_ulPhyId5,                .u.ul = 0x2 | BCM_WAN_PORT | PHYCFG_VALID | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_1_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_0_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usTsync1025mhz,          .u.us = BP_PIN_TSYNC_1025MHZ_11},
  {bp_usTsync8khz,             .u.us = BP_PIN_TSYNC_8KHZ_4},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usGpioTsyncPonUnstable,  .u.us = BP_GPIO_7_AH},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_14_AH}, // uncomment to enable second UART
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_15_AH}, // uncomment to enable second UART       
//{bp_usSerialLEDMuxSel,       .u.us = BP_SERIAL_LED_MUX_GROUPA}, an example of us eof shift register to output LEDs
  {bp_usSpiSlaveSelectNum,     .u.us = 4}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 67},
  {bp_last}
};

//TBD 
static bp_elem_t g_bcm968380sv_g[] = {
  {bp_cpBoardId,               .u.cp = "968380SV_G"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usSpiSlaveSelectNum,     .u.us = 4}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 67},  
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fsv_g}, //?????
  {bp_last}
};

//E8C Reference design  2L PCB, GPON, 2xFE, 1x FXS, SIM CARD, NAND, SPI NOR
static bp_elem_t g_bcm968385sfu[] = {
  {bp_cpBoardId,               .u.cp = "968385SFU"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_48_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedGpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usGpioLedSim,            .u.us = BP_GPIO_4_AL},
  {bp_usGpioLedSim_ITMS,       .u.us = BP_GPIO_9_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_11_AH},
  {bp_last}
};

//BCM968385SFU_SI board.
static bp_elem_t g_bcm968385sfu_si[] = {
  {bp_cpBoardId,               .u.cp = "968385SFU_SI"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385sfu},
  {bp_last}
};

//E8C Reference design  2L PCB, GPON, 1x GbE, SIM CARD, NAND, SPI NOR
static bp_elem_t g_bcm968385gsp[] = {
  {bp_cpBoardId,               .u.cp = "968385GSP"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_NONE},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385sfu},
  {bp_last}
};

//R&D only
static bp_elem_t g_bcm968385sv_g[] = {
  {bp_cpBoardId,               .u.cp = "968385SV_G"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x04 | MAC_IF_GMII},
//  {bp_ulPhyId2,                .u.ul = 0x00 | PHYCFG_VALID |MAC_IF_GMII | PHY_EXTERNAL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_4_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_12_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usSpiSlaveSelectNum,     .u.us = 4}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},  
  {bp_last}
};

static bp_elem_t g_bcm968381sv_g[] = {
  {bp_cpBoardId,               .u.cp = "968381SV_G"},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385sv_g},
  {bp_last}
};

static bp_elem_t g_bcm968380fttdps[] = {
  {bp_cpBoardId,               .u.cp = "968380FTTDPS"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x13},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulAttachedIdx,           .u.ul = 0},
/*
  {bp_ulPhyId0,                .u.ul = 0x7},
  {bp_ucPhyDevName,            .u.cp = "testme"},
  {bp_ulPhyId1,                .u.ul = 0x8},
*/
  {bp_ulAttachedIdx,           .u.ul = 4},
  {bp_ulPhyId0,                .u.ul = 0x0},
  {bp_ulPhyId1,                .u.ul = 0x1},
  {bp_ulPhyId2,                .u.ul = 0x2},
  {bp_ulPhyId3,                .u.ul = 0x3},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioSpromClk,          .u.us = BP_GPIO_68_AH}, /* for FTTDP */
  {bp_usGpioSpromData,         .u.us = BP_GPIO_69_AH}, /* for FTTDP */
  {bp_usGpioAttachedDevReset,  .u.us = BP_GPIO_0_AH}, /* for FTTDP */
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_last}
};

static bp_elem_t g_bcm968380dp2[] = {
  {bp_cpBoardId,               .u.cp = "968380DP2"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x11},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulAttachedIdx,           .u.ul = 4},
  {bp_ulPhyId0,                .u.ul = 0x0},
  {bp_ulPhyId1,                .u.ul = 0x1},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioSpromClk,          .u.us = BP_GPIO_68_AH}, /* for FTTDP */
  {bp_usGpioSpromData,         .u.us = BP_GPIO_69_AH}, /* for FTTDP */
  {bp_usGpioAttachedDevReset,  .u.us = BP_GPIO_67_AH}, /* for FTTDP */
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_last}
};

static bp_elem_t g_bcm965200f_cpe[] = {
  {bp_cpBoardId,               .u.cp = "965200F_CPE"},
  {bp_cpComment,               .u.cp = "(FCOPE_CPE)"},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x17},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 20000000},
  {bp_usSpiSlaveProtoRev,      .u.us = 2},
  {bp_usSpiSlaveSelectNum,     .u.us = 0},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_67_AL},
  {bp_last}
};

static bp_elem_t g_bcm965200f_co[] = {
  {bp_cpBoardId,               .u.cp = "965200F_CO"},
  {bp_cpComment,               .u.cp = "(FCOPE_CO)"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm965200f_cpe},
  {bp_last}
};

static bp_elem_t g_bcm965200dpf[] = {
  {bp_cpBoardId,               .u.cp = "965200DPF"},
  {bp_cpComment,               .u.cp = "(12L-CO,g.fast)"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  //{bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_ulAttachedIdx,           .u.ul = 1},
  {bp_ulPhyId0,                .u.ul = 6},
  {bp_ulPhyId1,                .u.ul = 7},
  {bp_ulPhyId2,                .u.ul = 8},
  {bp_ulAttachedIdx,           .u.ul = 2},
  {bp_ulPhyId0,                .u.ul = 3},
  {bp_ulPhyId1,                .u.ul = 4},
  {bp_ulPhyId2,                .u.ul = 5},
  {bp_ulAttachedIdx,           .u.ul = 3},
  {bp_ulPhyId0,                .u.ul = 0},
  {bp_ulPhyId1,                .u.ul = 1},
  {bp_ulPhyId2,                .u.ul = 2},
  {bp_ulAttachedIdx,           .u.ul = 4},
  {bp_ulPhyId0,                .u.ul = 9},
  {bp_ulPhyId1,                .u.ul = 10},
  {bp_ulPhyId2,                .u.ul = 11},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 20000000},
  {bp_usSpiSlaveProtoRev,      .u.us = 2},
  {bp_usSpiSlaveSelectNum,     .u.us = 0},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_67_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 1},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_68_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_72_AL},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usTsync8khz,             .u.us = BP_PIN_TSYNC_8KHZ_4},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_67_AL},
  {bp_cpXdResetName,           .u.cp = "DSP0_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_68_AL},
  {bp_cpXdResetName,           .u.cp = "DSP1_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_72_AL},
  {bp_cpXdResetName,           .u.cp = "DSP2_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_69_AL},
  {bp_cpXdResetName,           .u.cp = "AFE_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_70_AL},
  {bp_cpXdResetName,           .u.cp = "BCM54240_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_71_AL},
  {bp_cpXdResetName,           .u.cp = "BCM54220_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdGpio,                .u.us = BP_GPIO_54_AH},
  {bp_usXdGpioInitValue,       .u.us = 0},
  {bp_cpXdGpioInfo,            .u.cp = "DSP_CLK_SEL"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "DCXO"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "VCXO"},
  {bp_usXdGpio,                .u.us = BP_GPIO_2_AH},
  {bp_usXdGpioInitValue,       .u.us = 1},
  {bp_cpXdGpioInfo,            .u.cp = "DSP0_PWR"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "disable core power"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "enable core power"},
  {bp_usXdGpio,                .u.us = BP_GPIO_3_AH},
  {bp_usXdGpioInitValue,       .u.us = 1},
  {bp_cpXdGpioInfo,            .u.cp = "DSP1_PWR"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "disable core power"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "enable core power"},
  {bp_usXdGpio,                .u.us = BP_GPIO_7_AH},
  {bp_usXdGpioInitValue,       .u.us = 1},
  {bp_cpXdGpioInfo,            .u.cp = "DSP2_PWR"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "disable core power"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "enable core power"},
  {bp_usXdGpio,                .u.us = BP_GPIO_15_AH},
  {bp_usXdGpioInitValue,       .u.us = 0},
  {bp_cpXdGpioInfo,            .u.cp = "DSP2_SGMII_SEL"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "bypass dsp2 sgmii"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "connect dsp2 sgmii"},
  {bp_last}
};

static bp_elem_t g_bcm965200dpf2_co[] = {
  {bp_cpBoardId,               .u.cp = "965200DPF2_CO"},
  {bp_cpComment,               .u.cp = ""},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm965200f_cpe},
  {bp_last}
};

static bp_elem_t g_bcm965200dpf2_cpe[] = {
  {bp_cpBoardId,               .u.cp = "965200DPF2_CPE"},
  {bp_cpComment,               .u.cp = ""},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm965200f_cpe},
  {bp_last}
};

static bp_elem_t g_bcm968380fhgu_pg[] = {
  {bp_cpBoardId,               .u.cp = "968380FHGU_PG"},  
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_72_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_47_AL},
  {bp_usExtIntrWifiOnOff ,     .u.us = BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_71_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_4_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedGpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_LED_6_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usGpioLedUSB,            .u.us = BP_GPIO_53_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH}, 
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  /*{bp_usPmdMACEwakeEn,     .u.us = 1}, */
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_2 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_61_AH},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_35_AL},
  {bp_last}
};

static bp_elem_t g_bcm968380fhgu_dvt[] = {
  {bp_cpBoardId,               .u.cp = "968380FHGU_DVT"},  
  {bp_usRogueOnuEn,            .u.us = 0},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_51_AH},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fhgu_pg},
  {bp_last}
};

//BCM968381GREF board.
static bp_elem_t g_bcm968381gref[] = {
  {bp_cpBoardId,               .u.cp = "968381GREF"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385gsp},
  {bp_last}
};

static bp_elem_t g_bcm968380moca[] = {
  {bp_cpBoardId,               .u.cp = "968380MOCA"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
#if !defined(_CFE_)
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_7_AL},
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_4_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 1},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usExtIntrTrplxrTxFail,   .u.us = BP_EXT_INTR_4},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_12_AL},
  {bp_usExtIntrTrplxrSd,       .u.us = BP_EXT_INTR_5 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_13_AH},
  {bp_usTxLaserOnOutN,         .u.us = 1},
  {bp_usGpioPonReset,          .u.us = BP_GPIO_14_AH},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_16_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_16_AH},
  {bp_usSerialLEDMuxSel,       .u.us = BP_SERIAL_LED_MUX_GROUPB},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedGpon,           .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioLedOpticalLinkFail, .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedUSB,            .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA}, 
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_last}
};

static bp_elem_t g_bcm968380lte[] = {
  {bp_cpBoardId,               .u.cp = "968380LTE"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_4_AL},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usGpio1ppsStable,        .u.us = BP_GPIO_7_AL},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_8_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedUSB,            .u.us = BP_LED_3_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_11_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usWanNco10MClk,          .u.us = 1},
  {bp_usGpioVoip2Led,          .u.us = BP_LED_6_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_17_AL},
  {bp_usGpioLteReset,          .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedOpticalLinkFail, .u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usGpioLedWanData,        .u.us = BP_LED_1_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_34_AL},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usTrxSignalDetect,       .u.us = 1},
  {bp_usGpioStrapTxEn,         .u.us = BP_GPIO_58_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_57_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_72_AL},
  {bp_usExtIntrWifiOnOff,      .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_59_AL},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_61_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_14_AH}, // uncomment to enable second UART
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_15_AH}, // uncomment to enable second UART 
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_last}
};

static bp_elem_t g_bcm968380gwan[] = {
  {bp_cpBoardId,               .u.cp = "968380GWAN"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usMiiInterfaceEn,        .u.us = 1},
  {bp_usSerialLEDMuxSel,       .u.us = BP_SERIAL_LED_MUX_GROUPC},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrWifiOnOff,      .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_53_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedUSB,            .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x03 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId5,                .u.ul = 0x01 | BCM_WAN_PORT | PHYCFG_VALID | PHY_EXTERNAL | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968380gwan_opt[] = {
  {bp_cpBoardId,               .u.cp = "968380GWAN_OPT"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x03 | MAC_IF_GMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId5,                .u.ul = 0x02 | BCM_WAN_PORT | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_usAePolarity,            .u.us = 1},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380gwan},
  {bp_last}
};

static bp_elem_t g_bcm968389wlnvb[] = {
  {bp_cpBoardId,               .u.cp = "968389WLNVB"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usMiiInterfaceEn,        .u.us = 1},
  {bp_usSerialLEDMuxSel,       .u.us = BP_SERIAL_LED_MUX_GROUPC},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrWifiOnOff,      .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_53_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedUSB,            .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x01 | BCM_WAN_PORT | PHYCFG_VALID | PHY_EXTERNAL | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968385pgsp[] = {
  {bp_cpBoardId,               .u.cp = "968385PGSP"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_10_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_10_AH},
  /*{bp_usPmdMACEwakeEn,     .u.us = 1}, */
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_2 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_61_AH},
  {bp_usExtIntrWanSignalDetected,     .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_35_AL}, 
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385gsp},
  {bp_last}
};


bp_elem_t * g_BoardParms[] = {g_bcm968380fhgu, g_bcm968380fhgu_si, g_bcm968380ffhg, g_bcm968380gerg, g_bcm968380mgeg, g_bcm968380gerg_si,
    g_bcm968380fsv_g, g_bcm968380sv_g, g_bcm968380fggu, g_bcm968380fggu_tri, g_bcm968385sfu, g_bcm968385sfu_si, g_bcm968385gsp, g_bcm968385sv_g,
    g_bcm968380fttdps, g_bcm968380dp2, g_bcm965200f_cpe, g_bcm965200f_co, g_bcm965200dpf, g_bcm965200dpf2_co, g_bcm965200dpf2_cpe, g_bcm968380fhgu_pg,
    g_bcm968380fhgu_dvt, g_bcm968381gref, g_bcm968381sv_g, g_bcm968380moca, g_bcm968380lte, g_bcm968380gwan, g_bcm968380gwan_opt, g_bcm968385pgsp, g_bcm968389wlnvb, 0};

#endif

#if defined(_BCM96848_) || defined(CONFIG_BCM96848)
static bp_elem_t g_bcm968480fhgu[] = {
  {bp_cpBoardId,                .u.cp = "968480FHGU"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x0f},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_MII},
  {bp_usOamIndex,               .u.us = 1},
  {bp_ucPhyDevName,             .u.cp = "eth1"},
  {bp_usLinkLed,                .u.us = BP_GPIO_5_AL},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usOamIndex,               .u.us = 0},
  {bp_ucPhyDevName,             .u.cp = "eth0"},
  {bp_usLinkLed,                .u.us = BP_GPIO_9_AL},
  {bp_ulPhyId2,                 .u.ul = 0x03 | MAC_IF_MII},
  {bp_usOamIndex,               .u.us = 3},
  {bp_ucPhyDevName,             .u.cp = "eth3"},
  {bp_usLinkLed,                .u.us = BP_GPIO_54_AL},
  {bp_ulPhyId3,                 .u.ul = 0x04 | MAC_IF_MII},
  {bp_usOamIndex,               .u.us = 2},
  {bp_ucPhyDevName,             .u.cp = "eth2"},
  {bp_usLinkLed,                .u.us = BP_GPIO_52_AL},
  {bp_usGpioVoip1Led,           .u.us = BP_GPIO_10_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedUSB,             .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedSesWireless,     .u.us = BP_GPIO_12_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedSim,             .u.us = BP_GPIO_13_AL},
  {bp_usGpioLedOpticalLinkStat, .u.us = BP_GPIO_14_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedGpon,            .u.us = BP_GPIO_15_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedWanData,         .u.us = BP_GPIO_17_AL | BP_LED_USE_GPIO},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_18_AH},
  {bp_usExtIntrSesBtnWireless,  .u.us = BP_EXT_INTR_6},
  {bp_usExtIntrWifiOnOff,       .u.us = BP_EXT_INTR_7},
  {bp_usSimVccEn,               .u.us = BP_GPIO_35_AH},
  {bp_usSimRst,                 .u.us = BP_GPIO_37_AH},
  {bp_usSimDat,                 .u.us = BP_GPIO_43_AH},
  {bp_usSimClk,                 .u.us = BP_GPIO_44_AH},
  {bp_usSimPresence,            .u.us = BP_GPIO_45_AH},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_51_AH},
  {bp_usTrxSignalDetect,        .u.us = BP_GPIO_53_AH},
  {bp_usTxLaserOnOutN,          .u.us = BP_GPIO_62_AH},
  {bp_usGpioI2cScl,             .u.us = BP_GPIO_63_AH},
  {bp_usGpioI2cSda,             .u.us = BP_GPIO_64_AH},
  {bp_ucDspType0,               .u.uc =  BP_VOIP_DSP},
  {bp_ucDspAddress,             .u.uc =  0}, 
  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_5},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_53_AH},
  {bp_usTsync1pps,              .u.us = BP_GPIO_6_AH},
  {bp_last}
};

static bp_elem_t g_bcm968480fhbb[] = {
  {bp_cpBoardId,               .u.cp = "968480FHBB"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_4_AL | BP_LED_USE_GPIO},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_61_AL},
  {bp_usGpioLedSim,            .u.us = BP_GPIO_NONE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968480fhgu},
  {bp_last}
};

static bp_elem_t g_bcm968485sfu[] = {
  {bp_cpBoardId,                .u.cp = "968485SFU"},
  {bp_usGponOpticsType ,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x03},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usLinkLed,                .u.us = BP_GPIO_34_AL},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_MII},
  {bp_usLinkLed,                .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedSim,             .u.us = BP_GPIO_13_AL},
  {bp_usGpioLedGpon,            .u.us = BP_GPIO_15_AL | BP_LED_USE_GPIO},
  {bp_usGpioVoip1Led,           .u.us = BP_GPIO_16_AL | BP_LED_USE_GPIO},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_18_AH},
  {bp_usGpioLedOpticalLinkStat, .u.us = BP_GPIO_33_AL},
  {bp_usSimVccEn,               .u.us = BP_GPIO_35_AH},
  {bp_usSimRst,                 .u.us = BP_GPIO_37_AH},
  {bp_usSimDat,                 .u.us = BP_GPIO_43_AH},
  {bp_usSimClk,                 .u.us = BP_GPIO_44_AH},
  {bp_usSimPresence,            .u.us = BP_GPIO_45_AH},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_51_AH},
  {bp_usTrxSignalDetect,        .u.us = BP_GPIO_53_AH},
  {bp_usTxLaserOnOutN,          .u.us = BP_GPIO_62_AH},
  {bp_usGpioI2cScl,             .u.us = BP_GPIO_63_AH},
  {bp_usGpioI2cSda,             .u.us = BP_GPIO_64_AH},
  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_5},
  {bp_ucDspType0,              .u.uc =  BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc =  0}, 
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968485sfbb[] = {
  {bp_cpBoardId,               .u.cp = "968485SFBB"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_4_AL | BP_LED_USE_GPIO},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_61_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968485sfu},
  {bp_last}
};

static bp_elem_t g_bcm968480sv[] = {
  {bp_cpBoardId,               .u.cp = "968480SV"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 1},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 0},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AL},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 3},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 2},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_17_AL},
  {bp_usSimDat,                .u.us = BP_GPIO_43_AH},
  {bp_usSimClk,                .u.us = BP_GPIO_44_AH},
  {bp_usSimPresence,           .u.us = BP_GPIO_45_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_10_AH | BP_LED_USE_GPIO},
  {bp_usSerialLedData,         .u.us = BP_GPIO_11_AH},
  {bp_usSimVccEn,              .u.us = BP_GPIO_35_AH},
  {bp_usSimVccVolSel,          .u.us = BP_GPIO_36_AH},
  {bp_usSimRst,                .u.us = BP_GPIO_37_AH},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_18_AH},
//  {bp_usMiiMdc,                .u.us = BP_GPIO_47_AH},
//  {bp_usMiiMdio,               .u.us = BP_GPIO_48_AH},
  {bp_usTxLaserOnOutN,         .u.us = BP_GPIO_62_AH},
  {bp_usProbeClk,              .u.us = BP_GPIO_74_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioLedUSB,            .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedSim,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedOpticalLinkStat,.u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioLedGpon,           .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usAePolarity,            .u.us = 0},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_usTsync1pps,             .u.us = BP_GPIO_6_AH},
  {bp_last}
};

static bp_elem_t g_bcm968480sv_sgmii[] = {
  {bp_cpBoardId,               .u.cp = "968480SV_SGMII"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x06 | MAC_IF_SGMII }, /* or MAC_IF_HSGMII */
  {bp_usOamIndex,              .u.us = 1},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 0},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AL},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 3},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 2},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_17_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968480sv},
  {bp_last}
};

static bp_elem_t g_bcm968485sv[] = {
  {bp_cpBoardId,               .u.cp = "968485SV"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AL},
  {bp_usSimDat,                .u.us = BP_GPIO_43_AH},
  {bp_usSimClk,                .u.us = BP_GPIO_44_AH},
  {bp_usSimPresence,           .u.us = BP_GPIO_45_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_10_AH | BP_LED_USE_GPIO},
  {bp_usSerialLedData,         .u.us = BP_GPIO_11_AH},
  {bp_usSimVccEn,              .u.us = BP_GPIO_35_AH},
  {bp_usSimVccVolSel,          .u.us = BP_GPIO_36_AH},
  {bp_usSimRst,                .u.us = BP_GPIO_37_AH},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_18_AH},
//  {bp_usMiiMdc,                .u.us = BP_GPIO_47_AH},
//  {bp_usMiiMdio,               .u.us = BP_GPIO_48_AH},
  {bp_usTxLaserOnOutN,         .u.us = BP_GPIO_62_AH},
  {bp_usProbeClk,              .u.us = BP_GPIO_74_AH},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_1_AL},
//  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedSim,            .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioLedOpticalLinkStat,.u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedGpon,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 67},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_usTsync1pps,             .u.us = BP_GPIO_6_AH},
  {bp_last}
};

static bp_elem_t g_bcm968481sp[] = {
  {bp_cpBoardId,                .u.cp = "968481SP"},
  {bp_usGponOpticsType ,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x01},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usLinkLed,                .u.us = BP_GPIO_34_AL},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_16_AH},
  {bp_usGpioLedGpon,            .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedOpticalLinkStat, .u.us = BP_GPIO_33_AL},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_51_AH},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_53_AH},
  {bp_usTxLaserOnOutN,          .u.us = BP_GPIO_62_AH},
  {bp_usGpioI2cScl,             .u.us = BP_GPIO_63_AH},
  {bp_usGpioI2cSda,             .u.us = BP_GPIO_64_AH},
//  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_5},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_last}
};

static bp_elem_t g_bcm968481spbb[] = {
  {bp_cpBoardId,               .u.cp = "968481SPBB"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_4_AL | BP_LED_USE_GPIO},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_61_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968481sp},
  {bp_last}
};

static bp_elem_t g_bcm968481psv[] = {
  {bp_cpBoardId,               .u.cp = "968481PSV"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x01},
  {bp_ulPhyId0,                .u.ul = 0x06 | MAC_IF_SGMII },
  {bp_usWanEarlyTxEn,          .u.us = BP_GPIO_10_AH},
  {bp_usGpioUart2Cts,          .u.us = BP_GPIO_13_AH},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_14_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_15_AH},
  {bp_usWanNco10MClk,          .u.us = BP_GPIO_16_AH},
//  {bp_usMiiMdc,                .u.us = BP_GPIO_47_AH},
//  {bp_usMiiMdio,               .u.us = BP_GPIO_48_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 61},
  {bp_usTxLaserOnOutN,         .u.us = BP_GPIO_62_AH},
  {bp_usMs1588TodAlarm,        .u.us = BP_GPIO_65_AH},
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_66_AH},
  {bp_usWanNcoProgMClk,        .u.us = BP_GPIO_67_AH},
  {bp_usProbeClk,              .u.us = BP_GPIO_74_AH},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968486sgu[] = {
  {bp_cpBoardId,                .u.cp = "968486SGU"},
  {bp_usGponOpticsType ,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x03},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_MII},
  {bp_usLinkLed,                .u.us = BP_GPIO_52_AL},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usLinkLed,                .u.us = BP_GPIO_9_AL},
  {bp_ulPortFlags,              .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_usGpioVoip1Led,           .u.us = BP_GPIO_10_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedUSB,             .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedSesWireless,     .u.us = BP_GPIO_12_AL},
  {bp_usGpioLedOpticalLinkStat, .u.us = BP_GPIO_14_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedGpon,            .u.us = BP_GPIO_15_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedWanData,         .u.us = BP_GPIO_17_AL},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_18_AH},
  {bp_usExtIntrSesBtnWireless,  .u.us = BP_EXT_INTR_6},
  {bp_usExtIntrWifiOnOff,       .u.us = BP_EXT_INTR_7},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_51_AH},
  {bp_usTrxSignalDetect,        .u.us = BP_GPIO_53_AH},
  {bp_usTxLaserOnOutN,          .u.us = BP_GPIO_62_AH},
  {bp_usGpioI2cScl,             .u.us = BP_GPIO_63_AH},
  {bp_usGpioI2cSda,             .u.us = BP_GPIO_64_AH},
  {bp_ucDspType0,               .u.uc =  BP_VOIP_DSP},
  {bp_ucDspAddress,             .u.uc =  0},
  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_4},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968481psfp[] = {
  {bp_cpBoardId,               .u.cp = "968481PSFP"},
  {bp_usGponOpticsType ,       .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_use_def_polarity},
  {bp_InvSerdesTxPol,          .u.us = pmd_use_def_polarity},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x01},
  {bp_ulPhyId0,                .u.ul = 0x06 | MAC_IF_SGMII },
  {bp_usTsync1pps,             .u.us = BP_GPIO_6_AH},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AL},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_15_AH},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 0},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 60},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_61_AL},
  {bp_usTxLaserOnOutN,         .u.us = BP_GPIO_62_AH},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_68_AH},
  {bp_last}
  };

bp_elem_t * g_BoardParms[] = {g_bcm968480fhgu, g_bcm968480fhbb, g_bcm968485sfu, g_bcm968480sv, g_bcm968480sv_sgmii, g_bcm968485sv, g_bcm968481sp, g_bcm968481spbb, g_bcm968485sfbb, g_bcm968481psv, g_bcm968486sgu, g_bcm968481psfp, 0};
#endif

#if defined(_BCM96362_) || defined(CONFIG_BCM96362)

static bp_elem_t g_bcm96362advnx[] = {
  {bp_cpBoardId,               .u.cp = "96362ADVNX"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},
  {bp_last}
};

static bp_elem_t g_bcm96362advngr[] = {
  {bp_cpBoardId,               .u.cp = "96362ADVNgr"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_SPI_SSB3_EXT_CS |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ulPhyId5,                .u.ul = 0x19},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},
  {bp_last}
};

static bp_elem_t g_bcm96362advngr2[] = {
  {bp_cpBoardId,               .u.cp = "96362ADVNgr2"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_SPI_SSB3_EXT_CS |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_5_2_2},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm96362advngr},
  {bp_last}
};

static bp_elem_t g_bcm96362advn2xh[] = {
  {bp_cpBoardId,               .u.cp = "96362ADVN2xh"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_SPI_SSB2_EXT_CS |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x10},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_SPI_SSB_2},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x00 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = 0x01 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = 0x02 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = 0x03 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = 0x04 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm96362advn2xm[] = {
  {bp_cpBoardId,               .u.cp = "96362ADVN2XM"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_SPI_SSB2_EXT_CS |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x10},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_SPI_SSB_2},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x00 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = 0x01 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = 0x02 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = 0x03 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = 0x04 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},
  {bp_last}
};


static bp_elem_t g_bcm96361XF[] = {
  {bp_cpBoardId,               .u.cp = "96361XF"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = MII_DIRECT},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_5_2_2},
  {bp_usVregSel1P2,            .u.us = 0x13},
  {bp_usGpioFemtoReset,        .u.us = BP_GPIO_35_AH},
  {bp_last}
};

static bp_elem_t g_bcm96361I2[] = {
  {bp_cpBoardId ,              .u.cp = "96361I2"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},
  {bp_last}
};

static bp_elem_t g_bcm96362rpvt[] = {
  {bp_cpBoardId ,              .u.cp = "96362RPVT"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId5,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_5_2_2}, 
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm96362rpvt_2u[] = {
  {bp_cpBoardId ,              .u.cp = "96362RPVT_2U"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId5,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_5_2_2}, 
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm96362ravngr2[] = {
  {bp_cpBoardId,               .u.cp = "96362RAVNGR2"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_5_2_2},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm96362radvnxh5[] = {
  {bp_cpBoardId,               .u.cp = "96362RADVNXH5"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_SPI_SSB2_EXT_CS |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_5_2_2},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm96362advn2xh},
  {bp_last}
};

static bp_elem_t g_bcm96362radvnxh5_p203[] = {
  {bp_cpBoardId,               .u.cp = "96362RADVNXH503"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_SPI_SSB2_EXT_CS |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x11},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_SPI_SSB_2},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = 0x01 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = 0x02 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = 0x03 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = 0x04 | CONNECTED_TO_EXTERN_SW},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_2},
  {bp_last}
};


static bp_elem_t g_bcm96362radvn2xh[] = {
  {bp_cpBoardId,               .u.cp = "96362RADVN2XH"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm96362radvnxh5},
  {bp_last}
};

static bp_elem_t g_bcm96362rwfar[] = {
  {bp_cpBoardId,               .u.cp = "96362RWFAR"},
  {bp_ulGpioOverlay,           .u.ul = BP_OVERLAY_EPHY_LED_0},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_5_AL},  
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},  
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_0_AL},  
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_28_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_29_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_2},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x31},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ulPhyId5,                .u.ul = 0x19},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_16_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_17_AL},
  {bp_usGpioPotsLed,           .u.us = BP_GPIO_18_AL},	
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301| BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_2},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_bcm96362advnx, g_bcm96362advngr, g_bcm96362advngr2, g_bcm96362advn2xh, g_bcm96361XF, g_bcm96361I2, g_bcm96362rpvt, g_bcm96362rpvt_2u, g_bcm96362ravngr2, g_bcm96362advn2xm, g_bcm96362radvnxh5, g_bcm96362radvn2xh, g_bcm96362radvnxh5_p203, g_bcm96362rwfar, 0};
#endif


#if defined(_BCM96328_) || defined(CONFIG_BCM96328)

static bp_elem_t g_bcm96328avng[] = {
  {bp_cpBoardId,               .u.cp = "96328avng"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_0_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_4_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_8_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_6_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_7_AL},
  {bp_usGpioPotsLed,           .u.us = BP_GPIO_5_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},
  {bp_last}
};

static bp_elem_t g_bcm96328avngrP1[] = {
  {bp_cpBoardId,               .u.cp = "96328avngrP1"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SPI_EXT_CS |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},
  {bp_last}
};

static bp_elem_t g_bcm96328avngr[] = {
  {bp_cpBoardId,               .u.cp = "96328avngr"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SPI_EXT_CS |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},
  {bp_last}
};

static bp_elem_t g_bcm963281TAN[] = {
  {bp_cpBoardId,               .u.cp = "963281TAN"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_7_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_4_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_8_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},
  {bp_last}
};

static bp_elem_t g_bcm963281TAN2[] = {
  {bp_cpBoardId,               .u.cp = "963281TAN2"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_7_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_4_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_8_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_2},
  {bp_last}
};

static bp_elem_t g_bcm963281TAN3[] = {
  {bp_cpBoardId,               .u.cp = "963281TAN3"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_7_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_4_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_8_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302| BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_5_2_2},
  {bp_last}
};

static bp_elem_t g_bcm963281TAN4[] = {
  {bp_cpBoardId,               .u.cp = "963281TAN4"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_7_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_4_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_8_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_2},
  {bp_last}
};

static bp_elem_t g_bcm963283_24tstbrd[] = {
  {bp_cpBoardId,               .u.cp = "963283_24tstbrd"},
  {bp_ulGpioOverlay,           .u.ul =( BP_OVERLAY_PCIE_CLKREQ)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_last}
};

static bp_elem_t g_bcm963293_24sw_mb[] = {
  {bp_cpBoardId,               .u.cp = "963293_24SW_MB"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_31_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_last}
};

static bp_elem_t g_bcm93715rv[] = {
  {bp_cpBoardId,                 .u.cp = "93715rv"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SPI_EXT_CS)},

  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x01},
  {bp_ulPhyId0,                .u.ul = 0x01 | CONNECTED_TO_EPON_MAC},

  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_12_AL},
  
  {bp_usGpioPassDyingGasp,     .u.us = BP_SERIAL_GPIO_1_AL},
  
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_1},

  {bp_last}
 };


bp_elem_t * g_BoardParms[] = {g_bcm96328avng, g_bcm96328avngrP1, g_bcm96328avngr, g_bcm963281TAN, g_bcm963281TAN2, g_bcm963281TAN3, g_bcm963281TAN4, g_bcm963283_24tstbrd, g_bcm963293_24sw_mb, g_bcm93715rv, 0};
#endif

#if defined(_BCM963268_) || defined(CONFIG_BCM963268)

static char g_obsoleteStr[] = "(obsolete)";

static bp_elem_t g_bcm963268sv1[] = {
  {bp_cpBoardId,               .u.cp = "963268SV1"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV1},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_last}
};

static bp_elem_t g_bcm963168mbv_17a[] = {
  {bp_cpBoardId,               .u.cp = "963168MBV_17A"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0}, 
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_6306| BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_21},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168mbv_30a[] = {
  {bp_cpBoardId ,              .u.cp = "963168MBV_30A"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0}, 
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_AVMODE_VDSL | BP_AFE_FE_REV_12_21 | BP_AFE_FE_ANNEXA },
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168mbv17a302[] = {
  {bp_cpBoardId,               .u.cp = "963168MBV17A302"},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_17_AL},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_13_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_12_AH},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_17a},
  {bp_last}
};

static bp_elem_t g_bcm963167ref1[] = {
  {bp_cpBoardId,               .u.cp = "963167REF1"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE|BP_OVERLAY_VREG_CLK)},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30 },
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_36_AL},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv17a302},
  {bp_last}
};

static bp_elem_t g_bcm963167ref3[] = {
  {bp_cpBoardId,               .u.cp = "963167REF3"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963167ref1},
  {bp_last}

};

static bp_elem_t g_bcm963167ref2[] = {
  {bp_cpBoardId,               .u.cp = "963167REF2"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},

  {bp_elemTemplate,            .u.bp_elemp = g_bcm963167ref1},
  {bp_last}

};

static bp_elem_t g_bcm963168mbv30a302[] = {
  {bp_cpBoardId,               .u.cp = "963168MBV30A302"},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_17_AL},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_13_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_12_AH},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_30a},
  {bp_last}
};

static bp_elem_t g_bcm963268mbv[] = {
  {bp_cpBoardId,                 .u.cp = "963268MBV"},
  {bp_cpComment,               .u.cp = g_obsoleteStr},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},
  {bp_last}
};

static bp_elem_t g_bcm963168mbv3[] = {
  {bp_cpBoardId ,              .u.cp = "963168MBV3"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_17_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_20 }, 
  // LDMode is set to NONE in case the board we are inheriting from set them
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_NONE},  
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH},
  // IntAFELDClk uses dedicated pin
  // IntAFELDData uses dedicated pin
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_NONE},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_8_AL},
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_11_AH},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_13_AL},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_30a},
  {bp_last}
};

static bp_elem_t g_bcm963168PLC[] = {
  {bp_cpBoardId ,              .u.cp = "963168PLC"},
  {bp_ulGpioOverlay,           .u.ul = (BP_OVERLAY_PHY |
                                        BP_OVERLAY_SERIAL_LEDS |
                                        BP_OVERLAY_USB_LED |
                                        BP_OVERLAY_USB_DEVICE |
                                        BP_OVERLAY_HS_SPI_SSB7_EXT_CS)},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH},
  // Set unused inherited settings to BP_GPIO_NONE
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_NONE},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_NONE},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  //ExtIntr Config
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_39_AH },
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_40_AH },
  //Switch-phy Config - Ephy/Gphy
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  //Switch-phy Config - PLC
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT_3P3V},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulPortMaxRate,           .u.ul = 400000000},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY | PORT_FLAG_SOFT_SWITCHING},
  //Switch-phy Config - MOCA LAN
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },       
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},       
  {bp_ucPhyDevName,            .u.cp = "moca%d"},        
  //PLC Config
  {bp_usGpioPLCReset,          .u.us = BP_GPIO_18_AL},
  //MoCA Config - LAN
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},         
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},       
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_41_AH },
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_1},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},        
#endif         
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_19_AL},        
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_NONE},         
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},        
  {bp_usSpiSlaveSelectNum,     .u.us = 7},         
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},         
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},         
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},        
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},        
  //Voip SPI overrides
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_30a},
  {bp_last}
};

static bp_elem_t g_bcm963168PLC_MOCAW[] = {
  {bp_cpBoardId ,              .u.cp = "963168PLC_MOCAW"},
  {bp_ulGpioOverlay,           .u.ul = (BP_OVERLAY_PHY |
                                        BP_OVERLAY_SERIAL_LEDS |
                                        BP_OVERLAY_USB_LED |
                                        BP_OVERLAY_USB_DEVICE |
                                        BP_OVERLAY_HS_SPI_SSB6_EXT_CS |
                                        BP_OVERLAY_HS_SPI_SSB7_EXT_CS)},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH},
  // Set unused inherited settings to BP_GPIO_NONE
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_NONE},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_NONE},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  //ExtIntr Config
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_39_AH },
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_40_AH },
  //Switch-phy Config - Ephy/Gphy
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  //Switch-phy Config - MOCA WAN
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },       
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},       
  {bp_ucPhyDevName,            .u.cp = "moca%d"},        
  //Switch-phy Config - MOCA LAN
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },       
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},       
  {bp_ucPhyDevName,            .u.cp = "moca%d"},        
  //MoCA Config - WAN
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},  //first MoCA always for WAN
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},       
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_42_AH },
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AH },
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_13_AH },
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},        
#endif         
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_44_AL},        
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_NONE},         
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},        
  {bp_usSpiSlaveSelectNum,     .u.us = 6},         
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},         
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},         
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},        
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},        
  //MoCA Config - LAN
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN},         
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},       
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_41_AH },
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_1},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},        
#endif         
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_19_AL},        
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_NONE},         
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},        
  {bp_usSpiSlaveSelectNum,     .u.us = 7},         
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},         
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},         
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},        
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},        
  //Voip SPI overrides
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_30a},
  {bp_last}
};

#if 0
/* Uncomment "#define BP_GET_INT_AFE_DEFINED" in Boardparams.h when these bp_ids are in used:
* bp_usGpioIntAFELDPwr
* bp_usGpioIntAFELDMode
* bp_usGpioAFELDRelay
*/

static bp_elem_t g_bcm963268mbv6b[] = {
  {bp_cpBoardId,               .u.cp = "963168MBV6b"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ulPhyId6,                .u.ul = 0x19},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_12_21},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_13_AH},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_12_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},
  {bp_last}
};
#endif

static bp_elem_t g_bcm963168vx[] = {
  {bp_cpBoardId,               .u.cp = "963168VX"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV1},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_last}
};

static bp_elem_t g_bcm963168vx_p300[] = {
  {bp_cpBoardId,               .u.cp = "963168VX_P300"},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168vx}, 
  {bp_last}
};

static bp_elem_t g_bcm963168vx_p400[] = {
  {bp_cpBoardId,               .u.cp = "963168VX_P400"},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168vx_p300},
  {bp_last}
};

static bp_elem_t g_bcm963168vx_ext1p8[] = {
  {bp_cpBoardId,               .u.cp = "963168VX_ext1p8"},
  {bp_ucVreg1P8,               .u.uc = BP_VREG_EXTERNAL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168vx},
  {bp_last}
};

static bp_elem_t g_bcm963168xf[] = {
  {bp_cpBoardId,               .u.cp = "963168XF"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = MII_DIRECT},  
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_14_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_15_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioFemtoReset,        .u.us = BP_GPIO_8_AH},  
  {bp_last}
};

static bp_elem_t g_bcm963268sv2_extswitch[] = {
  {bp_cpBoardId,               .u.cp = "963268SV2_EXTSW"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_HS_SPI_SSB7_EXT_CS)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_usEphyBaseAddress,       .u.us = 0x08},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_9},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_10},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_11},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPhyId5,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = 0x19 | MAC_IF_RGMII},  
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV1},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_22_AH},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 781000},
  {bp_usSpiSlaveProtoRev,      .u.us = 0},   
  {bp_last}
};

static bp_elem_t g_bcm963268bu[] = {
  {bp_cpBoardId,               .u.cp = "963268BU"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_PHY |
                                       BP_OVERLAY_INET_LED |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  // {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xFC},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3 | PHY_INTERNAL | PHY_INTEGRATED_VALID },
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 },
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_0 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_1 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL },
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_last}
};

static bp_elem_t g_bcm963268bu_p300[] = {
  {bp_cpBoardId,               .u.cp = "963268BU_P300"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_PHY |
                                       BP_OVERLAY_INET_LED |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xF9},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_17 | PHY_INTERNAL | PHY_INTEGRATED_VALID },
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 | PHY_INTERNAL | PHY_INTEGRATED_VALID },
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_0 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_1 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL },
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_last}
};

static bp_elem_t g_bcm963168xh[] = {
  {bp_cpBoardId,               .u.cp = "963168XH"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_PCIE_CLKREQ |
                                       BP_OVERLAY_HS_SPI_SSB5_EXT_CS)},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x58},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_AVMODE_VDSL | BP_AFE_FE_REV_12_21 | BP_AFE_FE_ANNEXA },
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},  
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168xh5[] = {
    {bp_cpBoardId,               .u.cp = "963168XH5"},
    {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
    {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                      BP_OVERLAY_GPHY_LED_0|
                                      BP_OVERLAY_USB_DEVICE|
                                      BP_OVERLAY_USB_LED|
                                      BP_OVERLAY_PCIE_CLKREQ |
                                      BP_OVERLAY_HS_SPI_SSB5_EXT_CS)},
    {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
    {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
    {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
    {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
    {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_10_AL},
    {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
    {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
    {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
    {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
    {bp_usWirelessFlags,         .u.us = 0},
    {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
    {bp_ulPortMap,               .u.ul = 0x58},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
    {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
    {bp_ulPhyId6,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
    {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
    {bp_ulPortMap,               .u.ul = 0x0f},
    {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
    {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
    {bp_ucDspAddress,            .u.uc = 0},
    {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
    {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
    {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
    {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_AVMODE_VDSL | BP_AFE_FE_REV_12_21 | BP_AFE_FE_ANNEXA },
    {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},  
    {bp_usSpiSlaveSelectNum,     .u.us = 4},
    {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
    {bp_usSpiSlaveSelectNum,     .u.us = 7},
    {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
    {bp_last}
};

  static bp_elem_t g_bcm963168xm[] = {
    {bp_cpBoardId,               .u.cp = "963168XM"},
    {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
    {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                         BP_OVERLAY_USB_DEVICE|
                                         BP_OVERLAY_PCIE_CLKREQ |
                                         BP_OVERLAY_HS_SPI_SSB5_EXT_CS)},
    {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
    {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
    {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
    {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
    {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_10_AL},
    {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
    {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
    {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
    {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
    {bp_usWirelessFlags,         .u.us = 0},
    {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
    {bp_ulPortMap,               .u.ul = 0x58},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
    {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
    {bp_ulPhyId6,                .u.ul = BP_PHY_ID_25},
    {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
    {bp_ulPortMap,               .u.ul = 0x0f},
    {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
    {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
    {bp_ucDspAddress,            .u.uc = 0},
    {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
    {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
    {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
    {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_AVMODE_VDSL | BP_AFE_FE_REV_12_21 | BP_AFE_FE_ANNEXA },
    {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},  
    {bp_last}
  };


  static bp_elem_t g_bcm963168mp[] = {
  {bp_cpBoardId,               .u.cp = "963168MP"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {  bp_usGpio_Intr,             .u.us = BP_GPIO_32_AL },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,      .u.ul = (unsigned long)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },  
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {  bp_usGpio_Intr,             .u.us = BP_GPIO_33_AL },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S },    
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1F},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = MII_DIRECT},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_SOFT_SWITCHING},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

  static bp_elem_t g_bcm963268v30a[] = {
  {bp_cpBoardId,               .u.cp = "963268V30A"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
                                       BP_OVERLAY_PHY |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_SERIAL_LEDS )},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN}, // FIXME
  {bp_usWirelessFlags,         .u.us = 0}, // FIXME
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xD8},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x00 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId6,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_6302_6306_REV_A_12_40},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_9_AL},  
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_last}
};

  static bp_elem_t g_bcm963168media[] = {
  {bp_cpBoardId,               .u.cp = "963168MEDIA"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
                                       BP_OVERLAY_PHY |                                       
                                       BP_OVERLAY_SERIAL_LEDS )},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN}, // FIXME
  {bp_usWirelessFlags,         .u.us = 0}, // FIXME
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5F},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL}, 
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH},        
  {bp_last}
};


static bp_elem_t g_bcm963268sv2[] = {
  {bp_cpBoardId,               .u.cp = "963268SV2"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV1},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_last}
};

static bp_elem_t g_bcm963168xfg3[] = {
  {bp_cpBoardId,               .u.cp = "963168XFG3"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE  |
                                       BP_OVERLAY_PHY         |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1F},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1}, 
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2},  
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3},         
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = MII_DIRECT},  
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_11_AH},  
  {bp_usGpioFemtoReset,        .u.us = BP_GPIO_8_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_7_2_30}, 
  {bp_last}
};

static bp_elem_t g_bcm963269bhr[] = {
  {bp_cpBoardId,               .u.cp = "963269BHR"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_HS_SPI_SSB4_EXT_CS |
                                       BP_OVERLAY_HS_SPI_SSB5_EXT_CS |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  //{bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_NONE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_42_AH},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_41_AH},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},  //first MoCA always for WAN
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_43_AH},
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_45_AH},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_44_AH},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_40_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN}, // LAN
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_1},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_39_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xd8},
  {bp_usGphyBaseAddress,       .u.us = 0x08},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_12},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_1},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_last}
};

static bp_elem_t g_bcm963168ach5[] = {
  {bp_cpBoardId,               .u.cp = "963168ACH5"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_HS_SPI_SSB5_EXT_CS |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_usGphyBaseAddress,       .u.us = 0x08},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_12},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168ac5[] = {
  {bp_cpBoardId,               .u.cp = "963168AC5"},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168ach5},
  {bp_last}
};

static bp_elem_t g_bcm963168xn5[] = {
  {bp_cpBoardId,               .u.cp = "963168XN5"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_4},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168xm5[] = {
    {bp_cpBoardId,               .u.cp = "963168XM5"},
    {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC},
    {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                         BP_OVERLAY_USB_DEVICE  |
                                         BP_OVERLAY_USB_LED     |
                                         BP_OVERLAY_EPHY_LED_0  |
                                         BP_OVERLAY_EPHY_LED_1  |
                                         BP_OVERLAY_EPHY_LED_2  |
                                         BP_OVERLAY_GPHY_LED_0  |
                                         BP_OVERLAY_PCIE_CLKREQ )},
    {bp_usGpioLedAdsl,           .u.us = BP_GPIO_20_AL},
    {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
    {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
    {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
    {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_18_AL},
    {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
    {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
    {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
    {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
    {bp_usWirelessFlags,         .u.us = 0},
    {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
    {bp_ulPortMap,               .u.ul = 0x1f},
    {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1},
    {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2},
    {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
    {bp_ulPhyId4,                .u.ul = 0x18 | PHY_INTEGRATED_VALID | PHY_EXTERNAL | MAC_IF_RGMII},
    {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
    {bp_ucDspAddress,            .u.uc = 0},
    {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
    {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
    {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
    {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_4},
    {bp_last}
};

static bp_elem_t g_bcm963168xm5_6302[] = {
    {bp_cpBoardId,               .u.cp = "963168XM5_6302"},
    {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_5_2_3},
    {bp_elemTemplate,            .u.bp_elemp = g_bcm963168xm5},
    {bp_last}
};

static bp_elem_t g_bcm963168wfar[] = {
  {bp_cpBoardId,               .u.cp = "963168WFAR"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                        BP_OVERLAY_GPHY_LED_0 |
                                        BP_OVERLAY_PCIE_CLKREQ )},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0}, 
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x08},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

///20130821, TimLiu add new board parameter
#if defined(ZYXEL) && (ZYXEL==1)
#if defined(ZYPRJ_VMG8948) && (ZYPRJ_HARDWARE_VERSION == 2)
//20140117, TimLiu VMG8948 SR2, change shift register to active low.
static bp_elem_t g_bcm963168_VMG8948[] = {
  {bp_cpBoardId,               .u.cp = "963168_VMG8948"},
//<<20140210, TimLiu add for refine configurations for different boards.
//  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION | BP_DEVICE_OPTION_DISABLE_ALL_ETHERNET_SPD_LED},
//>>20140210, Timliu
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
		  	  	  	  	  	  	  	   BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED|
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_HS_SPI_SSB4_EXT_CS) },
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},	//WPS LED for 2.4G&5G,
//  {bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_51_AL},	//51 is wifi 5g
#ifdef ZYPRJ_VMG8948
  {bp_usGpioLedInternetData,   .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_SERIAL_GPIO_2_AL},
#else
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
#endif
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
  {bp_usGpioLedUSB0,           .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedUSB1,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
#if 0//ifdef ZYPRJ_VMG8948
  {bp_usGpioGuestWirelessBtn,  .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_1}, // for Guest WiFi push button
#else
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_1}, // for Guest WiFi push button
#endif
  {bp_usGpio_Intr,	       .u.us = BP_GPIO_22_AH},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_1},	// for WiFi/WPS push button
  {bp_usGpio_Intr,	       .u.us = BP_GPIO_22_AL},

  {bp_usExtIntrDECT,	       .u.us = BP_EXT_INTR_3},
  {bp_usGpioDECTReset,	       .u.us = BP_GPIO_10_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_4},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip1MessageLed,   .u.us = BP_SERIAL_GPIO_9_AL},	//using for voice message
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioVoip2MessageLed,   .u.us = BP_SERIAL_GPIO_10_AL},  //using for voice message
  {bp_usGpioDectLed,           .u.us = BP_SERIAL_GPIO_11_AL},
#ifdef ZYPRJ_VMG8948
  {bp_usGpioLedGuestWiFi,      .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usGpioLedGuestWPS,       .u.us = BP_SERIAL_GPIO_1_AL},
#if defined(ZYXEL_WIFI_LED_PATTERN) && (ZYXEL_WIFI_LED_PATTERN ==1)
  {bp_usGpioWirelessSelect,	   .u.us = BP_GPIO_39_AH},	// low for 2.4G WiFi LED, hight for 5G WiFi LED
#endif
#endif
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  //{bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_6306| BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_6302_6306_REV_A_12_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_6306| BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_21},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},	//LD1_DSL_MODE
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},	//LD1_SUPPLY_EN
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_8_AH},	//LD2_SDL_MODE
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_9_AH},	//LD2_SUPPLY_EN
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH},
  {bp_last}
};
#else  //defined(ZYPRJ_VMG8948) && (ZYPRJ_HARDWARE_VERSION == 1)
static bp_elem_t g_bcm963168_VMG8948[] = {
  {bp_cpBoardId,               .u.cp = "963168_VMG8948"},
//<<20140210, TimLiu add for refine configurations for different boards.
//  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION | BP_DEVICE_OPTION_DISABLE_ALL_ETHERNET_SPD_LED},
//>>20140210, Timliu
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
		  	  	  	  	  	  	  	   BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED|
                                       BP_OVERLAY_GPHY_LED_0|
                                       BP_OVERLAY_HS_SPI_SSB4_EXT_CS) },
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AH},
  {bp_usGpioLedVdsl,           .u.us = BP_SERIAL_GPIO_15_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AH},	//WPS LED for 2.4G&5G,
//  {bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_51_AL},	//51 is wifi 5g
#ifdef ZYPRJ_VMG8948
  {bp_usGpioLedInternetData,   .u.us = BP_SERIAL_GPIO_8_AH},
  {bp_usGpioLedInternetFail,   .u.us = BP_SERIAL_GPIO_2_AH},
#else
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AH},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AH},
#endif
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
  {bp_usGpioLedUSB0,           .u.us = BP_SERIAL_GPIO_13_AH},
  {bp_usGpioLedUSB1,           .u.us = BP_SERIAL_GPIO_14_AH},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
#if 0//ifdef ZYPRJ_VMG8948
  {bp_usGpioGuestWirelessBtn,  .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_1}, // for Guest WiFi push button
#else
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_1}, // for Guest WiFi push button
#endif
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_1},     // for WiFi/WPS push button
  {bp_usGpio_Intr,             .u.us = BP_GPIO_22_AL},
  {bp_usExtIntrDECT,           .u.us = BP_EXT_INTR_3},
  {bp_usGpioDECTReset,         .u.us = BP_GPIO_10_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_4},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},	//LD1_DSL_MODE
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},	//LD1_SUPPLY_EN
  {bp_last}
};
#endif //defined(ZYPRJ_VMG8948) && (ZYPRJ_HARDWARE_VERSION == 2)

//20140903, TimLiu Support VMG8924v2.
static bp_elem_t g_bcm963168_VMG8924[] = {
  {bp_cpBoardId,               .u.cp = "963168_VMG8924"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION | BP_DEVICE_OPTION_DISABLE_ALL_ETHERNET_SPD_LED},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
		  	  	  	  	  	  	  	   BP_OVERLAY_PHY |
                                       BP_OVERLAY_USB_LED|
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_HS_SPI_SSB4_EXT_CS) },
#if 1	//from 416L02A/158-ENHANCE_change_dsl_LED_behavior_for_vmg8924.patch
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_0_AL},
#else
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_0_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_1_AL},
#endif
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_17_AL},	//WPS LED for 2.4G wifi
  {bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_22_AL},	//WPS LED for 5g wifi
//  {bp_usGpioLedWL2_4GHz,       .u.us = BP_GPIO_17_AL},
//  {bp_usGpioLedWL5GHz,         .u.us = BP_GPIO_22_AL},
#if 1
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_GPIO_13_AH},
#else
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_13_AH},
#endif
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
  {bp_usGpioLedUSB0,           .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedUSB1,           .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_3}, // for Guest WiFi push button
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},	// for WiFi/WPS push button
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_4},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_18_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_19_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},	//LD1_DSL_MODE
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},	//LD1_SUPPLY_EN
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_last}
};

//20140903, TimLiu Support VMG3926.
static bp_elem_t g_bcm963168_VMG3926[] = {
  {bp_cpBoardId,               .u.cp = "963168_VMG3926"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION | BP_DEVICE_OPTION_DISABLE_ALL_ETHERNET_SPD_LED},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
		  	  	  	  	  	  	  	   BP_OVERLAY_PHY |
                                       BP_OVERLAY_USB_LED|
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_HS_SPI_SSB4_EXT_CS) },
#if 1	//from 416L02A/156-ENHANCE_change_DSL_LED_behavior.patch
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_0_AL},
#else
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_0_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_1_AL},
#endif
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_17_AL},	//WPS LED for 2.4G wifi
  {bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_22_AL},	//WPS LED for 5g wifi
//  {bp_usGpioLedWL2_4GHz,       .u.us = BP_GPIO_17_AL},
//  {bp_usGpioLedWL5GHz,         .u.us = BP_GPIO_22_AL},
#if 1
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_GPIO_13_AH},
#else
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_13_AH},
#endif
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
  {bp_usGpioLedUSB0,           .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedUSB1,           .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_3}, // for Guest WiFi push button
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},	// for WiFi/WPS push button
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_4},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},	//LD1_DSL_MODE
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},	//LD1_SUPPLY_EN
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_last}
};

//20150313, TimLiu Support VMG3926-B10B from T&W.
static bp_elem_t g_bcm963168_VMG3926B[] = {
  {bp_cpBoardId,               .u.cp = "963168_VMG3926B"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION | BP_DEVICE_OPTION_DISABLE_ALL_ETHERNET_SPD_LED},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_USB_LED) },
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_22_AL},	//WPS LED for 2.4G wifi
  {bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_12_AL},	//WPS LED for 5g wifi
#if 1
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_GPIO_18_AL},
#else
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_18_AL},
#endif
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
  {bp_usGpioLedUSB0,           .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedUSB1,           .u.us = BP_GPIO_14_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_2}, // for Guest WiFi push button
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},	// for WiFi/WPS push button
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_last}
};

//20150707, Mark Support VMG3925B (VMG3925 for Elisa).
static bp_elem_t g_bcm963168_VMG3925B[] = {
  {bp_cpBoardId,               .u.cp = "963168_VMG3925B"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION | BP_DEVICE_OPTION_DISABLE_ALL_ETHERNET_SPD_LED},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
		  	  	  	  	  	  	  	   BP_OVERLAY_PHY |
                                       BP_OVERLAY_USB_LED|
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_HS_SPI_SSB4_EXT_CS) },
#if 1 //Elisa customize
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_1_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_0_AL},
#else
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_0_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_1_AL},
#endif
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_17_AL},	//WPS LED for 2.4G wifi
  {bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_22_AL},	//WPS LED for 5g wifi
//  {bp_usGpioLedWL2_4GHz,       .u.us = BP_GPIO_17_AL},
//  {bp_usGpioLedWL5GHz,         .u.us = BP_GPIO_22_AL},
#if 1
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_GPIO_13_AH},
#else
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_13_AH},
#endif
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
  {bp_usGpioLedUSB0,           .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedUSB1,           .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_3}, // for Guest WiFi push button
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},	// for WiFi/WPS push button
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_4},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},	//LD1_DSL_MODE
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},	//LD1_SUPPLY_EN
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_last}
};

/*Cj_Lai , 20150212, Support VMG9823-B10A*/
static bp_elem_t g_bcm963168_VMG9823[] = {
  {bp_cpBoardId,               .u.cp = "963168_VMG9823"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION | BP_DEVICE_OPTION_DISABLE_ALL_ETHERNET_SPD_LED},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED
                                       )},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_14_AL},
#if 1 // __MSTC__, Richard Huang, for 30a board
  {bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioSecLedVdsl,        .u.us = BP_GPIO_16_AL},
#else
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_9_AL},
#endif
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioLedInternetData,   .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
#if 1//__MTS__,JhenYang,LED
  {bp_usGpioLedUSB0,			.u.us = BP_SERIAL_GPIO_6_AL},
  //{bp_usGpioWLANORANGE,            .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioWPSSpotlightRed,	.u.us = BP_SERIAL_GPIO_0_AH}, //WPS Spotlight Red
  {bp_usGpioWPSSpotlight,		.u.us = BP_SERIAL_GPIO_7_AH}, //WPS Spotlight Green
  {bp_usGpioADSLRED,            .u.us = BP_GPIO_14_AL},
  {bp_usGpioADSL2RED,            .u.us = BP_GPIO_16_AL},
  {bp_usGpioVoip1LedFail, 		 .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioVoip2LedFail, 		 .u.us = BP_SERIAL_GPIO_10_AL},
//  {bp_usGpioGWAN,            .u.us = BP_GPIO_17_AH},
#if 1
  {bp_usGpio5GDisable,          .u.us = BP_GPIO_39_AL},
  {bp_usGpio5GReset,           .u.us = BP_GPIO_23_AH},
#endif
#endif
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,			   .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,			 .u.uc = 0x0},
  {bp_usConfigType,			 .u.us = BP_ENET_CONFIG_MMAP},
#ifdef BUILD_HPNA
  {bp_ulPortMap,				 .u.ul = 0x58},
#else
  {bp_ulPortMap,				 .u.ul = 0x48},
#endif
  {bp_ulPhyId3,				 .u.ul = BP_PHY_ID_4}, // EthWAN
  {bp_ucPhyDevName,            .u.cp = "eth4"},
#ifdef BUILD_HPNA
  {bp_ulPhyId4,				 .u.ul = 0x14 | TMII_DIRECT},
#endif
  {bp_ulPhyId6,				 .u.ul = RGMII_DIRECT | EXTSW_CONNECTED}, // Switch
  {bp_ucPhyType1, 			 .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,			 .u.uc = 0x0},
  {bp_usConfigType,			 .u.us = BP_ENET_CONFIG_HS_SPI_SSB_0},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,			 .u.ul = 0x3e},
  {bp_ulPhyId1,				 .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ucPhyDevName,          .u.cp = "eth0"},
  {bp_ulPhyId2,				 .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ucPhyDevName,          .u.cp = "eth1"},
  {bp_ulPhyId3,				 .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ucPhyDevName,          .u.cp = "eth2"},
  {bp_ulPhyId4,				 .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucPhyDevName,          .u.cp = "eth3"},
  {bp_ulPhyId5,				 .u.ul = 0xff | RGMII_DIRECT}, // QTN
  {bp_ucPhyDevName,            .u.cp = "eth5"},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_4_AL},
//  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
#if 1 // __MSTC__, Richard Huang, for 30a board
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30}, // 0x10808900
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_6306| BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_20}, // 0x30808100
#else
  {bp_ulAfeId0,				 .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_ulAfeId1,				 .u.ul = BP_AFE_CHIP_6306| BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_21},
#endif
//  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
//  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},

#if 1 // __chchien
  {bp_usGpioInternetLedEnable, .u.us = BP_GPIO_22_AH},	// to provide power for Internet Green LED on VMG3925, DSL-491GNAU-B1BC.
  {bp_usGpioInternetCtrlSignal,.u.us = BP_GPIO_17_AL},	// to select which signal will output to Internet LED on VMG3925, DSL-491GNAU-B1BC.
  {bp_usGpioIntAFELDMode,		.u.us = BP_GPIO_NONE},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_NONE},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_8_AL},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_13_AL},
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_11_AH},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
#endif
  {bp_last}
};

/*Cj_Lai , 20150727, Support VMG9823-B10A old board*/
static bp_elem_t g_bcm963168_VMG9823B[] = {
  {bp_cpBoardId,               .u.cp = "963168_VMG9823B"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION | BP_DEVICE_OPTION_DISABLE_ALL_ETHERNET_SPD_LED},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED
                                       )},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_14_AL},
#if 1 // __MSTC__, Richard Huang, for 30a board
  {bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_3_AL},
#else
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_9_AL},
#endif
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioLedInternetData,   .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
#if 1//__MTS__,JhenYang,LED
  {bp_usGpioLedUSB0,			.u.us = BP_SERIAL_GPIO_6_AL},
  //{bp_usGpioWLANORANGE,            .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioWPSSpotlightRed,	.u.us = BP_SERIAL_GPIO_0_AH}, //WPS Spotlight Red
  {bp_usGpioWPSSpotlight,		.u.us = BP_SERIAL_GPIO_7_AH}, //WPS Spotlight Green
  {bp_usGpioADSLRED,            .u.us = BP_GPIO_14_AL},
  {bp_usGpioADSL2RED,            .u.us = BP_GPIO_16_AL},
  {bp_usGpioVoip1LedFail, 		 .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioVoip2LedFail, 		 .u.us = BP_SERIAL_GPIO_10_AL},
//  {bp_usGpioGWAN,            .u.us = BP_GPIO_17_AH},
#if 1
  {bp_usGpio5GDisable,          .u.us = BP_GPIO_39_AL},
  {bp_usGpio5GReset,           .u.us = BP_GPIO_23_AH},
#endif
#endif
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,			   .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,			 .u.uc = 0x0},
  {bp_usConfigType,			 .u.us = BP_ENET_CONFIG_MMAP},
#if 1
  {bp_ulPortMap,				 .u.ul = 0x58},
#else
  {bp_ulPortMap,				 .u.ul = 0x18},
#endif
  {bp_ulPhyId3,				 .u.ul = BP_PHY_ID_4}, // EthWAN
  {bp_ulPhyId4,				 .u.ul = RGMII_DIRECT | EXTSW_CONNECTED}, // Switch
#if 1
  {bp_ulPhyId6,				 .u.ul = 0xff | RGMII_DIRECT}, // QTN
  {bp_ulPortFlags,           .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
#endif
  {bp_ucPhyType1, 			 .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,			 .u.uc = 0x0},
  {bp_usConfigType,			 .u.us = BP_ENET_CONFIG_HS_SPI_SSB_0},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
#ifdef BUILD_HPNA
  {bp_ulPortMap,				 .u.ul = 0x3e},
#else
  {bp_ulPortMap,				   .u.ul = 0x1e},
#endif
  {bp_ulPhyId1,				 .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,				 .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,				 .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,				 .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
#ifdef BUILD_HPNA
  {bp_ulPhyId5, 			 .u.ul =	0x14 | MII_DIRECT_HPNA | CONNECTED_TO_EXTERN_SW},
#endif
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
 {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
//  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
#if 1 // __MSTC__, Richard Huang, for 30a board
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30}, // 0x10808900
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_6306| BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_20}, // 0x30808100
#else
  {bp_ulAfeId0,				 .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_ulAfeId1,				 .u.ul = BP_AFE_CHIP_6306| BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_21},
#endif
//  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
//  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},

#if 1 // __chchien
  {bp_usGpioIntAFELDMode,		.u.us = BP_GPIO_NONE},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_NONE},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_8_AL},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_13_AL},
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_11_AH},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
#endif
  {bp_last}
};

static bp_elem_t g_bcm963168_VMG8924_B10A[] = {
  {bp_cpBoardId,               .u.cp = "VMG8924-B10A"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION },
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
                                       BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_HS_SPI_SSB4_EXT_CS)},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_14_AL},
#ifndef ZYXEL_WIND_ITALY_CUSTOMIZATION
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_15_AL},
#else
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_14_AL},
#endif
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AH},
  {bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_17_AL},	//WPS LED for 5g wifi
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioVoip1MessageLed,   .u.us = BP_GPIO_9_AL},  //using for voice message
  {bp_usGpioVoip2MessageLed,   .u.us = BP_GPIO_10_AL}, //using for voice message
//  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
//  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
  //{bp_usGpioLedUSB0,           .u.us = BP_SERIAL_GPIO_6_AL},
  //{bp_usGpioLedUSB1,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedUSB0,           .u.us = BP_SERIAL_GPIO_3_AL},  // For physical USB_1
  {bp_usGpioLedUSB1,           .u.us = BP_SERIAL_GPIO_6_AL},  // For physical USB_0
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_2},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  //{bp_ulPortMap,               .u.ul = 0x58},
  {bp_ulPortMap,               .u.ul = 0x48},
  /*configure internal switch port 3 as wan*/
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  /*configure internal switch port 4(mii 1) as port(external switch port 6)*/
  //{bp_ulPhyId4,                .u.ul = TMII_DIRECT|0x14},
  /*configure internal switch port 6(mii 3) as external switch port 6*/
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_0},
  /*bp_ulPortMap:	bit 0:reserved,  bit 1~4: LAN port*/
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV1},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_usGpioInternetLedEnable, .u.us = BP_GPIO_22_AH},	// to provide power for Internet Green LED on VMG8924, DSL-491GNAU-B1BC.
  {bp_last}
};

static bp_elem_t g_bcm963167_VMG8924_B10D[] = {
	{bp_cpBoardId,               .u.cp = "VMG8924-B10D"},
	{bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION | BP_DEVICE_OPTION_DISABLE_ALL_ETHERNET_SPD_LED },
	{bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
										BP_OVERLAY_PHY |
										BP_OVERLAY_SERIAL_LEDS |
										BP_OVERLAY_USB_LED |
										BP_OVERLAY_GPHY_LED_0)},
	{bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_6_AL},	//DSL_LED_A
	{bp_usGpioLedVdsl,           .u.us = BP_SERIAL_GPIO_3_AL},	//DSL_LED_G
	{bp_usGpioLedSesWireless,    .u.us = BP_GPIO_9_AL},			//5G_WPS_LED_R
	{bp_usGpioLedSesWireless2,   .u.us = BP_SERIAL_GPIO_7_AL},	//2.4G_WPS_LED_R
	{bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
	{bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AH},
	//{bp_usGpioLedWanData,        .u.us = BP_GPIO_12_AL},
	{bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},		//Rest_Button, GPIO_32
	{bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_1},		//WLAN_Button, GPIO_33
	{bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_3},		//WPS_Button, GPIO_35
	{bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},		//wifi antenna
	{bp_usWirelessFlags,         .u.us = 0},
	//----------------------------------------------------------------->>> Internal
	{bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
	{bp_ucPhyAddress,            .u.uc = 0x0},
	{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
	{bp_ulPortMap,               .u.ul = 0x18},
	{bp_ulPhyId3,                .u.ul = 0x04},
	{bp_ucPhyDevName,            .u.cp = "eth4"},
	{bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
	//---------------------------------------------------------------->>> External
	{bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},	//BCM53134S
	{bp_ucPhyAddress,            .u.uc = 0x0},
	{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},
	{bp_ulPortMap,               .u.ul = 0x0f},
	{bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
	{bp_ucPhyDevName,            .u.cp = "eth3"},
	{bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
	{bp_ucPhyDevName,            .u.cp = "eth2"},
	{bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
	{bp_ucPhyDevName,            .u.cp = "eth1"},
	{bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
	{bp_ucPhyDevName,            .u.cp = "eth0"},
	//----------------------------------------------------------------<<<
	{bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
	{bp_ucDspAddress,            .u.uc = 0},
	{bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_1_AL},	//GPIO table list different from schematic
	{bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_4_AL},
	{bp_usGpioVoip1MessageLed,   .u.us = BP_SERIAL_GPIO_0_AL},	//using for voice message
	{bp_usGpioVoip2MessageLed,   .u.us = BP_SERIAL_GPIO_5_AL},	//using for voice message
	{bp_usGpioLedInternetData,   .u.us = BP_GPIO_8_AL},			//INET_ACT_LED_G
	{bp_usGpioLedInternetFail,   .u.us = BP_SERIAL_GPIO_2_AL},	//INET_FAIL_LED_R
	{bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30 },
	{bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH},
	{bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
	{bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
	{bp_usGpioLedUSB0,           .u.us = BP_GPIO_18_AL},  		//USB_DEV_LED
	{bp_last}
};
#endif  //defined(ZYXEL) && (ZYXEL==1)

bp_elem_t * g_BoardParms[] = {g_bcm963268sv1, g_bcm963268mbv, g_bcm963168vx, g_bcm963168vx_p300, g_bcm963268bu, g_bcm963268bu_p300,
		g_bcm963268sv2_extswitch, g_bcm963168mbv_17a, g_bcm963168mbv_30a, g_bcm963168xh, g_bcm963168xh5, g_bcm963168mp, g_bcm963268v30a,
		g_bcm963168media, g_bcm963268sv2, g_bcm963168xfg3, g_bcm963168xf, g_bcm963168xm, g_bcm963168mbv3, g_bcm963168mbv17a302, g_bcm963168mbv30a302,
		g_bcm963168vx_p400, g_bcm963168vx_ext1p8, g_bcm963269bhr, g_bcm963168ach5, g_bcm963168ac5, g_bcm963168xn5, g_bcm963168xm5, g_bcm963168xm5_6302, g_bcm963168wfar, g_bcm963167ref1, g_bcm963167ref3,
      g_bcm963168PLC, g_bcm963168PLC_MOCAW, g_bcm963167ref2
///20130821, TimLiu add new board parameters
#if defined(ZYXEL) && (ZYXEL==1)
		, g_bcm963168_VMG8948
		, g_bcm963168_VMG8924
		, g_bcm963168_VMG3926
		, g_bcm963168_VMG3926B
		, g_bcm963168_VMG3925B
		, g_bcm963168_VMG9823
		, g_bcm963168_VMG9823B
		, g_bcm963168_VMG8924_B10A
		, g_bcm963167_VMG8924_B10D
#endif
	  , 0};
#endif


#if defined(_BCM96318_) || defined(CONFIG_BCM96318)

static bp_elem_t g_bcm96318sv[] = {
  {bp_cpBoardId,               .u.cp = "96318SV"},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 )},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_10_AL},
 // {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_12_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_11_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_3},
  {bp_last}
};

static bp_elem_t g_bcm96318sv_sersw[] = {
  {bp_cpBoardId,               .u.cp = "96318SV_SERSW"},
  {bp_ulGpioOverlay,           .u.ul = (BP_OVERLAY_SERIAL_LEDS)},
  {bp_usSerialLEDMuxSel,       .u.us = (BP_SERIAL_MUX_SEL_GROUP0|BP_SERIAL_MUX_SEL_GROUP2)},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_10_AL},
 // {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_12_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_11_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_3},
  {bp_last}
};

static bp_elem_t g_bcm96318sv_serled[] = {
  {bp_cpBoardId,               .u.cp = "96318SV_SERLED"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_SERIAL_LEDS)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_10_AL},
 // {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_12_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},  
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_3},
  {bp_last}
};

static bp_elem_t g_bcm96318ref[] = {
  {bp_cpBoardId,               .u.cp = "96318REF"},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 )},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_10_AL},
 // {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_12_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_11_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_3},
  {bp_last}
};

static bp_elem_t g_bcm96318_2l5sgmt[] = {
  {bp_cpBoardId,               .u.cp = "96318_2L5SGMT"},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x01},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usGpioReserved,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioReserved,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioReserved,           .u.us = BP_GPIO_18_AL},
  {bp_usGpioReserved,           .u.us = BP_GPIO_19_AL},
  {bp_usGpioReserved,           .u.us = BP_GPIO_20_AL},
  {bp_usGpioReserved,           .u.us = BP_GPIO_21_AL},
  {bp_usGpioReserved,           .u.us = BP_GPIO_22_AL},
  {bp_usGpioReserved,           .u.us = BP_GPIO_23_AL},
  {bp_usGpioReserved,           .u.us = BP_GPIO_24_AL},
  {bp_usGpioReserved,           .u.us = BP_GPIO_25_AL},
  {bp_last}
};

static bp_elem_t g_bcm96318ref_p300[] = {
  {bp_cpBoardId,               .u.cp = "96318REF_P300"},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_EPHY_LED_1 |
                                       BP_OVERLAY_EPHY_LED_2 |
                                       BP_OVERLAY_EPHY_LED_3 |
                                       BP_OVERLAY_PCIE_CLKREQ )}, /* PCIE CLK req use GPIO 10 input so make sure GPIO 10 is not used when this flag is set. The linux kernel setup code check this condition */
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_16_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm96318ref},
  {bp_last}
};

static bp_elem_t g_bcm96319plc[] = {
  {bp_cpBoardId,               .u.cp = "96319PLC"},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_PCIE_CLKREQ )},
  {bp_usGpioPLCPwrEn,          .u.us = BP_GPIO_8_AH},
  {bp_usGpioPLCReset,          .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_12_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1},  //use reset to def irq for now instead of standby irq
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x11},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId4,                .u.ul = MII_DIRECT},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_SOFT_SWITCHING},
  {bp_usVregAvsMin,            .u.us = 950},
  {bp_last}
};

static bp_elem_t g_bcm96319plc_ac[] = {
  {bp_cpBoardId,               .u.cp = "96319PLC_AC"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm96319plc},
  {bp_last}
};

static bp_elem_t g_bcm96318plc[] = {
  {bp_cpBoardId,               .u.cp = "96318PLC"},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_7_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_11_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_3},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm96319plc},
  {bp_last}
};

static bp_elem_t g_bcm96318tiny[] = {
  {bp_cpBoardId,               .u.cp = "96318TINY"},
  {bp_usGpioOverlay,           .u.ul = BP_OVERLAY_EPHY_LED_0 },
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_10_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x01},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_3},
  {bp_last}
};


bp_elem_t * g_BoardParms[] = {g_bcm96318sv, g_bcm96318ref, g_bcm96318ref_p300, g_bcm96318sv_serled, g_bcm96318sv_sersw, g_bcm96319plc, g_bcm96319plc_ac, g_bcm96318plc, g_bcm96318tiny, g_bcm96318_2l5sgmt, 0};

#endif


#if defined(_BCM960333_) || defined(CONFIG_BCM960333)

static char g_obsoleteStr[] = "(obsolete)";

static bp_elem_t g_bcm960333plc_dut[] = {
  {bp_cpBoardId,               .u.cp = "960333PLC_DUT"},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_5_AH},

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY},
  {bp_ulPortMap,               .u.ul = 0x07},
  {bp_ulPhyId0,                .u.ul = 0},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_EXT_PHY},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_ulPhyId1,                .u.ul = 1},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_INT_PHY},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_ulPhyId2,                .u.ul = 2},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc0"},

  {bp_last}
};

static bp_elem_t g_bcm960333plc_ref[] = {
  {bp_cpBoardId,               .u.cp = "960333PLC_REF"},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_5_AH},

  /* NOTE: This is the only option for this signal.
   *       power LED is driven by AON and is not assigned to any GPIO */
  {bp_usGpioLedBlPowerOn,          .u.us = BP_PIN_AON_POWER},

  /*
   * ON and OFF time values for Power LED blinking (in ms).
   * If undefined, the Power LED will stay solid ON.
   */
  /*
  {bp_ulLedBlPowerOnBlinkTimeOn,   .u.ul = 350},
  {bp_ulLedBlPowerOnBlinkTimeOff,  .u.ul = 650},
  */

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY},
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = 1},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_INT_PHY},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usGpioLedLan,            .u.us = BP_GPIO_6_AH},
  {bp_ulPhyId1,                .u.ul = 2},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc0"},
  {bp_last}
};

static bp_elem_t g_bcm960500wifi_obsolete[] = {
  {bp_cpBoardId,               .u.cp = "960500PLC_WIFI"},
  {bp_cpComment,               .u.cp = g_obsoleteStr},  

  // buttons for 201
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_1_AL},
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL },
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,       .u.ul = (unsigned long)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },
  {bp_elemTemplate,            .u.bp_elemp = g_bcm960333plc_ref},
  {bp_last}
};

static bp_elem_t g_bcm960500wifi[] = {
  {bp_cpBoardId,               .u.cp = "960500WIFI"}, // works for P104 or P201
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL },
  {bp_usGpio_Intr,             .u.us = BP_GPIO_1_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_2 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL },
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AH},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,    .u.ul = (unsigned long)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usButtonIdx,             .u.us = 2},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_0_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,    .u.ul = (unsigned long)"Button 2 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },    
  {bp_elemTemplate,            .u.bp_elemp = g_bcm960333plc_ref},
  {bp_last}
};

static bp_elem_t g_bcm960500wifi_ubus167[] = {
  {bp_cpBoardId,               .u.cp = "960500_UBUS167"},  // reduced list for P201

  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_1_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,    .u.ul = (unsigned long)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },
  {bp_elemTemplate,            .u.bp_elemp = g_bcm960333plc_ref},
  {bp_last}
};


static bp_elem_t g_bcm960500wifi_p201[] = {
  {bp_cpBoardId,               .u.cp = "960500WIFI_P201"},  // reduced list for P201

  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_1_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_0_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,    .u.ul = (unsigned long)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },
  {bp_elemTemplate,            .u.bp_elemp = g_bcm960333plc_ref},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_bcm960333plc_dut, g_bcm960333plc_ref, g_bcm960500wifi_obsolete, g_bcm960500wifi, g_bcm960500wifi_ubus167, g_bcm960500wifi_p201, 0};
#endif


#if defined(_BCM963138_) || defined(CONFIG_BCM963138)

/* Only needed for internal GPHYs; by default internal GPHYs do not adv. 1000HD/100HD/10FD/10HD capabilities;
 * There are some NICs that will not negotiate 100FD - so need to advertise 100HD to link up with those NICs */
#define BCM963138_PHY_BASE             0x8

static bp_elem_t g_bcm963138sv[] = {
  {bp_cpBoardId,               .u.cp = "963138SV"},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH}, // uart2 is /dev/ttyS1
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH}, // stty 115200 < /dev/ttyS1 to set speed
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* BT Uart */
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_3_AH}, 
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdin,         .u.ul = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.ul = BP_GPIO_6_AH},                              
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_8},
  {bp_last}
};

static bp_elem_t g_bcm963138dvt[] = {
  {bp_cpBoardId,               .u.cp = "963138DVT"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_18_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_20_AL}, // LED register bit 20, shifted serially
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
                                              // to avoid conflicting P0 and P11 phy address of 1
                                              // the intergrated Quad GPHY address is now 0x8, 0x9, 0xa, 0xb
                                              // the intergrated Single GPHY address 0xc
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = 0x19 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL}, // bottom right.
  {bp_ulPhyId7,                .u.ul = 0x0 |  PHY_INTEGRATED_VALID  | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138dvt_p300[] = {
  {bp_cpBoardId,               .u.cp = "963138DVT_P300"},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_26_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_27_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* BT Uart */
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_3_AH}, 
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdin,         .u.ul = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.ul = BP_GPIO_6_AH},   
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = 0x19 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL}, // bottom right.
  {bp_ulPhyId7,                .u.ul = 0x0 |  PHY_INTEGRATED_VALID  | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138dvt},
  {bp_last}
};


static bp_elem_t g_bcm963138ref_bmu[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_BMU"},
  {bp_usBatteryEnable,         .u.us = 1},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_22_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_23_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_21_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_LD_REV_6303_VR5P3 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_LD_REV_6303_VR5P3 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioAFEVR5P3PwrEn,     .u.us = BP_GPIO_37_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usVregSync,              .u.us = BP_GPIO_18_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x4) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x0) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x1) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x2) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_29_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_30_AL},
  {bp_usGpioDectLed,           .u.us = BP_GPIO_31_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138bmu_p202[] = {
  {bp_cpBoardId,               .u.cp = "963138BMU_P202"},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_8},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_bmu},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_lte[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_LTE"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3}, 
  {bp_usGpioLteReset,          .u.us = BP_GPIO_116_AH}, 
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH}, 
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_25_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_21_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x2f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x0) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x1) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x2) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /*{bp_usSpeedLed100,           .u.us = BP_GPIO_22_AL},*/ //GPIO22 not supported for speed LED in b0
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_23_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_24_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId5,                .u.ul = RGMII_DIRECT}, // RGMII1 to MAC port in LTE chip
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_18_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_17_AL},
  {bp_usTsync1pps,             .u.us = BP_GPIO_4_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138lte_p302[] = {
  {bp_cpBoardId,               .u.cp = "963138LTE_P302"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usGpioLteReset,          .u.us = BP_GPIO_3_AH},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x2f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x0) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x1) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x2) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_24_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId5,                .u.ul = RGMII_DIRECT}, // RGMII1 to MAC port in LTE chip
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_lte},
  {bp_last}
};

static bp_elem_t g_bcm963138lte2[] = {
  {bp_cpBoardId,               .u.cp = "963138LTE2"},
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_20_AH}, 
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_21_AH},
  {bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_usGpioSecLedAdslFail,    .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138lte_p302},
  {bp_last}
};

/* for B0 chip */
static bp_elem_t g_bcm963138ref_p402[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_P402"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH},  // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH},  // placeholder for SF2 Port4 SPD1
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_27_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioSecLedWanData,     .u.us = BP_GPIO_19_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_25_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_26_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_28_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};


static bp_elem_t g_bcm963138ref_gfast[] = {
  {bp_cpBoardId,               .u.cp = "963138_GFAST"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_26_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_27_AL},  
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_14_AL},  
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};


static bp_elem_t g_bcm963138bg_gfast[] = {
  {bp_cpBoardId,               .u.cp = "963138BG_GFAST"},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_28_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x2},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x10},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
  {bp_usVregSync,              .u.us = BP_GPIO_37_AH},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_gfast_p40x[] = {
  {bp_cpBoardId,               .u.cp = "963138GFP40X"},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
 /* use the WAN LED from runner */
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_usGpioAFELDRelay,	       .u.us = BP_GPIO_3_AH},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_gfast},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_gfast_p40x_mem[] = {
  {bp_cpBoardId,               .u.cp = "138GFAST4G"},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_gfast_p40x},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_gfast_2[] = {
  {bp_cpBoardId,               .u.cp = "963138GFAST2"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_15_AH},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_16_AH},
  {bp_usGpioSecLedWanData,     .u.us = BP_SERIAL_GPIO_19_AH},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_18_AH},
  {bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_21_AH},
  {bp_usGpioLedReserved,    .u.us = BP_SERIAL_GPIO_20_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_17_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_8_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_9_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_14_AH},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_100_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_101_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_102_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_103_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_104_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_105_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_13_AH},
  {bp_usGpioAFELDRelay,	       .u.us = BP_GPIO_3_AH},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_116_AL | BP_LED_USE_GPIO },
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_118_AL | BP_LED_USE_GPIO },
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};


static bp_elem_t g_bcm963138ref_gfast_4[] = {
  {bp_cpBoardId,               .u.cp = "963138GFAST4"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_gfast_2},
};

/* for B0 chip */
static bp_elem_t g_bcm963138ref_p502[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_P502"},
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  //{bp_ulPortFlags,             .u.ul = PORT_FLAG_ADDNL_WAN }, // Additional WAN Port
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* BT Uart */
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_3_AH},
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdin,         .u.ul = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.ul = BP_GPIO_6_AH},
  {bp_usGpioBtWake,            .u.us = BP_GPIO_116_AH},
  {bp_usGpioBtReset,           .u.us = BP_GPIO_118_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_25_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p402},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_p802[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_P802"},
  {bp_usGpioSfpDetect,         .u.us = BP_GPIO_109_AH},
  {bp_usExtIntrNfc,            .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_5},
  {bp_usGpioNfcWake,           .u.ul = BP_GPIO_7_AH},
  {bp_usGpioNfcPower,          .u.ul = BP_GPIO_8_AH},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_p502_plc[] = {
  {bp_cpBoardId,               .u.cp = "963138P502_PLC"},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT_3P3V },
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_p502_moca[] = {
  {bp_cpBoardId,               .u.cp = "963138P502_MOCA"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_14_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_p502_bhr[] = {
  {bp_cpBoardId,               .u.cp = "963138P502_BHR"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_115_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_60_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_14_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_rnc[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_RNC"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3}, 
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioSecLedWanData,     .u.us = BP_GPIO_19_AL},
  {bp_usGpioLteReset,          .u.us = BP_GPIO_110_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usVregSync,              .u.us = BP_GPIO_37_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  /* BT Uart */
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_3_AH},
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdin,         .u.ul = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.ul = BP_GPIO_6_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_rncp400[] = {
  {bp_cpBoardId,               .u.cp = "138REFrncP400"},
  {bp_usGpioReserved,          .u.us = BP_GPIO_17_AL},
  {bp_usGpioReserved,          .u.us = BP_GPIO_110_AL},
  {bp_usGpioBtWake,            .u.us = BP_GPIO_116_AH},
  {bp_usGpioBtReset,           .u.us = BP_GPIO_118_AH},
  {bp_usNtrRefIn,              .u.us = BP_GPIO_25_AL},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH},
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_rnc},
  {bp_last}
};


static bp_elem_t g_bcm963138ref_bgw[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_BGW"},
  {bp_usVregSync,              .u.us = BP_GPIO_18_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3}, 
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_26_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_23_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_27_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_16_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_29_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_30_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};


/* single moca (lan) using p200 daughter card */
static bp_elem_t g_bcm963138ref_p502_moca_p200[] = {
  {bp_cpBoardId,               .u.cp = "963138P502_M200"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_13_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502_moca},
  {bp_last}
};

/* dual moca using p200 daughter cards */
static bp_elem_t g_bcm963138ref_p502_dual_moca_p200[] = {
  {bp_cpBoardId,               .u.cp = "138P502_DM200"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_115_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_61_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_13_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502_bhr},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_3wlan[] = {
  {bp_cpBoardId,               .u.cp = "138REF_3WLAN"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  // {bp_usGpioLedReserved,       .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  // {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH},  // placeholder for SF2 Port4 SPD0
  // {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH},  // placeholder for SF2 Port4 SPD1
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_25_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioSecLedWanData,     .u.us = BP_GPIO_19_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_26_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_27_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

#if defined(ZYXEL) && (ZYXEL==1)
#define PLATFORM_WORKAROUND 1
static bp_elem_t g_zyxel_fmg3586[] = {
  {bp_cpBoardId,               .u.cp = "963138_FMG3586"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
//  {bp_usGpio_Intr,             .u.us = BP_GPIO_32_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
//  {bp_usGpio_Intr,             .u.us = BP_GPIO_33_AL},
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_2},
//  {bp_usGpio_Intr,             .u.us = BP_GPIO_34_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_19_AL},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH },
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
#if PLATFORM_WORKAROUND
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  //{bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
  /* use the WAN LED from runner */
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  //{bp_ulCrossbar,              .u.ul = 9},
  //{bp_ulCrossbarPhyId,         .u.ul = 0x2 | PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL },
#else
  {bp_ucPhyDevName,            .u.cp = "eth0"},
// 8211 + SFP
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x3 | PHY_INTEGRATED_VALID  | MAC_IF_RGMII_3P3V | PHY_EXTERNAL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
// ActiveEthernet + 1x9 SC
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 0x2 | PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL },
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
#endif
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
#if PLATFORM_WORKAROUND
  {bp_ulPortMap,               .u.ul = 0xAF}, // Port 0, 1, 2, 3, 5 and 7
#else
  {bp_ulPortMap,               .u.ul = 0xBF}, // Port 0, 1, 2, 3, 4, 5 and 7
#endif
// Port1
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
// Port2
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
// Port3
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
// Port4 : GPHY3...(P13)Crossbar4...(P3)Switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if PLATFORM_WORKAROUND
#else
// Port5 : GPHY4...(P10)Crossbar2...(P4)Switch
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth5"},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
#endif
//#if defined(BUILD_QUANTENNA_WLAN)
  //{bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_2P5V | PHY_EXTERNAL}, // port 5 with PHY ID 19, RGMII port need to define the speed, power
  {bp_ulPhyId5,                .u.ul = RGMII_DIRECT},
  //{bp_ucPhyDevName,            .u.cp = "quant%d"},
  {bp_ucPhyDevName,            .u.cp = "eth6"},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
//#endif
// Port6(50210) : RGMII2 ...(P7)Switch
  {bp_ulPhyId7,                .u.ul = 1 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
#if PLATFORM_WORKAROUND
  {bp_ucPhyDevName,            .u.cp = "eth5"},
#else
  {bp_ucPhyDevName,            .u.cp = "eth7"},
#endif
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_0_AL},
  {bp_usGpioVoip1MessageLed,   .u.us = BP_GPIO_1_AL},	//using for voice message
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_2_AL},
  {bp_usGpioVoip2MessageLed,   .u.us = BP_GPIO_3_AL},  //using for voice message
  {bp_usGpioLedUSB0,           .u.us = BP_GPIO_7_AL},
  {bp_usGpioLedUSB1,           .u.us = BP_GPIO_8_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_zyxel_fmg3086[] = {
  {bp_cpBoardId,               .u.cp = "963138_FMG3086"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
//  {bp_usGpio_Intr,             .u.us = BP_GPIO_32_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
//  {bp_usGpio_Intr,             .u.us = BP_GPIO_33_AL},
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_2},
//  {bp_usGpio_Intr,             .u.us = BP_GPIO_34_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_19_AL},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH },
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "sfp"},
// 8211 + SFP
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x3 | PHY_INTEGRATED_VALID  | MAC_IF_RGMII_3P3V | PHY_EXTERNAL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
// ActiveEthernet + 1x9 SC
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 0x2 | PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL },
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xBF}, // Port 0, 1, 2, 3, 4, 5 and 7
// Port1
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
// Port2
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
// Port3
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
// Port4 : GPHY3...(P13)Crossbar4...(P3)Switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
// Port5 : GPHY4...(P10)Crossbar2...(P4)Switch
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
// Port6(50210) : RGMII2 ...(P7)Switch
  {bp_ulPhyId7,                .u.ul = 1 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ucPhyDevName,            .u.cp = "eth5"},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_0_AL},
  {bp_usGpioVoip1MessageLed,   .u.us = BP_GPIO_1_AL},	//using for voice message
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_2_AL},
  {bp_usGpioVoip2MessageLed,   .u.us = BP_GPIO_3_AL},  //using for voice message
  {bp_usGpioLedUSB0,           .u.us = BP_GPIO_7_AL},
  {bp_usGpioLedUSB1,           .u.us = BP_GPIO_8_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_zyxel_xmg3512_b10a_p1[] = {
  {bp_cpBoardId,               .u.cp = "XMG3512-B10A_P1"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_18_AH},	//PEGA rework to use this GPIO_18 as 2.4G WPS LEd
  //{bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_19_AL}, //5G WPS led was controled by QTN module
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_27_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_3_AL},
  {bp_usGpioSecLedVdsl,        .u.us = BP_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
// Eth WAN
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
// ActiveEthernet, SFP
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL },
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x2F}, // Port 0, 1, 2, 3, 5
// Port0
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
// Port1
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
// Port2
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
// Port3 : GPHY3...(P13)Crossbar4...(P3)Switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
// Port5 : RGMII1 for Quantenna 5G
  {bp_ulPhyId5,                .u.ul = RGMII_DIRECT | PHY_INTEGRATED_VALID | MAC_IF_RGMII_2P5V | PHY_EXTERNAL},
//__ZYXEL__, Mark, for XMG3512 SR2 board, disable host site RGMII delay
  //{bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
  //{bp_ucPhyDevName,            .u.cp = "quant%d"},
  {bp_ucPhyDevName,            .u.cp = "eth6"},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_21_AL},
  {bp_usGpioVoip1MessageLed,   .u.us = BP_GPIO_25_AL},	//using for voice message
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_19_AL},
  {bp_usGpioVoip2MessageLed,   .u.us = BP_GPIO_4_AL},  //using for voice message
  {bp_usGpioLedUSB0,           .u.us = BP_GPIO_7_AL},
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH},	//AE_LOS
  {bp_usGpioSFPDetect,         .u.us = BP_GPIO_26_AH},
  {bp_usGpioSFPTXFault,        .u.us = BP_GPIO_37_AL},
  {bp_usGpioWlanDisable,       .u.us = BP_GPIO_35_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_usUsbPwrOn0,             .u.us = BP_GPIO_133_AH},	// Using for invert port power.
  {bp_usGpio5GReset,           .u.us = BP_GPIO_34_AL},	//RESET#, 5G reset pin
  {bp_usGpioWPSSpotlight,      .u.us = BP_GPIO_24_AL},	//always on
  {bp_usGpioHTP,               .u.us = BP_GPIO_0_AL},	//using for check the board id is XMG3512-B10A or XMG3512_LAN
  {bp_last}
};

static bp_elem_t g_zyxel_xmg3512_b10a_p3[] = {
  {bp_cpBoardId,               .u.cp = "XMG3512-B10A_P3"},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
// Eth WAN
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
// ActiveEthernet, SFP
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL },
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x2F}, // Port 0, 1, 2, 3, 5
// Port0
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
// Port1
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
// Port2
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
// Port3 : GPHY3...(P13)Crossbar4...(P3)Switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
// Port5 : RGMII1 for Quantenna 5G
  {bp_ulPhyId5,                .u.ul = RGMII_DIRECT | PHY_INTEGRATED_VALID | MAC_IF_RGMII_2P5V | PHY_EXTERNAL},
//__ZYXEL__, Mark, for XMG3512 SR2 board, disable host site RGMII delay
  //{bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
  //{bp_ucPhyDevName,            .u.cp = "quant%d"},
  {bp_ucPhyDevName,            .u.cp = "eth6"},
  {bp_usGpioSelectWanLed,      .u.us = BP_GPIO_22_AL},	//using the GPIO to secelt output WAN signal to WAN LED(HIGH) or SFP LED(LOW)
  {bp_elemTemplate,            .u.bp_elemp = g_zyxel_xmg3512_b10a_p1},
  {bp_last}
};

static bp_elem_t g_zyxel_xmg3512_b10a[] = {
  {bp_cpBoardId,               .u.cp = "XMG3512-B10A"},
#if (ZYPRJ_HARDWARE_VERSION == 3)
  {bp_elemTemplate,            .u.bp_elemp = g_zyxel_xmg3512_b10a_p3},
#else
  {bp_elemTemplate,            .u.bp_elemp = g_zyxel_xmg3512_b10a_p1},
#endif
  {bp_last}
};

static bp_elem_t g_zyxel_xmg3512_b10a_lan_p1[] = {
  {bp_cpBoardId,               .u.cp = "XMG3512_LAN_P1"},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
// ActiveEthernet, SFP
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL },
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x3F}, // Port 0, 1, 2, 3, 4, 5
// Port0
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
// Port1
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
// Port2
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
// Port3 : GPHY3...(P13)Crossbar4...(P3)Switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
// Port4 : GPHY4...(P10)Crossbar1...(P4)Switch
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth5"},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
// Port5 : RGMII1 for Quantenna 5G
  {bp_ulPhyId5,                .u.ul = RGMII_DIRECT | PHY_INTEGRATED_VALID | MAC_IF_RGMII_2P5V | PHY_EXTERNAL},
  {bp_ucPhyDevName,            .u.cp = "eth6"},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioHTP,               .u.us = BP_GPIO_0_AH},	//using for check the board id is XMG3512-B10A or XMG3512_LAN
// reference template
  {bp_elemTemplate,            .u.bp_elemp = g_zyxel_xmg3512_b10a_p1},
  {bp_last}
};

static bp_elem_t g_zyxel_xmg3512_b10a_lan_p3[] = {
  {bp_cpBoardId,               .u.cp = "XMG3512_LAN_P3"},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
// ActiveEthernet, SFP
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL },
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x3F}, // Port 0, 1, 2, 3, 4, 5
// Port0
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
// Port1
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
// Port2
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
// Port3 : GPHY3...(P13)Crossbar4...(P3)Switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
// Port4 : GPHY4...(P10)Crossbar1...(P4)Switch
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "eth5"},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  //{bp_usLinkLed,               .u.us = BP_GPIO_14_AL}, // GPIO_14 using for WAN signal, ignore LAN signal.
// Port5 : RGMII1 for Quantenna 5G
  {bp_ulPhyId5,                .u.ul = RGMII_DIRECT | PHY_INTEGRATED_VALID | MAC_IF_RGMII_2P5V | PHY_EXTERNAL},
  {bp_ucPhyDevName,            .u.cp = "eth6"},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioHTP,               .u.us = BP_GPIO_0_AH},	//using for check the board id is XMG3512-B10A or XMG3512_LAN
// reference template
  {bp_elemTemplate,            .u.bp_elemp = g_zyxel_xmg3512_b10a_p3},
  {bp_last}
};

static bp_elem_t g_zyxel_xmg3512_b10a_lan[] = {
  {bp_cpBoardId,               .u.cp = "XMG3512_LAN"},
// reference template
#if (ZYPRJ_HARDWARE_VERSION == 3)
  {bp_elemTemplate,            .u.bp_elemp = g_zyxel_xmg3512_b10a_lan_p3},
#else
  {bp_elemTemplate,            .u.bp_elemp = g_zyxel_xmg3512_b10a_lan_p1},
#endif
  {bp_last}
};

static bp_elem_t g_xmg3512_b10a_ddr128[] = {
  {bp_cpBoardId, .u.cp = "XMG3512_128MB"},
  {bp_ulMemoryConfig, .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},

  {bp_elemTemplate, .u.bp_elemp = g_zyxel_xmg3512_b10a},
  {bp_last}
};

#if (ZYPRJ_HARDWARE_VERSION == 2)
/* ----------------------------------------------
 * VMG8823-B10B(xDSL) SR2-1 to SR2-2:
 * (1) xDSL and G.Fast all connet to AFE0 (not support bonding)
 * (2) 2.4G,5G Btn changed to WiFi,WPS Btn
 * ---------------------------------------------*/
static bp_elem_t g_zyxel_vmg8823_b10b[] = {
	{bp_cpBoardId,               .u.cp = "VMG8823-B10B"},
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND},	//Enable NAND pinmux even on SPI boot
	{bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16},	//returns the DDR Memory Config

	/* zyxel, returns the GPIO pin assignment for the Internet Data LED*/
	{bp_usGpioLedInternetData,   .u.us = BP_GPIO_15_AL},
	{bp_usGpioLedInternetFail,   .u.us = BP_GPIO_16_AL},

	{bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
	{bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
	{bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL},	//pinmux for PWM2 LED    //for reserve

	//external interrupt pin usage
	{bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
	{bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_1},	//WPS Btn,sr2-2
	//{bp_usGpio_Intr,	       .u.us = BP_GPIO_33_AL}, 		//5G --> WPS_IRQ
	{bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_2},	//WLAN 2.4GHz/5GHz Btn,sr2-2
	//{bp_usGpio_Intr,	       .u.us = BP_GPIO_34_AL}, 		//2.4G --> WLAN_IRQ_ON_OFF

	/* 2.4G,5G WPS LED */
	{bp_usGpioLedSesWireless,    .u.us = BP_GPIO_5_AL},		//2.4G_WPS_LED, Wi-Fi Protect Protected Setup(WPS)
	{bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_20_AL},	//5G_WPS_LED

	/* xDSL LINK LED */
	{bp_usGpioLedAdsl,           .u.us = BP_GPIO_6_AL},
	{bp_usGpioLedVdsl,           .u.us = BP_GPIO_21_AL},

	/* G.FAST LED */
	{bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_31_AL},	//G_FAST_LINK_LED

	/* AFE ID */
	{bp_ulAfeId0, .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },	//sr2-2
	//{bp_ulAfeId0, .u.ul = BP_AFE_CHIP_GFAST_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_40 },	//0x7080 8100
	//{bp_ulAfeId1, .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },	//0x5080 8100
	{bp_usGpioAFELDRelay,        .u.us = BP_GPIO_3_AH},		//GFAST_EN
	//conjunction with BP_OVERLAY_PHY option
	{bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH},	//Line Driver 0 = "Int"
	{bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
	{bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},	//LD0_DCLK,sr2-2
	//{bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH},	//Line Driver 1 = "Ext"
	//{bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
	//{bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},

	/* I2C */
	{bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
	{bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },

	{bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},		//use phy addressses on SF2 with base address 0x8

	/*Ethrenet Switch Parameters ID Definitions */
	/*------ WAN setting  ------*/
	{bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY},			//Runner (Internal port connect to internal switch)
	{bp_ucPhyAddress,            .u.uc = 0x1e},
	{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},		//set to BP_ENET_CONFIG_MMAP for internal switch
	{bp_ulPortMap,               .u.ul = 0x3},
	{bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},	//This has one crossbar setting
	// Eth WAN
	{bp_ulCrossbar,              .u.ul = 10},
	{bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_usLinkLed,               .u.us = BP_GPIO_14_AL},		//WAN_AE_Link/ACT_LED; BP_GPIO_22_AL==WAN_AE_LED_select
	// ActiveEthernet, SFP
	{bp_ulCrossbar,              .u.ul = 9},
	{bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL },
	{bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},	//MUST, due to old platform
	{bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT },					//MUST, due to old platform,Managment port is on switch

	/*------ LAN setting  ------*/
	{bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},	//external switch
	{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},		//Accessing SF2 as MMapped external switch
	{bp_ulPortMap,               .u.ul = 0xF},						//LAN port 0, 1, 2, 3
	// Port0
	{bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_ucPhyDevName,            .u.cp = "eth1"},
	{bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
	// Port1
	{bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_ucPhyDevName,            .u.cp = "eth2"},
	{bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
	// Port2
	{bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_ucPhyDevName,            .u.cp = "eth3"},
	{bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
	// Port3
	{bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
	{bp_ucPhyDevName,            .u.cp = "eth4"},
	{bp_ulCrossbar,              .u.ul = 13},
	{bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_usLinkLed,               .u.us = BP_GPIO_13_AL},

	/* VoIP */
	{bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
	{bp_ucDspAddress,            .u.uc = 0},
	{bp_usGpioVoip1Led,          .u.us = BP_GPIO_23_AL},								//FXS0_GREEN_LED
	{bp_usGpioVoip1MessageLed,   .u.us = BP_GPIO_27_AL},	//using for voice message	//FXS0_ORANGE_LED,sr2-2
	{bp_usGpioVoip2Led,          .u.us = BP_GPIO_19_AL},								//FXS1_GREEN_LED
	{bp_usGpioVoip2MessageLed,   .u.us = BP_GPIO_4_AL},		//using for voice message	//FXS1_ORANGE_LED

	/* USB, usb device LEDs directly controlled by HW, do not need to be specified with parameter id */
	{bp_usGpioLedUSB0,           .u.us = BP_GPIO_7_AL},		//USB0(/mnt/usb1_sda1/)
	{bp_usGpioLedUSB1,           .u.us = BP_GPIO_8_AL},		//USB1((/mnt/usb2_sda1/))

	/*------ Reserved for tsetting  ------*/
	// SFP
	//{bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH},	//AE_LOS //It indicate GPIO is used for SerDes Fiber Singnal Detection or not.
	//{bp_usGpioSFPDetect,         .u.us = BP_GPIO_26_AL},	//AE_SFP_PRESENT, 8823 not use but keep it
	//{bp_usGpioSFPTXFault,        .u.us = BP_GPIO_37_AH},	//AE_SFP_TX_FAULT
	{bp_usUsbPwrOn0,             .u.us = BP_GPIO_133_AL},	//Using for invert port power
	{bp_usGpioSelectWanLed,      .u.us = BP_GPIO_22_AL},	//vmg8823 default run WAN led(HIGH),so kGpioInactive @board.c
	{bp_last}
};
#else
static bp_elem_t g_zyxel_vmg8823_b10b[] = {
	{bp_cpBoardId,               .u.cp = "VMG8823-B10B"},
	{bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND},	//Enable NAND pinmux even on SPI boot
	{bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16},	//returns the DDR Memory Config

	/* zyxel, returns the GPIO pin assignment for the Internet Data LED*/
	{bp_usGpioLedInternetData,   .u.us = BP_GPIO_15_AL},
	{bp_usGpioLedInternetFail,   .u.us = BP_GPIO_16_AL},

	{bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
	{bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
	{bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL},	//pinmux for PWM2 LED    //for reserve

	//external interrupt pin usage
	{bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
	{bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_1},
	//{bp_usGpio_Intr,	       .u.us = BP_GPIO_33_AL}, //5G
	{bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_2},
	//{bp_usGpio_Intr,	       .u.us = BP_GPIO_34_AL}, //2.4G

	/* 2.4G,5G WPS LED */
	{bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},	//2.4G_WPS_LED, Wi-Fi Protect Protected Setup(WPS)
	{bp_usGpioLedSesWireless2,   .u.us = BP_GPIO_20_AL},	//5G_WPS_LED

	/* xDSL LINK LED */
	{bp_usGpioLedAdsl,           .u.us = BP_GPIO_6_AL},
	{bp_usGpioLedVdsl,           .u.us = BP_GPIO_21_AL},

	/* AFE ID */
	{bp_ulAfeId0, .u.ul = BP_AFE_CHIP_GFAST_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_40 },	//0x7080 8100
	{bp_ulAfeId1, .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },	//0x5080 8100
	{bp_usGpioAFELDRelay,        .u.us = BP_GPIO_3_AH},		//GFAST_EN
	//conjunction with BP_OVERLAY_PHY option
	{bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH},	//Line Driver 0 = "Int"
	{bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
	{bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH},	//Line Driver 1 = "Ext"
	{bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
	{bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},

	/* I2C */
	{bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
	{bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },

	{bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},		//use phy addressses on SF2 with base address 0x8

	/*Ethrenet Switch Parameters ID Definitions */
	/*------ WAN setting  ------*/
	{bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY},			//Runner (Internal port connect to internal switch)
	{bp_ucPhyAddress,            .u.uc = 0x1e},
	{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},		//set to BP_ENET_CONFIG_MMAP for internal switch
	{bp_ulPortMap,               .u.ul = 0x3},
	{bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},	//This has one crossbar setting
	// Eth WAN
	{bp_ulCrossbar,              .u.ul = 10},
	{bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
	// ActiveEthernet, SFP
	{bp_ulCrossbar,              .u.ul = 9},
	{bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL },
	{bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},	//MUST, due to old platform
	{bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT },					//MUST, due to old platform,Managment port is on switch

	/*------ LAN setting  ------*/
	{bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},	//external switch
	{bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},		//Accessing SF2 as MMapped external switch
	{bp_ulPortMap,               .u.ul = 0xF},						//LAN port 0, 1, 2, 3
	// Port0
	{bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_ucPhyDevName,            .u.cp = "eth1"},
	{bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
	// Port1
	{bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_ucPhyDevName,            .u.cp = "eth2"},
	{bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
	// Port2
	{bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_ucPhyDevName,            .u.cp = "eth3"},
	{bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
	// Port3
	{bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
	{bp_ucPhyDevName,            .u.cp = "eth4"},
	{bp_ulCrossbar,              .u.ul = 13},
	{bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	{bp_usLinkLed,               .u.us = BP_GPIO_13_AL},

	/* VoIP */
	{bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
	{bp_ucDspAddress,            .u.uc = 0},
	{bp_usGpioVoip1Led,          .u.us = BP_GPIO_23_AL},								//FXS0_GREEN_LED
	{bp_usGpioVoip1MessageLed,   .u.us = BP_GPIO_25_AL},	//using for voice message	//FXS0_ORANGE_LED
	{bp_usGpioVoip2Led,          .u.us = BP_GPIO_19_AL},								//FXS1_GREEN_LED
	{bp_usGpioVoip2MessageLed,   .u.us = BP_GPIO_4_AL},		//using for voice message	//FXS1_ORANGE_LED

	/* USB, usb device LEDs directly controlled by HW, do not need to be specified with parameter id */
	{bp_usGpioLedUSB0,           .u.us = BP_GPIO_7_AL},		//USB0(/mnt/usb1_sda1/)
	{bp_usGpioLedUSB1,           .u.us = BP_GPIO_8_AL},		//USB1((/mnt/usb2_sda1/))

	/*------ Reserved for tsetting  ------*/
	// SFP
	//{bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH},	//AE_LOS //It indicate GPIO is used for SerDes Fiber Singnal Detection or not.
	//{bp_usGpioSFPDetect,         .u.us = BP_GPIO_26_AL},	//AE_SFP_PRESENT, 8823 not use but keep it
	//{bp_usGpioSFPTXFault,        .u.us = BP_GPIO_37_AH},	//AE_SFP_TX_FAULT
	{bp_usUsbPwrOn0,             .u.us = BP_GPIO_133_AL},	//Using for invert port power
	{bp_last}
};
#endif
/* Different SDRAM config, reserved for 512MB
static bp_elem_t g_xmg8823_b10b_ddr512[] = {
  {bp_cpBoardId, .u.cp = "VMG8823_512MB"},
  {bp_ulMemoryConfig, .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},

  {bp_elemTemplate, .u.bp_elemp = g_zyxel_vmg8823_b10b},
  {bp_last}
};*/

#endif //if defined(ZYXEL) && (ZYXEL==1)

bp_elem_t * g_BoardParms[] = {g_bcm963138sv, g_bcm963138dvt, g_bcm963138ref_gfast_p40x, g_bcm963138ref_gfast_2,  g_bcm963138ref_gfast_p40x_mem, g_bcm963138ref_gfast_4,
    g_bcm963138bg_gfast, g_bcm963138ref_p502, g_bcm963138ref_p802, g_bcm963138bmu_p202, g_bcm963138lte_p302, g_bcm963138lte2, g_bcm963138ref_p502_plc, g_bcm963138ref_p502_moca,
    g_bcm963138ref_p502_bhr, g_bcm963138dvt_p300, g_bcm963138ref_rnc, g_bcm963138ref_rncp400, g_bcm963138ref_bgw, g_bcm963138ref_p502_moca_p200, g_bcm963138ref_p502_dual_moca_p200, g_bcm963138ref_3wlan
#if defined(ZYXEL) && (ZYXEL==1)
	, g_zyxel_fmg3586, g_zyxel_fmg3086
	, g_zyxel_xmg3512_b10a, g_zyxel_xmg3512_b10a_p1, g_zyxel_xmg3512_b10a_p3
	, g_zyxel_xmg3512_b10a_lan, g_zyxel_xmg3512_b10a_lan_p1, g_zyxel_xmg3512_b10a_lan_p3
	, g_xmg3512_b10a_ddr128, g_zyxel_vmg8823_b10b
#endif
	, 0};
#endif

#if defined(_BCM963381_) || defined(CONFIG_BCM963381)
static bp_elem_t g_bcm963381sv[] = {
  {bp_cpBoardId,               .u.cp = "963381SV"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, /* enable NAND interface even for SPI boot */
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 18},
  /*{bp_usGpioLedAdsl,           .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_12_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_11_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},*/
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x19 | MAC_IF_RGMII_1P8V | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },    
  {bp_last}
};

static bp_elem_t g_bcm963381dvt[] = {
  {bp_cpBoardId,               .u.cp = "963381DVT"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, /* enable NAND interface even for SPI boot */
  {bp_usSerialLedClk,          .u.us = BP_GPIO_16_AH},
  {bp_usSerialLedData,         .u.us = BP_GPIO_17_AH}, 
  {bp_usSerialLedMask,         .u.us = BP_GPIO_24_AH},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_13_AL},/*does not work in A0*/
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 19},
  {bp_usSpiSlaveSelectNum,     .u.us = 2}, /* needed in case a SPI device is plugged  into J504 */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 18},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_5_AL}, /* these link/speed led do not work in A0 */
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },    
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_17_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_18_AL}, 
  {bp_last}
};

static bp_elem_t g_bcm963381dvt_rgmii[] = {
  {bp_cpBoardId,               .u.cp = "963381DVT_RGMII"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x19 | MAC_IF_RGMII_1P8V | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381dvt},
  {bp_last}
};

static bp_elem_t g_bcm963381dvt_53125[] = {
  {bp_cpBoardId,               .u.cp = "963381DVT_53125"},
  {bp_cpComment,               .u.cp = "(incomplete)"},
  {bp_usEphyBaseAddress,       .u.us = 0x8},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x08},
  {bp_ulPhyId1,                .u.ul = 0x09},
  {bp_ulPhyId2,                .u.ul = 0x0a},
  {bp_ulPhyId3,                .u.ul = 0x0b},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  //{bp_usConfigType,            .u.us = BP_ENET_CONFIG_SPI_SSB_2},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = 0x00 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = 0x01 | CONNECTED_TO_EXTERN_SW},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381dvt},
  {bp_last}
};


static bp_elem_t g_bcm963381ref1_a0[] = {
  {bp_cpBoardId,               .u.cp = "963381REF1_A0"},
  {bp_ulPinmuxTableSelect,     .u.ul = 1}, // default pinmux is 0
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_3_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_5_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_2_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_9_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usSerialLedData,         .u.us = BP_GPIO_17_AL}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_16_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_24_AH},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_27_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_16_AH},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_24_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_29_AH},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_22_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },    
  {bp_last}
};

/* for A1 and B0 chip */
static bp_elem_t g_bcm963381ref1[] = {
  {bp_cpBoardId,               .u.cp = "963381REF1"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, /* enable NAND interface even for SPI boot */
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_16_AH},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AH},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_17_AH},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AH},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_1_AH},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AH},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AH},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_GPIO_8_AH},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_3_AH},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AH},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AH},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_GPIO_10_AH},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },   
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_13_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_12_AH}, 
  {bp_last}
};

static bp_elem_t g_bcm963381ref2[] = {
  {bp_cpBoardId,               .u.cp = "963381REF2"},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_1_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_GPIO_8_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_3_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_GPIO_10_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII_1P8V | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_13_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_12_AL}, 
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381ref1},
  {bp_last}
};

static bp_elem_t g_bcm963381bg_lte[] = {
  {bp_cpBoardId,               .u.cp = "963381BG_LTE"},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381ref2},
  {bp_last}
};

static bp_elem_t g_bcm963381a_ref1[] = {
  {bp_cpBoardId,               .u.cp = "963381A_REF1"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, /* enable NAND interface even for SPI boot */
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_23_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_35_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_36_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_GPIO_33_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_34_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_GPIO_38_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_31_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_GPIO_41_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_42_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AL}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AL},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },   
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_37_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_16_AL}, 
  {bp_last}
};

static bp_elem_t g_bcm963381ref3[] = {
  {bp_cpBoardId,               .u.cp = "963381REF3"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_40_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 19},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_39_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_35_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_36_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_GPIO_33_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_34_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_GPIO_38_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_31_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_GPIO_41_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_42_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },   
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_13_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_12_AH}, 
  {bp_last}
};

static bp_elem_t g_bcm963381wp[] = {
  {bp_cpBoardId,               .u.cp = "963381WP"},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_1_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x11},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT_3P3V | FORCE_LINK_1000FD},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulPortMaxRate,           .u.ul = 400000000},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY | PORT_FLAG_SOFT_SWITCHING},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381ref3},
  {bp_last}
};

#if defined(ZYXEL) && (ZYXEL==1)
static bp_elem_t g_bcm963881_VMG5313[] = {
  {bp_cpBoardId,               .u.cp = "963381_VMG5313B"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_2_AH},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AH},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_16_AH},
 #ifndef ZYXEL_ISKON_CUSTOMIZATION
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_16_AH},
 #else
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_23_AH},
 #endif
#if 1
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_19_AH},
  //{bp_ReservedAnyLed,          .u.us = BP_GPIO_17_AH},
  {bp_usGpioLedInternetFail,   .u.us = BP_GPIO_17_AH},
#else
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AH},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_17_AH},
#endif
  //{bp_ReservedAnyLed,          .u.us = BP_GPIO_1_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_1_AH},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
//  {bp_usGpio_Intr,             .u.us = BP_GPIO_20_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
//  {bp_usGpio_Intr,             .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_4},
//  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedUSB0,           .u.us = BP_GPIO_0_AH},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AH},
  //{bp_usSpeedLed100,           .u.us = BP_GPIO_5_AH},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_8_AH},
  //{bp_usSpeedLed100,           .u.us = BP_GPIO_8_AH},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AH},
  //{bp_usSpeedLed100,           .u.us = BP_GPIO_9_AH},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usLinkLed,               .u.us = BP_GPIO_10_AH},
  //{bp_usSpeedLed100,           .u.us = BP_GPIO_10_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_50
#ifdef ADSL_ANNEXB
                                       | BP_AFE_FE_ANNEXBJ},
#else
                                       | BP_AFE_FE_ANNEXA},
#endif
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_13_AH},
  {bp_usGpioVoip1MessageLed,   .u.us = BP_GPIO_3_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_12_AH},
  {bp_usGpioVoip2MessageLed,   .u.us = BP_GPIO_4_AH},
  {bp_last}
};

static bp_elem_t g_bcm963881_VMG1312[] = {
  {bp_cpBoardId,               .u.cp = "963381_VMG1312"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND | BP_PINMUX_OPTLED_VALID},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_23_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_27_AL},
  {bp_usGpioLedVdsl,           .u.us = BP_GPIO_27_AL},
#if 1
  //{bp_ReservedAnyLed,   .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedInternetData,   .u.us = BP_GPIO_19_AL},
  //{bp_ReservedAnyLed,          .u.us = BP_GPIO_30_AL},
  {bp_usGpioLedInternetFail,   .u.us = BP_GPIO_30_AL},
#else
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_30_AL},
#endif
  //{bp_ReservedAnyLed,          .u.us = BP_GPIO_49_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_49_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_2},
  {bp_usExtIntrWirelessBtn,    .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedUSB0,           .u.us = BP_GPIO_28_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
#if (ZYPRJ_HARDWARE_VERSION == 0)
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  //{bp_usLinkLed,               .u.us = BP_GPIO_45_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_16_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  //{bp_usLinkLed,               .u.us = BP_GPIO_46_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_17_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  //{bp_usLinkLed,               .u.us = BP_GPIO_47_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  //{bp_usLinkLed,               .u.us = BP_GPIO_49_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_24_AL},
#elif (ZYPRJ_HARDWARE_VERSION == 1)
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_35_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_33_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_usLinkLed,               .u.us = BP_GPIO_38_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usLinkLed,               .u.us = BP_GPIO_41_AL},
#endif
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },
  {bp_last}
};
#endif

bp_elem_t * g_BoardParms[] = {g_bcm963381sv, g_bcm963381dvt, g_bcm963381dvt_rgmii, g_bcm963381dvt_53125, g_bcm963381ref1_a0, g_bcm963381a_ref1, g_bcm963381ref1, g_bcm963381ref2, g_bcm963381ref3, g_bcm963381bg_lte, g_bcm963381wp
#if defined(ZYXEL) && (ZYXEL==1)
	,g_bcm963881_VMG5313
	, g_bcm963881_VMG1312
#endif
	, 0};
#endif

#if defined(_BCM963148_) || defined(CONFIG_BCM963148)

/* Only needed for internal GPHYs; by default internal GPHYs do not adv. 1000HD/100HD/10FD/10HD capabilities;
 * There are some NICs that will not negotiate 100FD - so need to advertise 100HD to link up with those NICs */
#define BCM963148_PHY_BASE             0x8

static bp_elem_t g_bcm963148sv[] = {
  {bp_cpBoardId,               .u.cp = "963148SV"},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH}, // uart2 is /dev/ttyS1
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH}, // stty 115200 < /dev/ttyS1 to set speed
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usGphyBaseAddress,       .u.us = BCM963148_PHY_BASE},  // use phy addressses on SF2 with base address 0x8

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_8},
  {bp_last}
};

static bp_elem_t g_bcm963148dvt[] = {
  {bp_cpBoardId,               .u.cp = "963148DVT"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_18_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_20_AL}, // LED register bit 20, shifted serially
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usGphyBaseAddress,       .u.us = BCM963148_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
                                              // to avoid conflicting P0 and P11 phy address of 1
                                              // the intergrated Quad GPHY address is now 0x8, 0x9, 0xa, 0xb
                                              // the intergrated Single GPHY address 0xc
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = 0x19 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL}, // bottom right.
  {bp_ulPhyId7,                .u.ul = 0x0 |  PHY_INTEGRATED_VALID  | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963148dvt_p300[] = {
  {bp_cpBoardId,               .u.cp = "963148DVT_P300"},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_26_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_27_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_28_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = 0x19 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL}, // bottom right.
  {bp_ulPhyId7,                .u.ul = 0x0 |  PHY_INTEGRATED_VALID  | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148dvt},
  {bp_last}
};

static bp_elem_t g_bcm963148ref[] = {
  {bp_cpBoardId,               .u.cp = "963148REF"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AL}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AL}, // placeholder for SF2 Port4 SPD1
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_27_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioSecLedWanData,     .u.us = BP_GPIO_19_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},
  {bp_usGphyBaseAddress,       .u.us = BCM963148_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_25_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_usUsbPwrFlt0,             .u.us = BP_GPIO_132_AL},
  {bp_usUsbPwrOn0,              .u.us = BP_GPIO_133_AL},
  {bp_usUsbPwrFlt1,             .u.us = BP_GPIO_134_AL},
  {bp_usUsbPwrOn1,              .u.us = BP_GPIO_135_AL},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_p502[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_P502"},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH}, // placeholder for SF2 Port4 SPD1
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_bmu[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_BMU"},
  {bp_usBatteryEnable,         .u.us = 1},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_22_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_23_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_21_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_LD_REV_6303_VR5P3 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_LD_REV_6303_VR5P3 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioAFEVR5P3PwrEn,     .u.us = BP_GPIO_37_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usVregSync,              .u.us = BP_GPIO_18_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963148_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x4) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x0) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x1) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x2) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x3) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_29_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_30_AL},
  {bp_usGpioDectLed,           .u.us = BP_GPIO_31_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_8},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_bmu_i2s[] = {
  {bp_cpBoardId,               .u.cp = "963148_BMUI2S"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_I2S}, // Enable I2S pinmux
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_NONE}, 
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_NONE},
  {bp_usGpioDectLed,           .u.us = BP_GPIO_NONE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref_bmu},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_plc[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_PLC"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT_3P3V },
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_moca[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_MOCA"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_14_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_bhr[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_BHR"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_115_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_60_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_14_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_p502_plc[] = {
  {bp_cpBoardId,               .u.cp = "963148P502_PLC"},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH}, // placeholder for SF2 Port4 SPD1
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT_3P3V },
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref_plc},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_p502_moca[] = {
  {bp_cpBoardId,               .u.cp = "963148P502_MOCA"},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH}, // placeholder for SF2 Port4 SPD1
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref_moca},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_p502_bhr[] = {
  {bp_cpBoardId,               .u.cp = "963148P502_BHR"},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH}, // placeholder for SF2 Port4 SPD1
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref_bhr},
  {bp_last}
};


bp_elem_t * g_BoardParms[] = {g_bcm963148sv, g_bcm963148dvt, g_bcm963148ref, g_bcm963148ref_bmu, g_bcm963148ref_bmu_i2s, g_bcm963148ref_plc, g_bcm963148ref_moca, g_bcm963148ref_bhr, g_bcm963148dvt_p300, 
    g_bcm963148ref_p502, g_bcm963148ref_p502_plc, g_bcm963148ref_p502_moca, g_bcm963148ref_p502_bhr, 0};
#endif

bp_elem_t * g_pCurrentBp = 0;





#if defined(_BCM96362_) || defined(CONFIG_BCM96362)
/* The unique part contains the subSytemId (boardId) and the BoardRev number */
static WLAN_SROM_ENTRY wlan_patch_unique_96362ADVNX[] = {
    {2,  0x536},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_96362ADVNgr2[] = {
    {2,  0x580},
    {65, 0x1500},
    {0, 0}
};


static WLAN_SROM_ENTRY wlan_patch_unique_96362ADVN2xh[] = {
    {2,  0x5a6},
    {65, 0x1200},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_96361XF[] = {
    {2,  0x5b8},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_96362RAVNGR2[] = {
    {2,  0x60d},
    {65, 0x1500},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_96362ADVN2XM[] = {
    {2,  0x60d},
    {65, 0x1500},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_96362RADVNXH5[] = {
    {2,  0x63F},
    {48, 0x434f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_96362RADVN2XH[] = {
    {2,  0x63E},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_96362RWFAR[] = {
    {2,  0x60d},
    {65, 0x1500},
    {0, 0}
};

/* The common part contains the entries that are valid for multiple boards */
static WLAN_SROM_ENTRY wlan_patch_common_96362ADVNX[] = {
    { 87, 0x0319},
    { 96, 0x2058},
    { 97, 0xfe6f},
    { 98, 0x1785},
    { 99, 0xfa21},
    {112, 0x2058},
    {113, 0xfe77},
    {114, 0x17e0},
    {115, 0xfa16},
    {161, 0x5555},
    {162, 0x5555},
    {169, 0x5555},
    {170, 0x5555},
    {171, 0x5555},
    {172, 0x5555},
    {173, 0x3333},
    {174, 0x3333},
    {175, 0x3333},
    {176, 0x3333},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_96362ADVNgr2[] = {
    { 96, 0x2046},
    {100, 0x3c46},
    {101, 0x4040},    
    {102, 0xFF3C},
    {103, 0x1381},
    {104, 0xFBF1},
    {108, 0xFF09},
    {109, 0x1310},
    {110, 0xFBD6},
    {112, 0x2046},
    {116, 0x3c46},  
    {117, 0x4040},
    {118, 0xFFE9},
    {119, 0x1383},
    {120, 0xFCBC},
    {124, 0xFF3F},
    {125, 0x13C9},
    {126, 0xFBEC},
    {160, 0x3333},
    {161, 0x0000},
    {162, 0x3333},
    {163, 0x0000},
    {164, 0x5555},
    {165, 0x0000},
    {166, 0x2222},
    {167, 0x0000},
    {168, 0x4444},
    {169, 0x3000},
    {170, 0x3333},
    {171, 0x3000},
    {172, 0x3333},
    {177, 0x5000},
    {178, 0x5555},
    {179, 0x5000},
    {180, 0x5555},
    {185, 0x2000},
    {186, 0x2222},
    {187, 0x2000},
    {188, 0x2222},
    {193, 0x4000},
    {194, 0x4444},
    {195, 0x4000},
    {196, 0x4444},
    {201, 0x1111},
    {202, 0x2222},
    {203, 0x6775},  
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_96361XF[] = {
    { 66, 0x0200},
    { 67, 0x0000},
    { 78, 0x0003},
    { 79, 0x0000},
    { 80, 0x0000},
    { 87, 0x0313},
    { 88, 0x0313},
    { 93, 0xffff},
    { 96, 0x2054},
    { 97, 0xfe80},
    { 98, 0x1fa2},
    { 99, 0xf897},
    {112, 0x2054},
    {113, 0xfe8c},
    {114, 0x1f13},
    {115, 0xf8c4},
    {161, 0x4444},
    {162, 0x4444},
    {169, 0x4444},
    {170, 0x4444},
    {171, 0x4444},
    {172, 0x4444},
    {203, 0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_96362ADVN2xh[] = {
    { 66, 0x3200},
    { 67, 0x8000},
    { 78, 0x0003},
    { 79, 0x0000},
    { 80, 0x0000},
    { 87, 0x031f},
    { 88, 0x031f},
    { 93, 0x0202},
    { 96, 0x2064},
    { 97, 0xfe80},
    { 98, 0x1fa2},
    { 99, 0xf897},
    {112, 0x2064},
    {113, 0xfe8c},
    {114, 0x1f13},
    {115, 0xf8c4},
    {203, 0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_96362ADVN2XM[] = {
    /* PA params not updated yet */
    { 65, 0x1200},                
    { 66, 0x3200},
    { 67, 0x8000},
    { 78, 0x0003},
    { 79, 0x0000},
    { 80, 0x0000},
    { 87, 0x031f},
    { 88, 0x031f},
    { 93, 0x0202},
    { 96, 0x205c},
    { 97, 0xfe80},
    { 98, 0x1fa2},
    { 99, 0xf897},
    {112, 0x205c},
    {113, 0xfe8c},
    {114, 0x1f13},
    {115, 0xf8c4},
    {203, 0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_96362RADVNXH5[] = {
    /* PA params not updated yet */
    { 66,  0x3200},
    { 67,  0x8000},
    { 78,  0x0300},
    { 87,  0x031f},
    { 88,  0x033f},
    { 93,  0x0202},
    { 100, 0x4060},
    { 101, 0x6060},
    { 102, 0xFE87},
    { 103, 0x1F06},
    { 104, 0xF8B0},
    { 108, 0xFE88},
    { 109, 0x1EC8},
    { 110, 0xF8C0},
    { 116, 0x4060},
    { 117, 0x6060},
    { 118, 0xFE87},
    { 119, 0x1F06},
    { 120, 0xF8B0},
    { 124, 0xFE8E},
    { 125, 0x1F0B},
    { 126, 0xF8BB},
    { 161, 0x0000},
    { 162, 0x0000},
    { 169, 0x0000},
    { 170, 0x0000},
    { 171, 0x0000},
    { 172, 0x0000},
    { 203, 0x2222},
    {0, 0}
};
#endif

#if defined(_BCM963268_) || defined(CONFIG_BCM963268)
/* The unique part contains the subSytemId (boardId) and the BoardRev number */
static WLAN_SROM_ENTRY wlan_patch_unique_963268MBV[] = {
    {2,  0x5BB},
    {65, 0x1204},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963268V30A[] = {
    {2,  0x5E7},
    {65, 0x1101},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963268BU[] = {
    {2,  0x5A7},
    {65, 0x1201},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XH[] = {
    {2,  0x5E2},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XM[] = {
    {2,  0x61F},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XH5[] = {
    {2,  0x640},
    {48, 0x434f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XN5[] = {
    {2,  0x684},
    {48, 0x434f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XM5[] = {
    {2,  0x685},
    {48, 0x434f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XM5_6302[] = {
    {2,  0x686},
    {48, 0x434f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168MP[] = {
    {2,  0x5BB},
    {48, 0x433f},
    {65, 0x1100},
    {0, 0}
};

/* The common part contains the entries that are valid for multiple boards */
static WLAN_SROM_ENTRY wlan_patch_common_963268MBV[] = {
    { 78,  0x0303}, 
    { 79,  0x0202}, 
    { 80,  0xff02},
    { 87,  0x0315}, 
    { 88,  0x0315},
    { 94,  0x001E},
    { 96,  0x2048}, 
    { 97,  0xFFB5}, 
    { 98,  0x175F},
    { 99,  0xFB29},
    { 100, 0x3E40},
    { 101, 0x403C},
    { 102, 0xFF15},
    { 103, 0x1455},
    { 104, 0xFB95},
    { 108, 0xFF28},
    { 109, 0x1315},
    { 110, 0xFBF0},
    { 112, 0x2048},
    { 113, 0xFFD7},
    { 114, 0x17D6},
    { 115, 0xFB67},
    { 116, 0x3E40},
    { 117, 0x403C},
    { 118, 0xFE87},
    { 119, 0x110F},
    { 120, 0xFB4B},
    { 124, 0xFF8D},
    { 125, 0x1146},
    { 126, 0xFCD6},
    { 161, 0x0000},
    { 162, 0x4444},
    { 163, 0x0000},
    { 164, 0x2222},
    { 165, 0x0000},
    { 166, 0x2222},
    { 167, 0x0000},
    { 168, 0x2222},
    { 169, 0x4000},
    { 170, 0x4444},
    { 171, 0x4000},
    { 172, 0x4444},
    { 177, 0x2000},
    { 178, 0x2222},
    { 179, 0x2000},
    { 180, 0x2222},
    { 185, 0x2000},
    { 186, 0x2222},
    { 187, 0x2000},
    { 188, 0x2222},
    { 193, 0x2000},
    { 194, 0x2222},
    { 195, 0x2000},
    { 196, 0x2222},
    { 201, 0x1111},
    { 202, 0x2222},
    { 203, 0x4446},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XH[] = {
    { 66,  0x3200},
    { 67,  0x8000},
    { 87,  0x031f},
    { 88,  0x031f},
    { 93,  0x0202},
    { 96,  0x2064},
    { 97,  0xfe59},
    { 98,  0x1c81},
    { 99,  0xf911},
    { 112, 0x2064},
    { 113, 0xfe55},
    { 114, 0x1c00},
    { 115, 0xf92c},
    { 161, 0x0000},
    { 162, 0x0000},
    { 169, 0x0000},
    { 170, 0x0000},
    { 171, 0x0000},
    { 172, 0x0000},
    { 203, 0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XM[] = {
    { 66,  0x3200},
    { 67,  0x8000},
    { 87,  0x031f},
    { 88,  0x031f},
    { 93,  0x0202},
    { 96,  0x205c},
    { 97,  0xfe94},
    { 98,  0x1c92},
    { 99,  0xf948},
    { 112, 0x205c},
    { 113, 0xfe81},
    { 114, 0x1be6},
    { 115, 0xf947},
    { 161, 0x0000},
    { 162, 0x0000},
    { 169, 0x0000},
    { 170, 0x0000},
    { 171, 0x0000},
    { 172, 0x0000},
    { 203, 0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XH5[] = {
    { 66,  0x3200},
    { 67,  0x8000},
    { 78,  0x0300},
    { 87,  0x031f},
    { 88,  0x033f},
    { 93,  0x0202},
    { 97,  0xffb5},
    { 98,  0x175f},
    { 99,  0xfb29},
    { 100, 0x4060},
    { 101, 0x6060},
    { 102, 0xfee4},
    { 103, 0x1d2c},
    { 104, 0xfa0c},
    { 105, 0xfea2},
    { 106, 0x149a},
    { 107, 0xfafc},
    { 108, 0xfead},
    { 109, 0x1da8},
    { 110, 0xf986},
    { 113, 0xffd7},
    { 114, 0x17d6},
    { 115, 0xfb67},
    { 116, 0x4060},
    { 117, 0x6060},
    { 118, 0xfee4},
    { 119, 0x1d2c},
    { 120, 0xfa0c},
    { 121, 0xfea2},
    { 122, 0x149a},
    { 123, 0xfafc},
    { 124, 0xfead},
    { 125, 0x1da8},
    { 126, 0xf986},
    { 161, 0x0000},
    { 162, 0x0000},
    { 169, 0x0000},
    { 170, 0x0000},
    { 171, 0x0000},
    { 172, 0x0000},
    { 203, 0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XN5[] = {
    { 66,  0x2200},
    { 67,  0x8000},
    { 78,  0x0300},
    { 87,  0x031f},
    { 88,  0x033f},
    { 96,  0x4054},
    { 97,  0xffb5},
    { 98,  0x175f},
    { 99,  0xfb29},
    { 100,  0x405c},
    { 101,  0x5c5c},
    { 102,  0xfedf},
    { 103,  0x1670},
    { 104,  0xfabf},
    { 105,  0xfeb2},
    { 106,  0x1691},
    { 107,  0xfa6a},
    { 108,  0xfec0},
    { 109,  0x16cd},
    { 110,  0xfaa5},
    { 112,  0x404e},
    { 113,  0xffd7},
    { 114,  0x17d6},
    { 115,  0xfb67},
    { 116,  0x405c},
    { 117,  0x5c5c},
    { 118,  0xfeb2},
    { 119,  0x1691},
    { 120,  0xfa6a},
    { 121,  0xfeb2},
    { 122,  0x1691},
    { 123,  0xfa6a},
    { 124,  0xfe60},
    { 125,  0x1685},
    { 126,  0xfa09},
    { 161,  0x0000},
    { 162,  0x0000},
    { 163,  0x8888},
    { 164,  0x8888},
    { 165,  0x8888},
    { 166,  0x8888},
    { 167,  0x8888},
    { 168,  0x8888},
    { 169,  0x0000},
    { 170,  0x0000},
    { 171,  0x0000},
    { 172,  0x0000},
    { 177,  0x0000},
    { 178,  0x8888},
    { 179,  0x8888},
    { 180,  0x8888},
    { 181,  0x8888},
    { 182,  0x8888},
    { 183,  0x8888},
    { 184,  0x8888},
    { 185,  0x8888},
    { 186,  0x8888},
    { 187,  0x0000},
    { 188,  0x8888},
    { 189,  0x8888},
    { 190,  0x8888},
    { 191,  0x8888},
    { 192,  0x8888},
    { 193,  0x8888},
    { 194,  0x8888},
    { 195,  0x8888},
    { 196,  0x8888},
    { 197,  0x0000},
    { 198,  0x8888},
    { 199,  0x8888},
    { 200,  0x8888},
    { 201,  0x2222},
    { 202,  0x2222},
    { 203,  0x2222},
    { 204,  0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XM5[] = {
    { 66,  0x3200},
    { 67,  0x8000},
    { 78,  0x0300},
    { 87,  0x031f},
    { 88,  0x033f},
    { 93,  0x0202},
    { 96,  0x405c},
    { 97,  0xffb5},
    { 98,  0x175f},
    { 99,  0xfb29},
    { 100,  0x405c},
    { 101,  0x5c5c},
    { 102,  0xfedd},
    { 103,  0x1a8b},
    { 104,  0xfa70},
    { 105,  0xfea2},
    { 106,  0x149a},
    { 107,  0xfafc},
    { 108,  0xfee7},
    { 109,  0x1a87},
    { 110,  0xfa84},
    { 112,  0x405c},
    { 113,  0xffd7},
    { 114,  0x17d6},
    { 115,  0xfb67},
    { 116,  0x405c},
    { 117,  0x5c5c},
    { 118,  0xfedd},
    { 119,  0x1a8b},
    { 120,  0xfa70},
    { 121,  0xfea2},
    { 122,  0x149a},
    { 123,  0xfafc},
    { 124,  0xfee7},
    { 125,  0x1a87},
    { 126,  0xfa84},
    { 161, 0x0000},
    { 162, 0x0000},
    { 169, 0x0000},
    { 170, 0x0000},
    { 171, 0x0000},
    { 172, 0x0000},
    { 203, 0x1111},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168MP[] = {
    { 78,  0x0303}, 
    { 79,  0x0202}, 
    { 80,  0xff02},
    { 87,  0x0315}, 
    { 88,  0x0315},
    { 96,  0x2048}, 
    { 97,  0xffb5},
    { 98,  0x168c},
    { 99,  0xfb31},
    { 100, 0x3E40},
    { 101, 0x403C},
    { 102, 0xFF15},
    { 103, 0x1455},
    { 104, 0xFB95},
    { 108, 0xFF28},
    { 109, 0x1315},
    { 110, 0xFBF0},
    { 112, 0x2048},
    { 113, 0xffd7},
    { 114, 0x17b6},
    { 115, 0xfb68},
    { 116, 0x3E40},
    { 117, 0x403C},
    { 118, 0xFE87},
    { 119, 0x110F},
    { 120, 0xFB4B},
    { 124, 0xFF8D},
    { 125, 0x1146},
    { 126, 0xFCD6},
    { 161, 0x0000},
    { 162, 0x4444},
    { 163, 0x0000},
    { 164, 0x2222},
    { 165, 0x0000},
    { 166, 0x2222},
    { 167, 0x0000},
    { 168, 0x2222},
    { 169, 0x4000},
    { 170, 0x4444},
    { 171, 0x4000},
    { 172, 0x4444},
    { 177, 0x2000},
    { 178, 0x2222},
    { 179, 0x2000},
    { 180, 0x2222},
    { 185, 0x2000},
    { 186, 0x2222},
    { 187, 0x2000},
    { 188, 0x2222},
    { 193, 0x2000},
    { 194, 0x2222},
    { 195, 0x2000},
    { 196, 0x2222},
    { 201, 0x1111},
    { 202, 0x2222},
    { 203, 0x4446},
    {0, 0}
};
///20130821, TimLiu add for new board parameter
#if defined(ZYXEL) && (ZYXEL==1)
/*** ZyXEL Project for SROM patch (BCM6362, 963168) ***/
// 20161027, Mark for BCM6362 chip commmon SROM patch
static WLAN_SROM_ENTRY wlan_patch_common_963168_BCM6362[] = {
/* Peter: CSP 932239 of MSTC for Wi-Fi 2.4G interference */
	{ 94, 0x001e},
    {0, 0}
};
//20140102, TimLiu add for modify calibration data for VMG8948
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG8948_BCM6362[] = {
	{2, 0x05bb},
	{65, 0x1204},
	//antenna
	{78, 0x0303},
	{79, 0x0202},
	{80, 0xFF02},
	{87, 0x0315},
	{88, 0x0315},
	//2G ant0 maxpower
	{96, 0x2048},
	//2G ant0 PA
	{97, 0xffd6},
	{98, 0x16e8},
	{99, 0xfb5b},
	//5G ant0 maxpower
	{100, 0x3e40},
	//5G ant0 PA
	{101, 0x403c},
	{102, 0xff15},
	{103, 0x1455},
	{104, 0xfb95},
	{105, 0xfea2},
	{106, 0x149a},
	{107, 0xfafc},
	{108, 0xff28},
	{109, 0x1315},
	{110, 0xfbf0},
	//2G ant1 maxpower
	{112, 0x2048},
	//2G ant1 PA
	{113, 0xff1c},
	{114, 0x157d},
	{115, 0xfad6},
	//5G ant1 maxpower
	{116, 0x3e40},
	//5G ant1 PA
	{117, 0x403c},
	{118, 0xfe87},
	{119, 0x110f},
	{120, 0xfb4b},
	{121, 0xfebe},
	{122, 0x1478},
	{123, 0xfb1a},
	{124, 0xff8d},
	{125, 0x1146},
	{126, 0xfcd6},
	//2G 20M power offset per rate
	{160, 0x0000},
	{161, 0x0000},
	{162, 0x4444},
	//5G 20M power offset per rate
	{163, 0x0000},
	{164, 0x2222},
	{165, 0x0000},
	{166, 0x2222},
	{167, 0x0000},
	{168, 0x2222},
	//2G 20M 11n power offset per rate
	{169, 0x4000},
	{170, 0x4444},
	{171, 0x4000},
	{172, 0x4444},
	//2G 40M 11n power offset per rate
	{173, 0x0000},
	{174, 0x0000},
	{175, 0x0000},
	{176, 0x0000},
	//5G 20M midband 11n power offset per rate
	{177, 0x2000},
	{178, 0x2222},
	{179, 0x2000},
	{180, 0x2222},
	//5G 40M midband 11n power offset per rate
	{181, 0x0000},
	{182, 0x0000},
	{183, 0x0000},
	{184, 0x0000},
	//5G 20M lowband 11n power offset per rate
	{185, 0x2000},
	{186, 0x2222},
	{187, 0x2000},
	{188, 0x2222},
	//5G 40M lowband 11n power offset per rate
	{189, 0x0000},
	{190, 0x0000},
	{191, 0x0000},
	{192, 0x0000},
	//5G 20M highband 11n power offset per rate
	{193, 0x2000},
	{194, 0x2222},
	{195, 0x2000},
	{196, 0x2222},
	//5G 40M highband 11n power offset per rate
	{197, 0x0000},
	{198, 0x0000},
	{199, 0x0000},
	{200, 0x0000},
	//2G/5G CCD power set
	{201, 0x1111},
	//2G/5G STBC power set
	{202, 0x2222},
	//2G 40M OFDM power-offset
	{203, 0x4446},
    {0, 0}
};
//20140903, TimLiu add for modify calibration data for VMG8924
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG8924_BCM6362[] = {
	{2, 0x0566},
	{65, 0x1230},
	//antenna
	{78, 0x0303},
	{79, 0x0202},
	{80, 0xFF02},
	{87, 0x0315},
	{88, 0x0315},
	//2G ant0 maxpower
	{96, 0x204e},
	//2G ant0 PA
	{97, 0xffda},
	{98, 0x1751},
	{99, 0xfac9},
	//2G ant1 maxpower
	{112, 0x204e},
	//2G ant1 PA
	{113, 0xffa3},
	{114, 0x16d2},
	{115, 0xfab7},
	//2G 20M power offset per rate
	{160, 0x2222},
	{161, 0x7777},
	{162, 0x7777},
	//2G 20M 11n power offset per rate
	{169, 0x7777},
	{170, 0x7777},
	{171, 0x8888},
	{172, 0x8888},
	//2G 40M 11n power offset per rate
	{173, 0x8888},
	{174, 0x8888},
	{175, 0x8888},
	{176, 0x8888},
	//2G/5G CCD power set
	{201, 0x0000},
	//2G/5G STBC power set
	{202, 0x0000},
	//2G 40M OFDM power-offset
	{203, 0x0000},
    {0, 0}
};
//20140903, TimLiu add for modify calibration data for VMG3926
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG3926_BCM6362[] = {
    {0, 0}
};
//20150313, TimLiu add for modify calibration data for VMG3926-B10B
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG3926B_BCM6362[] = {
	{2, 0x0566},
	{65, 0x1230},
	//antenna
	{78, 0x0303},
	{79, 0x0202},
	{80, 0xFF02},
	{87, 0x0315},
	{88, 0x0315},
	//2G ant0 maxpower
	{96, 0x204e},
	//2G ant0 PA
	{97, 0xffda},
	{98, 0x1751},
	{99, 0xfac9},
	//2G ant1 maxpower
	{112, 0x204e},
	//2G ant1 PA
	{113, 0xffa3},
	{114, 0x16d2},
	{115, 0xfab7},
	//2G 20M power offset per rate
	{160, 0x2222},
	{161, 0x7777},
	{162, 0x7777},
	//2G 20M 11n power offset per rate
	{169, 0x7777},
	{170, 0x7777},
	{171, 0x8888},
	{172, 0x8888},
	//2G 40M 11n power offset per rate
	{173, 0x8888},
	{174, 0x8888},
	{175, 0x8888},
	{176, 0x8888},
	//2G/5G CCD power set
	{201, 0x0000},
	//2G/5G STBC power set
	{202, 0x0000},
	//2G 40M OFDM power-offset
	{203, 0x0000},
    {0, 0}
};
//20150707, Mark add for 6362 modify calibration data for VMG3925B
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG3925B_BCM6362[] = {
#ifndef USE_CE_SROM_FOR_ELISA_PROJECT //for Generic project(Max power)
	//SubsystemID
	{2, 0x0566},
	//Board Rev
	{65, 0x1230},
	//antenna
	{78, 0x0303},
	{79, 0x0202},
	{80, 0xFF02},
	{87, 0x0315},
	{88, 0x0315},
	//2G, ant0, maxpower, PA
	{96, 0x204e},
	{97, 0xffda},
	{98, 0x1751},
	{99, 0xfac9},
	//2G, ant1, maxpower, PA
	{112, 0x204e},
	{113, 0xffa3},
	{114, 0x16d2},
	{115, 0xfab7},
	//2G Band CCK power
	{160, 0x0000},
	//2G Band 20 MHz Legacy rates power offsets
	{161, 0x0000},
	{162, 0x7531},
	//2G 20MHz MCS power offset
	{169, 0x1000},
	{170, 0x9753},
	{171, 0x1000},
	{172, 0x9753},
	//2G 40MHz MCS power offset
	{173, 0x1000},
	{174, 0x9753},
	{175, 0x1000},
	{176, 0x9753},
	//CDD power offset
	{201, 0x0000},
	//STBC power offset
	{202, 0x0000},
	//Additional 40 MHz OFDM power-offset
	{203, 0x0000},
	{204, 0x0000},
    {0, 0}
#else //for CE
	//SubsystemID
	{2, 0x0566},
	//Board Rev
	{65, 0x1230},
	//antenna
	{78, 0x0303},
	{79, 0x0202},
	{80, 0xff02},
	{87, 0x0315},
	{88, 0x0315},
	//2G, ant0, maxpower, PA
	{96, 0x2046},
	{97, 0xffda},
	{98, 0x1751},
	{99, 0xfac9},
	//5G, ant0, maxpower, PA
	{100, 0x3e30},
	{101, 0x403c},
	{102, 0xff43},
	{103, 0x1317},
	{104, 0xfb23},
	{108, 0xff43},
	{109, 0x1317},
	{110, 0xfb23},
	//2G, ant1, maxpower, PA
	{112, 0x2046},
	{113, 0xffa3},
	{114, 0x16d2},
	{115, 0xfab7},
	//5G, ant1, maxpower, PA
	{116, 0x3e30},
	{117, 0x403c},
	{118, 0xff80},
	{119, 0x12f0},
	{120, 0xfb15},
	{124, 0xff80},
	{125, 0x12f0},
	{126, 0xfb15},
	//2G Band 20 MHz Legacy rates power offsets
	{161, 0x0000},
	{162, 0x3100},
	//5G 20M power offset per rate
	{164, 0x0000},
	{166, 0x0000},
	{168, 0x0000},
	//2G 20MHz MCS power offset
	{169, 0x7777},
	{170, 0x7777},
	{171, 0x7777},
	{172, 0x7777},
	//2G 40MHz MCS power offset
	{173, 0x7777},
	{174, 0x7777},
	{175, 0x7777},
	{176, 0x7777},
	//5G 20M midband 11n power offset per rate
	{177, 0x0000},
	{178, 0x0000},
	{179, 0x0000},
	{180, 0x0000},
	//5G 20M lowband 11n power offset per rate
	{185, 0x0000},
	{186, 0x0000},
	{187, 0x0000},
	{188, 0x0000},
	//5G 20M highband 11n power offset per rate
	{193, 0x0000},
	{194, 0x0000},
	{195, 0x0000},
	{196, 0x0000},
	//CDD power offset
	{201, 0x0000},
	//STBC power offset
	{202, 0x0000},
	//Additional 40 MHz OFDM power-offset
	{203, 0x0000},
	{204, 0x0000},
	{0, 0}
#endif
};
//20161027, Mark add for 6362 modify calibration data for VMG8924_B10A
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG8924_B10A_BCM6362[] = {
    //SubsystemID
	{2, 0x05e2},
	//Board Rev
	{65, 0x1204},
	//boardflags, external LNA
	{66, 0x0200},
	{67, 0x0000},
	{79, 0x3a3a},
	{80, 0xffff},
	//FEM2G
	{87, 0x0315},
	//FEM5G
	{88, 0x0315},
	//EXTLNA gain
	{93, 0xffff},
	{94, 0x001e},
	//2G ant0 maxpower
	{96, 0x204a},
	//2G ant0 PA
	{97, 0xff96},
	{98, 0x17ff},
	{99, 0xfab6},
	//2G ant1 maxpower
	{112, 0x204a},
	//2G ant1 PA
	{113, 0xff84},
	{114, 0x17f8},
	{115, 0xfad4},
	//2G 20M power offset per rate
	{161, 0x0000},
	{162, 0x0000},
	//2G 20M 11n power offset per rate
	{169, 0x7777},
	{170, 0x7777},
	{171, 0x7777},
	{172, 0x7777},
	//2G 40M 11n power offset per rate
	{173, 0x7777},
	{174, 0x7777},
	{175, 0x7777},
	{176, 0x7777},
	//2G 40M OFDM power-offset
	{203, 0x2220},
	{0, 0}
};
//20150212, Cj_Lai add for modify calibration data for VMG9823
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG9823_BCM6362[] = {
	//SubsystemID
	{2, 0x05e2},
	//Board Rev
	{65, 0x1100},
	//boardflags, external LNA
	{66, 0x3200},
	{67, 0x8000},
	//FEM2G
	{87, 0x031f},
	//FEM5G
	{88, 0x031f},
	//EXTLNA gain
	{93, 0x0202},
	//2G ant0 maxpower
	{96, 0x206a},
	//2G ant0 PA
	{97, 0xfe7b},
	{98, 0x1ec3},
	{99, 0xf8b6},
	//5G ant0 maxpower
	{100, 0x3e40},
	//2G ant1 maxpower
	{112, 0x206a},
	//2G ant1 PA
	{113, 0xfe7f},
	{114, 0x1ed0},
	{115, 0xf8bd},
	//2G 20M power offset per rate
	{160, 0x0000},
	{161, 0x2222},
	{162, 0x2222},
	//5G ant1 maxpower
	{116, 0x3e40},
	//2G 20M 11n power offset per rate
	{169, 0x4444},
	{170, 0x4444},
	{171, 0x4444},
	{172, 0x4444},
	//2G 40M 11n power offset per rate
	{173, 0x4444},
	{174, 0x4444},
	{175, 0x4444},
	{176, 0x4444},
	//2G/5G CCD power set
	{201, 0x0000},
	//2G/5G STBC power set
	{202, 0x0000},
	//2G 40M OFDM power-offset
	{203, 0x0000},
    {0, 0}
};
//20150720, Mark add for modify calibration data for VMG3925
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG3925_BCM6362[] = {
	//boardflags
	{66, 0x3200}, // Bit12=external LNA
	{67, 0x8000},
	//antenna
	{78, 0x0003},
	{79, 0x0000},
	{80, 0x0000},
	{87, 0x031f},
	{88, 0x031f},
	//EXTLNA gain,elna2g
	{93, 0x0202},
	//2G ant0 maxpower
	{96, 0x2067},
	//2G ant0 PA
	{97, 0xfe8e}, // 97, 0xfe36, 
	{98, 0x1e5d}, // 98, 0x1976,
	{99, 0xf8f3}, // 99, 0xf9a2,
	//2G ant1 maxpower
	{112, 0x2067},
	//2G ant1 PA
	{113, 0xfe6f}, // 113, 0xfe67,
	{114, 0x1de8}, // 114, 0x1990,
	{115, 0xf8c8}, // 115, 0xf9d3,
	//2G 20M power offset per rate
	{160, 0x2222},
	{161, 0x2222},
	{162, 0x2222},
	//2G 20M 11n power offset per rate
	{169, 0x4444},
	{170, 0x4444},
	{171, 0x4444},
	{172, 0x4444},
	//2G 40M 11n power offset per rate
	{173, 0x4444},
	{174, 0x4444},
	{175, 0x4444},
	{176, 0x4444},
	//2G/5G CCD power set
	{201, 0x0000},
	//2G/5G STBC power set
	{202, 0x0000},
	//2G 40M OFDM power-offset 
	{203, 0x0000},
    {0, 0}
};
//20161027, Mark add for 6362 modify calibration data for VMG8924_B10D
static WLAN_SROM_ENTRY wlan_patch_unique_963167_VMG8924_B10D_BCM6362[] = {
  //2.4G ant0
  {97, 0x0096},
  {98, 0x196f},
  {99, 0xfc7c},
  //2.4G ant1
  {113, 0xfff4},
  {114, 0x1879},
  {115, 0xfba0},
  {0, 0}
};


/*** ZyXEL Project for SROM patch (BCM4360, 963168) ***/
// 20161027, Mark for BCM4360 chip commmon SROM patch
static WLAN_SROM_ENTRY wlan_patch_common_963168_BCM4360[] = {
    {0, 0}
};
//20150720, Mark add for modify calibration data for VMG8948, wifi 5G (BCM4360)
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG8948_BCM4360[] = {
	{104, 0x0000},
	{105, 0x0000},
	{106, 0x0000},
	//5G ant0 maxpower
	{114, 0x4c4c},
	{115, 0x4c4c},
	//5G ant0 PA
	{116, 0xff52},
	{117, 0x16f0},
	{118, 0xfd22},
	{119, 0xff55},
	{120, 0x1687},
	{121, 0xfd41},
	{122, 0xff2d},
	{123, 0x162c},
	{124, 0xfd10},
	{125, 0xff40},
	{126, 0x1687},
	{127, 0xfd2a},
	//5G ant1 maxpower
	{134, 0x4c4c},
	{135, 0x4c4c},
	//5G ant1 PA
	{136, 0xff49},
	{137, 0x16b2},
	{138, 0xfd20},
	{139, 0xff44},
	{140, 0x1646},
	{141, 0xfd32},
	{142, 0xff47},
	{143, 0x16df},
	{144, 0xfd25},
	{145, 0xff4b},
	{146, 0x1749},
	{147, 0xfd1c},
	//5G ant2 maxpower
	{154, 0x4c4c},
	{155, 0x4c4c},
	//5G ant2 PA
	{156, 0xff5e},
	{157, 0x176d},
	{158, 0xfd22},
	{159, 0xff61},
	{160, 0x177b},
	{161, 0xfd2d},
	{162, 0xff72},
	{163, 0x1870},
	{164, 0xfd27},
	{165, 0xff6c},
	{166, 0x1853},
	{167, 0xfd2c},
	//5G lowband 11ag/11n/11ac power offset per rate
	{176, 0x5420}, //20M
	{177, 0x9876},
	{178, 0x6542}, //40M
	{179, 0xa987},
	{180, 0x6554}, //80M
	{181, 0xa987},
	{182, 0x0000}, //160M
	{183, 0x0000},
	//5G midband 11ag/11n/11ac power offset per rate
	{184, 0x6420}, //20M
	{185, 0xcca8},
	{186, 0x6420}, //40M
	{187, 0xcca8},
	{188, 0x6420}, //80M
	{189, 0xcca8},
	{190, 0x0000}, //160M
	{191, 0x0000},
	//5G highband 11ag/11n/11ac power offset per rate
	{192, 0x6420}, //20M
	{193, 0xcca8},
	{194, 0x6420}, //40M
	{195, 0xcca8},
	{196, 0x6420}, //80M
	{197, 0xcca8},
	{198, 0x0000}, //160M
	{199, 0x0000},
	//5G 11ag/11n/11ac QPSK power offset
	{200, 0x0010}, //lowband
	{201, 0x0000}, //midband
	{202, 0x0000}, //highband
	//16/64 QAM power offset
	{203, 0x00b0},
	{204, 0x000b},
	{205, 0x000c},
	{210, 0x00f0},
	{211, 0x000f},
	{217, 0x00c0},
    {0, 0}
};
//20161027, Mark add for BCM4360 modify calibration data for VMG8924_B10A
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG8924_B10A_BCM4360[] = {
    {81, 0x3a3a},
	{82, 0x3a3a},
	{83, 0x3a3a},
	{101, 0x4226},
	{102, 0x7621},
	{103, 0x309c},
	{104, 0x0000},
	{105, 0x0000},
	{106, 0x0000},
	//5G ant0 PA
	{116, 0xff31},
	{117, 0x15c1},
	{118, 0xfd1a},
	{119, 0xff4f},
	{120, 0x1695},
	{121, 0xfd30},
	{122, 0xff3a},
	{123, 0x158f},
	{124, 0xfd34},
	{125, 0xff59},
	{126, 0x1652},
	{127, 0xfd41},
	//5G ant1 PA
	{136, 0xff55},
	{137, 0x1688},
	{138, 0xfd3c},
	{139, 0xff53},
	{140, 0x1668},
	{141, 0xfd37},
	{142, 0xff4e},
	{143, 0x153c},
	{144, 0xfd47},
	{145, 0xff55},
	{146, 0x156a},
	{147, 0xfd50},
	//5G ant2 PA
	{156, 0xff21},
	{157, 0x1570},
	{158, 0xfd23},
	{159, 0xff4A},
	{160, 0x16DA},
	{161, 0xfd2D},
	{162, 0xff4C},
	{163, 0x1697},
	{164, 0xfd35},
	{165, 0xff41},
	{166, 0x1519},
	{167, 0xfd46},
	//5G lowband 11ag/11n/11ac power offset per rate
	{176, 0x5000}, //20M
	{177, 0x9955},
	{178, 0x5000}, //40M
	{179, 0x9955},
	{180, 0x5000}, //80M
	{181, 0x9955},
	//5G midband 11ag/11n/11ac power offset per rate
	{184, 0x5000}, //20M
	{185, 0x9955},
	{186, 0x5000}, //40M
	{187, 0x9955},
	{188, 0x5000}, //80M
	{189, 0x9955},
	//5G highband 11ag/11n/11ac power offset per rate
	{192, 0x5000}, //20M
	{193, 0x9955},
	{194, 0x5000}, //40M
	{195, 0x9955}, 
	{196, 0x5000}, //80M
	{197, 0x9955},
	{0, 0}
};


/*** ZyXEL Project for SROM patch (BCM43602, 963168) ***/
// 20161027, Mark for BCM43602 chip commmon SROM patch
static WLAN_SROM_ENTRY wlan_patch_common_963168_BCM43602[] = {
#ifdef ZYXEL_FORCE_WIFI_SROM
	// 20161103, Workaround for 43602, because driver will sync MAC address
	// Broadcom was set MAC address to zero in this version(7.14.164.301, impl24)
	// It will cause force SROM feature cannot work. So workaround to fix MAC address to SROM
	// MAC Address
	{72, 0x1C74},
	{73, 0x0D00},
	{74, 0x0000},
#endif
    {0, 0}
};
//20150720, Mark add for modify calibration data for VMG3926, wifi 5G (BCM43602)
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG3926_BCM43602[] = {
	{65, 0x1121}, //rev
	//5G ant0 maxpower
	{114, 0x5454},
	{115, 0x5454},
	//5G ant0 PA
	{116, 0xff25},
	{117, 0x16ee},
	{118, 0xfd1d},
	{119, 0xff30},
	{120, 0x1703},
	{121, 0xfd30},
	{122, 0xff2f},
	{123, 0x16c4},
	{124, 0xfd3a},
	{125, 0xff20},
	{126, 0x167b},
	{127, 0xfd2a},
	//5G ant1 maxpower
	{134, 0x5454},
	{135, 0x5454},
	//5G ant1 PA
	{136, 0xff38},
	{137, 0x16af},
	{138, 0xfd44},
	{139, 0xff49},
	{140, 0x17c3},
	{141, 0xfd4b},
	{142, 0xff2c},
	{143, 0x1747},
	{144, 0xfd22},
	{145, 0xff3d},
	{146, 0x17cf},
	{147, 0xfd2c},
	//5G ant2 maxpower
	{154, 0x5454},
	{155, 0x5454},
	//5G ant2 PA
	{156, 0xff46},
	{157, 0x1689},
	{158, 0xfd5d},
	{159, 0xff3c},
	{160, 0x1722},
	{161, 0xfd45},
	{162, 0xff33},
	{163, 0x1703},
	{164, 0xfd35},
	{165, 0xff38},
	{166, 0x172c},
	{167, 0xfd39},
	//5G lowband 11ag/11n/11ac power offset per rate
	{176, 0x8640}, //20M
	{177, 0xaaa9},
	{178, 0x9862}, //40M
	{179, 0xbbba},
	{180, 0x9874}, //80M
	{181, 0xbbba},
	{182, 0x0000}, //160M
	{183, 0x0000},
	//5G midband 11ag/11n/11ac power offset per rate
	{184, 0x8640}, //20M
	{185, 0xaaa9},
	{186, 0x9862}, //40M
	{187, 0xbbba},
	{188, 0x9874}, //80M
	{189, 0xbbba},
	{190, 0x0000}, //160M
	{191, 0x0000},
	//5G highband 11ag/11n/11ac power offset per rate
	{192, 0x8640}, //20M
	{193, 0xaaa9},
	{194, 0x9862}, //40M
	{195, 0xbbba},
	{196, 0x9874}, //80M
	{197, 0xbbba},
	{198, 0x0000}, //160M
	{199, 0x0000},
	//5G 11ag/11n/11ac QPSK power offset
	{200, 0x0222}, //lowband
	{201, 0x0222}, //midband
	{202, 0x0222}, //highband
    {0, 0}
};
//20150720, Mark add for modify calibration data for VMG8924, wifi 5G (BCM43602)
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG8924_BCM43602[] = {
	{65, 0x1121}, //rev
	//5G ant0 maxpower
	{114, 0x5454},
	{115, 0x5454},
	//5G ant0 PA
	{116, 0xff25},
	{117, 0x16ee},
	{118, 0xfd1d},
	{119, 0xff30},
	{120, 0x1703},
	{121, 0xfd30},
	{122, 0xff2f},
	{123, 0x16c4},
	{124, 0xfd3a},
	{125, 0xff20},
	{126, 0x167b},
	{127, 0xfd2a},
	//5G ant1 maxpower
	{134, 0x5454},
	{135, 0x5454},
	//5G ant1 PA
	{136, 0xff38},
	{137, 0x16af},
	{138, 0xfd44},
	{139, 0xff49},
	{140, 0x17c3},
	{141, 0xfd4b},
	{142, 0xff2c},
	{143, 0x1747},
	{144, 0xfd22},
	{145, 0xff3d},
	{146, 0x17cf},
	{147, 0xfd2c},
	//5G ant2 maxpower
	{154, 0x5454},
	{155, 0x5454},
	//5G ant2 PA
	{156, 0xff46},
	{157, 0x1689},
	{158, 0xfd5d},
	{159, 0xff3c},
	{160, 0x1722},
	{161, 0xfd45},
	{162, 0xff33},
	{163, 0x1703},
	{164, 0xfd35},
	{165, 0xff38},
	{166, 0x172c},
	{167, 0xfd39},
	//5G lowband 11ag/11n/11ac power offset per rate
	{176, 0x8640}, //20M
	{177, 0xaaa9},
	{178, 0x9862}, //40M
	{179, 0xbbba},
	{180, 0x9874}, //80M
	{181, 0xbbba},
	{182, 0x0000}, //160M
	{183, 0x0000},
	//5G midband 11ag/11n/11ac power offset per rate
	{184, 0x8640}, //20M
	{185, 0xaaa9},
	{186, 0x9862}, //40M
	{187, 0xbbba},
	{188, 0x9874}, //80M
	{189, 0xbbba},
	{190, 0x0000}, //160M
	{191, 0x0000},
	//5G highband 11ag/11n/11ac power offset per rate
	{192, 0x8640}, //20M
	{193, 0xaaa9},
	{194, 0x9862}, //40M
	{195, 0xbbba},
	{196, 0x9874}, //80M
	{197, 0xbbba},
	{198, 0x0000}, //160M
	{199, 0x0000},
	//5G 11ag/11n/11ac QPSK power offset
	{200, 0x0222}, //lowband
	{201, 0x0222}, //midband
	{202, 0x0222}, //highband
    {0, 0}
};
//20150720, Mark add for modify calibration data for VMG3925, wifi 5G (BCM43602)
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG3925_BCM43602[] = {
	//5G ant0 maxpower
	{114, 0x5858},
	{115, 0x5858},
	//5G ant0 PA
	{116, 0xff36},
	{117, 0x1794},
	{118, 0xfd35},
	{119, 0xff37},
	{120, 0x173c},
	{121, 0xfd3f},
	{122, 0xff30},
	{123, 0x1700},
	{124, 0xfd3e},
	{125, 0xff3d},
	{126, 0x17e1},
	{127, 0xfd34},
	//5G ant1 maxpower
	{134, 0x5858},
	{135, 0x5858},
	//5G ant1 PA
	{136, 0xff3f},
	{137, 0x1810},
	{138, 0xfd38},
	{139, 0xff40},
	{140, 0x17bd},
	{141, 0xfd3d},
	{142, 0xff48},
	{143, 0x17cf},
	{144, 0xfd44},
	{145, 0xff51},
	{146, 0x183a},
	{147, 0xfd46},
	//5G ant2 maxpower
	{154, 0x5858},
	{155, 0x5858},
	//5G ant2 PA
	{156, 0xff2f},
	{157, 0x170b},
	{158, 0xfd40},
	{159, 0xff32},
	{160, 0x16fe},
	{161, 0xfd41},
	{162, 0xff39},
	{163, 0x177f},
	{164, 0xfd3b},
	{165, 0xff3d},
	{166, 0x17ef},
	{167, 0xfd32},
	//5G lowband 11ag/11n/11ac power offset per rate
	{176, 0x4000}, //20M
	{177, 0x8844},
	{178, 0x4000}, //40M
	{179, 0x8844},
	{180, 0x4000}, //80M
	{181, 0x8844},
	{182, 0x0000}, //160M
	{183, 0x0000},
	//5G midband 11ag/11n/11ac power offset per rate
	{184, 0x4000}, //20M
	{185, 0x8844},
	{186, 0x4000}, //40M
	{187, 0x8844},
	{188, 0x4000}, //80M
	{189, 0x8844},
	{190, 0x0000}, //160M
	{191, 0x0000},
	//5G highband 11ag/11n/11ac power offset per rate
	{192, 0x4000}, //20M
	{193, 0x8844},
	{194, 0x4000}, //40M
	{195, 0x8844},
	{196, 0x4000}, //80M
	{197, 0x8844},
	{198, 0x0000}, //160M
	{199, 0x0000},
	//5G 11ag/11n/11ac QPSK power offset
	{200, 0x0000}, //lowband
	{201, 0x0000}, //midband
	{202, 0x0000}, //highband
    {0, 0}
};
//20150707, Mark add for 43602 modify calibration data for VMG3925B
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG3925B_BCM43602[] = {
#ifndef USE_CE_SROM_FOR_ELISA_PROJECT //for Generic project(Max power)
	//PD offset
	{81, 0x0202},
	{82, 0x0202},
	{83, 0x0202},	
	{101, 0x0000},
	{102, 0x0000},
	{103, 0x0000},
	{104, 0x0000},
	{105, 0x0000},
	{106, 0x0000},
	//5G, ant0, maxpower, PA
	{114, 0x5a5a},
	{115, 0x5a5a},
	{116, 0xff4a},
	{117, 0x181e},
	{118, 0xfd2c},
	{119, 0xff33},
	{120, 0x1761},
	{121, 0xfd20},
	{122, 0xff38},
	{123, 0x171e},
	{124, 0xfd33},
	{125, 0xff3f},
	{126, 0x1765},
	{127, 0xfd30},
	//5G, ant1, maxpower, PA
	{134, 0x5a5a},
	{135, 0x5a5a},
	{136, 0xff47},
	{137, 0x17ec},
	{138, 0xfd2f},
	{139, 0xff37},
	{140, 0x1735},
	{141, 0xfd30},
	{142, 0xff33},
	{143, 0x1721},
	{144, 0xfd2a},
	{145, 0xff37},
	{146, 0x171f},
	{147, 0xfd36},
	//5G, ant2, maxpower, PA
	{154, 0x5a5a},
	{155, 0x5a5a},
	{156, 0xff2a},
	{157, 0x172f},
	{158, 0xfd1f},
	{159, 0xff3a},
	{160, 0x17c5},
	{161, 0xfd26},
	{162, 0xff42},
	{163, 0x17f6},
	{164, 0xfd29},
	{165, 0xff2c},
	{166, 0x16ca},
	{167, 0xfd2e},
	//5G, mcsbw205glpo
	{176, 0x0000},
	{177, 0x7531},
	//5G, mcsbw405glpo
	{178, 0x0000},
	{179, 0x7531},
	//5G, mcsbw805glpo
	{180, 0x0000},
	{181, 0x9753},
	//5G, mcsbw205gmpo
	{184, 0x0000},
	{185, 0x7531},
	//5G, mcsbw405gmpo
	{186, 0x0000},
	{187, 0x7531},
	//5G, mcsbw805gmpo
	{188, 0x0000},
	{189, 0x9753},
	//5G, mcsbw205ghpo
	{192, 0x0000},
	{193, 0x7531},
	//5G, mcsbw405ghpo
	{194, 0x0000},
	{195, 0x7531},
	//5G, mcsbw805ghpo
	{196, 0x0000},
	{197, 0x9753},
	{0, 0}
#else // for CE
	//PD offset
	{101, 0x0000},
	{102, 0x0000},
	{103, 0x0000},
	{104, 0x0000},
	{105, 0x0000},
	{106, 0x0000},
	//5G, ant0, maxpower, PA
	{113, 0xb300},
	{114, 0x4646},
	{115, 0x4e4e},
	{116, 0xff3b},
	{117, 0x1769},
	{118, 0xfd31},
	{119, 0xff34},
	{120, 0x16e3},
	{121, 0xfd39},
	{122, 0xff45},
	{123, 0x17ac},
	{124, 0xfd34},
	{125, 0xff3f},
	{126, 0x1700},
	{127, 0xfd41},
	//5G, ant1, maxpower, PA
	{133, 0xb300},
	{134, 0x4646},
	{135, 0x4e4e},
	{136, 0xff44},
	{137, 0x1803},
	{138, 0xfd28},
	{139, 0xff2a},
	{140, 0x16a0},
	{141, 0xfd34},
	{142, 0xff4d},
	{143, 0x18b3},
	{144, 0xfd18},
	{145, 0xff34},
	{146, 0x1737},
	{147, 0xfd2d},
	//5G, ant2, maxpower, PA
	{153, 0xb300},
	{154, 0x4646},
	{155, 0x4e4e},
	{156, 0xff40},
	{157, 0x1789},
	{158, 0xfd31},
	{159, 0xff3b},
	{160, 0x16e8},
	{161, 0xfd42},
	{162, 0xff32},
	{163, 0x165e},
	{164, 0xfd41},
	{165, 0xff46},
	{166, 0x16b7},
	{167, 0xfd4c},
	//5G, mcsbw205glpo
	{176, 0x0000},
	{177, 0x0000},
	//5G, mcsbw405glpo
	{178, 0x0000},
	{179, 0x3100},
	//5G, mcsbw805glpo
	{180, 0x0000},
	{181, 0x3100},
	//5G, mcsbw205gmpo
	{184, 0x0000},
	{185, 0x0000},
	//5G, mcsbw405gmpo
	{186, 0x0000},
	{187, 0x3100},
	//5G, mcsbw805gmpo
	{188, 0x0000},
	{189, 0x3100},
	//5G, mcsbw205ghpo
	{192, 0x0000},
	{193, 0x0000},
	//5G, mcsbw405ghpo
	{194, 0x0000},
	{195, 0x3100},
	//5G, mcsbw805ghpo
	{196, 0x0000},
	{197, 0x3100},
	{0, 0}
#endif
};
//20150720, Mark add for modify calibration data for VMG3926B, wifi 5G (BCM43602)
static WLAN_SROM_ENTRY wlan_patch_unique_963168_VMG3926B_BCM43602[] = {
    {0, 0}
};
//20161027, Mark add for 43602 modify calibration data for VMG8924_B10D
static WLAN_SROM_ENTRY wlan_patch_unique_963167_VMG8924_B10D_BCM43602[] = {
  //5G ant0 PA
  {116, 0xff4c},
  {117, 0x1804},
  {118, 0xfd41},
  {119, 0xff1e},
  {120, 0x16b1},
  {121, 0xfd12},
  {122, 0xff33},
  {123, 0x171e},
  {124, 0xfd1f},
  {125, 0xff24},
  {126, 0x170b},
  {127, 0xfd16},
  //5G ant1 PA
  {136, 0xff30},
  {137, 0x179d},
  {138, 0xfd16},
  {139, 0xff3d},
  {140, 0x1794},
  {141, 0xfd2c},
  {142, 0xff20},
  {143, 0x16f2},
  {144, 0xfd01},
  {145, 0xff3c},
  {146, 0x17f0},
  {147, 0xfd26},
  //5G ant2 PA
  {156, 0xff56},
  {157, 0x1707},
  {158, 0xfd65},
  {159, 0xff17},
  {160, 0x161a},
  {161, 0xfd11},
  {162, 0xff40},
  {163, 0x167d},
  {164, 0xfd4b},
  {165, 0xff43},
  {166, 0x16b2},
  {167, 0xfd59},
  {0, 0}
};
#endif

static WLAN_SROM_ENTRY wlan_patch_unique_963167REF2[] = {
    {97,  0xfe97},
    {98,  0x189e},
    {99,  0xfa0c},
    {113, 0xfe8b},
    {114, 0x187b},
    {115, 0xfa0a},
    {0, 0}
};

#endif

#if defined(_BCM96838_) || defined(CONFIG_BCM96838)
/* The unique part contains the subSytemId (boardId) and the BoardRev number */
static WLAN_SROM_ENTRY wlan_patch_unique_968380GERG[] = {
    {   2, 0x05e9},
    {  65, 0x1256},
    {0, 0}
};

/* The common part contains the entries that are valid for multiple boards */
static WLAN_SROM_ENTRY wlan_patch_common_968380GERG[] = {
    { 113, 0xfe94},
    { 114, 0x1904},
    { 115, 0xfa18},
    { 162, 0x4444},
    { 170, 0x4444},
    { 172, 0x4444},
    {0, 0}
};
#endif
#if defined(_BCM96318_) || defined(CONFIG_BCM96318)
static WLAN_SROM_ENTRY wlan_patch_unique_6318REF[] = {
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_96318REF[] = {
    { 97,  0xfe6e}, 
    { 98,  0x178c},
    { 99,  0xfa64},
    { 113, 0xfe5a},
    { 114, 0x171c},
    { 115, 0xfa5a},
    {0, 0}
};
#endif

#if defined(_BCM963138_) || defined(CONFIG_BCM963138)
static WLAN_SROM_ENTRY wlan_patch_unique_963138REF[] = {
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963138REF[] = {
    { 66,  0x200},
    { 68,  0x9800},
    { 87,  0x41f},
    { 96,  0x204A},
    { 97,  0xFE9B}, 
    { 98,  0x17D5},
    { 99,  0xFAAD},
    { 112, 0x204A},
    { 113, 0xFE74},
    { 114, 0x1646},
    { 115, 0xFAC2},
    { 162, 0x4444},
    { 170, 0x4444},
    { 172, 0x4444},
    {0, 0}
};

#if defined(ZYXEL) && (ZYXEL==1)
/*** ZyXEL Project for SROM patch (BCM43217, 963138) ***/
// 20161027, Mark for BCM43217 chip commmon SROM patch
static WLAN_SROM_ENTRY wlan_patch_common_963138_BCM43217[] = {
    {0, 0}
};
//20161027, Mark add for 43217 modify calibration data for FMG3586
static WLAN_SROM_ENTRY wlan_patch_unique_FMG3586_BCM43217[] = {
    {0, 0}
};
//20161027, Mark add for 43217 modify calibration data for FMG3086
static WLAN_SROM_ENTRY wlan_patch_unique_FMG3086_BCM43217[] = {
    {0, 0}
};
//20161027, Mark add for 43217 modify calibration data for XMG3512_B10A
static WLAN_SROM_ENTRY wlan_patch_unique_XMG3512_B10A_BCM43217[] = {
	{  2,  0x062b},
	{ 65,  0x1204},
	{ 66,  0x1200},
	{ 67,  0x8000},
	{ 68,  0x1800},
	{ 76,  0x83ff},
	{ 87,  0x051f},
	{ 93,  0x0002},
	//2G ant0 maxpower, PA
	{ 96,  0x2068},
    { 97,  0xfe89},
    { 98,  0x1a97},
    { 99,  0xfa00},
	//2G ant1 maxpower, PA
	{ 112, 0x2068},
    { 113, 0xfecd},
    { 114, 0x1b04},
    { 115, 0xfa5b},
    {0, 0}
};
//20161027, Mark add for 43217 modify calibration data for VMG8823_B10B
static WLAN_SROM_ENTRY wlan_patch_unique_VMG8823_B10B_BCM43217[] = {
	//2G ant0 maxpower, PA
	{97, 0xfe9f},
	{98, 0x1920},
	{99, 0xfa5e},
	//2G ant1 maxpower, PA
	{113, 0xfeab},
	{114, 0x185a},
	{115, 0xfa94},
	//5G Idle Target TSSI / midband Max Power 
	{132, 0xff44},
	{148, 0xff44},
	//2G 20M MCS SISO OFDM power offsets
	{161, 0x7766},
	{162, 0x9988},
	//2G 20M 11n power offset per rate
	{169, 0x7766},
	{170, 0x9988},
	{171, 0x7766},
	{172, 0x9988},
	//2G 40M 11n power offset per rate
	{173, 0x7766},
	{174, 0x9988},
	{175, 0x7766},
	{176, 0x9988},
    {0, 0}
};


/*** ZyXEL Project for SROM patch (BCM4366, 963138) ***/
// 20161027, Mark for BCM4366C0 chip commmon SROM patch
static WLAN_SROM_ENTRY wlan_patch_common_963138_BCM4366[] = {
    {0, 0}
};
// PEGA 20160801, BCM4366C0
static WLAN_SROM_ENTRY wlan_patch_unique_VMG8823_B10B_BCM4366[] = {
	// PCI subsystem ID 
	{2, 0x077d},
	// PCI device ID 
	{48, 0x43c5},
	// Board Rev
	{65, 0x1145},
	// boardflags, bit12 : extlna_2g
	{66, 0x0000},
	// fem_cfg2
	{86, 0x0031},
	// PD Offset 2G 20 in 40M
	{94, 0xffff},
	{95, 0xffff},
	// rxgains
	{97, 0xabab},
	// PD Offset 5G 20 in 40M
	{98, 0x0000},
	{99, 0x0000},
	// rpcal
	{101, 0x0000},
	{102, 0x0000},
	{103, 0x0000},
	// PD Offset 5G 40 in 80M
	{105, 0x0000},
	{106, 0x0000},
	// MCS 
	{108, 0xffff},
	{109, 0x3142},
	{110, 0x3131},
	{111, 0x3142},
	{112, 0x3131},
	{113, 0x3142},
	{114, 0x3131},
	{115, 0x3142},
	{116, 0x3131},
	{117, 0x3142},
	{118, 0x3131},
	{119, 0x7654},
	{120, 0xdb98},
	{121, 0x7654},
	{122, 0xdb98},
	{123, 0x7654},
	{124, 0xdb98},
	{125, 0x7654},
	{126, 0xdb98},
	{127, 0x7654},
	{128, 0xdb98},
	{135, 0x0000},
	{136, 0x0000},
	{137, 0x0000},
	{138, 0x0000},
	{139, 0xfefe},
	{140, 0xfefe},
	{141, 0xfefe},
	{142, 0xfefe},
	{167, 0xffff},  
	{168, 0x0000},
	{169, 0x0000},
	{170, 0x7222},
	{171, 0x9977},
	{172, 0x7222},
	{173, 0x9977},
	{174, 0x7722},
	{175, 0x0022},
	// MCS 5G low sb
	{176, 0x7530}, 
	{177, 0xca98},
	{178, 0x7652},
	{179, 0xca98},
	{180, 0x7650},
	{181, 0xdb98},
	// rpcal2g 
	{182, 0x0000},
	// rpcal5gb0 
	{183, 0x0000},
	// MCS 5G mid sb
	{184, 0x7530},
	{185, 0xca98},
	{186, 0x7652},
	{187, 0xca98},
	{188, 0x7651},
	{189, 0xdb98},
	// rpcal5gb1
	{190, 0x0000},
	// rpcal5gb2 
	{191, 0x0000},
	// MCS 5G high sb
	{192, 0x7530},
	{193, 0xca98},
	{194, 0x7653},
	{195, 0xca98},
	{196, 0x7652}, 
	{197, 0xdb98},
	// rpcal5gb3
	{198, 0x0000},
	// rxgainerr5gl
	{228, 0x0004},
	// rxgainerr5gm
	{229, 0x0004},
	// rxgainerr5gh
	{230, 0x0008},
	// rxgainerr5gu
	{231, 0x0008},
	// MCS 5G X1po
	{234, 0x7530},
	{235, 0xca98},
	{236, 0x7653},
	{237, 0xca98},
	{238, 0x7653},
	{239, 0xdb98},
	// MCS 5G X2po
	{245, 0x7531},
	{246, 0xca98},
	{247, 0x7654},
	{248, 0xca98},
	{249, 0x7654},
	{250, 0xdb98},
	// maxp5gb4/maxp2ga0
	{256, 0x5e54},
	// PA 2G 20M, a0
	{257, 0xffff},
	{258, 0xffff},
	{259, 0xffff},
	{260, 0xffff},
	// rxgains0core0
	{261, 0xabab},
	// maxp5gb0/maxp5gb1
	{262, 0x5e5e},
	// maxp5gb2/maxp5gb3
	{263, 0x5e5e},
	// PA 5G 20M, a0
	{264, 0x1927},
	{265, 0xd194},
	{266, 0x173f},
	{267, 0x23a9},
	{268, 0x18ed},
	{269, 0xd290},
	{270, 0x17a1},
	{271, 0x235b},
	{272, 0x18f1},
	{273, 0xd388},
	{274, 0x184e},
	{275, 0x23ac},
	{276, 0x18f4},
	{277, 0xd61e},
	{278, 0x1cb7},
	{279, 0x2459},
	{280, 0x18ea},
	{281, 0xd8e7},
	{282, 0x214e},
	{283, 0x2515},
	// PA 2G 40M, a0
	{284, 0xffff},
	{285, 0xffff},
	{286, 0xffff},
	{287, 0xffff},
	// PA 5G 40M, a0
	{288, 0x18c2},
	{289, 0xdb34},
	{290, 0x1ed8},
	{291, 0x238b},
	{292, 0x18b3},
	{293, 0xdd00},
	{294, 0x22f1},
	{295, 0x245f},
	{296, 0x186c},
	{297, 0xe0e9},
	{298, 0x2882},
	{299, 0x24f6},
	{300, 0x1873},
	{301, 0xe623},
	{302, 0x3828},
	{303, 0x2770},
	{304, 0x1856},
	{305, 0xe72f},
	{306, 0x344b},
	{307, 0x2681},
	// PA 5G 80M, a0
	{308, 0x199e},
	{309, 0xe2dd},
	{310, 0x362b},
	{311, 0x27b2},
	{312, 0x19fb},
	{313, 0xd4ab},
	{314, 0x122c},
	{315, 0x20d4},
	{316, 0x19da},
	{317, 0xd832},
	{318, 0x1662},
	{319, 0x21d6},
	{320, 0x18e4},
	{321, 0xeb63},
	{322, 0x4591},
	{323, 0x291f},
	{324, 0x1905},
	{325, 0xe8c2},
	{326, 0x37f4},
	{327, 0x2706},
	// maxp5gb4/maxp2ga1
	{328, 0x5e54},
	// PA 2G 20M, a1
	{329, 0xffff},
	{330, 0xffff},
	{331, 0xffff},
	{332, 0xffff},
	// rxgains0core1
	{333, 0xabab},
	// maxp5gb0/maxp5gb1
	{334, 0x5e5e},
	// maxp5gb2/maxp5gb3
	{335, 0x5e5e},
	// PA 5G 20M, a1
	{336, 0x18f9},
	{337, 0xcedb},
	{338, 0x0efd},
	{339, 0x20fc},
	{340, 0x18f3},
	{341, 0xd0e6},
	{342, 0x1527},
	{343, 0x238d},
	{344, 0x18fd},
	{345, 0xd1f6},
	{346, 0x157a},
	{347, 0x233c},
	{348, 0x18ec},
	{349, 0xd2c1},
	{350, 0x1514},
	{351, 0x228a},
	{352, 0x1919},
	{353, 0xd3c4},
	{354, 0x16e4},
	{355, 0x232f},
	// PA 2G 40M, a1
	{356, 0xffff},
	{357, 0xffff},
	{358, 0xffff},
	{359, 0xffff},
	// PA 5G 40M, a1
	{360, 0x18a0},
	{361, 0xde4f},
	{362, 0x2d6d},
	{363, 0x2740},
	{364, 0x18aa},
	{365, 0xdd4b},
	{366, 0x273f},
	{367, 0x25b6},
	{368, 0x1896},
	{369, 0xddc4},
	{370, 0x2696},
	{371, 0x2595},
	{372, 0x189e},
	{373, 0xe029},
	{374, 0x2a50},
	{375, 0x25c5},
	{376, 0x18bd},
	{377, 0xdd3e},
	{378, 0x1f68},
	{379, 0x23ac},
	// PA 5G 80M, a1
	{380, 0x1953},
	{381, 0xe5a6},
	{382, 0x45a8},
	{383, 0x2a7e},
	{384, 0x1977},
	{385, 0xdf79},
	{386, 0x2c99},
	{387, 0x266a},
	{388, 0x1959},
	{389, 0xe3c0},
	{390, 0x3ca6},
	{391, 0x291d},
	{392, 0x1925},
	{393, 0xe3ff},
	{394, 0x343b},
	{395, 0x2766},
	{396, 0x1921},
	{397, 0xe5ff},
	{398, 0x3561},
	{399, 0x2704},
	// maxp5gb4/maxp2ga2
	{400, 0x5e54},
	// PA 2G 20M, a2
	{401, 0xffff},
	{402, 0xffff},
	{403, 0xffff},
	{404, 0xffff},
	// rxgains0core2
	{405, 0xabab},
	// maxp5gb0/maxp5gb1
	{406, 0x5e5e},
	// maxp5gb2/maxp5gb3
	{407, 0x5e5e},
	// PA 5G 20M, a2
	{408, 0x190f},
	{409, 0xd0fa},
	{410, 0x153c},
	{411, 0x2353},
	{412, 0x191e},
	{413, 0xd2b3},
	{414, 0x1862},
	{415, 0x2418},
	{416, 0x192b},
	{417, 0xd42f},
	{418, 0x1ba4},
	{419, 0x24b0},
	{420, 0x1945},
	{421, 0xd3cb},
	{422, 0x1754},
	{423, 0x2307},
	{424, 0x1907},
	{425, 0xe0c0},
	{426, 0x4daf},
	{427, 0x2e97},
	// PA 2G 40M, a2
	{428, 0xffff},
	{429, 0xffff},
	{430, 0xffff},
	{431, 0xffff},
	// PA 5G 40M, a2
	{432, 0x18f0},
	{433, 0xd93e},
	{434, 0x1aa3},
	{435, 0x22cc},
	{436, 0x18ce},
	{437, 0xdf51},
	{438, 0x2e27},
	{439, 0x2715},
	{440, 0x18c4},
	{441, 0xe098},
	{442, 0x2d06},
	{443, 0x2642},
	{444, 0x18a4},
	{445, 0xe4c4},
	{446, 0x364a},
	{447, 0x276c},
	{448, 0x1895},
	{449, 0xe8cd},
	{450, 0x40d6},
	{451, 0x28d4},
	// PA 5G 80M, a2
	{452, 0x1a03},
	{453, 0xd9c4},
	{454, 0x1e79},
	{455, 0x23fb},
	{456, 0x199e},
	{457, 0xe2f3},
	{458, 0x3971},
	{459, 0x2886},
	{460, 0x1959},
	{461, 0xeb57},
	{462, 0x5251},
	{463, 0x2b49},
	{464, 0x19b3},
	{465, 0xe03c},
	{466, 0x288d},
	{467, 0x2582},
	{468, 0x1957},
	{469, 0xea4b},
	{470, 0x47bc},
	{471, 0x29f6},
	// PD Offest
	{472, 0xffff},
	{473, 0x0000},
	{474, 0x0000},
	{475, 0x0000},
	{476, 0x0000},
	{477, 0x0000},
	{478, 0x0000},
	{479, 0x0000},
	{480, 0x0000},
	{481, 0x0000},
	{482, 0x0000},
	// rxgains
	{483, 0xabab},
	{484, 0xabab},
	{485, 0xabab},
	// boardflags4
	{486, 0x000e},
	// PD Offest 20 in 80M
	{488, 0x0000},
	{489, 0x0000},
	{490, 0x0000},
	{491, 0x0000},
	{492, 0x0000},
	// swctrlmap4
	{494, 0x4444},
	{495, 0x3333},
	{496, 0x2222},
	{497, 0x0000},
	{498, 0x4444},
	{499, 0x3333},
	{500, 0x2222},
	{501, 0x0000},
	// PD Offest 20 in 80M core3
	{510, 0x0000},
	{511, 0x0000},
	// maxp5gb4/maxp2ga3
	{512, 0x5e54},
	// PA 2G 20M, a3
	{513, 0xffff},
	{514, 0xffff},
	{515, 0xffff},
	{516, 0xffff},
	// rxgains0core3
	{517, 0xabab},
	// maxp5gb0/maxp5gb1
	{518, 0x5e5e},
	// maxp5gb2/maxp5gb3
	{519, 0x5e5e},
	// PA 5G 20M, a3
	{520, 0x18e4},
	{521, 0xcd1c},
	{522, 0x0b50},
	{523, 0x1f93},
	{524, 0x18da},
	{525, 0xd016},
	{526, 0x1148},
	{527, 0x21df},
	{528, 0x18ba},
	{529, 0xd850},
	{530, 0x2b51},
	{531, 0x2904},
	{532, 0x18f4},
	{533, 0xd630},
	{534, 0x1c8b},
	{535, 0x2460},
	{536, 0x18f4},
	{537, 0xd3ec},
	{538, 0x135a},
	{539, 0x218b},
	// PA 2G 40M, a3
	{540, 0xffff},
	{541, 0xffff},
	{542, 0xffff},
	{543, 0xffff},
	// PA 5G 40M, a3
	{544, 0x185b},
	{545, 0xdcc2},
	{546, 0x2565},
	{547, 0x2569},
	{548, 0x1853},
	{549, 0xdfd9},
	{550, 0x2fce},
	{551, 0x2785},
	{552, 0x183c},
	{553, 0xe4e4},
	{554, 0x3cf8},
	{555, 0x2974},
	{556, 0x1867},
	{557, 0xe869},
	{558, 0x461c},
	{559, 0x2a49},
	{560, 0x1827},
	{561, 0xec37},
	{562, 0x4d60},
	{563, 0x2ac6},
	// PA 5G 80M, a3
	{564, 0x1943},
	{565, 0xe96f},
	{566, 0x5097},
	{567, 0x2b85},
	{568, 0x193c},
	{569, 0xe5dd},
	{570, 0x45a1},
	{571, 0x2ab4},
	{572, 0x194a},
	{573, 0xe97e},
	{574, 0x4d62},
	{575, 0x2b2f},
	{576, 0x193d},
	{577, 0xdf59},
	{578, 0x1e86},
	{579, 0x22ce},
	{580, 0x18c6},
	{581, 0xef88},
	{582, 0x511b},
	{583, 0x2529},
	// sromrev
	{589, 0x110d},
	{0, 0}
};


/*** ZyXEL Project for SROM patch (BCM4366e, 963138) ***/
// 20161027, Mark for BCM4366e chip commmon SROM patch
static WLAN_SROM_ENTRY wlan_patch_common_963138_BCM43664[] = {
    {0, 0}
};
// PEGA 20161027, BCM4366e
static WLAN_SROM_ENTRY wlan_patch_unique_VMG8823_B10B_BCM43664[] = {
	// PCI subsystem ID 
	{2, 0x077d},
	// Board Rev
	{65, 0x1145},
	// PA 5G 20M, a0
	{265, 0xd194},
	{266, 0x173f},
	{267, 0x23a9},
	{268, 0x18ed},
	{269, 0xd290},
	{270, 0x17a1},
	{271, 0x235b},
	{272, 0x18f1},
	{273, 0xd388},
	{274, 0x184e},
	{275, 0x23ac},
	{276, 0x18f4},
	{277, 0xd61e},
	{278, 0x1cb7},
	{279, 0x2459},
	{280, 0x18ea},
	{281, 0xd8e7},
	{282, 0x214e},
	{283, 0x2515},
	// PA 5G 40M, a0
	{288, 0x18c2},
	{289, 0xdb34},
	{290, 0x1ed8},
	{291, 0x238b},
	{292, 0x18b3},
	{293, 0xdd00},
	{294, 0x22f1},
	{295, 0x245f},
	{296, 0x186c},
	{297, 0xe0e9},
	{298, 0x2882},
	{299, 0x24f6},
	{300, 0x1873},
	{301, 0xe623},
	{302, 0x3828},
	{303, 0x2770},
	{304, 0x1856},
	{305, 0xe72f},
	{306, 0x344b},
	{307, 0x2681},
	// PA 5G 80M, a0
	{308, 0x199e},
	{309, 0xe2dd},
	{310, 0x362b},
	{311, 0x27b2},
	{312, 0x19fb},
	{313, 0xd4ab},
	{314, 0x122c},
	{315, 0x20d4},
	{316, 0x19da},
	{317, 0xd832},
	{318, 0x1662},
	{319, 0x21d6},
	{320, 0x18e4},
	{321, 0xeb63},
	{322, 0x4591},
	{323, 0x291f},
	{324, 0x1905},
	{325, 0xe8c2},
	{326, 0x37f4},
	{327, 0x2706},
	// PA 5G 20M, a1
	{336, 0x18f9},
	{337, 0xcedb},
	{338, 0x0efd},
	{339, 0x20fc},
	{340, 0x18f3},
	{341, 0xd0e6},
	{342, 0x1527},
	{343, 0x238d},
	{344, 0x18fd},
	{345, 0xd1f6},
	{346, 0x157a},
	{347, 0x233c},
	{348, 0x18ec},
	{349, 0xd2c1},
	{350, 0x1514},
	{351, 0x228a},
	{352, 0x1919},
	{353, 0xd3c4},
	{354, 0x16e4},
	{355, 0x232f},
	// PA 5G 40M, a1
	{360, 0x18a0},
	{361, 0xde4f},
	{362, 0x2d6d},
	{363, 0x2740},
	{364, 0x18aa},
	{365, 0xdd4b},
	{366, 0x273f},
	{367, 0x25b6},
	{368, 0x1896},
	{369, 0xddc4},
	{370, 0x2696},
	{371, 0x2595},
	{372, 0x189e},
	{373, 0xe029},
	{374, 0x2a50},
	{375, 0x25c5},
	{376, 0x18bd},
	{377, 0xdd3e},
	{378, 0x1f68},
	{379, 0x23ac},
	// PA 5G 80M, a1
	{380, 0x1953},
	{381, 0xe5a6},
	{382, 0x45a8},
	{383, 0x2a7e},
	{384, 0x1977},
	{385, 0xdf79},
	{386, 0x2c99},
	{387, 0x266a},
	{388, 0x1959},
	{389, 0xe3c0},
	{390, 0x3ca6},
	{391, 0x291d},
	{392, 0x1925},
	{393, 0xe3ff},
	{394, 0x343b},
	{395, 0x2766},
	{396, 0x1921},
	{397, 0xe5ff},
	{398, 0x3561},
	{399, 0x2704},
	// PA 5G 20M, a2
	{408, 0x190f},
	{409, 0xd0fa},
	{410, 0x153c},
	{411, 0x2353},
	{412, 0x191e},
	{413, 0xd2b3},
	{414, 0x1862},
	{415, 0x2418},
	{416, 0x192b},
	{417, 0xd42f},
	{418, 0x1ba4},
	{419, 0x24b0},
	{420, 0x1945},
	{421, 0xd3cb},
	{422, 0x1754},
	{423, 0x2307},
	{424, 0x1907},
	{425, 0xe0c0},
	{426, 0x4daf},
	{427, 0x2e97},
	// PA 5G 40M, a2
	{432, 0x18f0},
	{433, 0xd93e},
	{434, 0x1aa3},
	{435, 0x22cc},
	{436, 0x18ce},
	{437, 0xdf51},
	{438, 0x2e27},
	{439, 0x2715},
	{440, 0x18c4},
	{441, 0xe098},
	{442, 0x2d06},
	{443, 0x2642},
	{444, 0x18a4},
	{445, 0xe4c4},
	{446, 0x364a},
	{447, 0x276c},
	{448, 0x1895},
	{449, 0xe8cd},
	{450, 0x40d6},
	{451, 0x28d4},
	// PA 5G 80M, a2
	{452, 0x1a03},
	{453, 0xd9c4},
	{454, 0x1e79},
	{455, 0x23fb},
	{456, 0x199e},
	{457, 0xe2f3},
	{458, 0x3971},
	{459, 0x2886},
	{460, 0x1959},
	{461, 0xeb57},
	{462, 0x5251},
	{463, 0x2b49},
	{464, 0x19b3},
	{465, 0xe03c},
	{466, 0x288d},
	{467, 0x2582},
	{468, 0x1957},
	{469, 0xea4b},
	{470, 0x47bc},
	{471, 0x29f6},
	// PA 5G 20M, a3
	{520, 0x18e4},
	{521, 0xcd1c},
	{522, 0x0b50},
	{523, 0x1f93},
	{525, 0xd016},
	{526, 0x1148},
	{527, 0x21df},
	{528, 0x18ba},
	{529, 0xd850},
	{530, 0x2b51},
	{531, 0x2904},
	{532, 0x18f4},
	{533, 0xd630},
	{534, 0x1c8b},
	{535, 0x2460},
	{536, 0x18f4},
	{537, 0xd3ec},
	{538, 0x135a},
	{539, 0x218b},
	// PA 5G 40M, a3
	{544, 0x185b},
	{545, 0xdcc2},
	{546, 0x2565},
	{547, 0x2569},
	{548, 0x1853},
	{549, 0xdfd9},
	{550, 0x2fce},
	{551, 0x2785},
	{552, 0x183c},
	{553, 0xe4e4},
	{554, 0x3cf8},
	{555, 0x2974},
	{556, 0x1867},
	{557, 0xe869},
	{558, 0x461c},
	{559, 0x2a49},
	{560, 0x1827},
	{561, 0xec37},
	{562, 0x4d60},
	{563, 0x2ac6},
	// PA 5G 80M, a3
	{564, 0x1943},
	{565, 0xe96f},
	{566, 0x5097},
	{567, 0x2b85},
	{568, 0x193c},
	{569, 0xe5dd},
	{570, 0x45a1},
	{571, 0x2ab4},
	{572, 0x194a},
	{573, 0xe97e},
	{574, 0x4d62},
	{575, 0x2b2f},
	{576, 0x193d},
	{577, 0xdf59},
	{578, 0x1e86},
	{579, 0x22ce},
	{580, 0x18c6},
	{581, 0xef88},
	{582, 0x511b},
	// sromrev
	{589, 0x110d},
    {0, 0}
};


#endif //if defined(ZYXEL) && (ZYXEL==1)
#endif //if defined(_BCM963138_) || defined(CONFIG_BCM963138)

#if defined(_BCM963381_) || defined(CONFIG_BCM963381)
static WLAN_SROM_ENTRY wlan_patch_unique_963381REF[] = {
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963381[] = {
    { 97,  0xfe46},
    { 98,  0x170e},
    { 99,  0xfa44},
    { 113, 0xfe87},
    { 114, 0x1932},
    { 115, 0xfa2d},
    {0, 0}
};
#if defined(ZYXEL) && (ZYXEL==1)

/*** ZyXEL Project for SROM patch (BCM43217, 963381) ***/
// 20161027, Mark for BCM43217 chip commmon SROM patch
static WLAN_SROM_ENTRY wlan_patch_common_963381_BCM43217[] = {
    {0, 0}
};
//20161027, Mark add for 43217 modify calibration data for VMG5313
static WLAN_SROM_ENTRY wlan_patch_unique_963381_VMG5313_BCM43217[] = {
	//2G ant0 maxpower
	//20150727, Nick, change to T&W FW's SROM
	{96, 0x204c},
	//2G ant0 PA
	//20150727, Nick, change to T&W suggest in 7/27
	{97, 0xfe96},
	{98, 0x192c},
	{99, 0xfa15},
	//2G ant1 maxpower
	//20150727, Nick, change to T&W FW's SROM
	{112, 0x204c},
	//2G ant1 PA
	//20150727, Nick, change to T&W suggest in 7/27
	{113, 0xfe91},
	{114, 0x1950},
	{115, 0xfa0a},
	//2G 20M power offset per rate
	//20150727, Nick, change to T&W FW's SROM
	{161, 0x4444},
	{162, 0x6444},
	//2G 20M 11n power offset per rate
	//20150727, Nick, change to T&W FW's SROM
	{169, 0x4444},
	{170, 0x6444},
	{171, 0x4444},
	{172, 0x6444},
	//2G 40M 11n power offset per rate
	//20150727, Nick, change to T&W FW's SROM
	{173, 0x6666},
	{174, 0x6666},
	{175, 0x6666},
	{176, 0x6666},
    {0, 0}
};
//20160106, David add for 5dBi antenna
static WLAN_SROM_ENTRY wlan_patch_unique_963381_VMG1312_BCM43217[] = {
#ifdef ZYFWID_ABDS
    //5dBi antenna gain
    { 79,  0x0404},
    //2G ant0 PA
    { 97,  0xfe7e},
    { 98,  0x1713},
    { 99,  0xfa67},
	//2G ant1 PA
    { 113, 0xfe63},
    { 114, 0x1558},
    { 115, 0xfacd},
#else
	{ 97,  0xfe7e},
    { 98,  0x1713},
    { 99,  0xfa67},
    { 113, 0xfe63},
    { 114, 0x1558},
    { 115, 0xfacd},
#endif
    {0, 0}
};
#endif
#endif


static WLAN_SROM_ENTRY wlan_patch_LAST[] = {
    {0, 0}
};

/* this data structure could be moved to boardparams structure in the future */
/* does not require to rebuild cfe here if more srom entries are needed */
WLAN_SROM_PATCH_INFO wlanPaInfo[]={
#if defined(_BCM96362_) || defined(CONFIG_BCM96362)
    {"96362ADVNX",    0x6362, 220, wlan_patch_unique_96362ADVNX,    wlan_patch_common_96362ADVNX},
    {"96362ADVNgr2",  0x6362, 220, wlan_patch_unique_96362ADVNgr2,  wlan_patch_common_96362ADVNgr2},
    {"96361XF",       0x6362, 220, wlan_patch_unique_96361XF,       wlan_patch_common_96361XF},
    {"96362RAVNGR2",  0x6362, 220, wlan_patch_unique_96362RAVNGR2,  wlan_patch_common_96362ADVNgr2},
    {"96362ADVN2xh",  0x6362, 220, wlan_patch_unique_96362ADVN2xh,  wlan_patch_common_96362ADVN2xh},
    {"96362ADVN2XM",  0x6362, 220, wlan_patch_unique_96362ADVN2XM,  wlan_patch_common_96362ADVN2XM},
    {"96362RADVN2XH", 0x6362, 220, wlan_patch_unique_96362RADVN2XH, wlan_patch_common_96362ADVN2xh},
    {"96362RADVNXH5", 0x6362, 220, wlan_patch_unique_96362RADVNXH5, wlan_patch_common_96362RADVNXH5},
    {"96362RADVNXH503", 0x6362, 220, wlan_patch_unique_96362RADVNXH5, wlan_patch_common_96362RADVNXH5},
    {"96362RWFAR",    0x6362, 220, wlan_patch_unique_96362RWFAR,    wlan_patch_common_96362ADVNgr2},
#endif

#if defined(_BCM963268_) || defined(CONFIG_BCM963268)
    {"963268MBV",      0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV_17A",  0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV_30A",  0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV3",     0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV17A302",0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV30A302",0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963268V30A",     0x6362, 220, wlan_patch_unique_963268V30A,    wlan_patch_common_963268MBV},
    {"963268BU",       0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963268BU_P300",  0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963168AC5",      0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963168ACH5",     0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963168XH",       0x6362, 220, wlan_patch_unique_963168XH,      wlan_patch_common_963168XH},
    {"963167REF1",     0x6362, 220, wlan_patch_unique_963168XH,      wlan_patch_common_963168XH},
    {"963167REF2",     0x6362, 220, wlan_patch_unique_963167REF2,    wlan_patch_common_963168XH},
    {"963167REF3",     0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963168XM",       0x6362, 220, wlan_patch_unique_963168XM,      wlan_patch_common_963168XM},
    {"963168XH5",      0x6362, 220, wlan_patch_unique_963168XH5,     wlan_patch_common_963168XH5},
    {"963168XN5",      0x6362, 220, wlan_patch_unique_963168XN5,     wlan_patch_common_963168XN5},
    {"963168XM5",      0x6362, 220, wlan_patch_unique_963168XM5,     wlan_patch_common_963168XM5},
    {"963168XM5_6302", 0x6362, 220, wlan_patch_unique_963168XM5_6302,wlan_patch_common_963168XM5},
    {"963168WFAR",     0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MP",       0x6362, 220, wlan_patch_unique_963168MP,      wlan_patch_common_963168MP},
//20130821, TimLiu add for new board parameter
#if defined(ZYXEL) && (ZYXEL==1)
	{"963168_VMG8948", 0x6362, 220, wlan_patch_unique_963168_VMG8948_BCM6362,	wlan_patch_common_963168_BCM6362},
	{"963168_VMG8948", 0x1108, 234, wlan_patch_unique_963168_VMG8948_BCM4360,	wlan_patch_common_963168_BCM4360},
	{"963168_VMG8924", 0x6362, 220, wlan_patch_unique_963168_VMG8924_BCM6362,	wlan_patch_common_963168_BCM6362},
	{"963168_VMG8924", 0xAA52, 234, wlan_patch_unique_963168_VMG8924_BCM43602,	wlan_patch_common_963168_BCM43602},
	{"963168_VMG3926", 0x6362, 220, wlan_patch_unique_963168_VMG3926_BCM6362,	wlan_patch_common_963168_BCM6362},
	{"963168_VMG3926", 0xAA52, 234, wlan_patch_unique_963168_VMG3926_BCM43602,	wlan_patch_common_963168_BCM43602},
	{"963168_VMG3926B", 0x6362, 220, wlan_patch_unique_963168_VMG3926B_BCM6362,	wlan_patch_common_963168_BCM6362},
	{"963168_VMG3926B", 0xAA52, 234, wlan_patch_unique_963168_VMG3926B_BCM43602,	wlan_patch_common_963168_BCM43602},
	{"963168_VMG3925B", 0x6362, 220, wlan_patch_unique_963168_VMG3925B_BCM6362,	wlan_patch_common_963168_BCM6362},
	{"963168_VMG3925B", 0xAA52, 220, wlan_patch_unique_963168_VMG3925B_BCM43602,	wlan_patch_common_963168_BCM43602},
	{"963168_VMG9823", 0x6362, 220, wlan_patch_unique_963168_VMG9823_BCM6362,	wlan_patch_common_963168_BCM6362},
	{"963168_VMG9823B", 0x6362, 220, wlan_patch_unique_963168_VMG9823_BCM6362,	wlan_patch_common_963168_BCM6362},
	{"963168_VMG3925", 0x6362, 220, wlan_patch_unique_963168_VMG3925_BCM6362,	wlan_patch_common_963168_BCM6362},
	{"963168_VMG3925", 0xAA52, 234, wlan_patch_unique_963168_VMG3925_BCM43602,	wlan_patch_common_963168_BCM43602},
	{"VMG8924-B10A", 0x6362, 220, wlan_patch_unique_963168_VMG8924_B10A_BCM6362,	wlan_patch_common_963168_BCM6362},
	{"VMG8924-B10A", 0x4360, 234, wlan_patch_unique_963168_VMG8924_B10A_BCM4360,	wlan_patch_common_963168_BCM4360},
	{"VMG8924-B10D", 0x6362, 220, wlan_patch_unique_963167_VMG8924_B10D_BCM6362,			wlan_patch_common_963168_BCM6362},
	{"VMG8924-B10D", 0xAA52, 234, wlan_patch_unique_963167_VMG8924_B10D_BCM43602,	wlan_patch_common_963168_BCM43602},
#endif
#endif

#if defined(_BCM96838_) || defined(CONFIG_BCM96838)
    {"968380GERG",     0xa8d1, 220, wlan_patch_unique_968380GERG,       wlan_patch_common_968380GERG},
#endif

#if defined(_BCM96318_) || defined(CONFIG_BCM96318)
    {"96318REF",     0xa8d1, 220, wlan_patch_unique_6318REF,     wlan_patch_common_96318REF},
    {"96318REF_P300",     0xa8d1, 220, wlan_patch_unique_6318REF,     wlan_patch_common_96318REF},
#endif
    
#if defined(_BCM963138_) || defined(CONFIG_BCM963138)
    {"963138REF_LTE",     0xa8d1, 220, wlan_patch_unique_963138REF,     wlan_patch_common_963138REF},
    {"963138LTE_P302",     0xa8d1, 220, wlan_patch_unique_963138REF,     wlan_patch_common_963138REF},
#if defined(ZYXEL) && (ZYXEL==1)
	// 0xa8d1 == 43217
	{"963138_FMG3586",     0xa8d1, 220, wlan_patch_unique_FMG3586_BCM43217,     wlan_patch_common_963138_BCM43217},
	{"963138_FMG3086",     0xa8d1, 220, wlan_patch_unique_FMG3086_BCM43217,     wlan_patch_common_963138_BCM43217},
	{"XMG3512-B10A",     0xa8d1, 220, wlan_patch_unique_XMG3512_B10A_BCM43217,     wlan_patch_common_963138_BCM43217},
	{"XMG3512_LAN",      0xa8d1, 220, wlan_patch_unique_XMG3512_B10A_BCM43217,     wlan_patch_common_963138_BCM43217},
	{"XMG3512_128MB",     0xa8d1, 220, wlan_patch_unique_XMG3512_B10A_BCM43217,     wlan_patch_common_963138_BCM43217},
	{"VMG8823-B10B",     0xa8d1, 220, wlan_patch_unique_VMG8823_B10B_BCM43217,     wlan_patch_common_963138_BCM43217},
	{"VMG8823-B10B",     0x4366, 590, wlan_patch_unique_VMG8823_B10B_BCM4366,  wlan_patch_common_963138_BCM4366},
	// 0xaa90 == 43664 == BCM4366e
	{"VMG8823-B10B",     0xaa90, 590, wlan_patch_unique_VMG8823_B10B_BCM43664,  wlan_patch_common_963138_BCM43664},
#endif
#endif
    
#if defined(_BCM963381_) || defined(CONFIG_BCM963381)
    {"963381REF1",     0xa8d1, 220, wlan_patch_unique_963381REF,     wlan_patch_common_963381},
    {"963381A_REF1",     0xa8d1, 220, wlan_patch_unique_963381REF,     wlan_patch_common_963381},
    {"963381REF1_A0",     0xa8d1, 220, wlan_patch_unique_963381REF,     wlan_patch_common_963381},
#if defined(ZYXEL) && (ZYXEL==1)
    {"963381_VMG1312", 0xa8d1, 220, wlan_patch_unique_963381_VMG1312_BCM43217,   wlan_patch_common_963381_BCM43217},
	{"963381_VMG5313B", 0xa8d1, 220, wlan_patch_unique_963381_VMG5313_BCM43217,   wlan_patch_common_963381_BCM43217},
#endif
#endif
    
    {"", 0, 0, wlan_patch_LAST, wlan_patch_LAST}, /* last entry*/
};


WLAN_PCI_PATCH_INFO wlanPciInfo[]={
#if defined(_BCM96362_) || defined(CONFIG_BCM96362)
    /* this is the patch to boardtype(boardid) for internal PA */
    {"96362ADVNX", 0x435f14e4, 64,
    {{"subpciids", 11, 0x53614e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96362ADVNgr2 */
    {"96362ADVNgr2", 0x435f14e4, 64,
    {{"subpciids", 11, 0x58014e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96362ADVN2xh */
    {"96362ADVN2xh", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5a614e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96361XF */
    {"96361XF", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5b814e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96361I2 */
    {"96361I2", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5e514e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96362RAVNGR2 */
    {"96362RAVNGR2", 0x435f14e4, 64,
    {{"subpciids", 11, 0x60d14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96362ADVN2XM */
    {"96362ADVN2XM", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5d414e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96362RADVNXH5 */
    {"96362RADVNXH5", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x63F14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96362RADVNXH503 */
    {"96362RADVNXH503", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x63F14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96362RADVN2XH */
    {"96362RADVN2XH", 0x435f14e4, 64,
    {{"subpciids", 11, 0x63E14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 96362RWFAR */
    {"96362RWFAR", 0x435f14e4, 64,
    {{"subpciids", 11, 0x60d14e4},
    {"",       0,      0}}},
#endif
#if defined(_BCM963268_) || defined(CONFIG_BCM963268)
    /* this is the patch to boardtype(boardid) for 63268MBV */
    {"963268MBV", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV_17A */
    {"963168MBV_17A", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV_30A */
    {"963168MBV_30A", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV3 */
    {"963168MBV3", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV17A302 */
    {"963168MBV17A302", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV30A302 */
    {"963168MBV30A302", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963268V30A */
    {"963268V30A", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5E714e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 63268BU */
    {"963268BU", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A714e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 63168ACH5 */
    {"963168ACH5", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A714e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168VX */
    {"963168VX", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A814e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168VX_P300 */
    {"963168VX_P300", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A814e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168VX_P400 */
    {"963168VX_P400", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A814e4},
    {"",       0,      0}}},    
    /* this is the patch to boardtype(boardid) for 63168XH */
    {"963168XH", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5E214e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 63168XM */
    {"963168XM", 0x435f14e4, 64,
    {{"subpciids", 11, 0x61f14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168XH5 */
    {"963168XH5", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x64014e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168XN5 */
    {"963168XN5", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x68414e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168XM5 */
    {"963168XM5", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x68514e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168XM5_6302 */
    {"963168XM5_6302", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x68614e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MP */
    {"963168MP", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 63168WFAR */
    {"963168WFAR", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
#if defined(ZYXEL) && (ZYXEL==1)
    /* this is the patch to boardtype(boardid) for VMG8948, reference 963168MBV_17A */
    {"963168_VMG8948", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for VMG8924, reference 963168MBV_17A */
    {"963168_VMG8924", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for VMG3926, reference 963168MBV_17A */
    {"963168_VMG3926", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for VMG3926-B10B, reference 963168MBV_17A */
    {"963168_VMG3926B", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
	/* this is the patch to boardtype(boardid) for VMG3925B, reference 963168MBV_17A */
    {"963168_VMG3925B", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for VMG9823, reference 963168MBV_17A */
    {"963168_VMG9823", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
	{"963168_VMG9823B", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    {"VMG8924-B10A", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
	/* temp for VMG8924-B10D */
    {"VMG8924-B10D", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
#endif
#endif
    {"",                 0, 0, {{"",       0,      0}}}, /* last entry*/
};

