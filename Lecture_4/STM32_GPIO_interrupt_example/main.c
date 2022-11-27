/**
 * @file main.c
 * @brief Main function for STM32_GPIO_interrupt_example application.
 */

void EXT_ISR() iv 22
{
    /* NOTE what happens if you don't clear
     * the interrupt flag.
     */
    EXTI_PR.B0 = 1;             // Clear flag.
    GPIOE_ODR = ~GPIOE_IDR;     // Toggle PORTE.
    Delay_ms(100);
}

void main(void)
{
    RCC_APB2ENR.B14 = 1;        // Enable clock for alternate pin functions.
    SYSCFG_EXTICR1 = 1;         // Map external interrupt on PB0.
    
    EXTI_PTSR = 0x00000000;     // Set interrupt on Rising edge (none).
    EXTI_FTSR = 0x00000001;     // Set interrupt on Falling edge (PB0).
    
    EXTI_IMR |= 0x00000001;     // Set mask - input 0.
    
    /* NOTE that this is defined as
     * External interrupt 0
     * for STM32F407ZG.
     * Effectively, we do the following:
     * NVIC_ISER0.B6 = 1;
     */
    NVIC_IntEnable(22);         // Enable External interrupt.
    
    // Enable digital output on PORTE.
    GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_HIGH);
    GPIOE_ODR = 0xAAAA;
    // Enable digital input on PORTB pin 0.
    GPIO_Digital_Input(&GPIOB_BASE, _GPIO_PINMASK_0);
    
    while (1);                  // Infinite loop.
}
