/*
 * bsp.c
 *
 *  Created on: 23 ���. 2017 �.
 *      Author: user
 */

#include <stdint.h>
#include "em_usart.h"
#include "em_gpio.h"
#include "InitDevice.h"
#include "bsp.h"
#include "sharpLCD.h"

extern uint32_t msTicks;

void _ErrorHandler(void)
{
	DEBUG_BREAK;
}

void Delay(uint32_t dlyTicks)
{
	uint32_t curTicks;

	curTicks = msTicks;
	while ((msTicks - curTicks) < dlyTicks) ;
}

void SPI1_SendPacket(uint8_t * pkt, uint16_t len)
{
	for(uint8_t i = 0; i < len; i++)
	{
		USART_SpiTransfer(USART1, *pkt);
		pkt++;
	}
}

void SPI1_SetMSBFirst()
{
	USART1->CTRL |= USART_CTRL_MSBF;
}

void SPI1_SetLSBFirst()
{
	USART1->CTRL &= ~USART_CTRL_MSBF;
}

void DISPLAY_SetCS(void)
{
	GPIO_PinOutSet(LCDCS_PORT, LCDCS_PIN);
}

void DISPLAY_ClearCS(void)
{
	GPIO_PinOutClear(LCDCS_PORT, LCDCS_PIN);
}

void DISPLAY_SetVCOM(void)
{
	GPIO_PinOutSet(VCOM_PORT, VCOM_PIN);
}

void DISPLAY_ClearVCOM(void)
{
	GPIO_PinOutClear(VCOM_PORT, VCOM_PIN);
}

uint8_t DISPLAY_GetVCOM(void)
{
	//TODO
	uint8_t result = 0;

	return result;
}

void DISPLAY_SetDISP(void)
{
	GPIO_PinOutSet(DISP_PORT, DISP_PIN);
}

void DISPLAY_ClearDISP(void)
{
	GPIO_PinOutClear(DISP_PORT, DISP_PIN);
}


/* =================================Rework and transfer in sharplcd.c================================= */
/*
void DISPLAY_WriteLine(uint8_t * dataarr, uint8_t len, uint8_t linenumber, uint8_t vcom)
{
	SPI1_SetMSBFirst();											//Set MSB
	DISPLAY_SetCS();											//Set CS
	USART_SpiTransfer(USART1, SHARPLCD_WRITE_CMD | vcom);		//Line and Vcom
	SPI1_SetLSBFirst();											//Set LSB
	SPI1_SendPacket(&linenumber, 1);							//Line number
	SPI1_SendPacket(dataarr, len);								//Data
	SPI1_SendPacket((uint8_t *)(SHARPLCD_NULL_BYTE), 1);		//==Trailer==
	SPI1_SendPacket((uint8_t *)(SHARPLCD_NULL_BYTE), 1);		//===========
	DISPLAY_ClearCS();											//Clear CS
	SPI1_SetMSBFirst();											//Set MSB
}

void DISPLAY_Clear(uint8_t vcom)
{
	SPI1_SetMSBFirst();											//Set MSB
	DISPLAY_SetCS();											//Set CS
	USART_SpiTransfer(USART1, SHARPLCD_CLEAR_CMD | vcom);		//Command to clean and Vcom
	SPI1_SetLSBFirst();											//Set LSB
	SPI1_SendPacket((uint8_t *)(SHARPLCD_NULL_BYTE), 1);		//Trailer
	DISPLAY_ClearCS();											//Clear CS
	SPI1_SetMSBFirst();											//Set MSB
}
*/