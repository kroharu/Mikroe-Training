/**
 * @file main.c
 * @brief Main function for I2C_Test_1 application.
 */

#define DATA_TO_SEND 0xA5
#define ADDRESS_OF_DATA 0x2

//----------------Writes data to 24C02 EEPROM - single location
void EEPROM_24C02_WrSingle(unsigned short wAddr, unsigned short wData) {
    I2C2_Start();           // issue I@C start signal
    I2C2_Wr(0xA0);           // send byte via I2C (device address + W)
    I2C2_Wr(wAddr);         // send byte (address of EEPROM location)
    I2C2_Wr(wData);         // send data (data to be written)
    I2C2_Stop();            // issue I2C stop signal
}

//----------------Reads data from 24C02 EEPROM - single location (random)
unsigned short EEPROM_24C02_RdSingle(unsigned short rAddr) {
    unsigned short result;
    
    I2C2_Start();           // issue I2C start signal
    I2C2_Wr(0xA0);          // send byte via I2C (device address + W)
    I2C2_Wr(rAddr);         // send byte (data address)
    I2C2_Repeated_Start();  // issue I2C signal repeated start
    I2C2_Wr(0xA1);          // send byte (device address + R)
    result = I2C1_Rd(0);
    while (!I2C1_Is_Idle())
        asm nop;            // wait for the read cycle to finish
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
    TRISB.B0 = 0;           // configure PORTB as output
    TRISB.B1 = 0;           // configure PORTB as output
    LATB = 0;               // clear PORTB
    
    TRISD = 0;
    LATD = 0;
    
    I2C2_Init(100000);      // initialize I2C communication
    Delay_ms(100);
    I2C2_SetTimeoutCallback(1000, &test);   // initialize I2C communication
    I2C2_Start();                           // issue I2C start signal
    
    I2C2_Wr(0);             // bad write and read will report error on port A
    I2C2_Rd(0);             //as a demonstration of SetTimeoutCallback
    
    I2C2_Stop();                            // issue I2C stop signal
    
    EEPROM_24C02_WrSingle(ADDRESS_OF_DATA, DATA_TO_SEND);
    Delay_ms(5);
    
    LATD = EEPROM_24C02_RdSingle(ADDRESS_OF_DATA);
    Delay_ms(5);
    while (1)
    {
    }
}
