################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
A:/Engineering/DataSheets/STM32/STM32Cube_FW_F4_V1.13.0/Projects/STM32F412ZG-Nucleo/Examples/GPIO/GPIO_IOToggle/Src/system_stm32f4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f4xx.o: A:/Engineering/DataSheets/STM32/STM32Cube_FW_F4_V1.13.0/Projects/STM32F412ZG-Nucleo/Examples/GPIO/GPIO_IOToggle/Src/system_stm32f4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F412Zx -DUSE_HAL_DRIVER -DUSE_STM32F4XX_NUCLEO_144 -I"A:/Engineering/DataSheets/STM32/STM32Cube_FW_F4_V1.13.0/Projects/STM32F412ZG-Nucleo/Examples/GPIO/GPIO_IOToggle/Inc" -I"A:/Engineering/DataSheets/STM32/STM32Cube_FW_F4_V1.13.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"A:/Engineering/DataSheets/STM32/STM32Cube_FW_F4_V1.13.0/Drivers/CMSIS/Include" -I"A:/Engineering/DataSheets/STM32/STM32Cube_FW_F4_V1.13.0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"A:/Engineering/DataSheets/STM32/STM32Cube_FW_F4_V1.13.0/Drivers/BSP/STM32F4xx_Nucleo_144"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


