/*
 * font.h
 *
 *  Created on: 29 ���. 2017 �.
 *      Author: user
 */

#ifndef INC_FONT_H_
#define INC_FONT_H_

// ASCII offset 32, i.e. starts with SPACE. Ends with upper case Z.

const unsigned char font8x8[] = {
		/*   0 ' ' */
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		/*   1 '!' */
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		/*   2 '"' */
		    /* 01101100 */  0x6c,
		    /* 01101100 */  0x6c,
		    /* 01101100 */  0x6c,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		/*   3 '#' */
		    /* 01101100 */  0x6c,
		    /* 01101100 */  0x6c,
		    /* 11111110 */  0xfe,
		    /* 01101100 */  0x6c,
		    /* 11111110 */  0xfe,
		    /* 01101100 */  0x6c,
		    /* 01101100 */  0x6c,
		    /* 00000000 */   0,
		/*   4 '$' */
		    /* 00011000 */  0x18,
		    /* 01111110 */  0x7e,
		    /* 11011000 */  0xd8,
		    /* 01111100 */  0x7c,
		    /* 00011010 */  0x1a,
		    /* 11111100 */  0xfc,
		    /* 00011000 */  0x18,
		    /* 00000000 */   0,
		/*   5 '%' */
		    /* 01100000 */  0x60,
		    /* 01100110 */  0x66,
		    /* 00001100 */  0xc,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 01100110 */  0x66,
		    /* 01000110 */  0x46,
		    /* 00000000 */   0,
		/*   6 '&' */
		    /* 01110000 */  0x70,
		    /* 11011000 */  0xd8,
		    /* 11010000 */  0xd0,
		    /* 01110000 */  0x70,
		    /* 11011010 */  0xda,
		    /* 11001100 */  0xcc,
		    /* 01111010 */  0x7a,
		    /* 00000000 */   0,
		/*   7 ''' */
		    /* 00111000 */  0x38,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		/*   8 '(' */
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 01100000 */  0x60,
		    /* 01100000 */  0x60,
		    /* 01100000 */  0x60,
		    /* 00110000 */  0x30,
		    /* 00011000 */  0x18,
		    /* 00000000 */   0,
		/*   9 ')' */
		    /* 01100000 */  0x60,
		    /* 00110000 */  0x30,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 01100000 */  0x60,
		    /* 00000000 */   0,
		/*   a '*' */
		    /* 00110000 */  0x30,
		    /* 10110100 */  0xb4,
		    /* 01111000 */  0x78,
		    /* 00110000 */  0x30,
		    /* 01111000 */  0x78,
		    /* 10110100 */  0xb4,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		/*   b '+' */
		    /* 00000000 */   0,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 11111100 */  0xfc,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		/*   c ',' */
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 11100000 */  0xe0,
		    /* 01100000 */  0x60,
		    /* 11000000 */  0xc0,
		/*   d '-' */
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 01111100 */  0x7c,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		/*   e '.' */
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 01110000 */  0x70,
		    /* 01110000 */  0x70,
		    /* 00000000 */   0,
		/*   f '/' */
		    /* 00000000 */   0,
		    /* 00001100 */  0xc,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 01100000 */  0x60,
		    /* 11000000 */  0xc0,
		    /* 10000000 */  0x80,
		    /* 00000000 */   0,
		/*  10 '0' */
		    /* 00111000 */  0x38,
		    /* 11000110 */  0xc6,
		    /* 11001110 */  0xce,
		    /* 11010110 */  0xd6,
		    /* 11100110 */  0xe6,
		    /* 11000110 */  0xc6,
		    /* 00111000 */  0x38,
		    /* 00000000 */   0,
		/*  11 '1' */
		    /* 00110000 */  0x30,
		    /* 01110000 */  0x70,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 01111000 */  0x78,
		    /* 00000000 */   0,
		/*  12 '2' */
		    /* 01111000 */  0x78,
		    /* 11001100 */  0xcc,
		    /* 00001100 */  0xc,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 01100000 */  0x60,
		    /* 11111100 */  0xfc,
		    /* 00000000 */   0,
		/*  13 '3' */
		    /* 11111100 */  0xfc,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 00011000 */  0x18,
		    /* 00001100 */  0xc,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 00000000 */   0,
		/*  14 '4' */
		    /* 00111000 */  0x38,
		    /* 01111000 */  0x78,
		    /* 11011000 */  0xd8,
		    /* 10011000 */  0x98,
		    /* 11111100 */  0xfc,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 00000000 */   0,
		/*  15 '5' */
		    /* 11111100 */  0xfc,
		    /* 11000000 */  0xc0,
		    /* 11111000 */  0xf8,
		    /* 00001100 */  0xc,
		    /* 00001100 */  0xc,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 00000000 */   0,
		/*  16 '6' */
		    /* 00111000 */  0x38,
		    /* 01100000 */  0x60,
		    /* 11000000 */  0xc0,
		    /* 11111000 */  0xf8,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 00000000 */   0,
		/*  17 '7' */
		    /* 11111100 */  0xfc,
		    /* 00001100 */  0xc,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 01100000 */  0x60,
		    /* 01100000 */  0x60,
		    /* 01100000 */  0x60,
		    /* 00000000 */   0,
		/*  18 '8' */
		    /* 01111000 */  0x78,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 00000000 */   0,
		/*  19 '9' */
		    /* 01111000 */  0x78,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 01111100 */  0x7c,
		    /* 00001100 */  0xc,
		    /* 00011000 */  0x18,
		    /* 01110000 */  0x70,
		    /* 00000000 */   0,
		/*  1a ':' */
		    /* 00000000 */   0,
		    /* 00111000 */  0x38,
		    /* 00111000 */  0x38,
		    /* 00000000 */   0,
		    /* 00111000 */  0x38,
		    /* 00111000 */  0x38,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		/*  1b ';' */
		    /* 00000000 */   0,
		    /* 00111000 */  0x38,
		    /* 00111000 */  0x38,
		    /* 00000000 */   0,
		    /* 00111000 */  0x38,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		/*  1c '<' */
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 01100000 */  0x60,
		    /* 11000000 */  0xc0,
		    /* 01100000 */  0x60,
		    /* 00110000 */  0x30,
		    /* 00011000 */  0x18,
		    /* 00000000 */   0,
		/*  1d '=' */
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 01111100 */  0x7c,
		    /* 00000000 */   0,
		    /* 01111100 */  0x7c,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		    /* 00000000 */   0,
		/*  1e '>' */
		    /* 01100000 */  0x60,
		    /* 00110000 */  0x30,
		    /* 00011000 */  0x18,
		    /* 00001100 */  0xc,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 01100000 */  0x60,
		    /* 00000000 */   0,
		/*  1f '?' */
		    /* 01111000 */  0x78,
		    /* 11001100 */  0xcc,
		    /* 00001100 */  0xc,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		/*  20 '@' */
		    /* 00111000 */  0x38,
		    /* 11001100 */  0xcc,
		    /* 11010110 */  0xd6,
		    /* 11010110 */  0xd6,
		    /* 11011100 */  0xdc,
		    /* 11000000 */  0xc0,
		    /* 00111000 */  0x38,
		    /* 00000000 */   0,
		/*  21 'A' */
		    /* 01111000 */  0x78,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11111100 */  0xfc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 00000000 */   0,
		/*  22 'B' */
		    /* 11111000 */  0xf8,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11111000 */  0xf8,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11111000 */  0xf8,
		    /* 00000000 */   0,
		/*  23 'C' */
		    /* 01111000 */  0x78,
		    /* 11001100 */  0xcc,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 00000000 */   0,
		/*  24 'D' */
		    /* 11110000 */  0xf0,
		    /* 11011000 */  0xd8,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11011000 */  0xd8,
		    /* 11110000 */  0xf0,
		    /* 00000000 */   0,
		/*  25 'E' */
		    /* 11111100 */  0xfc,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11111000 */  0xf8,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11111100 */  0xfc,
		    /* 00000000 */   0,
		/*  26 'F' */
		    /* 11111100 */  0xfc,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11111000 */  0xf8,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 00000000 */   0,
		/*  27 'G' */
		    /* 01111000 */  0x78,
		    /* 11001100 */  0xcc,
		    /* 11000000 */  0xc0,
		    /* 11011100 */  0xdc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 01111100 */  0x7c,
		    /* 00000000 */   0,
		/*  28 'H' */
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11111100 */  0xfc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 00000000 */   0,
		/*  29 'I' */
		    /* 01111110 */  0x7e,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 01111110 */  0x7e,
		    /* 00000000 */   0,
		/*  2a 'J' */
		    /* 00111100 */  0x3c,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 00011000 */  0x18,
		    /* 11011000 */  0xd8,
		    /* 01110000 */  0x70,
		    /* 00000000 */   0,
		/*  2b 'K' */
		    /* 11001100 */  0xcc,
		    /* 11011000 */  0xd8,
		    /* 11110000 */  0xf0,
		    /* 11100000 */  0xe0,
		    /* 11110000 */  0xf0,
		    /* 11011000 */  0xd8,
		    /* 11001100 */  0xcc,
		    /* 00000000 */   0,
		/*  2c 'L' */
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11111100 */  0xfc,
		    /* 00000000 */   0,
		/*  2d 'M' */
		    /* 11000110 */  0xc6,
		    /* 11101110 */  0xee,
		    /* 11111110 */  0xfe,
		    /* 11010110 */  0xd6,
		    /* 11000110 */  0xc6,
		    /* 11000110 */  0xc6,
		    /* 11000110 */  0xc6,
		    /* 00000000 */   0,
		/*  2e 'N' */
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11101100 */  0xec,
		    /* 11111100 */  0xfc,
		    /* 11011100 */  0xdc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 00000000 */   0,
		/*  2f 'O' */
		    /* 01111000 */  0x78,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 00000000 */   0,
		/*  30 'P' */
		    /* 11111000 */  0xf8,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11111000 */  0xf8,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 00000000 */   0,
		/*  31 'Q' */
		    /* 01111100 */  0x7c,
		    /* 11000110 */  0xc6,
		    /* 11000110 */  0xc6,
		    /* 11000110 */  0xc6,
		    /* 11010110 */  0xd6,
		    /* 11001000 */  0xc8,
		    /* 01110100 */  0x74,
		    /* 00000000 */   0,
		/*  32 'R' */
		    /* 11111000 */  0xf8,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11111000 */  0xf8,
		    /* 11110000 */  0xf0,
		    /* 11011000 */  0xd8,
		    /* 11001100 */  0xcc,
		    /* 00000000 */   0,
		/*  33 'S' */
		    /* 01111100 */  0x7c,
		    /* 11000000 */  0xc0,
		    /* 11000000 */  0xc0,
		    /* 01111000 */  0x78,
		    /* 00001100 */  0xc,
		    /* 00001100 */  0xc,
		    /* 11111000 */  0xf8,
		    /* 00000000 */   0,
		/*  34 'T' */
		    /* 11111100 */  0xfc,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		/*  35 'U' */
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 00000000 */   0,
		/*  36 'V' */
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		/*  37 'W' */
		    /* 11000110 */  0xc6,
		    /* 11000110 */  0xc6,
		    /* 11000110 */  0xc6,
		    /* 11010110 */  0xd6,
		    /* 11010110 */  0xd6,
		    /* 11111110 */  0xfe,
		    /* 01101100 */  0x6c,
		    /* 00000000 */   0,
		/*  38 'X' */
		    /* 11000110 */  0xc6,
		    /* 11000110 */  0xc6,
		    /* 01101100 */  0x6c,
		    /* 00111000 */  0x38,
		    /* 01101100 */  0x6c,
		    /* 11000110 */  0xc6,
		    /* 11000110 */  0xc6,
		    /* 00000000 */   0,
		/*  39 'Y' */
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 11001100 */  0xcc,
		    /* 01111000 */  0x78,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00110000 */  0x30,
		    /* 00000000 */   0,
		/*  3a 'Z' */
		    /* 11111100 */  0xfc,
		    /* 00001100 */  0xc,
		    /* 00011000 */  0x18,
		    /* 00110000 */  0x30,
		    /* 01100000 */  0x60,
		    /* 11000000 */  0xc0,
		    /* 11111100 */  0xfc,
		    /* 00000000 */   0,
};

#endif /* INC_FONT_H_ */
