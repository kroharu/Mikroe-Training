#line 1 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_3/I2C_Test_1/main.c"
#line 10 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_3/I2C_Test_1/main.c"
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
    result = I2C1_Rd(0);
    while (!I2C1_Is_Idle())
        asm nop;
    I2C1_Stop();
    return result;
}

void test(char err) {
    if (err == _I2C_TIMEOUT_RD)
        LATB.B0 = 1;
    if (err == _I2C_TIMEOUT_WR)
        LATB.B1 = 1;
}

void main(void) {
    TRISB.B0 = 0;
    TRISB.B1 = 0;
    LATB = 0;

    TRISD = 0;
    LATD = 0;

    I2C2_Init(100000);
    Delay_ms(100);
    I2C2_SetTimeoutCallback(1000, &test);
    I2C2_Start();

    I2C2_Wr(0);
    I2C2_Rd(0);

    I2C2_Stop();

    EEPROM_24C02_WrSingle( 0x2 ,  0xA5 );
    Delay_ms(5);

    LATD = EEPROM_24C02_RdSingle( 0x2 );
    Delay_ms(5);
    while (1)
    {
    }
}
