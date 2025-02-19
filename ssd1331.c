#ifndef SSD1331_C
#define SSD1331_C

#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SSD1331_SPI_PORT spi0
#define SSD1331_PIN_CS   17  //chip select, activated by low
#define SSD1331_PIN_DC   16  //data/commandm, command = 0, data = 1
#define SSD1331_PIN_RST  20  //reset, activated by low
#define SSD1331_PIN_SCK  18  //spi clock
#define SSD1331_PIN_MOSI 19  //mosi

//function sends 1 byte of command
void ssd1331_send_cmd(uint8_t cmd){
    gpio_put(SSD1331_PIN_DC, 0);
    gpio_put(SSD1331_PIN_CS, 0);
    spi_write_blocking(SSD1331_SPI_PORT, &cmd, 1);
    gpio_put(SSD1331_PIN_CS, 1);
}
//function sends len bytes of command
void ssd1331_send_many_cmd(uint8_t* cmd, uint8_t len){
    gpio_put(SSD1331_PIN_DC, 0);
    gpio_put(SSD1331_PIN_CS, 0);
    spi_write_blocking(SSD1331_SPI_PORT, cmd, len);
    gpio_put(SSD1331_PIN_CS, 1);
}

//function resets oled display (doesn't turn all the pixels black)
void ssd1331_reset() {
    gpio_put(SSD1331_PIN_RST, 0);
    sleep_ms(100);
    gpio_put(SSD1331_PIN_RST, 1);
    sleep_ms(100);
}

//initialization function
void ssd1331_init() {
    //initializing the pins
    gpio_init(SSD1331_PIN_CS);
    gpio_init(SSD1331_PIN_DC);
    gpio_init(SSD1331_PIN_RST);
    gpio_set_dir(SSD1331_PIN_CS, GPIO_OUT);
    gpio_set_dir(SSD1331_PIN_DC, GPIO_OUT);
    gpio_set_dir(SSD1331_PIN_RST, GPIO_OUT);

    //initializing spi
    spi_init(SSD1331_SPI_PORT, 1000000); // 1 MHz
    gpio_set_function(SSD1331_PIN_SCK, GPIO_FUNC_SPI);
    gpio_set_function(SSD1331_PIN_MOSI, GPIO_FUNC_SPI);

    //resetting the screen
    //necessary part of the power on sequence
    ssd1331_reset();

    //0xAE - set display off
    //0xA4 - set display mode to normal
    //0xAF - set display on
    uint8_t cmd[3] = {0xAE, 0xA4, 0xAF};
    ssd1331_send_many_cmd(cmd, 3);

    //set remap to smth normal
    ssd1331_send_cmd(0xA0);
    ssd1331_send_cmd(0x72);
}

//function sends 1 byte of data
//please note, that in rgb565 1 color consist of 2 bytes
void ssd1331_send_data(uint8_t data){
    gpio_put(SSD1331_PIN_DC, 1);
    gpio_put(SSD1331_PIN_CS, 0);
    spi_write_blocking(SSD1331_SPI_PORT, &data, 1);
    gpio_put(SSD1331_PIN_CS, 1);
}

//function sens 2 bytes of data
//used to set color
void ssd1331_send_data_2b(uint16_t data){
    uint8_t color_data[2] = {data >> 8, data & 0xFF};
    gpio_put(SSD1331_PIN_DC, 1);
    gpio_put(SSD1331_PIN_CS, 0);
    spi_write_blocking(SSD1331_SPI_PORT, color_data, 2);
    gpio_put(SSD1331_PIN_CS, 1);
}

//primitive function for drawing pixels
//doesn't check if x and y are in bounds
void ssd1331_draw_pixel(uint8_t x, uint8_t y, uint16_t color) {
    uint8_t cmd[3];

    //set column address
    cmd[0] = 0x15;
    cmd[1] = x;
    cmd[2] = 95;
    ssd1331_send_many_cmd(cmd,3);

    //set row address
    cmd[0] = 0x75;
    cmd[1] = y;
    cmd[2] = 63;
    ssd1331_send_many_cmd(cmd, 3);

    //set color
    ssd1331_send_data_2b(color);
}

//temporary, change later
void ssd1331_clear(){
    for(int x = 0; x < 96; x++){
        for(int y = 0; y < 64; y++){
            ssd1331_draw_pixel(x, y, 0x0000);
        }
    }
}
#endif