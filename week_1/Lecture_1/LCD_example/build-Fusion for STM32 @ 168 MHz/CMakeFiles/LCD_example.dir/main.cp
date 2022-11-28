#line 1 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_1/LCD_example/main.c"
#line 23 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_1/LCD_example/main.c"
sbit LCD_RS at GPIOF_ODR.B11;
sbit LCD_EN at GPIOF_ODR.B12;
sbit LCD_D4 at GPIOF_ODR.B4;
sbit LCD_D5 at GPIOF_ODR.B5;
sbit LCD_D6 at GPIOF_ODR.B6;
sbit LCD_D7 at GPIOF_ODR.B7;


char txt1[] = "mikroelektronika";
char txt2[] = "STM32";
char txt3[] = "Lcd4bit";
char txt4[] = "example";

char i;

void Move_Delay() {
    Delay_ms(200);
}

void main () {
    Lcd_Init();

    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Out(1, 6, txt3);

    Lcd_Out(2, 6, txt4);
    Delay_ms(2000);
    Lcd_Cmd(_LCD_CLEAR);

    Lcd_Out(1, 1, txt1);
    Lcd_Out(2, 7, txt2);

    Delay_ms(2000);


    for (i = 0; i < 4; i++) {
        Lcd_Cmd(_LCD_SHIFT_RIGHT);
        Move_Delay();
    }

    while (1) {
        for (i = 0; i < 7; i++) {
            Lcd_Cmd(_LCD_SHIFT_LEFT);
            Move_Delay();
        }
    }
}
