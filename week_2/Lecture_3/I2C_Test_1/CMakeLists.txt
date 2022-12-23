cmake_minimum_required(VERSION 3.19)

if (${TOOLCHAIN_LANGUAGE} MATCHES "MikroC")
    project(I2C_Test_1 LANGUAGES MikroC)
else()
    project(I2C_Test_1 LANGUAGES C ASM)
endif()

set(PROJECT_TYPE "legacy" CACHE STRING "" FORCE)

add_executable(I2C_Test_1 main.c)

############################ I2C_Test_1 GENERATED CODE START ###########################
find_package(MikroC.Core REQUIRED)
target_link_libraries(I2C_Test_1 PUBLIC MikroC.Core)
find_package(MikroC.System REQUIRED)
target_link_libraries(I2C_Test_1 PUBLIC MikroC.System)
find_package(MikroC.Software_I2C REQUIRED)
target_link_libraries(I2C_Test_1 PUBLIC MikroC.Software_I2C)
find_package(MikroC.I2C REQUIRED)
target_link_libraries(I2C_Test_1 PUBLIC MikroC.I2C)
############################ I2C_Test_1 GENERATED CODE END ###########################
if (${MIKROSDK_TYPE} STREQUAL "mikrosdk")
    find_package(MikroC.Core REQUIRED)
    target_link_libraries(I2C_Test_1
        PUBLIC
            MikroC.Core
    )
else()
    find_package(MikroC.System REQUIRED)
    target_link_libraries(I2C_Test_1
        PUBLIC
            MikroC.System
    )
endif()
