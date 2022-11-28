#line 1 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_1/LED_Blinking/main.c"
#line 20 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_1/LED_Blinking/main.c"
void main() {
    GPIO_Digital_Output(&GPIOA_BASE, 0x1FFF);
    GPIO_Digital_Output(&GPIOB_BASE, _GPIO_PINMASK_ALL);
    GPIO_Digital_Output(&GPIOC_BASE, _GPIO_PINMASK_ALL);
    GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_ALL);
    GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_ALL);
    GPIO_Digital_Output(&GPIOF_BASE, _GPIO_PINMASK_ALL);
    GPIO_Digital_Output(&GPIOG_BASE, _GPIO_PINMASK_ALL);

    GPIOA_ODR = 0;
    GPIOB_ODR = 0;
    GPIOC_ODR = 0;
    GPIOD_ODR = 0;
    GPIOE_ODR = 0;
    GPIOF_ODR = 0;
    GPIOG_ODR = 0;

    while(1) {
        GPIOA_ODR = ~GPIOA_ODR;
        GPIOB_ODR = ~GPIOA_ODR;
        GPIOC_ODR = ~GPIOA_ODR;
        GPIOD_ODR = ~GPIOA_ODR;
        GPIOE_ODR = ~GPIOA_ODR;
        GPIOF_ODR = ~GPIOA_ODR;
        GPIOG_ODR = ~GPIOA_ODR;
        Delay_ms(1000);
    }
}
