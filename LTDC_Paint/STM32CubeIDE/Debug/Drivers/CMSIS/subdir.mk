################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/aljazjustin/soal-programi/2.\ Letnik/OR/Game/LTDC_Paint/Src/system_stm32h7xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32h7xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32h7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32h7xx.o: /Users/aljazjustin/soal-programi/2.\ Letnik/OR/Game/LTDC_Paint/Src/system_stm32h7xx.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_USB_FS -DAPPLICATION_ADDRESS=0x90000000 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/BSP/STM32H750B-DK -I../../Utilities/Fonts -I../../Drivers/BSP/Components/Common -I../../Utilities -I../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I../../Middlewares/Third_Party/FatFs/src -I../../Utilities/lcd -I../../Utilities/Lcd_Trace -I.././ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/system_stm32h7xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32h7xx.d ./Drivers/CMSIS/system_stm32h7xx.o ./Drivers/CMSIS/system_stm32h7xx.su

.PHONY: clean-Drivers-2f-CMSIS

