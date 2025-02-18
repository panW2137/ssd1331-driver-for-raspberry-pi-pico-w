#ifndef FONT_C
#define FONT_C

#include "ssd1331.c"
#include <math.h>

typedef struct{
    uint8_t height;
    uint8_t horizontalSpacing;
    uint8_t verticalSpacing;

    uint8_t charWidthList[256];
    uint8_t charBodyList[256][8];
} font_font8; //wonderful name

typedef struct
{
    char name;
    uint8_t width;
    uint8_t body[8];
} font_char;


font_char font_defaultTemplate[26] = {
    {
        .name = 'a',
        .width = 4,
        .body = {
            0b00001111,
            0b00001001,
            0b00001111,
            0b00001001,
            0b00001001,
            0,0,0
        }
    },
    {
        .name = 'b',
        .width = 4,
        .body = {
            0b00001110,
            0b00001001,
            0b00001110,
            0b00001001,
            0b00001110,
            0,0,0
        }
    },
    {
        .name = 'c',
        .width = 3,
        .body = {
            0b00000111,
            0b00000101,
            0b00000100,
            0b00000101,
            0b00000111,
            0,0,0
        }
    },
    {
        .name = 'd',
        .width = 4,
        .body = {
            0b00001110,
            0b00001001,
            0b00001001,
            0b00001001,
            0b00001110,
            0,0,0
        }
    },
    {
        .name = 'e',
        .width = 3,
        .body = {
            0b00000111,
            0b00000100,
            0b00000111,
            0b00000100,
            0b00000111,
            0,0,0
        }
    },
    {
        .name = 'f',
        .width = 3,
        .body = {
            0b00000111,
            0b00000100,
            0b00000111,
            0b00000100,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = 'g',
        .width = 5,
        .body = {
            0b00011111,
            0b00010000,
            0b00010011,
            0b00010001,
            0b00011110,
            0,0,0
        }
    },
    {
        .name = 'h',
        .width = 4,
        .body = {
            0b00001001,
            0b00001001,
            0b00001111,
            0b00001001,
            0b00001001,
            0,0,0
        }
    },
    {
        .name = 'i',
        .width = 1,
        .body = {
            0b00000001,
            0b00000001,
            0b00000001,
            0b00000001,
            0b00000001,
            0,0,0
        }
    },
    {
        .name = 'j',
        .width = 4,
        .body = {
            0b00000001,
            0b00000001,
            0b00000001,
            0b00001001,
            0b00000110,
            0,0,0
        }
    },
    {
        .name = 'k',
        .width = 4,
        .body = {
            0b00001001,
            0b00001010,
            0b00001100,
            0b00001010,
            0b00001001,
            0,0,0
        }
    },
    {
        .name = 'l',
        .width = 3,
        .body = {
            0b00000100,
            0b00000100,
            0b00000100,
            0b00000100,
            0b00000111,
            0,0,0
        }
    },
    {
        .name = 'm',
        .width = 7,
        .body = {
            0b01100011,
            0b01010101,
            0b01001001,
            0b01000001,
            0b01000001,
            0,0,0
        }
    },
    {
        .name = 'n',
        .width = 7,
        .body = {
            0b01100001,
            0b01010001,
            0b01001001,
            0b01000101,
            0b01000011,
            0,0,0
        }
    },
    {
        .name = 'o',
        .width = 4,
        .body = {
            0b00000110,
            0b00001001,
            0b00001001,
            0b00001001,
            0b00000110,
            0,0,0
        },
    },
    {
        .name = 'p',
        .width = 4,
        .body = {
            0b00001110,
            0b00001001,
            0b00001110,
            0b00001000,
            0b00001000,
            0,0,0
        }
    },
    {
        .name = 'r',
        .width = 5,
        .body = {
            0b00011110,
            0b00010001,
            0b00011110,
            0b00010100,
            0b00010010,
            0,0,0
        }
    },
    {
        .name = 's',
        .width = 4,
        .body = {
            0b00001111,
            0b00001000,
            0b00001111,
            0b00000001,
            0b00001111,
            0,0,0
        }
    },
    {
        .name = 't',
        .width = 5,
        .body = {
            0b00011111,
            0b00000100,
            0b00000100,
            0b00000100,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = 'u',
        .width = 4,
        .body = {
            0b00001001,
            0b00001001,
            0b00001001,
            0b00001001,
            0b00000110,
            0,0,0
        }
    },
    {
        .name = 'w',
        .width = 7,
        .body = {
            0b01000001,
            0b01000001,
            0b01001001,
            0b01010101,
            0b01100011,
            0,0,0
        }
    },
    {
        .name = 'y',
        .width = 5,
        .body = {
            0b00010001,
            0b00001010,
            0b00000100,
            0b00000100,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = 'z',
        .width = 5,
        .body = {
            0b00011111,
            0b00000010,
            0b00000100,
            0b00001000,
            0b00011111,
            0,0,0
        }
    },
    {
        .name = 'q',
        .width = 5,
        .body = {
            0b00011111,
            0b00010001,
            0b00010101,
            0b00011111,
            0b00000010,
            0,0,0
        }
    },
    {
        .name = 'x',
        .width = 5,
        .body = {
            0b00010001,
            0b00001010,
            0b00000100,
            0b00001010,
            0b00010001,
            0,0,0
        }
    },
    {
        .name = 'v',
        .width = 7,
        .body = {
            0b01000001,
            0b01000001,
            0b00100010,
            0b00010100,
            0b00001000,
            0,0,0
        }
    }
};


font_font8 font_initialize(font_char* template,uint8_t length,uint8_t height, uint8_t horizontalSpacing, uint8_t verticalSpacing){
    font_font8 newFont;
    newFont.height = height;
    newFont.horizontalSpacing = horizontalSpacing;
    newFont.verticalSpacing = verticalSpacing;
    
    //insert default values
    for(int i=0; i<256; i++){
        newFont.charWidthList[i] = 8;
        for(int j=0; j<8; j++){
            newFont.charBodyList[i][j] = UINT8_MAX;
        }
    }
    //insert values from font template
    for(int i=0; i<length; i++){
        uint8_t index = template[i].name;
        newFont.charWidthList[index] = template[i].width;
        for(int j=0; j<8; j++){
            newFont.charBodyList[index][j] = template[i].body[j];
        }
    }
    return newFont;
}

font_font8 font_initialize_default(){
    return font_initialize(font_defaultTemplate, 26, 5, 2, 1);
}

void font_write(char* msg, uint8_t anchorX, uint8_t anchorY, font_font8 font, uint16_t color){
    uint8_t cursorX = anchorX;
    uint8_t cursorY = anchorY;
    //loop for every character
    for(int ch=0; msg[ch] != '\0'; ch++){
        uint8_t index = msg[ch];
        //newline
        if(msg[ch] == '\n'){
            cursorX = anchorX;
            cursorY += (font.height + font.verticalSpacing);
            continue;
        }
        //space
        if(msg[ch] == ' '){
            cursorX += (font.charWidthList[index] + font.horizontalSpacing);
            continue;
        }
        //other chars
        
        for(int y=0; y<font.height; y++){ //for every row
            uint8_t mask = pow(2, font.charWidthList[index]-1);
            for(int x=0; x<font.charWidthList[index]; x++){ //for every column
                if(font.charBodyList[index][y] & mask){
                    ssd1331_draw_pixel(cursorX + x, cursorY + y, color);
                }
                mask >>= 1;
            }
        }

        //move cursor to new position
        cursorX += (font.charWidthList[index] + font.verticalSpacing);
    }
}

#endif