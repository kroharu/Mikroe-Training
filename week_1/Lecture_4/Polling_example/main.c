/**
 * @file main.c
 * @brief Main function for Polling_example application.
 */

// Global variable
char uart_rd;

// NOTE This just to illustrate the point.
// The operations can be any statement.
#define operation1() asm nop
#define operation2() asm nop
#define operation3() asm nop

// ISR (interrupt service routine)
/* ATTENTION Number 87 represents the IRQ number from the documentation.
 * It is the IRQ number for module UART6.
 * Page 378.
 * iv stands for interrupt vector.
 */

void UART_ISR() iv 87 {
    uart_rd = UART6_Read();         // Read the data.
    UART6_Write(uart_rd);           // Write it data.
}

void main(void)
{
    UART6_Init(115200);             // Initialize UART module at 115200 bps.
    Delay_ms(100);                  // Wait for UART module to stabilize.
    
    UART_Write_Text("Start\r\n");   // Signal start (add new row at the end).

    /* NOTE This will be explained
     * in details in one of the
     * later courses.
     */
    USART6_CR1.B5 = 1;
    NVIC_IntEnable(87);
    EnableInterrupts();
    /* END of NOTE */
    
    while (1) {                     // Endless loop.
        /* Notice that the MCU will continue other operations
           all the while polling the module for commands. */
        operation1();
        
        operation2();
        
        operation3();
    }
}
