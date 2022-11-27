/**
 * @file main.c
 * @brief Main function for PIC_GPIO_example application.
 */

void EXT_ISR() iv 8
{
    /* NOTE what happens if you don't clear
     * the interrupt flag.
     */
    INTCON.B1 = 0;  // Clear interrupt flag.
    LATC = ~LATC;   // Toggle pins.
}

void main(void)
{
    INTCON.B6 = 1;  // Enable peripheral interrupt.
    INTCON.B7 = 1;  // Enable global interrupt.
    
    INTCON.B4 = 1;  // Enable External Interrupt0.
    
    TRISB.B0 = 1;   // This will be the input.
    TRISC = 0;      // This will be the output.
    LATC = 0;       // Set all pins to 0.
    
    /* NOTE that we aren't doing anything
     * in the main code flow.
     */
    
    while (1);
}
