#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSansBold12pt7b.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4
#define OLED_SDA   A4
#define OLED_SCL   A5
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 'basla', 22x24px
const unsigned char epd_bitmap_basla [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x23, 0x00, 0x0c,
  0x21, 0x80, 0x18, 0x20, 0xc0, 0x30, 0x20, 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x20, 0x20, 0x00, 0x20, 0x20, 0x00, 0x20, 0x20, 0x00, 0x20,
  0x20, 0x00, 0x20, 0x30, 0x00, 0x60, 0x18, 0x00, 0xc0, 0x0c, 0x01, 0x80, 0x07, 0xff, 0x00, 0x01,
  0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'zorluk', 22x24px
const unsigned char epd_bitmap_zorluk [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x7c, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x1f, 0xc0, 0x00, 0x3f,
  0xe0, 0x10, 0x7d, 0xf0, 0x38, 0xf8, 0xe0, 0x7d, 0xf0, 0x40, 0x3f, 0xe0, 0x00, 0x1f, 0xc0, 0x00,
  0x0f, 0x80, 0x00, 0x07, 0xc0, 0x00, 0x03, 0xe0, 0x00, 0x01, 0xf0, 0x00, 0x00, 0xe0, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'cerceve', 120x30px
const unsigned char epd_bitmap_cerceve [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x10, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x20, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
  0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x02, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xfc
};
// 'noktalar', 8x64px
const unsigned char epd_bitmap_noktalar [] PROGMEM = {
  0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02,
  0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02,
  0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02,
  0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00
};

// 'kolay', 22x24px
const unsigned char epd_bitmap_kolay [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0xc0, 0x00, 0x02, 0x2c, 0x00, 0x04, 0x38, 0x00, 0x04, 0xf0, 0x00, 0x04, 0xe0,
  0x00, 0x03, 0xc0, 0x00, 0x01, 0x98, 0x00, 0x03, 0x3e, 0x00, 0x06, 0x1f, 0x00, 0x04, 0x1f, 0x80,
  0x00, 0x1f, 0x80, 0x00, 0x0f, 0x80, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'zor', 22x24px
const unsigned char epd_bitmap_zor [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x01, 0x04, 0x00, 0x01, 0xfc, 0x00, 0x01,
  0x04, 0x00, 0x01, 0x04, 0x00, 0x01, 0x8c, 0x00, 0x0f, 0x8f, 0xe0, 0x10, 0x00, 0x20, 0x14, 0x00,
  0xa0, 0x12, 0x01, 0x20, 0x12, 0x01, 0x20, 0x1e, 0x01, 0xe0, 0x02, 0x01, 0x00, 0x03, 0x33, 0x00,
  0x03, 0xff, 0x00, 0x02, 0x49, 0x00, 0x02, 0x45, 0x00, 0x02, 0x95, 0x00, 0x04, 0x95, 0x00, 0x03,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char epd_bitmap_uzay [] PROGMEM = {
  0x38, 0x00, 0x70, 0x00, 0x60, 0x00, 0x30, 0x00, 0x7c, 0x00, 0x7c, 0x00, 0x37, 0xc0, 0x7f, 0xfe,
  0x7f, 0xfe, 0x37, 0xc0, 0x7c, 0x00, 0x7c, 0x00, 0x30, 0x00, 0x60, 0x00, 0x70, 0x00, 0x38, 0x00
};

const unsigned char meteor [] PROGMEM = {
  0x07, 0xe0, 0x3e, 0x7c, 0x68, 0x06, 0x40, 0x22, 0xd0, 0x03, 0xb0, 0x0d, 0x80, 0x05, 0x81, 0x81,
  0x81, 0x01, 0x88, 0x03, 0xc8, 0x0e, 0xc1, 0x02, 0x63, 0x26, 0x38, 0x0c, 0x0e, 0x18, 0x03, 0xf0
};
// 'cop', 16x15px
const unsigned char epd_bitmap_cop [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xff, 0xec, 0xc0, 0x2c, 0xff, 0xee, 0xc0, 0x2d, 0xff, 0xed,
  0xc0, 0x2d, 0xff, 0xee, 0xc0, 0x2c, 0xff, 0xec, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00
};
// 'kalp', 16x15px
const unsigned char epd_bitmap_kalp [] PROGMEM = {
  0x00, 0x00, 0x38, 0x1c, 0x7e, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0x7f, 0xfe, 0x7f, 0xfe, 0x3f, 0xfc, 0x1f, 0xf8, 0x0f, 0xf0, 0x07, 0xe0, 0x03, 0xc0
};
// 'mermi', 16x15px
const unsigned char epd_bitmap_mermi [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 0x3b, 0xb8, 0x2a, 0xa8, 0x2a, 0xa8, 0x2a, 0xa8, 0x2a, 0xa8,
  0x2a, 0xa8, 0x3b, 0xb8, 0x2a, 0xa8, 0x3b, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const unsigned char epd_bitmap_dokunulmazlik [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x1f, 0xfc, 0x3f, 0xfe, 0x3f, 0xfe, 0x3f, 0xfe, 0x1f, 0xfc,
  0x0f, 0xf8, 0x07, 0xf0, 0x03, 0xe0, 0x01, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00
};
const unsigned char epd_bitmap_gameOver [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x0f, 0x80, 0x81, 0x01, 0xff,
  0x00, 0x3f, 0x80, 0x81, 0xc3, 0xff, 0x07, 0xf0, 0x0f, 0xfc, 0x0f, 0x80, 0x81, 0x81, 0xff, 0x80,
  0x7f, 0xc0, 0x81, 0xc7, 0xff, 0x0f, 0xf8, 0x3f, 0xfc, 0x3f, 0xc3, 0xe7, 0xc7, 0xf8, 0x80, 0xf9,
  0xf3, 0x81, 0xcf, 0xff, 0x1f, 0x3c, 0x3c, 0x00, 0x38, 0x63, 0xe7, 0xc7, 0x00, 0x00, 0xe0, 0x73,
  0x81, 0xce, 0x03, 0x1c, 0x0c, 0x3c, 0x00, 0xf8, 0x73, 0xe7, 0xc7, 0x80, 0x00, 0xe0, 0x73, 0x81,
  0xce, 0x03, 0x1c, 0x0c, 0x3c, 0x00, 0x70, 0x73, 0xe7, 0xc7, 0x80, 0x00, 0xe6, 0x73, 0x81, 0xce,
  0x00, 0x1c, 0xcc, 0x3c, 0x00, 0x70, 0x73, 0xff, 0xc7, 0x00, 0x00, 0xe6, 0x73, 0x81, 0xce, 0x00,
  0x1c, 0xcc, 0x3c, 0xfc, 0x70, 0x73, 0xff, 0xc7, 0xfe, 0x00, 0xe0, 0x73, 0x81, 0xcf, 0xfc, 0x1c,
  0x0c, 0x3c, 0xfc, 0x70, 0x73, 0xff, 0xc7, 0xfe, 0x00, 0xe0, 0x73, 0x81, 0xcf, 0xfc, 0x1c, 0x0c,
  0x3c, 0x7c, 0x70, 0x73, 0x99, 0xc7, 0xfe, 0x00, 0xe0, 0x73, 0x81, 0xcf, 0xe4, 0x1f, 0xfc, 0x0c,
  0x10, 0x70, 0x73, 0x81, 0xc7, 0x00, 0x00, 0xe0, 0x73, 0x81, 0xce, 0x04, 0x1f, 0xf8, 0x0c, 0x10,
  0x7f, 0xf3, 0x81, 0xc7, 0x00, 0x00, 0xe0, 0x73, 0x81, 0xce, 0x00, 0x1f, 0xf8, 0x0c, 0x18, 0x79,
  0xc3, 0x01, 0xc7, 0x00, 0x00, 0xe0, 0x70, 0x87, 0x0e, 0x00, 0x1c, 0xe0, 0x3c, 0x1c, 0x79, 0xc3,
  0x01, 0xc7, 0x00, 0x00, 0xe0, 0x70, 0xe7, 0x0e, 0x00, 0x1c, 0xe0, 0x3f, 0xfc, 0xf0, 0x73, 0xc1,
  0xc1, 0xff, 0x80, 0x3f, 0xf0, 0xff, 0x0f, 0xff, 0x1c, 0x38, 0x0f, 0xfc, 0x70, 0x73, 0xc1, 0xc1,
  0xff, 0x80, 0x3f, 0xe0, 0xff, 0x0f, 0xff, 0x1c, 0x38, 0x0f, 0x90, 0x30, 0x73, 0xc1, 0x81, 0xf3,
  0x80, 0x3c, 0xc0, 0x78, 0x02, 0x7c, 0x10, 0x0e, 0x07, 0x10, 0x00, 0x01, 0x81, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0xc0, 0x00, 0x0c, 0x00, 0x00, 0x03, 0x00,
  0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0xc0, 0x00, 0x0c, 0x00, 0x03, 0x00, 0x00, 0x01,
  0x83, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x03, 0x00, 0x00, 0x01, 0x80,
  0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x18,
  0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x30,
  0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00,
  0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x03, 0x00, 0x00, 0x18, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00
};

const unsigned char* epd_bitmap_allArray[2] = {
  epd_bitmap_cerceve,
  epd_bitmap_noktalar
};
const unsigned char* menuIcons[2] = {
  epd_bitmap_basla,
  epd_bitmap_zorluk
};
const unsigned char* uzayNesneleri[5] = {
  meteor,
  epd_bitmap_cop,
  epd_bitmap_dokunulmazlik,
  epd_bitmap_mermi,
  epd_bitmap_kalp
};

#define  BUTTON_UP_PIN 12
#define  BUTTON_DOWN_PIN 4
#define  BUTTON_ENTER_PIN 8
#define  BUTTON_FIRE_PIN 7
#define  XPOS   0
#define  YPOS   1
#define  DELTAY 2
#define  tur 3
#define  mXPOS   0
#define  mYPOS   1
#define  mDELTAY 2
#define dayaniklilik 4

int val, meteorPnt = 0, sonc, NUMFLAKES, toplamCan = 3, atilanMermi = 0;
int potPin = 0, potPin2 = 1, isMenu = 0, konum = 1, deltayDegeri = 1;
boolean fire = false, zorMu = false, isClick = false, whereIs = false;
boolean ikiSnKoruma = false, canAldiMi = false, atesMi = false;
int ikiSnKorumaInt, ikiSnKorumaHedef, canBeklemesi, canBeklemesiHedef, turSayisi = 0;
int meteorDongusu = 50, skor = 0, skorSayaci = 0, mevcutMermi = 3, atesSayaci = 0;
int onlar = 8, yuzler = 8, birler = 8;

int sayilar[10][7] = {
  {0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 1, 1, 0},
  {1, 0, 0, 1, 1, 0, 0},
  {0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0}
};

int pins[3][7] = {
  {22, 23, 24, 25, 26, 27, 28},
  {29, 30, 31, 32, 33, 34, 35},
  {36, 37, 38, 39, 40, 41, 42}
};

void setup() {
  //Oyun bastan baslayinca yeni bir random turetme
  randomSeed(analogRead(3)); 
  //Cikis pinlerinin belirlenmesi
  for (int i = 22; i < 43; i++)
    pinMode(i, OUTPUT);
  for (int i = 2; i < 6; i++)
    pinMode(i, OUTPUT);
  for (int i = 13; i < 17; i++)
    pinMode(i, OUTPUT);
  //ekranin baslatilması
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  //butonların aktive edilmesi
  pinMode(BUTTON_UP_PIN, INPUT_PULLUP);
  pinMode(BUTTON_DOWN_PIN, INPUT_PULLUP);
  pinMode(BUTTON_ENTER_PIN, INPUT_PULLUP);
  pinMode(BUTTON_FIRE_PIN, INPUT_PULLUP);
}
void loop() {
  display.clearDisplay();
  //Gece gunduz modunun ayarlanmasi
  if (analogRead(potPin2) > 500) {
    display.invertDisplay(true);
  }
  else {
    display.invertDisplay(false);
  }
  //Ekran üzerinde hareket etme ve secim yapma
  if (digitalRead(BUTTON_UP_PIN) == LOW && whereIs == true ) {
    konum = 1;
    whereIs = false;
  }
  if (digitalRead(BUTTON_DOWN_PIN) == LOW && whereIs == false) {
    konum = 35;
    whereIs = true;
  }
  if (digitalRead(BUTTON_ENTER_PIN) == LOW && whereIs == false && isMenu==0) {
    isMenu = 2;
  }
  if (digitalRead(BUTTON_ENTER_PIN) == LOW && whereIs == true && isMenu==0) {
    isMenu = 1;
    konum = 1;
    whereIs = false;
  }
  if (digitalRead(BUTTON_ENTER_PIN) == LOW && whereIs == false && isClick == true) {
    zorMu = false;
    isMenu = 0;
  }
  if (digitalRead(BUTTON_ENTER_PIN) == LOW && whereIs == true && isClick == true) {
    zorMu = true;
    isMenu = 0;
  }
  //Ana menu
  if (isMenu == 0) {
    //Oyun bastan basladıgında degerlerin sifirlanmasi
    deltayDegeri = 1;
    mevcutMermi = 3;
    skor = 0;
    skorSayaci = 0;
    toplamCan = 3;
    ikiSnKoruma = false;
    meteorDongusu = 50;
    isClick = false;
    //Nesnelerin ekran uzerindeki cizimleri
    display.drawBitmap(5, 4, menuIcons[0], 24, 24, WHITE);
    display.drawBitmap(5, 37, menuIcons[1], 24, 24, WHITE);
    display.drawBitmap(0, konum, epd_bitmap_cerceve, 120, 30, WHITE);
    display.drawBitmap(120, 0, epd_bitmap_noktalar, 8, 64, WHITE);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setFont(&FreeSansBold12pt7b);
    display.setCursor(28, 25);
    display.print("Basla");
    display.setCursor(28, 58);
    display.print("Zorluk");
  }
  //Zorluk secim menusu
  if (isMenu == 1) {
    isClick = true;
    //Nesnelerin ekran uzerinde cizilmesi
    display.drawBitmap(5, 4, epd_bitmap_kolay, 24, 24, WHITE);
    display.drawBitmap(5, 37, epd_bitmap_zor, 24, 24, WHITE);
    display.drawBitmap(0, konum, epd_bitmap_cerceve, 120, 30, WHITE);
    display.drawBitmap(120, 0, epd_bitmap_noktalar, 8, 64, WHITE);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setFont(&FreeSansBold12pt7b);
    display.setCursor(28, 25);
    display.print("Kolay");
    display.setCursor(28, 58);
    display.print("Zor");
  }
  //Oyun menusu
  if (isMenu == 2) {
    //Oyunun oynandigi metod
    testanimate();
    display.clearDisplay();
    display.drawBitmap(1, 1, epd_bitmap_gameOver, 120, 46, WHITE);
    display.display();
    noTone(13);
    delay(5000);
    //pinlerin sifirlanmasi
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < 7; i++) {
        digitalWrite(pins[j][i], LOW);
      }
    }
    isMenu = 0;
  }
  display.display();
}

void testanimate() {
  NUMFLAKES = 1;
  //zorluk modunun olmama durumundaki akis degerleri
  if (zorMu == false) {
    deltayDegeri = 2;
    meteorDongusu = 25;
  }
  int8_t canSay = 0, mermiSay = 0, dokunulmazlikSay = 0, rnd;
  int8_t f, icons[10][5];
  int8_t mermiler[10][3];
  boolean mermiKnt = true, canKnt = true, dokunulmazlikKnt = true;
  int kontTut = 0, kontTut2, kontTut3;

  //ilk uzay nesnenin turetilmesi
  for (f = 0; f < NUMFLAKES; f++) {
    icons[f][YPOS] = 128;
    icons[f][XPOS]   = random(0, display.height() - 16);
    icons[f][DELTAY] = deltayDegeri;
    icons[f][tur] = 0;
    icons[f][dayaniklilik] = 1;
  }

  //Oyunun oynandigi dongu
  for (;;) {
    noTone(13);
    display.clearDisplay();

    //Mermi atesleme islemi
    if (digitalRead(BUTTON_FIRE_PIN) == LOW && mevcutMermi > 0 && atesMi == false) {
      mermiler[atilanMermi][mXPOS] = 17;
      mermiler[atilanMermi][mYPOS] = 40 + val;
      atilanMermi++;
      mevcutMermi--;
      atesMi = true;
      atesSayaci = 0;
    }
    //Birden fazla merminin ateslenmesinin onlenmesi
    atesSayaci++;
    if (atesSayaci == 5) {
      atesMi = false;
    }

    //Belli bir dongude bir uzay nesnesi turetilmesi
    meteorPnt++;
    if (meteorPnt >= meteorDongusu && meteorPnt % meteorDongusu == 0) {
      //can ve mermi uretimi kontrolu ile uretimin zorululastırılması
      if (canSay != 12 && mermiSay != 13)
        rnd = random(0, 5);
      //Mermi nesnesi olusumu durumunda 14 tur oranında tekrar ateslenmesinin engellenmesi
      if (mermiKnt == false && rnd == 3) {
        for (;;) {
          rnd = random(0, 5);
          if (rnd != 3 && canKnt == true && dokunulmazlikKnt == true)
            break;
          if (canKnt == false && dokunulmazlikKnt == false) {
            rnd = random(0, 2);
            break;
          }
          if (canKnt == false && rnd != 4 && rnd != 3) {
            break;
          }
          if (dokunulmazlikKnt == false && rnd != 3 && rnd != 2) {
            break;
          }
        }
      }
      //Can nesnesi olusumu durumunda 14 tur oranında tekrar ateslenmesinin engellenmesi
      if (canKnt == false && rnd == 4) {
        for (;;) {
          rnd = random(0, 5);
          if (rnd != 4 && mermiKnt == true && dokunulmazlikKnt == true)
            break;
          if (mermiKnt == false && dokunulmazlikKnt == false) {
            rnd = random(0, 2);
            break;
          }
          if (mermiKnt == false && rnd != 4 && rnd != 3) {
            break;
          }
          if (dokunulmazlikKnt == false && rnd != 2 && rnd != 4) {
            break;
          }
        }
      }
      //Dokunulmazlik nesnesi olusumu durumunda 14 tur oranında tekrar ateslenmesinin engellenmesi
      if (dokunulmazlikKnt == false && rnd == 2) {
        for (;;) {
          rnd = random(0, 5);
          if (rnd != 2 && mermiKnt == true && canKnt == true)
            break;
          if (mermiKnt == false && canKnt == false) {
            rnd = random(0, 2);
            break;
          }
          if (mermiKnt == false && rnd != 2 && rnd != 3) {
            break;
          }
          if (canKnt == false && rnd != 2 && rnd != 4) {
            break;
          }
        }
      }
      //Zorunlu nesne uretimi
      if (canSay == 12)
        rnd = 4;
      if (mermiSay == 13)
        rnd = 3;
      if (dokunulmazlikSay == 11)
        rnd = 2;
      //rnd tipine gore nesnelerin uretilmesi, deger atanmasi
      if (rnd == 0) {
        icons[f][YPOS] = 128;
        icons[f][XPOS]   = random(0, display.height() - 16);
        icons[f][DELTAY] = deltayDegeri;
        icons[f][tur] = 0;
        icons[f][dayaniklilik] = 1;
        NUMFLAKES++;
        mermiSay++;
        dokunulmazlikSay++;
        canSay++;
      }
      if (rnd == 1) {
        icons[f][YPOS] = 128;
        icons[f][XPOS]   = random(0, display.height() - 16);
        icons[f][DELTAY] = deltayDegeri;
        icons[f][dayaniklilik] = 0;
        icons[f][tur] = 1;
        NUMFLAKES++;
        dokunulmazlikSay++;
        mermiSay++;
        canSay++;
      }
      if (rnd == 2) {
        icons[f][YPOS] = 128;
        icons[f][XPOS]   = random(0, display.height() - 16);
        icons[f][DELTAY] = deltayDegeri;
        icons[f][tur] = 2;
        icons[f][dayaniklilik] = 0;
        NUMFLAKES++;
        mermiSay++;
        canSay++;
        dokunulmazlikKnt = false;
        kontTut3 = 14 - dokunulmazlikSay;
        dokunulmazlikSay = 0;
      }
      if (rnd == 3) {
        icons[f][YPOS] = 128;
        icons[f][XPOS]   = random(0, display.height() - 16);
        icons[f][DELTAY] = deltayDegeri;
        icons[f][tur] = 3;
        icons[f][dayaniklilik] = 0;
        NUMFLAKES++;
        dokunulmazlikSay++;
        canSay++;
        mermiKnt = false;
        kontTut = 14 - mermiSay;
        mermiSay = 0;
      }
      if (rnd == 4) {
        icons[f][YPOS] = 128;
        icons[f][XPOS]   = random(0, display.height() - 16);
        icons[f][DELTAY] = deltayDegeri;
        icons[f][tur] = 4;
        icons[f][dayaniklilik] = 0;
        NUMFLAKES++;
        dokunulmazlikSay++;
        mermiSay++;
        canKnt = false;
        kontTut2 = 14 - canSay;
        canSay = 0;
      }
      //14 turluk limitin doldurulmasi ile tekrar uretime izin verilmesi
      if (canSay == kontTut2 && canKnt == false)
        canKnt = true;
      if (dokunulmazlikSay == kontTut3 && dokunulmazlikKnt == false)
        dokunulmazlikKnt = true;
      if (mermiSay == kontTut && mermiKnt == false)
        mermiKnt = true;
    }
    //Nesnelerin ekrandaki cizimi
    for (f = 0; f < NUMFLAKES; f++) {
      val = analogRead(potPin);
      if (val >= 512)
        val = (512 - val) / 16;
      else
        val = (512 - val) / 32;
      display.drawBitmap(icons[f][YPOS], icons[f][XPOS], uzayNesneleri[icons[f][tur]], 16, 15, WHITE);
      display.drawBitmap(0, 32 + val, epd_bitmap_uzay, 16, 16, WHITE);
    }
    //Mermilerin ekrandaki cizimi
    for (int i = 0; i < atilanMermi; i++) {
      display.drawCircle(mermiler[i][mXPOS], mermiler[i][mYPOS], 2, WHITE);
    }
    //Her merminin ekran üzerindeki kordinatlarının belirlenmesi, siniri gecenlerin silinmesi
    for (int i = 0; i < atilanMermi; i++) {
      mermiler[i][mXPOS] += deltayDegeri;
      if (mermiler[i][mXPOS] >= 126 - deltayDegeri && atilanMermi == 1) {
        mermiler[i][mXPOS] = 0;
        mermiler[i][mYPOS] = 0;
        atilanMermi--;
      }
      if (mermiler[i][mXPOS] >= 128 - deltayDegeri && atilanMermi > 1) {
        mermiler[i][mXPOS] = mermiler[i + 1][mXPOS];
        mermiler[i][mYPOS] = mermiler[i + 1][mYPOS];
        atilanMermi--;
      }
    }
    //Uzay nesnelerinin konum duzenlemesi ve carpisma kontrolu
    for (f = 0; f < NUMFLAKES; f++) {
      icons[f][DELTAY] = deltayDegeri;
      icons[f][YPOS] -= icons[f][DELTAY];
      //nesnenin sinira ulasip silinmesi
      if (icons[f][YPOS] <= 0) {
        icons[f][YPOS] = icons[NUMFLAKES - 1][YPOS];
        icons[f][XPOS]   = icons[NUMFLAKES - 1][XPOS];
        icons[f][DELTAY] = icons[NUMFLAKES - 1][DELTAY];
        icons[f][tur] = icons[NUMFLAKES - 1][tur];
        icons[f][dayaniklilik] = icons[NUMFLAKES - 1][dayaniklilik];
        NUMFLAKES--;
      }
      //nesnenin uzay copu olması ve uzay gemisine carpmasi
      else if (icons[f][YPOS] < 16 && (icons[f][XPOS] > val + 16 && icons[f][XPOS] < val + 48 )) {
        if ((icons[f][tur] == 0 || icons[f][tur] == 1) && ikiSnKoruma == false) {
          tone(13, 100);
          toplamCan--;
          ikiSnKoruma = true;
          ikiSnKorumaInt = meteorPnt;
          ikiSnKorumaHedef = meteorPnt;
        }
        //uzay gemisinin can alma durumu
        if (icons[f][tur] == 4 && toplamCan != 3 && canAldiMi == false) {
          toplamCan++;
          canAldiMi = true;
          canBeklemesi = meteorPnt;
          canBeklemesiHedef = meteorPnt;
        }
        //uzay gemisinin dokunulmaz olma durumu
        if (icons[f][tur] == 2) {
          ikiSnKoruma = true;
          ikiSnKorumaInt = meteorPnt;
          ikiSnKorumaHedef = meteorPnt + meteorDongusu;
        }
        //uzay gemisinin mermi alma durumu
        if (icons[f][tur] == 3 && mevcutMermi < 3) {
          mevcutMermi++;
        }
        icons[f][YPOS] = icons[NUMFLAKES - 1][YPOS];
        icons[f][XPOS]   = icons[NUMFLAKES - 1][XPOS];
        icons[f][DELTAY] = icons[NUMFLAKES - 1][DELTAY];
        icons[f][tur] = icons[NUMFLAKES - 1][tur];
        icons[f][dayaniklilik] = icons[NUMFLAKES - 1][dayaniklilik];
        NUMFLAKES--;
      }
      int akisDegeri = 0;
      akisDegeri = deltayDegeri;
      if (akisDegeri < 2)
        akisDegeri = 2;
      //Mermilerin nesneler ile olan karsilastirmasi
      for (int i = 0; i < atilanMermi; i++) {
        if (icons[f][XPOS] <= mermiler[i][mYPOS] - 1 && icons[f][XPOS] + 16 > mermiler[i][mYPOS]) {
          //merminin uzay copune carpma durumu
          if (icons[f][YPOS] >= mermiler[i][mXPOS] - akisDegeri
              && icons[f][YPOS] <= mermiler[i][mXPOS] + akisDegeri
              && icons[f][tur] == 1) {
            icons[f][YPOS] = icons[NUMFLAKES - 1][YPOS];
            icons[f][XPOS]   = icons[NUMFLAKES - 1][XPOS];
            icons[f][DELTAY] = icons[NUMFLAKES - 1][DELTAY];
            icons[f][tur] = icons[NUMFLAKES - 1][tur];
            icons[f][dayaniklilik] = icons[NUMFLAKES - 1][dayaniklilik];
            NUMFLAKES--;
            //Mermi silme islemleri
            if (atilanMermi == 1) {
              mermiler[i][mXPOS] = 0;
              mermiler[i][mYPOS] = 0;
              atilanMermi--;
            }
            if (atilanMermi > 1) {
              mermiler[i][mXPOS] = mermiler[i + 1][mXPOS];
              mermiler[i][mYPOS] = mermiler[i + 1][mYPOS];
              atilanMermi--;
            }
          }
          //Merminin meteora carpma durumu
          else if (icons[f][YPOS] >= mermiler[i][mXPOS] - akisDegeri
                   && icons[f][YPOS] <= mermiler[i][mXPOS] + akisDegeri
                   && icons[f][tur] == 0) {
            if (icons[f][dayaniklilik] == 0) {
              icons[f][YPOS] = icons[NUMFLAKES - 1][YPOS];
              icons[f][XPOS]   = icons[NUMFLAKES - 1][XPOS];
              icons[f][DELTAY] = icons[NUMFLAKES - 1][DELTAY];
              icons[f][tur] = icons[NUMFLAKES - 1][tur];
              icons[f][dayaniklilik] = icons[NUMFLAKES - 1][dayaniklilik];
              NUMFLAKES--;
            }
            else {
              icons[f][dayaniklilik] = 0;
            }
            if (atilanMermi == 1) {
              mermiler[i][mXPOS] = 0;
              mermiler[i][mYPOS] = 0;
              atilanMermi--;
            }
            if (atilanMermi > 1) {
              mermiler[i][mXPOS] = mermiler[i + 1][mXPOS];
              mermiler[i][mYPOS] = mermiler[i + 1][mYPOS];
              atilanMermi--;
            }
          }
        }
      }
    }
    //Tek can alma isleminin ardindan yeniden can almasinin engellenmesi
    if (canAldiMi == true) {
      canBeklemesi++;
      if (canBeklemesi == canBeklemesiHedef + 16) {
        canAldiMi = false;
      }
    }
    //Uzay gemisinin dokunulmaz kilinma durumu
    if (ikiSnKoruma == true) {
      display.drawCircle(0, 40 + val, 13, WHITE);
      ikiSnKorumaInt++;
      if (ikiSnKorumaInt >= ikiSnKorumaHedef + meteorDongusu * 2)
        ikiSnKoruma = false;
    }
    display.display();
    //Can lambalarının ayarlanmasi
    if (toplamCan == 3) {
      digitalWrite(5, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
    }
    if (toplamCan == 2) {
      digitalWrite(5, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(2, HIGH);
    }
    if (toplamCan == 1) {
      digitalWrite(5, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
    }
    if (toplamCan == 0) {
      digitalWrite(5, LOW);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      //Oyun sonu
      break;
    }
    //Mermi lambalarının ayarlanmasi
    if (mevcutMermi == 3) {
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
    }
    if (mevcutMermi == 2) {
      digitalWrite(16, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(14, HIGH);
    }
    if (mevcutMermi == 1) {
      digitalWrite(16, LOW);
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
    }
    if (mevcutMermi == 0) {
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, LOW);
    }
    delay(10);
    //Zor olma durumunda nesnelerin hizlandirilma islemi
    if (zorMu == true && deltayDegeri < 12) {
      turSayisi++;
      if (turSayisi % 170 == 0 && turSayisi != 0) {
        deltayDegeri++;
        if (meteorDongusu >= 15)
          meteorDongusu = meteorDongusu / 2;
        else
          meteorDongusu -= 1;
      }
    }
    //Skor hesaplanmasi ve ledlere yansitilmasi
    skorSayaci++;
    if (skorSayaci % meteorDongusu == 0)
      skor++;
    birler = skor % 10;
    onlar = (skor % 100) / 10;
    yuzler = (skor % 1000) / 100;
    for (int i = 0; i < 7; i++) {
      if (sayilar[onlar][i] == 1)
        digitalWrite(pins[1][i], HIGH);
      else
        digitalWrite(pins[1][i], LOW);
    }
    for (int i = 0; i < 7; i++) {
      if (sayilar[birler][i] == 1)
        digitalWrite(pins[2][i], HIGH);
      else
        digitalWrite(pins[2][i], LOW);
    }
    for (int i = 0; i < 7; i++) {
      if (sayilar[yuzler][i] == 1)
        digitalWrite(pins[0][i], HIGH);
      else
        digitalWrite(pins[0][i], LOW);
    }
  }
}