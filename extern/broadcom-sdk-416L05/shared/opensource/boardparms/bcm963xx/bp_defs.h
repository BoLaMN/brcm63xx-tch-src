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

#if !defined(_BP_DEFS_H)
#define _BP_DEFS_H

#include "boardparms.h"

/* Typedefs */

/*
You can add a new enum entry anywhere in the enum list below.
Then, you can use the enums in the board parm arrays, with the following restrictions:
-An API must be created for accessing any data from the array except for bp_elemTemplate.
-bp_cpBoardId  must be the first element of the array.
-bp_elemTemplate if used should be the last or second to last (just before bp_last) element
 of the array
-Most enums that are used only once in the array can be placed anywhere after bp_cpBoardId.
-These enums are read with the BpGetUc/BpGetUs/BpGetUl private functions.
-If there is a board parm array that is very similar to one you are adding, then you
 can use the bp_elemTemplate to point to that the board parm array BUT the restriction
 below still applies - that is do not split up the "groups"
 (see g_bcm96362advngr and g_bcm96362advngr2 or g_bcm963168vx and g_bcm963168vx_p300)
-Certain enums can appear multiple times in the board parm arrays
-These enums have special APIs that understand how to loop through each occurence
 They are:
 *packet switch related parameters (from bp_ucPhyAddress to bp_ulPhyId7) which can
  appear once per packet switch (bp_ucPhyType0 and bp_ucPhyType1)
 *led info related parameters (bp_usDuplexLed, bp_usSpeedLed100 and bp_usSpeedLed1000) which can
  appear once per internal led (bp_ulPhyId0 and bp_ulPhyId1)
 *add a new id bp_usPhyConnType to specify the phy connection type as we are running out phy id flag
 *bits. use this id initially for PLC MAC connection type, but will use it for MOCA, EPON, GPON in the
 *futures and remove the phy id connecton type flags.
 *voip dsp related parameters (from bp_ucDspAddress to bp_usGpioDectLed) which can
  appear once per dsp (bp_ucDspType0 and bp_ucDspType1)
*/

#define bp_usGpioOverlay     bp_ulGpioOverlay

enum bp_id {
  bp_cpBoardId,
  bp_cpComment,
  bp_ulGpioOverlay,
  bp_usGpioLedAdsl,
  bp_usGpioLedAdslFail,
  bp_usGpioSecLedAdsl,
  bp_usGpioSecLedAdslFail,
  bp_usGpioLedSesWireless,
  bp_usGpioLedWanData,
  bp_usGpioSecLedWanData,
  bp_usGpioLedWanError,
  bp_usGpioLedBlPowerOn,
  bp_usGpioLedBlStop,
  bp_usGpioFpgaReset,
  bp_usGpioLedGpon,
  bp_usGpioLedGponFail,
  bp_usGpioLedMoCA,
  bp_usGpioLedMoCAFail,
  bp_usGpioLedEpon,
  bp_usGpioLedEponFail,
  bp_usExtIntrResetToDefault,
  bp_usExtIntrResetToDefault2,
  bp_usExtIntrSesBtnWireless,
  bp_usExtIntrNfc,
  bp_usGpioNfcWake,
  bp_usGpioNfcPower,
  bp_usGpioBitbangI2cScl,
  bp_usGpioBitbangI2cSda,
  bp_usAntInUseWireless,
  bp_usWirelessFlags,
  bp_usGpioWirelessPowerDown,
  bp_ucPhyType0,
  bp_ucPhyType1,
  bp_ucPhyAddress,
  bp_usConfigType,
  bp_ulPortMap,
  bp_ulPhyId0,
  bp_ulPhyId1,
  bp_ulPhyId2,
  bp_ulPhyId3,
  bp_ulPhyId4,
  bp_ulPhyId5,
  bp_ulPhyId6,
  bp_ulPhyId7,
  bp_ulPhyId8,
  bp_ulPhyId9,
  bp_ulPhyId10,
  bp_ulPhyId11,
  bp_ulPhyId12,
  bp_ulPhyId13,
  bp_ulPhyId14,
  bp_ulPhyId15,
  bp_usDuplexLed,
  bp_usLinkLed, // Link/Activity
  bp_usSpeedLed100,
  bp_usSpeedLed1000,
  bp_usPhyConnType,
  bp_usGpioPhyReset,    // used if each phy has a different gpio pin for reset
  bp_ucPhyDevName,
  bp_ucDspType0,
  bp_ucDspType1,
  bp_ucDspAddress,
  bp_usGpioLedVoip,
  bp_usGpioVoip1Led,
  bp_usGpioVoip1LedFail,
  bp_usGpioVoip2Led,
  bp_usGpioVoip2LedFail,
  bp_usGpioPotsLed,
  bp_usGpioDectLed,
  bp_usGpioPassDyingGasp,
  bp_ulAfeId0,
  bp_ulAfeId1,
  bp_usGpioExtAFEReset,
  bp_usGpioExtAFELDPwr,
  bp_usGpioExtAFELDMode,
  bp_usGpioIntAFELDPwr,
  bp_usGpioIntAFELDMode,
  bp_usGpioAFELDRelay,
  bp_usGpioAFEVR5P3PwrEn,
  bp_usGpioUart2Sdin,
  bp_usGpioUart2Sdout,
  bp_usGpioUart2Cts,
  bp_usGpioUart2Rts,
  bp_usGpioLaserDis,
  bp_usGpioLaserTxPwrEn,
  bp_usGpioLaserRxPwrEn,
  bp_usGpioEponOpticalSD,
  bp_usVregSel1P2,
  bp_ucVreg1P8,
  bp_usVregAvsMin,
  bp_usGponOpticsType,
  bp_usGpioFemtoReset,
  bp_cpDefaultOpticalParams,
  bp_usEphyBaseAddress,
  bp_usGpioSpiSlaveReset,
  bp_usGpioSpiSlaveBootMode,
  bp_usSpiSlaveBusNum,  
  bp_usSpiSlaveSelectNum,
  bp_usSpiSlaveSelectGpioNum,
  bp_usSpiSlaveMode,
  bp_ulSpiSlaveCtrlState,
  bp_ulSpiSlaveMaxFreq,
  bp_usSpiSlaveProtoRev,
  bp_usGpioIntAFELDData,
  bp_usGpioIntAFELDClk,
  bp_usGpioExtAFELDData,
  bp_usGpioExtAFELDClk,
  bp_ulNumFePorts,
  bp_ulNumGePorts,
  bp_ulNumVoipPorts,
  bp_usGpioI2cScl,
  bp_usGpioI2cSda,
  bp_elemTemplate,
  bp_usSerialLEDMuxSel,
  bp_ulDeviceOptions,
  bp_pPhyInit,
  bp_usGpioLaserReset,  
  bp_usGpio_Intr,
  bp_usGphyBaseAddress,
  bp_cpPersonalityName,
  bp_usExtIntrMocaHostIntr,
  bp_usExtIntrMocaSBIntr0,
  bp_usExtIntrMocaSBIntr1,
  bp_usExtIntrMocaSBIntr2,
  bp_usExtIntrMocaSBIntr3,
  bp_usExtIntrMocaSBIntr4,
  bp_usExtIntrMocaSBIntrAll,
  bp_usMocaType0,
  bp_usMocaType1,
  bp_pMocaInit,
  bp_usGpioMocaReset,
  bp_ulDyingGaspIntrPin,
  bp_usGpioPLCPwrEn,
  bp_usGpioPLCReset,
  bp_usExtIntrPLCStandBy,
  bp_ulPortFlags,
  bp_usMocaRfBand,
  bp_usGpioLedOpticalLinkFail,
  bp_usGpioLedOpticalLinkStat,
  bp_usGpioLedLan,
  bp_usGpioLedWL2_4GHz,
  bp_usGpioLedWL5GHz, 
  bp_usGpioLedUSB,
  bp_usGpioBoardReset, // used to reset the entire board
  bp_usGpioUsb0,  	   // used for USB 0	
  bp_usGpioUsb1,       // used for USB 0
  bp_ulOpticalWan,
  bp_ulSimInterfaces,
  bp_ulSlicInterfaces,
  bp_usGpioPonTxEn,
  bp_usGpioPonRxEn,
  bp_usRogueOnuEn,
  bp_usGpioLedSim,
  bp_usGpioLedSim_ITMS,
  bp_usPinMux,
  bp_usGpioSpromClk, /* for BRCM_FTTDP */
  bp_usGpioSpromData, /* for BRCM_FTTDP */
  bp_usGpioSpromRst, /* for BRCM_FTTDP */
  bp_usGpioAttachedDevReset,
  bp_usTsync1025mhz,
  bp_usTsync8khz,
  bp_usTsync1pps,
  bp_usGpioTsyncPonUnstable,
  bp_usGpioLedReserved,
  bp_usGpioReserved,
  bp_usSerialLedData,
  bp_usSerialLedClk,
  bp_usSerialLedMask,
  bp_ReservedDslCtl, // used only internally
  bp_ReservedAnyGpio, // used only internally
  bp_ReservedAnyLed, // used only internally
  bp_ulCrossbar,
  bp_ulCrossbarPhyId,
  bp_ulInterfaceEnable,
  bp_ulMemoryConfig,
  bp_usBatteryEnable,
  bp_ulPinmuxTableSelect,
  bp_usExtIntrPmdAlarm,
  bp_usGpioPmdReset,
  bp_usPmdMACEwakeEn,
  bp_ulPortMaxRate,
  bp_ulAttachedIdx,
  bp_usExtIntrTrplxrTxFail,
  bp_usExtIntrTrplxrSd,
  bp_usTxLaserOnOutN,
  bp_usGpioPonReset,
  bp_usGpio1ppsStable,
  bp_usWanNco10MClk,
  bp_usGpioLteReset,
  bp_usTrxSignalDetect,
  bp_usGpioStrapTxEn,
  bp_usExtIntrWifiOnOff,
  bp_usExtIntrLTE,
  bp_usMiiInterfaceEn,
  bp_usFxsFxo1SpiSSNum,  //
  bp_usFxsFxo2SpiSSNum,  // Enum order must not be changed, also must be contiguous       
  bp_usFxsFxo3SpiSSNum,  //
  bp_usGpioFxsFxoRst1,   //     
  bp_usGpioFxsFxoRst2,   // Enum order must not be changed, also must be contiguous       
  bp_usGpioFxsFxoRst3,   //     
  bp_usGpioDectRst,           
  bp_usGpioVoipRelayCtrl1,    
  bp_usGpioVoipRelayCtrl2,    
  bp_usGpioLe9540Reset,
  bp_usSi32392SpiSSNum,
  bp_usHvgMaxPwm,
  bp_usZarIfSclk,
  bp_usZarIfSdout,
  bp_usZarIfSdin,
  bp_usZarIfEnable,
  bp_iDectCfg,             
  bp_daughterCardList,    
  bp_usSgmiiDetect,
  bp_usVregSync,
  bp_usGpioLedPwmReserved,
  bp_usAePolarity,
  bp_usButtonIdx,
  bp_usButtonExtIntr,
  bp_usButtonAction,
  bp_ulButtonActionParm,
  bp_usCfeResetToDefaultBtnIdx,
  bp_usVoipApmChSwap,
  bp_usUsbPwrOn0,
  bp_usUsbPwrOn1,
  bp_usUsbPwrFlt0,
  bp_usUsbPwrFlt1,
  bp_usGpioSfpDetect,
  bp_usSimDat,
  bp_usSimClk,
  bp_usSimPresence,
  bp_usSimVccEn,
  bp_usSimVccVolSel,
  bp_usSimRst,
  bp_usSimVppEn,
  bp_usMiiMdc,
  bp_usMiiMdio,
  bp_usProbeClk,
  bp_usGpioWanSignalDetected,
  bp_usExtIntrWanSignalDetected,
  bp_usOamIndex,
  bp_usXdResetGpio,
  bp_cpXdResetName,
  bp_usXdResetReleaseOnInit,
  bp_usXdGpio,
  bp_usXdGpioInitValue,
  bp_cpXdGpioInfo,
  bp_cpXdGpioInfoValue0,
  bp_cpXdGpioInfoValue1,
  bp_ulLedBlPowerOnBlinkTimeOn,
  bp_ulLedBlPowerOnBlinkTimeOff,
  bp_usWanEarlyTxEn,
  bp_usMs1588TodAlarm,
  bp_usWanNcoProgMClk,
  bp_usNtrRefIn,
  bp_usGpioBtReset,
  bp_usGpioBtWake,
  bp_InvSerdesRxPol,
  bp_InvSerdesTxPol,
//20130821, TimLiu add for ZyXEL usage.
#if defined(ZYXEL) && (ZYXEL==1)
  bp_usGpioVoip1MessageLed,
  bp_usGpioVoip2MessageLed,
  bp_usGpioLedVdsl,
  bp_usGpioLedVdslFail,
  bp_usGpioSecLedVdsl,
  bp_usGpioSecLedVdslFail,
  bp_usGpioLedInternetData,
  bp_usGpioLedInternetFail,
  bp_usGpioLedUSB0,
  bp_usGpioLedUSB0Fail,
  bp_usGpioLedUSB1,
  bp_usGpioLedUSB1Fail,
  bp_usExtIntrWirelessBtn,
  bp_usGpioSFPDetect,
  bp_usGpioSFPTXFault,
  bp_usGpioSFPTXDisable,
  bp_usGpioHTP,
  bp_usGpioLedLTESignal1,
  bp_usGpioLedLTESignal2,
  bp_usGpioLedLTESignal3,
  bp_usGpioLedLTESignal4,
  bp_usGpioLedSesWireless2,
  bp_usExtIntrDECT,
  bp_usGpioDECT,
  bp_usGpioDECTReset,
  bp_usGpioWlanDisable,
#ifdef ZYPRJ_VMG8948
  bp_usGpioGuestWirelessBtn,
  bp_usGpioLedGuestWiFi,
  bp_usGpioLedGuestWPS,
#if defined(ZYXEL_WIFI_LED_PATTERN) && (ZYXEL_WIFI_LED_PATTERN ==1)
  bp_usGpioWirelessSelect, //for select the signal of 2.4G or 5G to output to LED.
#endif  //ZYXEL_WIFI_LED_PATTERN
#endif  //ZYPRJ_VMG8948
  bp_usGpioInternetLedEnable,	// to provide power for Internet Green LED on VMG9823 and VMG3925(DSL-491GNAU-B1BC).
  bp_usGpioInternetCtrlSignal,	// to select which signal will output to Internet LED on VMG9823 and VMG3925(DSL-491GNAU-B1BC).
  bp_usGpioWPSSpotlightRed,		//Only for VMG9823
  bp_usGpioWPSSpotlight,		//only XMG3512 use it at the moment
#endif
#if 1
  bp_usGpioWLANRED,
  bp_usGpioWLANORANGE,
  bp_usGpioADSLRED,
  bp_usGpioADSL2RED,
  bp_usGpio5GDisable,
  bp_usGpio5GReset,
#endif
  bp_usGpioSelectWanLed,	//XMG3512 using the GPIO to secelt output WAN signal to WAN LED or SFP LED
  bp_last
};



typedef struct bp_elem {
  enum bp_id id;
  union {
    char * cp;
    unsigned char * ucp;
    unsigned char uc;
    unsigned short us;
    unsigned long ul;
    void * ptr;
    struct bp_elem * bp_elemp;
  } u;
} bp_elem_t;

extern bp_elem_t * g_pCurrentBp;
extern bp_elem_t * g_BoardParms[];
extern WLAN_SROM_PATCH_INFO wlanPaInfo[];
extern WLAN_PCI_PATCH_INFO wlanPciInfo[];

#endif /* _BP_DEFS_H */
