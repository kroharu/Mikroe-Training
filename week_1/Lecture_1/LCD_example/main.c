/*
 * Project name:
     LCD Test (Simple demonstration of the LCD Library functions)
 * Copyright:
     (c) Mikroelektronika, 2019.
 * Description:
 This is a simple demonstration of LCD library functions. LCD is first initialized (4-bit data interface, default pin settings), then some test is written at the first and the second row, then the text is moved.
 * Test configuration:
     Device:          STM32F407ZG
                      https://www.st.com/resource/en/datasheet/stm32f407zg.pdf
     Dev.Board:       Fusion for STM32 v8
                      https://www.mikroe.com/fusion-for-stm
     Oscillator:      HSE-PLL, 168.000MHz
     Ext. Modules:    LCD
                      https://www.mikroe.com/lcd-2x16-blue
     SW:              NECTO Studio
                      https://mikroe.com/necto
 * NOTES:
     - Turn on LCD backlight switch. (board specific)
*/

// LCD module connections
sbit LCD_RS at GPIOF_ODR.B11;
sbit LCD_EN at GPIOF_ODR.B12;
sbit LCD_D4 at GPIOF_ODR.B4;
sbit LCD_D5 at GPIOF_ODR.B5;
sbit LCD_D6 at GPIOF_ODR.B6;
sbit LCD_D7 at GPIOF_ODR.B7;
// End LCD module connections

char txt1[] = "mikroelektronika";
char txt2[] = "STM32";
char txt3[] = "Lcd4bit";
char txt4[] = "example";

char i;                             // Loop counter variable

void Move_Delay() {                 // Function used for text moving
    Delay_ms(200);                  // You can change the moving speed here
}

void main () {
    Lcd_Init();                     // Initialize LCD
    
    Lcd_Cmd(_LCD_CLEAR);            // Clear display
    Lcd_Cmd(_LCD_CURSOR_OFF);       // Cursur off
    Lcd_Out(1, 6, txt3);            // Write text in first row
    
    Lcd_Out(2, 6, txt4);            // Write text in second row
    Delay_ms(2000);                 
    Lcd_Cmd(_LCD_CLEAR);            // Clear display
    
    Lcd_Out(1, 1, txt1);            // Write text in first row
    Lcd_Out(2, 7, txt2);            // Write text in second row
    
    Delay_ms(2000);
    
    // Moving text
    for (i = 0; i < 4; i++) {       // Move text to the right 4 times
        Lcd_Cmd(_LCD_SHIFT_RIGHT);
        Move_Delay();
    }
    
    while (1) {                     // Endless loop
        for (i = 0; i < 7; i++) {   // Move text to the left 7 times
            Lcd_Cmd(_LCD_SHIFT_LEFT);
            Move_Delay();
        }
    }
}
