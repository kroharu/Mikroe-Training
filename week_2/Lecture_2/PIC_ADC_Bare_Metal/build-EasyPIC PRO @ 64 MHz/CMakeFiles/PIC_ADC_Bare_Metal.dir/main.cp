#line 1 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_2/PIC_ADC_Bare_Metal/main.c"
#line 6 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_2/PIC_ADC_Bare_Metal/main.c"
#line 1 "C:/NECTOStudio/NECTOStudio/compilers/PIC/mikroC/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;


typedef signed char int_fast8_t;
typedef signed int int_fast16_t;
typedef signed long int int_fast32_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;


typedef signed int intptr_t;
typedef unsigned int uintptr_t;


typedef signed long int intmax_t;
typedef unsigned long int uintmax_t;
#line 7 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_2/PIC_ADC_Bare_Metal/main.c"
#line 15 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_2/PIC_ADC_Bare_Metal/main.c"
uint16_t adc_rd;


void main(void) {
#line 23 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_2/PIC_ADC_Bare_Metal/main.c"
    ANCON1.B3 = 1;

    TRISA.B3 = 1;

    TRISD = 0x00;
    TRISE = 0x00;
#line 34 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_2/PIC_ADC_Bare_Metal/main.c"
    ADCON1L = 0x70;

    ADCON1H.MODE12 = 1;

    ADCSS0H = 0;
#line 41 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_2/PIC_ADC_Bare_Metal/main.c"
    ADCON3H = 0x1F;
#line 47 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_2/PIC_ADC_Bare_Metal/main.c"
    ADCON3L = 0x02;

    ADCON2L = 0;

    ADCHS0L = 3;
#line 55 "C:/Users/footb/Documents/MIKROE/Week_2/Lecture_2/PIC_ADC_Bare_Metal/main.c"
    ADCON1H.ADON = 1;

    Delay_ms(100);


    TRISL.B1 = 0;
    TRISG.B4 = 0;
    LATL.B1 = 1;
    LATG.B4 = 1;


    while (1) {

        ADCON1L.SAMP = 1;
        while (ADCON1L.DONE != 0) {

        } ;


        adc_rd = ADCBUF0;


        LATD = adc_rd;

        LATE = adc_rd >> 8;
    }
}
