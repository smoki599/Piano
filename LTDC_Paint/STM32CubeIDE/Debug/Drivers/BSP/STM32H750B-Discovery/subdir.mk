################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery.c \
/Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery_bus.c \
/Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery_lcd.c \
/Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery_sdram.c \
/Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery_ts.c 

OBJS += \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery.o \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_bus.o \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_lcd.o \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_sdram.o \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_ts.o 

C_DEPS += \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery.d \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_bus.d \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_lcd.d \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_sdram.d \
./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery.o: /Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery.c Drivers/BSP/STM32H750B-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_USB_FS -DAPPLICATION_ADDRESS=0x90000000 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/BSP/STM32H750B-DK -I../../Utilities/Fonts -I../../Drivers/BSP/Components/Common -I../../Utilities -I../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I../../Middlewares/Third_Party/FatFs/src -I../../Utilities/lcd -I../../Utilities/Lcd_Trace -I.././ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_bus.o: /Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery_bus.c Drivers/BSP/STM32H750B-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_USB_FS -DAPPLICATION_ADDRESS=0x90000000 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/BSP/STM32H750B-DK -I../../Utilities/Fonts -I../../Drivers/BSP/Components/Common -I../../Utilities -I../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I../../Middlewares/Third_Party/FatFs/src -I../../Utilities/lcd -I../../Utilities/Lcd_Trace -I.././ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_bus.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_lcd.o: /Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery_lcd.c Drivers/BSP/STM32H750B-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_USB_FS -DAPPLICATION_ADDRESS=0x90000000 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/BSP/STM32H750B-DK -I../../Utilities/Fonts -I../../Drivers/BSP/Components/Common -I../../Utilities -I../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I../../Middlewares/Third_Party/FatFs/src -I../../Utilities/lcd -I../../Utilities/Lcd_Trace -I.././ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_sdram.o: /Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery_sdram.c Drivers/BSP/STM32H750B-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_USB_FS -DAPPLICATION_ADDRESS=0x90000000 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/BSP/STM32H750B-DK -I../../Utilities/Fonts -I../../Drivers/BSP/Components/Common -I../../Utilities -I../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I../../Middlewares/Third_Party/FatFs/src -I../../Utilities/lcd -I../../Utilities/Lcd_Trace -I.././ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_sdram.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_ts.o: /Users/aljazjustin/soal-programi/2.\ Letnik/OR/Stm32H750B-DK_Minesweeper/LTDC_Paint/Drivers/BSP/STM32H750B-DK/stm32h750b_discovery_ts.c Drivers/BSP/STM32H750B-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_USB_FS -DAPPLICATION_ADDRESS=0x90000000 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/BSP/STM32H750B-DK -I../../Utilities/Fonts -I../../Drivers/BSP/Components/Common -I../../Utilities -I../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I../../Middlewares/Third_Party/FatFs/src -I../../Utilities/lcd -I../../Utilities/Lcd_Trace -I.././ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_ts.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H750B-2d-Discovery

clean-Drivers-2f-BSP-2f-STM32H750B-2d-Discovery:
	-$(RM) ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery.d ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery.o ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery.su ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_bus.d ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_bus.o ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_bus.su ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_lcd.d ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_lcd.o ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_lcd.su ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_sdram.d ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_sdram.o ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_sdram.su ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_ts.d ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_ts.o ./Drivers/BSP/STM32H750B-Discovery/stm32h750b_discovery_ts.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H750B-2d-Discovery

