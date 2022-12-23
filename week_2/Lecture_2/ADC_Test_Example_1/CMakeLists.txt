cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(ADC_Test_Example_1 LANGUAGES MikroC)
else()
    project(ADC_Test_Example_1 LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(ADC_Test_Example_1 main.c)
############################ ADC_Test_Example_1 GENERATED CODE START ###########################
############################ ADC_Test_Example_1 GENERATED CODE END ###########################

if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(ADC_Test_Example_1
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(ADC_Test_Example_1
        PUBLIC
            MikroC.System
    )
endif()
