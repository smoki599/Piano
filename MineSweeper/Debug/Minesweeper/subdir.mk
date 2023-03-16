################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Minesweeper/sweeperMain.c 

OBJS += \
./Minesweeper/sweeperMain.o 

C_DEPS += \
./Minesweeper/sweeperMain.d 


# Each subdirectory must supply rules for building sources it contributes
Minesweeper/%.o Minesweeper/%.su: ../Minesweeper/%.c Minesweeper/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Utilities/Fonts" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/ft5336" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/mt25tl01g" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/mt48lc4m32b2" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/rk043fn48h" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/wm8994" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/Common" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Middlewares/ST/STM32_Audio/Addons/PDM/Inc" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Minesweeper -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Minesweeper

clean-Minesweeper:
	-$(RM) ./Minesweeper/sweeperMain.d ./Minesweeper/sweeperMain.o ./Minesweeper/sweeperMain.su

.PHONY: clean-Minesweeper

