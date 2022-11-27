/**
 * @file main.c
 * @brief Main function for LED_Test application.
 */

void ft_straight_LED(void)
{
    LATD.B0 = 0;
    LATD.B7 = 1;
    Delay_ms(100);
    LATD.B7 = 0;
    LATD.B6 = 1;
    Delay_ms(100);
    LATD.B6 = 0;
    LATD.B5 = 1;
    Delay_ms(100);
    LATD.B5 = 0;
    LATD.B4 = 1;
    Delay_ms(100);
    LATD.B4 = 0;
    LATD.B3 = 1;
    Delay_ms(100);
    LATD.B3 = 0;
    LATD.B2 = 1;
    Delay_ms(100);
    LATD.B2 = 0;
    LATD.B1 = 1;
    Delay_ms(100);
    LATD.B1 = 0;
    LATD.B0 = 1;
    Delay_ms(100);    
}

ft_reverse_LED(void)
{
    LATD.B0 = 0;
    LATD.B1 = 1;
    Delay_ms(100);
    LATD.B1 = 0;
    LATD.B2 = 1;
    Delay_ms(100);
    LATD.B2 = 0;
    LATD.B3 = 1;
    Delay_ms(100);
    LATD.B3 = 0;
    LATD.B4 = 1;
    Delay_ms(100);
    LATD.B4 = 0;
    LATD.B5 = 2;
    Delay_ms(100);
    LATD.B5 = 0;
    LATD.B6 = 1;
    Delay_ms(100);
    LATD.B6 = 0;
    LATD.B7 = 1;
    Delay_ms(100);
}

void main(void)
{
    /* Replace with your application code */
    TRISD = 0;
    LATD = 0;
    while (1)
    {
        ft_straight_LED();
        ft_reverse_LED();
    //     LATD = ~LATD;
    //     Delay_ms(500);
    }        
}
