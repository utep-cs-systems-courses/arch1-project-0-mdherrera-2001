#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}
void print_char_8x12(char c)
{
  //calculate how the shape is orientated
  //solve what is truly moving the orientation
  //possibly for row and column
  c -= 0x20;
  for(char row = 0;row < 10; row++) {
    unsigned short rowBits = font_8x12[c][row];
    for (char col = 0; col < 12; col++) {
      unsigned short colMask = 1 << (11-col);
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
  putchar('\n');
  }
}
void print_char_5x7(char c)
{
  c -= 0x20;
  for (char col = 9; col > 0; col--){
    unsigned short colMask = 1 << (8-col);
    // unsigned short rowBits = font_5x7[c][row];
    for (char row = 0; row < 5; row++) {
      unsigned short rowBits = font_5x7[c][row];
      // unsigned short colMask = 1 << (8-col);
      putchar( ( rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}
