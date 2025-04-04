// SPDX-License-Identifier: GPL-2.0+
// Copyright (c) 2023, SiliconMotion Inc.


#ifndef LYNX_HW750_H__
#define LYNX_HW750_H__

#include "hw_com.h"
#ifdef USE_EP952
#include "ddk768/ep952api.h"
#endif




void ddk750_set_mmio(volatile unsigned char * addr,unsigned short devId,char revId);
unsigned long ddk750_getFrameBufSize(void);
long ddk750_initChip(void);
void ddk750_deInit(void);
long ddk750_detectCRTMonitor(unsigned char redValue, unsigned char greenValue,
	unsigned char blueValue);

long ddk750_edidHeaderReadMonitorExHwI2C(void);
long ddk750_edidHeaderReadMonitorEx(
    unsigned char sclGpio,
    unsigned char sdaGpio
);	

/*
 *  edidReadMonitor
 *      This function reads the EDID structure from the attached monitor
 *
 *  Input:
 *      displayPath - Display device which EDID to be read from.
 *      pEDIDBuffer - Buffer that contains the EDID structure of the monitor
 *      bufferSize  - The EDID Buffer size index (usually 128-bytes)
 *      edidExtNo   - Extension Index of the EDID Structure to be read
 *
 *  Output:
 *      0   - Success
 *     -1   - Fail
 */
long ddk750_edidReadMonitor(
    disp_path_t displayPath,
    unsigned char *pEDIDBuffer,
    unsigned long bufferSize,
    unsigned char edidExtNo
);

/*
 *  edidReadMonitor
 *      This function reads the EDID structure from the attached monitor
 *
 *  Input:
 *      displayPath - Display device which EDID to be read from.
 *      pEDIDBuffer - Buffer that contains the EDID structure of the monitor
 *      bufferSize  - The EDID Buffer size index (usually 128-bytes)
 *      edidExtNo   - Extension Index of the EDID Structure to be read
 *      sclGpio     - GPIO pin used as the I2C Clock (SCL)
 *      sdaGpio     - GPIO pin used as the I2C Data (SDA)
 *
 *  Output:
 *      0   - Success
 *     -1   - Fail
 */
long ddk750_edidReadMonitorEx(
    disp_path_t displayPath,
    unsigned char *pEDIDBuffer,
    unsigned long bufferSize,
    unsigned char edidExtNo,
    unsigned char sclGpio,
    unsigned char sdaGpio
);


long ddk750_edidReadMonitorEx_HW(
    disp_path_t displayPath,
    unsigned char *pEDIDBuffer,
    unsigned long bufferSize,
    unsigned char edidExtNo
);


/*
 * This function initializes the cursor attributes.
 */
void ddk750_initCursor(
    disp_control_t dispControl,     /* Display control (CHANNEL0_CTRL or CHANNEL1_CTRL) */
    unsigned long base,             /* Base Address */ 
    unsigned long color1,           /* Cursor color 1 in RGB 5:6:5 format */
    unsigned long color2,           /* Cursor color 2 in RGB 5:6:5 format */
    unsigned long color3            /* Cursor color 3 in RGB 5:6:5 format */
);

/*
 * This function sets the cursor position.
 */
void ddk750_setCursorPosition(
    disp_control_t dispControl,     /* Display control (CHANNEL0_CTRL or CHANNEL1_CTRL) */
    unsigned long dx,               /* X Coordinate of the cursor */
    unsigned long dy,               /* Y Coordinate of the cursor */
    unsigned char topOutside,       /* Top Boundary Select: either partially outside (= 1) 
                                       or within the screen top boundary (= 0) */
    unsigned char leftOutside       /* Left Boundary Select: either partially outside (= 1) 
                                       or within the screen left boundary (= 0) */
);

/*
 * This function enables/disables the cursor.
 */
void ddk750_enableCursor(
    disp_control_t dispControl,     /* Display control (CHANNEL0_CTRL or CHANNEL1_CTRL) */
    unsigned long enable
);



void hw750_set_base(int display,int pitch,int base_addr);

long setMode(
	logicalMode_t *pLogicalMode
);
void setDisplayControl(disp_control_t dispControl, disp_state_t dispState);
void setPath(
    disp_path_t dispPath, 
    disp_control_t dispControl, 
    disp_state_t dispState
);

void swPanelPowerSequence(disp_state_t dispState, unsigned long vsync_delay);
void setDAC(disp_state_t state);
void setDPMS(DPMS_t state);



void hw750_set_dpms(int display,int state);
void hw750_suspend(struct smi_750_register * pSave);
void hw750_resume(struct smi_750_register * pSave);
int hw750_check_vsync_interrupt(int path);
void hw750_clear_vsync_interrupt(int path);

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
int hw750_en_dis_interrupt(int status, int pipe);
#else
int hw750_en_dis_interrupt(int status);
#endif


void ddk750_disable_IntMask(void);

int sii9022xInitChip(void);
int sii9022xSetMode(int);
unsigned char sii9022xIsConnected(void);

int ddk750_GetDDC_9022Access(void);
int ddk750_Release9022DDC(void);

void ddk750_DoEdidRead(void);

void hw750_setgamma(disp_control_t dispCtrl, unsigned long enable);
void hw750_load_lut(disp_control_t dispCtrl, int size, u8 lut_r[], u8 lut_g[], u8 lut_b[]);

long hw750_AdaptI2CInit(struct smi_connector *smi_connector);
long hw750_AdaptI2CCleanBus(struct drm_connector *connector);

#endif
