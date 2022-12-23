#line 1 "C:/Users/footb/Documents/MIKROE/Week_2/UART1_Demo/main.c"
#line 6 "C:/Users/footb/Documents/MIKROE/Week_2/UART1_Demo/main.c"
unsigned char *uart_dat;

void main() {

    ANCON1 = 0x00;


    UART1_Init(115200);

    Delay_ms(100);


    UART1_Write_Text("Example 1 Started\r\n");


    while (1) {

        ByteToStr(PORTD, &uart_dat);

        UART1_Write_Text(&uart_dat);

        UART1_Write(10);
        UART1_Write(13);
        Delay_ms(500);
    }
}
