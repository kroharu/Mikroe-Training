/*
 * UART Test example 2.
 * Checks input value from host.
 * Values:
 *      o - turn whole PORTD on.
 *      x - clear whole PORTD.
 *      i - increment PORTD value. (+1)
 *      d - decrement PORTD value. (-1)
 * 
 * NOTE Any other data will result in an error.
 */

unsigned char command;

void main() {

    /* Configure PORTD as digital output
     * and set initial value to 0 (cleared).
     */
    TRISD = 0;
    LATD = 0;
    
    /* Initialize UART1 module @ 115200 baud. */
    UART1_Init(115200);
    /* Wait for UART module to stabilize. */
    Delay_ms(100);
    
    /* Initial message. */
    UART1_Write_Text("Example 2 Started\r\n");
    
    /* Endless loop. */
    while (1) {
        /* If there is any data on the terminal. */
        if (UART1_Data_Ready()) {
            
            /* Parser the command. */
            command = UART1_Read();
            
            /* Check the value of the command.
             * NOTE the 'break' statement.__FLASH_SIZEWithout it, our code will check every other
             * statement as well.
             */
            switch (command)
            {
                case 'x':
                    /* Clear LATD. - 0 */
                    LATD = 0;
                    break;
                    
                case 'o':
                    /* Turn LATD on. - 0xFF */
                    LATD = 0xFF;
                    break;
                    
                case 'i':
                    /* Increase value of LATD. */
                    LATD++;
                    break;
                    
                case 'd':
                    /* Decrease value of LATD. */
                    LATD--;
                    break;
                    
                default:
                    /* ATTENTION Take into consideration that
                     * each character is being parsed separately.
                     * Writing multiple characters might result
                     * in multiple 'Unrecognized command' errors.
                     */
                    UART1_Write_Text("Unrecognized command.\r\n");
                    break;
            }
        }
    }
}
