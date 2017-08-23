/*
 * sharpLCD.c
 *
 *  Created on: 23 ���. 2017 �.
 *      Author: user
 */

#include <stdint.h>
#include <stdbool.h>
#include "sharpLCD.h"

void SHARPLCD_Init(sharplcd_t * sharplcd)
{
	//Calculate values for struct
	sharplcd.xRes = SHARPLCD_XRES;
	sharplcd.yRes = SHARPLCD_YRES;
	sharplcd.bytesPerLine = SHARPLCD_BYTES_LINE;
	sharplcd.bufferSize = SHARPLCD_BUF_SIZE;
	sharplcd.Write = SPI1_SendPacket;
	sharplcd.SetCS = DISPLAY_SetCS;
	sharplcd.ClearCS = DISPLAY_ClearCS;
	sharplcd.SetVCOM = DISPLAY_SetVCOM;
	sharplcd.ClearVCOM = DISPLAY_ClearVCOM;
	//sharplcd.GetVCOM = DISPLAY_GetVCOM;
	sharplcd.SetDISP = DISPLAY_SetDISP;
	sharplcd.ClearDISP = DISPLAY_ClearDISP;
	sharplcd.SetLSBFirst = SPI1_SetLSBFirst;
	sharplcd.SetMSBFirst = SPI1_SetMSBFirst;
	sharplcd.DelayMs = Delay;

	//Set CS to inactive


	//Set DISP to inactive

}

void SHARPLCD_Clear(sharplcd_t * sharplcd)
{

}

void SHARPLCD_ShowFrame(sharplcd_t *sharplcd, uint8_t frame)
{

}

void SHARPLCD_SendWriteCommand(sharplcd_t * sharplcd)
{

}

void SHARPLCD_SendTrailer(sharplcd_t * sharplcd)
{

}

void SHARPLCD_WriteLine(sharplcd_t *sharplcd, uint8_t lineNo, uint8_t * lineArray)
{
	//1. Set MSB byte order for command
	sharplcd->SetMSBFirst();

	//2. Pullup CS line for select display
	sharplcd->SetCS();

	//3. Write command
	sharplcd->Write(SHARPLCD_WRITE_CMD, 1);

	//4. VCOM

	//5. Set proper byte order - LSB for line number and data
	sharplcd->SetLSBFirst();

	//6. Send number of line. Warning! Number of line starts from 1!
	sharplcd->Write(lineNo + 1, 1);

	//7. Write line data
	sharplcd->Write(lineArray, sharplcd->bytesPerLine);

	//8. Clear CS
	sharplcd->ClearCS();

	//9. Set MSB byte order again
	sharplcd->SetMSBFirst();
}