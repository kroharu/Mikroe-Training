#line 1 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_3/I2C_Test_2/main.c"
#line 35 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_3/I2C_Test_2/main.c"
sbit LCD_RS at LATL7_bit;
sbit LCD_EN at LATJ3_bit;
sbit LCD_D4 at LATK4_bit;
sbit LCD_D5 at LATK5_bit;
sbit LCD_D6 at LATK6_bit;
sbit LCD_D7 at LATK7_bit;

sbit LCD_RS_Direction at TRISL7_bit;
sbit LCD_EN_Direction at TRISJ3_bit;
sbit LCD_D4_Direction at TRISK4_bit;
sbit LCD_D5_Direction at TRISK5_bit;
sbit LCD_D6_Direction at TRISK6_bit;
sbit LCD_D7_Direction at TRISK7_bit;


void EEPROM_24C02_WrSingle(unsigned short wAddr, unsigned short wData) {
    I2C2_Start();
    I2C2_Wr(0xA0);
    I2C2_Wr(wAddr);
    I2C2_Wr(wData);
    I2C2_Stop();
}


unsigned short EEPROM_24C02_RdSingle(unsigned short rAddr) {
    unsigned short result;
    I2C2_Start();
    I2C2_Wr(0xA0);
    I2C2_Wr(rAddr);
    I2C2_Repeated_Start();
    I2C2_Wr(0xA1);
    result = I2C2_Rd(0);
    while (!I2C2_Is_Idle())
        asm nop;
        I2C2_Stop();
    return result;
}

char someData[] = "Ivans I2C Test";
char i, tmpdata;

void main(void) {

    I2C2_Init(100000);
    Delay_ms(100);

    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);


    i = 0;
    tmpdata = 1;
    while ((tmpdata = someData[i]) != 0) {
        i++;
        EEPROM_24C02_WrSingle(i, tmpdata);
        Delay_ms(5);
        Lcd_Chr(1, i, tmpdata);
    }
    EEPROM_24C02_WrSingle(i+1, 0);
    Delay_ms(5);


    i = 1;
    tmpdata = 1;
    while ((tmpdata = EEPROM_24C02_RdSingle(i)) != 0) {
        Lcd_Chr(2, i, tmpdata);
        Delay_ms(5);
        i++;
    }
}
