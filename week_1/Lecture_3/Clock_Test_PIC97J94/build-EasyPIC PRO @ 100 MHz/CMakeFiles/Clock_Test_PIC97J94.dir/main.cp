#line 1 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_3/Clock_Test_PIC97J94/main.c"
#line 6 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_3/Clock_Test_PIC97J94/main.c"
void main(void)
{

    TRISD = 0;
    LATD = 0xFF;
    while (1)
    {
        LATD = ~LATD;
        Delay_ms(1000);
    }
}
