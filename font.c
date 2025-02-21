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


font_char font_defaultTemplate[93] = {
    {
        .name = 'A',
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
        .name = 'B',
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
        .name = 'C',
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
        .name = 'D',
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
        .name = 'E',
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
        .name = 'F',
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
        .name = 'G',
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
        .name = 'H',
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
        .name = 'I',
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
        .name = 'J',
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
        .name = 'K',
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
        .name = 'L',
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
        .name = 'M',
        .width = 5,
        .body = {
            0b00010001,
            0b00011011,
            0b00010101,
            0b00010001,
            0b00010001,
            0,0,0
        }
    },
    {
        .name = 'N',
        .width = 5,
        .body = {
            0b00010001,
            0b00011001,
            0b00010101,
            0b00010011,
            0b00010001,
            0,0,0
        }
    },
    {
        .name = 'O',
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
        .name = 'P',
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
        .name = 'R',
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
        .name = 'S',
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
        .name = 'T',
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
        .name = 'U',
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
        .name = 'W',
        .width = 5,
        .body = {
            0b00010001,
            0b00010001,
            0b00010101,
            0b00011011,
            0b00010001,
            0,0,0
        }
    },
    {
        .name = 'Y',
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
        .name = 'Z',
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
        .name = 'Q',
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
        .name = 'X',
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
        .name = 'V',
        .width = 5,
        .body = {
            0b00010001,
            0b00010001,
            0b00010001,
            0b00001010,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = 'a',
        .width = 3,
        .body = {
            0b00000000,
            0b00000111,
            0b00000001,
            0b00000111,
            0b00000111,
            0,0,0
        }
    },
    {
        .name = 'b',
        .width = 3,
        .body = {
            0b00000000,
            0b00000100,
            0b00000110,
            0b00000101,
            0b00000111,
            0,0,0
        }
    },
    {
        .name = 'c',
        .width = 3,
        .body = {
            0b00000000,
            0b00000011,
            0b00000100,
            0b00000100,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = 'd',
        .width = 3,
        .body = {
            0b00000000,
            0b00000001,
            0b00000011,
            0b00000101,
            0b00000111,
            0,0,0
        }
    },
    {
        .name = 'e',
        .width = 3,
        .body = {
            0b00000000,
            0b00000011,
            0b00000111,
            0b00000100,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = 'f',
        .width = 3,
        .body = {
            0b00000000,
            0b00000011,
            0b00000010,
            0b00000111,
            0b00000010,
            0,0,0
        }
    },
    {
        .name = 'g',
        .width = 3,
        .body = {
            0b00000000,
            0b00000111,
            0b00000111,
            0b00000001,
            0b00000111,
            0,0,0
        }
    },
    {
        .name = 'h',
        .width = 4,
        .body = {
            0b00000000,
            0b00001000,
            0b00001110,
            0b00001001,
            0b00001001,
            0,0,0
        }
    },
    {
        .name = 'i',
        .width = 1,
        .body = {
            0b00000000,
            0b00000001,
            0b00000000,
            0b00000001,
            0b00000001,
            0,0,0
        }
    },
    {
        .name = 'j',
        .width = 3,
        .body = {
            0b00000000,
            0b00000001,
            0b00000001,
            0b00000101,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = 'k',
        .width = 3,
        .body = {
            0b00000000,
            0b00000100,
            0b00000101,
            0b00000110,
            0b00000101,
            0,0,0
        }
    },
    {
        .name = 'l',
        .width = 3,
        .body = {
            0b00000000,
            0b00000010,
            0b00000010,
            0b00000010,
            0b00000111,
            0,0,0
        }
    },
    {
        .name = 'm',
        .width = 5,
        .body = {
            0b00000000,
            0b00001111,
            0b00010101,
            0b00010101,
            0b00010101,
            0,0,0
        }
    },
    {
        .name = 'n',
        .width = 4,
        .body = {
            0b00000000,
            0b00001011,
            0b00001101,
            0b00001001,
            0b00001001,
            0,0,0
        }
    },
    {
        .name = 'o',
        .width = 3,
        .body = {
            0b00000000,
            0b00000010,
            0b00000101,
            0b00000101,
            0b00000010,
            0,0,0
        },
    },
    {
        .name = 'p',
        .width = 3,
        .body = {
            0b00000000,
            0b00000111,
            0b00000101,
            0b00000110,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = 'r',
        .width = 5,
        .body = {
            0b00000000,
            0b00001011,
            0b00001100,
            0b00001000,
            0b00001000,
            0,0,0
        }
    },
    {
        .name = 's',
        .width = 3,
        .body = {
            0b00000000,
            0b00000011,
            0b00000100,
            0b00000011,
            0b00000110,
            0,0,0
        }
    },
    {
        .name = 't',
        .width = 3,
        .body = {
            0b00000000,
            0b00000010,
            0b00000111,
            0b00000010,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = 'u',
        .width = 3,
        .body = {
            0b00000000,
            0b00000101,
            0b00000101,
            0b00000101,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = 'w',
        .width = 5,
        .body = {
            0b00000000,
            0b00010001,
            0b00010101,
            0b00010101,
            0b00001111,
            0,0,0
        }
    },
    {
        .name = 'y',
        .width = 3,
        .body = {
            0b00000000,
            0b00000101,
            0b00000101,
            0b00000010,
            0b00000110,
            0,0,0
        }
    },
    {
        .name = 'z',
        .width = 2,
        .body = {
            0b00000000,
            0b00000011,
            0b00000001,
            0b00000010,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = 'q',
        .width = 3,
        .body = {
            0b00000000,
            0b00000111,
            0b00000101,
            0b00000011,
            0b00000001,
            0,0,0
        }
    },
    {
        .name = 'x',
        .width = 3,
        .body = {
            0b00000000,
            0b00000101,
            0b00000010,
            0b00000010,
            0b00000101,
            0,0,0
        }
    },
    {
        .name = 'v',
        .width = 5,
        .body = {
            0b00000000,
            0b00010001,
            0b00010001,
            0b00001010,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = '1',
        .width = 3,
        .body = {
            0b00000010,
            0b00000110,
            0b00000010,
            0b00000010,
            0b00000111,
            0,0,0
        }
    },
    {
        .name = '2',
        .width = 4,
        .body = {
            0b00000110,
            0b00001001,
            0b00000010,
            0b00000100,
            0b00001111,
            0,0,0
        }
    },
    {
        .name = '3',
        .width = 3,
        .body = {
            0b00000110,
            0b00000001,
            0b00000110,
            0b00000001,
            0b00000110,
            0,0,0
        }
    },
    {
        .name = '4',
        .width = 4,
        .body = {
            0b00000110,
            0b00001010,
            0b00001111,
            0b00000010,
            0b00000010,
            0,0,0
        }
    },
    {
        .name = '5',
        .width = 4,
        .body = {
            0b00000111,
            0b00000100,
            0b00000110,
            0b00000001,
            0b00001110,
            0,0,0
        }
    },
    {
        .name = '6',
        .width = 4,
        .body = {
            0b00000111,
            0b00001000,
            0b00001110,
            0b00001001,
            0b00000110,
            0,0,0
        }
    },
    {
        .name = '7',
        .width = 4,
        .body = {
            0b00001111,
            0b00000001,
            0b00000010,
            0b00000010,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = '8',
        .width = 4,
        .body = {
            0b00000110,
            0b00001001,
            0b00000110,
            0b00001001,
            0b00000110,
            0,0,0
        }
    },
    {
        .name = '9',
        .width = 4,
        .body = {
            0b00000110,
            0b00001001,
            0b00000111,
            0b00000001,
            0b00001110,
            0,0,0
        }
    },
    {
        .name = '0',
        .width = 5,
        .body = {
            0b00000110,
            0b00001011,
            0b00001101,
            0b00001101,
            0b00000110,
            0,0,0
        }
    },
    {
        .name = '!',
        .width = 1,
        .body = {
            0b00000001,
            0b00000001,
            0b00000001,
            0b00000000,
            0b00000001,
            0,0,0
        }
    },
    {
        .name = '@',
        .width = 5,
        .body = {
            0b00001110,
            0b00010001,
            0b00010110,
            0b00010000,
            0b00001111,
            0,0,0
        }
    },
    {
        .name = '#',
        .width = 5,
        .body = {
            0b00001010,
            0b00011111,
            0b00001010,
            0b00011111,
            0b00001010,
            0,0,0
        }
    },
    {
        .name = '$',
        .width = 4,
        .body = {
            0b00000100,
            0b00001111,
            0b00001110,
            0b00000101,
            0b00001110,
            0,0,0
        }
    },
    {
        .name = '%',
        .width = 5,
        .body = {
            0b00011001,
            0b00011010,
            0b00000100,
            0b00001011,
            0b00010011,
            0,0,0
        }
    },
    {
        .name = '^',
        .width = 3,
        .body = {
            0b00000010,
            0b00000101,
            0b00000000,
            0b00000000,
            0b00000000,
            0,0,0
        }
    },
    {
        .name = '&',
        .width = 5,
        .body = {
            0b00001000,
            0b00010100,
            0b00001001,
            0b00010110,
            0b00001001,
            0,0,0
        }
    },
    {
        .name = '*',
        .width = 5,
        .body = {
            0b00000100,
            0b00010101,
            0b00001110,
            0b00010101,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = '(',
        .width = 2,
        .body = {
            0b00000001,
            0b00000010,
            0b00000010,
            0b00000010,
            0b00000001,
            0,0,0
        }
    },
    {
        .name = ')',
        .width = 2,
        .body = {
            0b00000010,
            0b00000001,
            0b00000001,
            0b00000001,
            0b00000010,
            0,0,0
        }
    },
    {
        .name = '+',
        .width = 5,
        .body = {
            0b00000100,
            0b00000100,
            0b00011111,
            0b00000100,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = '-',
        .width = 3,
        .body = {
            0b00000000,
            0b00000000,
            0b00000111,
            0b00000000,
            0b00000000,
            0,0,0
        }
    },
    {
        .name = '=',
        .width = 3,
        .body = {
            0b00000000,
            0b00000111,
            0b00000000,
            0b00000111,
            0b00000000,
            0,0,0
        }
    },
    {
        .name = '~',
        .width = 4,
        .body = {
            0b00000000,
            0b00000000,
            0b00001010,
            0b00000101,
            0b00000000,
            0,0,0
        }
    },
    {
        .name = '[',
        .width = 2,
        .body = {
            0b00000011,
            0b00000010,
            0b00000010,
            0b00000010,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = ']',
        .width = 2,
        .body = {
            0b00000011,
            0b00000001,
            0b00000001,
            0b00000001,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = '{',
        .width = 3,
        .body = {
            0b00000011,
            0b00000010,
            0b00000110,
            0b00000010,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = '}',
        .width = 3,
        .body = {
            0b00000110,
            0b00000010,
            0b00000011,
            0b00000010,
            0b00000110,
            0,0,0
        }
    },
    {
        .name = '<',
        .width = 3,
        .body = {
            0b00000001,
            0b00000010,
            0b00000100,
            0b00000010,
            0b00000001,
            0,0,0
        }
    },
    {
        .name = '>',
        .width = 3,
        .body = {
            0b00000100,
            0b00000010,
            0b00000001,
            0b00000010,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = ':',
        .width = 1,
        .body = {
            0b00000000,
            0b00000001,
            0b00000000,
            0b00000001,
            0b00000000,
            0,0,0
        }
    },
    {
        .name = ';',
        .width = 2,
        .body = {
            0b00000000,
            0b00000001,
            0b00000000,
            0b00000001,
            0b00000010,
            0,0,0
        }
    },
    {
        .name = '?',
        .width = 3,
        .body = {
            0b00000111,
            0b00000011,
            0b00000110,
            0b00000000,
            0b00000100,
            0,0,0
        }
    },
    {
        .name = '.',
        .width = 2,
        .body = {
            0b00000000,
            0b00000000,
            0b00000000,
            0b00000011,
            0b00000011,
            0,0,0
        }
    },
    {
        .name = ',',
        .width = 2,
        .body = {
            0b00000000,
            0b00000000,
            0b00000000,
            0b00000010,
            0b00000001,
            0,0,0
        }
    },
    {
        .name = '/',
        .width = 2,
        .body = {
            0b00000001,
            0b00000001,
            0b00000010,
            0b00000010,
            0b00000010,
            0,0,0
        }
    },
    {
        .name = '\\',
        .width = 2,
        .body = {
            0b00000010,
            0b00000010,
            0b00000001,
            0b00000001,
            0b00000001,
            0,0,0
        }
    },
    {
        .name = '\'',
        .width = 1,
        .body = {
            0b00000001,
            0b00000001,
            0b00000000,
            0b00000000,
            0b00000000,
            0,0,0
        }
    },
    {
        .name = '\"',
        .width = 3,
        .body = {
            0b00000101,
            0b00000101,
            0b00000000,
            0b00000000,
            0b00000000,
            0,0,0
        }
    },
    {
        .name = '|',
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
        .name = ' ',
        .width = 3,
        .body = {
            0b00000000,
            0b00000000,
            0b00000000,
            0b00000000,
            0b00000000,
            0,0,0
        }
    }
};


font_font8 font_create(font_char* template,uint8_t length,uint8_t height, uint8_t horizontalSpacing, uint8_t verticalSpacing){
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

font_font8 font_create_default(){
    return font_create(font_defaultTemplate, 93, 5, 2, 1);
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

void font_smart_write(char* msg, uint8_t anchorX, uint8_t anchorY, uint8_t maxwidth, font_font8 font, uint16_t color){
    uint8_t cursorX = anchorX;
    uint8_t cursorY = anchorY;
    char substr[2] = {'\0','\0'};
    //loop for every character
    for(int ch=0; msg[ch] != '\0'; ch++){
        uint8_t index = msg[ch];
        //check if there is enough space
        if(cursorX + font.charWidthList[index] > maxwidth+anchorX){
            cursorX = anchorX;
            cursorY += (font.height + font.verticalSpacing);
            //remove space if it's the first character in the new line
            if(msg[ch]==' '){
                ch++;
            }
        }
        substr[0] = msg[ch];
        font_write(substr, cursorX, cursorY, font, color);        
        //move cursor to new position
        cursorX += (font.charWidthList[index] + font.verticalSpacing);
    }
}



#endif