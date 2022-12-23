/*
 * Project name:
     I2C_Advanced (Advanced I2C Example)
 * Copyright:
     (c) Mikroelektronika, 2012.
 * Revision History:
     20120116:
       - initial release (FJ);
 * Description:
     This example features the advanced communication with the 24AA01 EEPROM chip
     by introducing its own library of functions for this task: init, single
     write, single and sequential read. It performs write of a sequence of bytes
     (characters) into the EEPROM and writes this out at the first row on Lcd.
     Then, data read from EEPROM is performed and the result is displayed at the
     second row on Lcd.
 * Test configuration:
     MCU:             PIC18F87K22
                      http://www.microchip.com/downloads/en/DeviceDoc/39960b.pdf
     Dev.Board:       EasyPIC PRO v7 -  ac:Serial_EEPROM
                      http://www.mikroe.com/easypic-pro/
     Oscillator:      HS-PLL 64.0000 MHz, 16.0000 MHz Crystal
     Ext. Modules:    Character Lcd 2x16
                      http://www.mikroe.com/lcd-2x16-blue
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/mikroc/pic
 * NOTES:
     - Turn on I2C switches SW5.7 and SW5.8 (board specific)
     - Turn off PORTC LEDs (Sw6.3). (board specific)
     - Turn on LCD backlight switch SW4.1 (board specific)
 */

// #include "EEPROM_24AA01.h"

// Lcd module connections
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

//--------Writes data to 24C02 EEPROM - single location
void EEPROM_24C02_WrSingle(unsigned short wAddr, unsigned short wData) {
    I2C2_Start();           // issue I2C start signal
    I2C2_Wr(0xA0);          // send byte via I2C (device address + W)
    I2C2_Wr(wAddr);         // send byte (address of EEPROM location)
    I2C2_Wr(wData);         // send data (data to be written)
    I2C2_Stop();            // issue I2C stop signal
}

//--------Reads data from 24C02 EEPROM - single location (random)
unsigned short EEPROM_24C02_RdSingle(unsigned short rAddr) {
    unsigned short result;
    I2C2_Start();           // issue I2C start signal
    I2C2_Wr(0xA0);          // send byte via I2C (device address + W)
    I2C2_Wr(rAddr);         // send byte (data address)
    I2C2_Repeated_Start();  // issue I2C signal repeated start
    I2C2_Wr(0xA1);          // send byte (device address + R)
    result = I2C2_Rd(0);
    while (!I2C2_Is_Idle())
        asm nop;            // wait for the read cycle to finish
        I2C2_Stop();
    return result;
}

char someData[] = "Ivans I2C Test";
char i, tmpdata;

void main(void) {
    
    I2C2_Init(100000);          // initialize I2C communication
    Delay_ms(100);
    
    Lcd_Init();                 // performs Lcd initiation
    Lcd_Cmd(_LCD_CLEAR);        // clear Lcd
    Lcd_Cmd(_LCD_CURSOR_OFF);   // set cursor off
    
    // example for single-byte write
    i = 0;
    tmpdata = 1;
    while ((tmpdata = someData[i]) != 0) {
        i++;
        EEPROM_24C02_WrSingle(i, tmpdata);      // writes data, char by char, in the EEPROM
        Delay_ms(5);
        Lcd_Chr(1, i, tmpdata);                 // displays data on the first row of the Lcd
    }
    EEPROM_24C02_WrSingle(i+1, 0);              // writes string termination
    Delay_ms(5);
    
    // example for single-byte read
    i = 1;
    tmpdata = 1;
    while ((tmpdata = EEPROM_24C02_RdSingle(i)) != 0) {
        Lcd_Chr(2, i, tmpdata);                 // displays data from EEPROM on the second row of the Lcd
        Delay_ms(5);
        i++;
    }
}
