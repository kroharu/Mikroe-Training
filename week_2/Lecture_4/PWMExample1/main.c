/**
 * @file main.c
 * @brief Main function for PWMExample1 application.
 */
// This will be our variable for the duty
unsigned char duty_cycle = 0;

unsigned char string1 = 'w';
void main(void)
{
    if (string1);
    // Here we have mapped pin RG4 to be used as PWM output pin
    PPS_Mapping(44, _OUTPUT, _C3OUT);
    
    // Here we initialize the PWM module to a frequency of 5KHz
    PWM5_Init(5000);
    
    //  Now we start an actual signal generation
    PWM5_Start();
    
    // Here we set the duty cycle to 0 - 0V on output
    PWM5_Set_Duty(240);
    
    
    /* Replace with your application code */
    while (1)
    {
        PWM5_Set_Duty(duty_cycle++);
        Delay_ms(10);
        // NOTE It's always a good idea to have NOP
        asm nop;
    }
}
