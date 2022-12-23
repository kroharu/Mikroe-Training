/*
 * UART Test example 1.
 * Writes out PORTD value via UART.
 */

unsigned char *uart_dat;

void main() {
    
    /* Initialize UART1 @ 115200 baud. */
    UART1_Init(115200);
    /* Wait for UART module to stabilize. */
    Delay_ms(100);
    
    /* Initial message. */
    UART1_Write_Text("Example 1 Started\r\n");
    
    /* Endless loop. */
    while (1) {
        /* Convert to string first. */
        ByteToStr(PORTD, &uart_dat);
        /* Then write the converted data via UART. */
        UART1_Write_Text(&uart_dat);
        /* Lsatly, write new row. */
        UART1_Write(10);
        UART1_Write(13);
        Delay_ms(500);
    }
}
