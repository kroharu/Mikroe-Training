/*
 * UART Test example 3.
 * Simple echo example with interrupt functionality.
 * DS link:
 * https://www.microchip.com/content/dam/documents/OTH/ProductDocuments/DataSheets/30000575C.pdf
 */

void UART_ISR() iv 8 {
    /* Read data and transmit it back. */
    TXREG1 = UART1_Read();
    /* Clear interrupt flag. */
    PIR1.B5 = 0;
}

void main() {
    
    /* Initialize UART1 module @ 115200 baud. */
    UART1_Init(115200);
    /* Wait for UART module to stabilize. */
    Delay_ms(100);
    
    /* Initial message. */
    UART1_Write_Text("Example 3 Started\r\n");
    
    /* Enable peripheral interrupt.
     * DS page 171
     */
    INTCON.B6 = 1;
    /* Enable global interrupt.
     * DS page 171.
     */
    INTCON.B7 = 1;
    /* Enable UART RX interrupt.
     * DS page 174.
     */
    PIE1.B5 = 1;
    
    /* NOTE that we aren't doing anything
     * in the main code flow.
     */
    while (1);
}
