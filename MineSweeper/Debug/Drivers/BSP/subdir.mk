################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/stm32h750b_discovery.c \
../Drivers/BSP/stm32h750b_discovery_audio.c \
../Drivers/BSP/stm32h750b_discovery_bus.c \
../Drivers/BSP/stm32h750b_discovery_lcd.c \
../Drivers/BSP/stm32h750b_discovery_mmc.c \
../Drivers/BSP/stm32h750b_discovery_qspi.c \
../Drivers/BSP/stm32h750b_discovery_sdram.c \
../Drivers/BSP/stm32h750b_discovery_ts.c 

OBJS += \
./Drivers/BSP/stm32h750b_discovery.o \
./Drivers/BSP/stm32h750b_discovery_audio.o \
./Drivers/BSP/stm32h750b_discovery_bus.o \
./Drivers/BSP/stm32h750b_discovery_lcd.o \
./Drivers/BSP/stm32h750b_discovery_mmc.o \
./Drivers/BSP/stm32h750b_discovery_qspi.o \
./Drivers/BSP/stm32h750b_discovery_sdram.o \
./Drivers/BSP/stm32h750b_discovery_ts.o 

C_DEPS += \
./Drivers/BSP/stm32h750b_discovery.d \
./Drivers/BSP/stm32h750b_discovery_audio.d \
./Drivers/BSP/stm32h750b_discovery_bus.d \
./Drivers/BSP/stm32h750b_discovery_lcd.d \
./Drivers/BSP/stm32h750b_discovery_mmc.d \
./Drivers/BSP/stm32h750b_discovery_qspi.d \
./Drivers/BSP/stm32h750b_discovery_sdram.d \
./Drivers/BSP/stm32h750b_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o Drivers/BSP/%.su: ../Drivers/BSP/%.c Drivers/BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Utilities/Fonts" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/ft5336" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/mt25tl01g" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/mt48lc4m32b2" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/rk043fn48h" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/wm8994" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components/Common" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Middlewares/ST/STM32_Audio/Addons/PDM/Inc" -I"/Users/aljazjustin/soal-programi/2. Letnik/OR/Stm32H750B-DK_Minesweeper/MineSweeper/Drivers/BSP/Components" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Minesweeper -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP

clean-Drivers-2f-BSP:
	-$(RM) ./Drivers/BSP/stm32h750b_discovery.d ./Drivers/BSP/stm32h750b_discovery.o ./Drivers/BSP/stm32h750b_discovery.su ./Drivers/BSP/stm32h750b_discovery_audio.d ./Drivers/BSP/stm32h750b_discovery_audio.o ./Drivers/BSP/stm32h750b_discovery_audio.su ./Drivers/BSP/stm32h750b_discovery_bus.d ./Drivers/BSP/stm32h750b_discovery_bus.o ./Drivers/BSP/stm32h750b_discovery_bus.su ./Drivers/BSP/stm32h750b_discovery_lcd.d ./Drivers/BSP/stm32h750b_discovery_lcd.o ./Drivers/BSP/stm32h750b_discovery_lcd.su ./Drivers/BSP/stm32h750b_discovery_mmc.d ./Drivers/BSP/stm32h750b_discovery_mmc.o ./Drivers/BSP/stm32h750b_discovery_mmc.su ./Drivers/BSP/stm32h750b_discovery_qspi.d ./Drivers/BSP/stm32h750b_discovery_qspi.o ./Drivers/BSP/stm32h750b_discovery_qspi.su ./Drivers/BSP/stm32h750b_discovery_sdram.d ./Drivers/BSP/stm32h750b_discovery_sdram.o ./Drivers/BSP/stm32h750b_discovery_sdram.su ./Drivers/BSP/stm32h750b_discovery_ts.d ./Drivers/BSP/stm32h750b_discovery_ts.o ./Drivers/BSP/stm32h750b_discovery_ts.su

.PHONY: clean-Drivers-2f-BSP

