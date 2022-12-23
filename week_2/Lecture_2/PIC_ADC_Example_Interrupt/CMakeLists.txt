cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(PIC_ADC_Example_Interrupt LANGUAGES MikroC)
else()
    project(PIC_ADC_Example_Interrupt LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(PIC_ADC_Example_Interrupt main.c)
############################ PIC_ADC_Example_Interrupt GENERATED CODE START ###########################
############################ PIC_ADC_Example_Interrupt GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(PIC_ADC_Example_Interrupt
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(PIC_ADC_Example_Interrupt
        PUBLIC
            MikroC.System
    )
endif()
