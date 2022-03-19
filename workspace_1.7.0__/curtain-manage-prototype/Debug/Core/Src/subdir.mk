################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/LDR.c \
../Core/Src/Servo.c \
../Core/Src/ServoScheduler.c \
../Core/Src/adc.c \
../Core/Src/bluetooth.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/myutilities.c \
../Core/Src/rtc.c \
../Core/Src/stm32l0xx_hal_msp.c \
../Core/Src/stm32l0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l0xx.c \
../Core/Src/tim.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/LDR.o \
./Core/Src/Servo.o \
./Core/Src/ServoScheduler.o \
./Core/Src/adc.o \
./Core/Src/bluetooth.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/myutilities.o \
./Core/Src/rtc.o \
./Core/Src/stm32l0xx_hal_msp.o \
./Core/Src/stm32l0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l0xx.o \
./Core/Src/tim.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/LDR.d \
./Core/Src/Servo.d \
./Core/Src/ServoScheduler.d \
./Core/Src/adc.d \
./Core/Src/bluetooth.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/myutilities.d \
./Core/Src/rtc.d \
./Core/Src/stm32l0xx_hal_msp.d \
./Core/Src/stm32l0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l0xx.d \
./Core/Src/tim.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I"/home/asap/STM32CubeIDE/workspace_1.7.0__/curtain-manage-prototype/Core/Inc" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

