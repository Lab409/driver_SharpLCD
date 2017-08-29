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
#include "font.h"

sharplcd_t sharplcd;

/* =============TEST FIELD============= */

void Bitmap(const unsigned char* bitmap, int width, int height, char line, char options);
char m_buffer[12];
void WriteBuffer(char line);
void Print(const char* text, char line, char options);
uint8_t Vcom = 0x40;

/* ==================================== */

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

	//Set Display ON
	DISPLAY_SetDISP();

	while (1)
	{
		//Straight line
		uint8_t line_1[12] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

		//LEDs
		GPIO_PinOutToggle(LED0_PORT, LED0_PIN);
		GPIO_PinOutToggle(LED1_PORT, LED1_PIN);

		// ========== Test Field

		// ====================== First decent result
		/*
		SHARPLCD_WriteLine(&sharplcd, 2, line_1);
		Delay(500);
		SHARPLCD_WriteLine(&sharplcd, 4, line_1);
		Delay(500);
		SHARPLCD_WriteLine(&sharplcd, 6, line_1);
		Delay(500);
		SHARPLCD_Clear(&sharplcd);
		Delay(500);
		Bitmap(pixel_ti_logo, 96, 96, 0, 1);
		Delay(1000);
		SHARPLCD_Clear(&sharplcd);
		Delay(1000);
		Print("TESTING!", 8, 0);
		Delay(1000);
		Print("OVERIDE!", 8, 0);
		Delay(1000);
		Print("   HR:68   ", 16, 0);
		Delay(1000);
		Print("   HR:72   ", 16, 0);
		Delay(1000);
		Print("   HR:79   ", 16, 0);
		Delay(1000);
		SHARPLCD_Clear(&sharplcd);
		*/
		// ==============================================

		Delay(1000);
		SHARPLCD_Clear(&sharplcd);
		Delay(1000);
		Bitmap(heart, 96, 96, 0, 1);
		Delay(1000);
		SHARPLCD_Clear(&sharplcd);

	}
}
/* ============================================================ */




/* ==========================TEST FIELD========================== */

void Bitmap(const unsigned char* bitmap, int width, int height, char line, char options)
{
	SPI1_SetMSBFirst();

    if (!bitmap) return;

    unsigned char b;
    int i = 0;
    int p = 0;
    int x = width/8;

    while (height > 0 && line < 96) {
        while (i < 96/8 && i < x) {
            b = bitmap[p+i];
            if (!(options & 1)) {         // invert bits if DISP_INVERT is _NOT_ selected
                b = ~b;// pixels are LOW active
            }
            m_buffer[i] = b;
            i++;
        }
        WriteBuffer(line);
        p += x;
        i = 0;
        height--;
        line++;
    }
}

void WriteBuffer(char line)
{
    if (line > 96) return;         // ignore writing to invalid lines

    SPI1_SetMSBFirst();

    DISPLAY_SetCS();

    USART_SpiTransfer(USART1, 0x80 | Vcom);

    Vcom ^= 0x40;

    SPI1_SetLSBFirst();

    USART_SpiTransfer(USART1, line+1);                // send line address

    SPI1_SetMSBFirst();

    char j = 0;
    while (j < (96/8)) {           // write pixels / 8 bytes
        USART_SpiTransfer(USART1, m_buffer[j++]);
    }

    USART_SpiTransfer(USART1, 0);
    USART_SpiTransfer(USART1, 0);

    SPI1_SetMSBFirst();

    DISPLAY_ClearCS();
}

void Print(const char* text, char line, char options)
{
    SPI1_SetMSBFirst();

    // c = char
    // b = bitmap
    // i = text index
    // j = line buffer index
    // k = char line
    unsigned char c, b, i, j, k;

    // rendering happens line-by-line because this display can only be written by line
    k = 0;
    while (k < 8 && line < 96) { // loop for 8 character lines while within display
        i = 0;
        j = 0;
        while (j < (96/8) && (c = text[i]) != 0) {     // while we did not reach end of line or string
            if (c < ' ' || c > 'Z') {                        // invalid characters are replace with SPACE
                c = ' ';
            }

            c = c - 32;                                      // convert character to index in font table
            b = font8x8[(c*8)+k];                            // retrieve byte defining one line of character

            if (!(options & 1)) {                  // invert bits if DISP_INVERT is _NOT_ selected
                b = ~b;// pixels are LOW active
            }

            if ((options & 2) && (c != 0)) {         // double width rendering if DISP_WIDE and character is not SPACE
                //doubleWide(b, j);
                j += 2;                                      // we've written two bytes to buffer
            } else {                                         // else regular rendering
                m_buffer[j] = b;                             // store pixels in line buffer
                j++;                                         // we've written one byte to buffer
            }

            i++;                                             // next character
        }

        while (j < (96/8)) {                           // pad line for empty characters
            m_buffer[j] = 0xff;
            j++;
        }

        WriteBuffer(line++);                                 // write line buffer to display

        if ((options & 4)&& line < 96) {        // repeat line if DISP_HIGH is selected
            WriteBuffer(line++);
        }

        k++;                                                 // next pixel line
    }
}
/* ============================================================== */

