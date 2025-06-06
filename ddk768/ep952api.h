#ifndef EP952_API_H
#define EP952_API_H

// HDCP	enable define ////////////////

#define Enable_HDCP 	0

//////////////////////////////////////


// Debug define	//////////////////////

#define DBG_printf(x) printf x		// enable DBG message
//#define DBG_printf(x)				// disable DBG message

//////////////////////////////////////

// -----------------------------------------------------------------------------

typedef enum {
	// Master
	SMBUS_STATUS_Success = 0x00,
	SMBUS_STATUS_Pending,//	SMBUS_STATUS_Abort,
	SMBUS_STATUS_NoAct = 0x02,
	SMBUS_STATUS_TimeOut,
	SMBUS_STATUS_ArbitrationLoss = 0x04,
} SMBUS_STATUS;


/*typedef enum {
	AUD_I2S = 0,
	AUD_SPDIF	
}HDMI_AudFmt_t;*/

typedef enum {
	AUD_None = 0,
	AUD_SF_32000Hz = 1,
	AUD_SF_44100Hz,
	AUD_SF_48000Hz,	
	//AUD_SF_88200Hz,
	//AUD_SF_96000Hz,
	//AUD_SF_176400Hz,
	//AUD_SF_192000Hz

}HDMI_AudFreq;

//--------------------------------------------------------------------------------------------------
// 															BitMask		Value
#define EP_TX_System_Status__KEY_FAIL									0x02
#define EP_TX_System_Configuration__HDCP_DIS							0x20

#define EP_TX_Video_Interface_Setting_0__DKEN_Disable					0x80	// Disable De-skew
#define EP_TX_Video_Interface_Setting_0__DKEN_M_4_Step					0x10	// -4 step
#define EP_TX_Video_Interface_Setting_0__DKEN_M_3_Step					0x30	// -3 step
#define EP_TX_Video_Interface_Setting_0__DKEN_M_2_Step					0x50	// -2 step
#define EP_TX_Video_Interface_Setting_0__DKEN_M_1_Step					0x70	// -1 step
#define EP_TX_Video_Interface_Setting_0__DKEN_M_0_Step					0x90	//  0 step
#define EP_TX_Video_Interface_Setting_0__DKEN_P_1_Step					0xB0	// +1 step
#define EP_TX_Video_Interface_Setting_0__DKEN_P_2_Step					0xD0	// +2 step
#define EP_TX_Video_Interface_Setting_0__DKEN_P_3_Step					0xF0	// +3 step

#define EP_TX_Video_Interface_Setting_0__DSEL							0x08
#define EP_TX_Video_Interface_Setting_0__BSEL							0x04
#define EP_TX_Video_Interface_Setting_0__EDGE							0x02
#define EP_TX_Video_Interface_Setting_0__FMT12							0x01

#define EP_TX_Video_Interface_Setting_1__SYNC				0x0C
#define EP_TX_Video_Interface_Setting_1__SYNC__HVDE						0x00
#define EP_TX_Video_Interface_Setting_1__SYNC__HV						0x04
#define EP_TX_Video_Interface_Setting_1__SYNC__Embeded					0x08

#define EP_TX_Video_Interface_Setting_1__VIN_FMT			0x03
#define EP_TX_Video_Interface_Setting_1__VIN_FMT__RGB					0x00
#define EP_TX_Video_Interface_Setting_1__VIN_FMT__YCC444				0x01
#define EP_TX_Video_Interface_Setting_1__VIN_FMT__YCC422				0x02

#define EP_TX_Audio_Input_Format__ADO_FREQ					0x07
#define EP_TX_Audio_Input_Format__ADO_FREQ__None					0x00
#define EP_TX_Audio_Input_Format__ADO_FREQ__32000Hz					0x01
#define EP_TX_Audio_Input_Format__ADO_FREQ__44100Hz					0x02
#define EP_TX_Audio_Input_Format__ADO_FREQ__48000Hz					0x03
#define EP_TX_Audio_Input_Format__ADO_FREQ__88200Hz					0x04
#define EP_TX_Audio_Input_Format__ADO_FREQ__96000Hz					0x05
#define EP_TX_Audio_Input_Format__ADO_FREQ__176400Hz				0x06
#define EP_TX_Audio_Input_Format__ADO_FREQ__192000Hz				0x07

// -----------------------------------------------------------------------------

#ifndef min
#define min(a,b) (((a)<(b))? (a):(b))
#endif

#ifndef max
#define max(a,b) (((a)>(b))? (a):(b))
#endif

//--------------------------------------------------------------------------------------------------
void EP_EP952_Reset(void);
//void EP_HDMI_Set_Audio_Fmt(HDMI_AudFmt_t Audfmt, HDMI_AudFreq Audfreq);
void  EP_HDMI_Set_Video_Timing(unsigned int isHDMI,unsigned int dsel); //(logicalMode_t *pLogicalMode, unsigned int isHDMI);
void EP_HDMI_Init(int chipID); 
void EP_Register_Init(void);
int EP952_HDMI_Set_Mode (logicalMode_t *pLogicalMode);
void EP952_Register_Message(void);




//--------------------------------------------------------------------------------------------------
#endif
