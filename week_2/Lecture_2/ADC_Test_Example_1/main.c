/**
 * @file main.c
 * @brief Main function for ADC_Test_Example_1 application.
 */

void main(void)
{
    TRISA.B3 = 1; // Set pin RA3 as input.
    ANCON1.B3 = 1; // Set pin RA3 as analog.
    
    // Set the ADC module.
    ADCON1L = 0x70; // internal counter starts the conversion.
    // Set 12bit mode. Resolution.
    ADCON1H.MODE12 = 1;
    
    ADCON3H = 0x1F; // TAD time to max value.
    
    ADCON3L = 0x02; // Conversion time set to 4*2/Fosc - Fosc (64MHz).
    
    ADCHS0L = 3; // Select channel number 3 for ADC conversion.
    
    ADCON1H.ADON = 1; // Turn the module ON.
    
    while (1)
    {
        ADCON1L.SAMP = 1; // Sample bit in ADCON1 -- meaning we triggered the conversion.
        while (ADCON1L.DONE != 0) { // Polling method.
            // Wait for the data conversion to finish.
        } ;
        
        unsigned int adc_rd = ADCBUF0; // Read the ADC data.
    }
}
