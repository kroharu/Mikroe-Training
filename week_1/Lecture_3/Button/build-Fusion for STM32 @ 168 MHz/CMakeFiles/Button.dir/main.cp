#line 1 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_3/Button/main.c"
#line 23 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_3/Button/main.c"
unsigned int oldstate;

void main (void)
{
    GPIO_Digital_Input(&GPIOA_IDR, _GPIO_PINMASK_0);
    GPIO_Digital_Output(&GPIOD_ODR, _GPIO_PINMASK_ALL);
    oldstate = 0;

    do {
        if (Button(&GPIOA_IDR, 0, 1, 1))
            oldstate = 1;
        if (oldstate && Button(&GPIOA_IDR, 0, 1, 0)) {
            GPIOD_ODR = ~GPIOD_ODR;
            oldstate = 0;
        }
    } while (1);
}
