/**
 * @file main.c
 * @brief Main function for PIC_ADC_Example_Interrupt application.
 */

#include <stdint.h>

/* Memory type is unsigned char. (2 bytes)
 * This variable will be used to hold the data
 * read from the ADC module on pin PA3.
 * NOTE that the data has a 12-bit resolution,
 * so if the variable is uint8, four bits
 * would be lost.
 */
uint16_t adc_rd;

void ADC_ISR() iv 8 {
        /* Get 12-bit results of A/D conversion. */
        adc_rd = ADCBUF0;
        
        /* Display eight most significant bits. (bits 0-7) */
        LATD = adc_rd;
        /* Display remaining two bits (bits 8-11) */
        LATE = adc_rd >> 8;
        
        PIR1.ADIE = 0; // Clear the interrupt flag.
}

// Main code.
void main(void) {
    /*
     * Configure RA3 pin as analog input.
     * NOTE The registers for PIC chips are ANCONx, ANSELx.
     */
    ANCON1.B3 = 1;
    
    TRISA.B3 = 1;   // Set direction of RA3 pin as input.
    
    TRISD = 0x00;   // Set direction of PORTD as output.
    TRISE = 0x00;   // Set direction of PORTE as output.
    
    /* 
     * SSRC<2:0> = 111 Implies internal counter ends sampling
     * and starts converting.
     */
    ADCON1L = 0x70;
    /* Set 12bit mode. */
    ADCON1H.MODE12 = 1;
    /* Dosable all higher channels for data scanning. */
    ADCSS0H = 0;
    /* Set data acquisition time.
     * Sample time = 31Tad, Tad = 3Tcy */
    ADCON3H = 0x1F;
    /* Set adequate A/D Conversion Clock.
     * This will be the value of the 'Tad'.
     * The formula is ((ADCS<7:0> + 1) 2/Fosc).
     * In our case it will be '4 * 2/Focs'
     */
    ADCON3L = 0x02;
    /* Clear whole register. */
    ADCON2L = 0;
    /* Set adequate sampling channel. */
    ADCHS0L = 3;
    /* Turn the module ON.
     * NOTE that we do this at the very end.
     */
    ADCON1H.ADON = 1;   // turn ADC ON
    
    INTCON.PEIE = 1;    // Peripheral interrupt ON.
    INTCON.GIE = 1;     // Global interrupt ON.
    PIE1.ADIE = 1;      // ADC module interrupt ON.
    
    Delay_ms(100);      // Wait for the module to stabilize.
    
    /* Slider 2 click specifics */
    TRISL.B1 = 0;
    TRISG.B4 = 0;
    LATL.B1 = 1;
    LATG.B4 = 1;
    /* EOF Slider 2 click specifics */
    
    while (1) {
        /* Initialize the sampling / software trigger. */
        ADCON1L.SAMP = 1; // Start sampling, then after 31Tad go to conversion.
        while (ADCON1L.DONE != 0) {
            // Wait for conversion to complete.
        } ;
    }
}
