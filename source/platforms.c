// ***************************************************************************
// Vectrex C programming file template
// ***************************************************************************

#include <vectrex.h>

// ---------------------------------------------------------------------------

// format:
// y, x
// h, w
const signed int platform01_dim[] =
{
  -16, -20,
  -12,  24
};

const signed int platform02_dim[] =
{
   16, -72,
  -12,  24
};

const signed int platform03_dim[] =
{
   16,  64,
  -12,  24
};

const signed int platform04_dim[] =
{
   20,  40,
  -12,  24
};

// format:
// height, width
// shiftreg, ...,  shiftreg
// ....
// shiftreg, ...,  shiftreg
// 
// every second row is a 'backward' row
// backward rows have the direction AND the bits reversed!
const unsigned int platform01_data[] =
{
  0x06, 0x12, 
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, // forward
  0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111000, // backward
  0b00000000, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11100000, 0b00000000, // backward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000  // backward
};

const unsigned int platform02_data[] =
{
  0x06, 0x12, 
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111000, // forward
  0b00000000, 0b00000000, 0b00000001, 0b11111111, 0b11111110, 0b01111111, 0b11111111, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, // backward
  0b11111111, 0b11111111, 0b11110000, 0b00011111, 0b11111111, 0b11111100, 0b00000000, 0b00000000, 0b00000000, 0b00000011, 0b11111111, 0b11111111, 0b00000001, 0b11111111, 0b11111111, 0b00000000, 0b00000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00011111, 0b11101000, 0b00000000, 0b00011111, 0b00110000, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10000000, 0b00000000, 0b00000000, 0b00000000, // backward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001, 0b11111111, 0b11100000, 0b00000000, 0b00000000, 0b00001001, 0b11000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00110000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000  // backward
};

const unsigned int platform03_data[] =
{
  0x06, 0x0C, 
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11100000, // forward
  0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, 0b00111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, // backward
  0b00000011, 0b11000111, 0b11111100, 0b00000000, 0b11111111, 0b11111111, 0b11111111, 0b10000001, 0b11111111, 0b11111111, 0b11111111, 0b11100000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000011, 0b10000000, 0b01111100, 0b00001110, 0b00000000, 0b00111111, 0b11111100, 0b00000000, // backward
  0b00000000, 0b00111111, 0b10000000, 0b00000000, 0b00001111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001100, 0b00000000  // backward
};

const unsigned int platform04_data[] =
{
  0x06, 0x0F, 
  0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, // forward
  0b00000000, 0b00111111, 0b11111100, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111100, // backward
  0b00000011, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b11111111, 0b11111000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b00000000, 0b00000011, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000000, 0b00000000, // backward
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110000, 0b00000000, 0b00000000, // forward
  0b00000000, 0b00000000, 0b00000000, 0b00000111, 0b11111111, 0b11110000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 // backward
};

// ***************************************************************************
// end of file
// ***************************************************************************
