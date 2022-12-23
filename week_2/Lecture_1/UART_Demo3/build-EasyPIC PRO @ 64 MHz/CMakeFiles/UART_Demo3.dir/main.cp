#line 1 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo3/main.c"
#line 8 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo3/main.c"
void UART_ISR() iv 8 {

    TXREG1 = UART1_Read();

    PIR1.B5 = 0;
}

void main() {


    UART1_Init(115200);

    Delay_ms(100);


    UART1_Write_Text("Example 3 Started\r\n");
#line 28 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo3/main.c"
    INTCON.B6 = 1;
#line 32 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo3/main.c"
    INTCON.B7 = 1;
#line 36 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo3/main.c"
    PIE1.B5 = 1;
#line 41 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo3/main.c"
    while (1);
}
