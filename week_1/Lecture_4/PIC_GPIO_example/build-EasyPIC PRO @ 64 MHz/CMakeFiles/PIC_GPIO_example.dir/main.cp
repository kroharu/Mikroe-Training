#line 1 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/PIC_GPIO_example/main.c"
#line 6 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/PIC_GPIO_example/main.c"
void EXT_ISR() iv 8
{
#line 11 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/PIC_GPIO_example/main.c"
    INTCON.B1 = 0;
    LATC = ~LATC;
}

void main(void)
{
    INTCON.B6 = 1;
    INTCON.B7 = 1;

    INTCON.B4 = 1;

    TRISB.B0 = 1;
    TRISC = 0;
    LATC = 0;
#line 30 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/PIC_GPIO_example/main.c"
    while (1);
}
