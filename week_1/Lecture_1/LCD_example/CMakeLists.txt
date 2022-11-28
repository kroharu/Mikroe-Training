cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(LCD_example LANGUAGES MikroC)
else()
    project(LCD_example LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(LCD_example main.c)

############################ LCD_example GENERATED CODE START ###########################
find_package(MikroC.Core REQUIRED)
target_link_libraries(LCD_example PUBLIC MikroC.Core)
find_package(MikroC.System REQUIRED)
target_link_libraries(LCD_example PUBLIC MikroC.System)
find_package(MikroC.Lcd_Constants REQUIRED)
target_link_libraries(LCD_example PUBLIC MikroC.Lcd_Constants)
find_package(MikroC.Lcd REQUIRED)
target_link_libraries(LCD_example PUBLIC MikroC.Lcd)
############################ LCD_example GENERATED CODE END ###########################
if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(LCD_example
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(LCD_example
        PUBLIC
            MikroC.System
    )
endif()
