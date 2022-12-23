cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(PIC_ADC_Bare_Metal LANGUAGES MikroC)
else()
    project(PIC_ADC_Bare_Metal LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(PIC_ADC_Bare_Metal main.c)
############################ PIC_ADC_Bare_Metal GENERATED CODE START ###########################
############################ PIC_ADC_Bare_Metal GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(PIC_ADC_Bare_Metal
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(PIC_ADC_Bare_Metal
        PUBLIC
            MikroC.System
    )
endif()
