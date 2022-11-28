#line 1 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/Polling_example/main.c"
#line 7 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/Polling_example/main.c"
char uart_rd;
#line 22 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/Polling_example/main.c"
void UART_ISR() iv 87 {
    uart_rd = UART6_Read();
    UART6_Write(uart_rd);
}

void main(void)
{
    UART6_Init(115200);
    Delay_ms(100);

    UART_Write_Text("Start\r\n");
#line 38 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/Polling_example/main.c"
    USART6_CR1.B5 = 1;
    NVIC_IntEnable(87);
    EnableInterrupts();


    while (1) {
#line 46 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/Polling_example/main.c"
        asm nop ;

        asm nop ;

        asm nop ;
    }
}
