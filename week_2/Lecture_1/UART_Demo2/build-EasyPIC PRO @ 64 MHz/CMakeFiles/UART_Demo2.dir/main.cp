#line 1 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo2/main.c"
#line 13 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo2/main.c"
unsigned char command;

void main() {
#line 20 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo2/main.c"
    TRISD = 0;
    LATD = 0;


    UART1_Init(115200);

    Delay_ms(100);


    UART1_Write_Text("Example 2 Started\r\n");


    while (1) {

        if (UART1_Data_Ready()) {


            command = UART1_Read();
#line 43 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo2/main.c"
            switch (command)
            {
                case 'x':

                    LATD = 0;
                    break;

                case 'o':

                    LATD = 0xFF;
                    break;

                case 'i':

                    LATD++;
                    break;

                case 'd':

                    LATD--;
                    break;

                default:
#line 71 "C:/Users/footb/Documents/MIKROE/Week_2/UART_Demo2/main.c"
                    UART1_Write_Text("Unrecognized command.\r\n");
                    break;
            }
        }
    }
}
