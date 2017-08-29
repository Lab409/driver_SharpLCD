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
	sharplcd->xRes = SHARPLCD_XRES;
	sharplcd->yRes = SHARPLCD_YRES;
	sharplcd->bytesPerLine = SHARPLCD_BYTES_LINE;
	sharplcd->bufferSize = SHARPLCD_BUF_SIZE;
	sharplcd->currentVcom = 0;

	//Set CS to inactive

	//Set DISP to inactive

}

void SHARPLCD_ToggleVCOM(sharplcd_t * sharplcd)
{
	sharplcd->currentVcom ^= SHARPLCD_VCOM_TOGGLE_CMD;
}

void SHARPLCD_Clear(sharplcd_t * sharplcd)
{
	uint8_t buffer[1];

	//1. Set MSB byte order for command
	sharplcd->SetMSBFirst();

	//2. Pullup CS line for select display
	sharplcd->SetCS();

	//3. Write command
	buffer[0] = SHARPLCD_CLEAR_CMD | sharplcd->currentVcom;
	SHARPLCD_ToggleVCOM(sharplcd);
	sharplcd->Write(buffer, 1);

	//4. Set proper byte order - LSB for line number and data
	sharplcd->SetLSBFirst();

	//5. Write trailer
	buffer[0] = SHARPLCD_NULL_BYTE;
	sharplcd->Write(buffer, 1);

	//6. Clear CS
	sharplcd->ClearCS();

	//7. Set MSB byte order again
	sharplcd->SetMSBFirst();
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
	uint8_t buffer[1];

	//1. Set MSB byte order for command
	sharplcd->SetMSBFirst();

	//2. Pullup CS line for select display
	sharplcd->SetCS();

	//3. Write command
	buffer[0] = SHARPLCD_WRITE_CMD | sharplcd->currentVcom;
	SHARPLCD_ToggleVCOM(sharplcd);
	sharplcd->Write(buffer, 1);

	//4. Set proper byte order - LSB for line number and data
	sharplcd->SetLSBFirst();

	//5. Send number of line. Warning! Number of line starts from 1!
	buffer[0] = lineNo + 1;
	sharplcd->Write(buffer, 1);

	//6. Write line data
	sharplcd->Write(lineArray, sharplcd->bytesPerLine);

	//7. Trailer
	buffer[0] = SHARPLCD_NULL_BYTE;
	sharplcd->Write(buffer, 1);
	sharplcd->Write(buffer, 1);

	//8. Clear CS
	sharplcd->ClearCS();

	//9. Set MSB byte order again
	sharplcd->SetMSBFirst();
}


/* =============================TESTING============================= */


