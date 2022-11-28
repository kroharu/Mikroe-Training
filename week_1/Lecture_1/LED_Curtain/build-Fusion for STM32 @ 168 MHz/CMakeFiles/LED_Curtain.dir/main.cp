#line 1 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_1/LED_Curtain/main.c"
#line 20 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_1/LED_Curtain/main.c"
int counter;
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

    counter = 0;
    while(1) {

        for (counter = 0; counter < 8; counter++) {
            GPIOA_ODR |= 0x8080 >> counter;
            GPIOB_ODR |= 0x8080 >> counter;
            GPIOC_ODR |= 0x8080 >> counter;
            GPIOD_ODR |= 0x8080 >> counter;
            GPIOE_ODR |= 0x8080 >> counter;
            GPIOF_ODR |= 0x8080 >> counter;
            GPIOG_ODR |= 0x8080 >> counter;
            Delay_ms(100);
        }

        for (counter = 0; counter < 8; counter++) {
            GPIOA_ODR &= 0x7F7F >> counter;
            GPIOB_ODR &= 0x7F7F >> counter;
            GPIOC_ODR &= 0x7F7F >> counter;
            GPIOD_ODR &= 0x7F7F >> counter;
            GPIOE_ODR &= 0x7F7F >> counter;
            GPIOF_ODR &= 0x7F7F >> counter;
            GPIOG_ODR &= 0x7F7F >> counter;
            Delay_ms(100);
        }
    }
}
