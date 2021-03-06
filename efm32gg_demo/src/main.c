#include <stdbool.h>
#include <stdint.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_cmu.h"
#include "em_usart.h"
#include "InitDevice.h"
#include "sharpLCD.h"
#include "bsp.h"
#include "testFrame.h"

sharplcd_t sharplcd;

// ========================== TEST

char heartRate[12];
int hr_curr_1 = 6;
int hr_curr_2 = 0;

char text_buffer[9];
int min_1 = 0;
int sec_1 = 0;
int min_2 = 0;
int sec_2 = 0;

// ===============================

/* =====Counts 1ms timeTicks===== */
volatile uint32_t msTicks = 0;

/* =====Interrupt Handlers Section===== */
void SysTick_Handler(void)
{
	msTicks++;
}

/* =====================Main Section===================== */
int main(void)
{
	// Chip errata
	CHIP_Init();
	enter_DefaultMode_from_RESET();

	SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000);

	// Init Display
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
	SHARPLCD_Init(&sharplcd);

	//Clear Display before start
	SHARPLCD_Clear(&sharplcd);

	//Set Display ON
	DISPLAY_SetDISP();

	//Clear Display (just in case)
	SHARPLCD_Clear(&sharplcd);

	//Clear Buffer
	SHARPLCD_ClearFrameBuffer(&sharplcd);

	while (1)
	{
		//LEDs
		GPIO_PinOutToggle(LED0_PORT, LED0_PIN);
		GPIO_PinOutToggle(LED1_PORT, LED1_PIN);

		//Display

		if (sec_2 > 9)
		{
			sec_2 = 0;
			sec_1++;
		}

		if (sec_1 == 6 && sec_2 == 0)
		{
			sec_1 = 0;
			sec_2 = 0;
			min_2++;
		}

		if (min_2 > 9)
		{
			min_2 = 0;
			min_1++;
		}

		text_buffer[0] = ' ';
		text_buffer[1] = ' ';
		text_buffer[2] = ' ';
		text_buffer[3] = min_1 + '0';
		text_buffer[4] = min_2 + '0';
		text_buffer[5] = ':';
		text_buffer[6] = sec_1 + '0';
		text_buffer[7] = sec_2 + '0';
		text_buffer[8] = 0;

		SHARPLCD_AddTextToBuffer(&sharplcd, text_buffer, 0, 5);

		// ============ BATTERY
		if ((hr_curr_2 % 2) == 0)
		{
			SHARPLCD_AddArrayToBuffer(&sharplcd, battery_0, 96, 8, 0, 1);
		}
		else
		{
			SHARPLCD_AddArrayToBuffer(&sharplcd, battery_100, 96, 8, 0, 1);
		}
		SHARPLCD_AddArrayToBuffer(&sharplcd, heart, 96, 96, 0, 1);
		// ====================

		sec_2++;


		if (hr_curr_2 > 9)
		{
			hr_curr_2 = 0;
			hr_curr_1++;
		}

		if (hr_curr_1 == 8 && hr_curr_2 == 0)
		{
			hr_curr_1 = 6;
			hr_curr_2 = 0;
		}

		heartRate[0] = ' ';
		heartRate[1] = ' ';
		heartRate[2] = ' ';
		heartRate[3] = ' ';
		heartRate[4] = ' ';
		heartRate[5] = hr_curr_1 + '0';
		heartRate[6] = hr_curr_2 + '0';
		heartRate[7] = ' ';
		heartRate[8] = ' ';
		heartRate[9] = ' ';
		heartRate[10] =  ' ';
		heartRate[11] = 0;

		SHARPLCD_AddTextToBuffer(&sharplcd, heartRate, 40, 1);

		hr_curr_2++;

		Delay(500);
		SHARPLCD_ShowFrame(&sharplcd);
	}
}
