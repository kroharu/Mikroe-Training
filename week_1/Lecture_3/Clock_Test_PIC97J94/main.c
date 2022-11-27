/**
 * @file main.c
 * @brief Main function for Clock_Test_PIC97J94 application.
 */

void main(void)
{
    /* Replace with your application code */
    TRISD = 0;
    LATD = 0xFF;
    while (1)
    {
        LATD = ~LATD;
        Delay_ms(1000);
    }
}
