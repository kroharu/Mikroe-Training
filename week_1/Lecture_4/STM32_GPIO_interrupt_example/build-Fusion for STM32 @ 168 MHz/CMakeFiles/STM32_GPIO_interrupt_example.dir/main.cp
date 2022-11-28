#line 1 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/STM32_GPIO_interrupt_example/main.c"
#line 6 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/STM32_GPIO_interrupt_example/main.c"
void EXT_ISR() iv 22
{
#line 11 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/STM32_GPIO_interrupt_example/main.c"
    EXTI_PR.B0 = 1;
    GPIOE_ODR = ~GPIOE_IDR;
    Delay_ms(100);
}

void main(void)
{
    RCC_APB2ENR.B14 = 1;
    SYSCFG_EXTICR1 = 1;

    EXTI_RTSR = 0x00000000;
    EXTI_FTSR = 0x00000001;

    EXTI_IMR |= 0x00000001;
#line 32 "C:/Users/footb/Documents/MIKROE/Week_1/Lecture_4/STM32_GPIO_interrupt_example/main.c"
    NVIC_IntEnable(22);


    GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_HIGH);
    GPIOE_ODR = 0xAAAA;

    GPIO_Digital_Input(&GPIOB_BASE, _GPIO_PINMASK_0);

    while (1);
}
