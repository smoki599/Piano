################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/fmc.c \
D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/main.c \
D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/memory_msp.c \
D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/mmc.c \
D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/qspi.c \
D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/stm32h7xx_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c 

OBJS += \
./Application/User/fmc.o \
./Application/User/main.o \
./Application/User/memory_msp.o \
./Application/User/mmc.o \
./Application/User/qspi.o \
./Application/User/stm32h7xx_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o 

C_DEPS += \
./Application/User/fmc.d \
./Application/User/main.d \
./Application/User/memory_msp.d \
./Application/User/mmc.d \
./Application/User/qspi.d \
./Application/User/stm32h7xx_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/fmc.o: D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/fmc.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../Drivers/BSP/STM32H750B-DK -I../../../../../../Drivers/BSP/Components -I../../../../../../Utilities -I../../../../../../Utilities/Fonts -I../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../Middlewares/Third_Party/FatFs/src/drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../Drivers/BSP/STM32H750B-DK -I../../../../../../Drivers/BSP/Components -I../../../../../../Utilities -I../../../../../../Utilities/Fonts -I../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../Middlewares/Third_Party/FatFs/src/drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/memory_msp.o: D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/memory_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../Drivers/BSP/STM32H750B-DK -I../../../../../../Drivers/BSP/Components -I../../../../../../Utilities -I../../../../../../Utilities/Fonts -I../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../Middlewares/Third_Party/FatFs/src/drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/mmc.o: D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/mmc.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../Drivers/BSP/STM32H750B-DK -I../../../../../../Drivers/BSP/Components -I../../../../../../Utilities -I../../../../../../Utilities/Fonts -I../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../Middlewares/Third_Party/FatFs/src/drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/qspi.o: D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/qspi.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../Drivers/BSP/STM32H750B-DK -I../../../../../../Drivers/BSP/Components -I../../../../../../Utilities -I../../../../../../Utilities/Fonts -I../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../Middlewares/Third_Party/FatFs/src/drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32h7xx_it.o: D:/FRI_zapiski/OR/STM32CubeH7-master/STM32CubeH7-master/Projects/STM32H750B-DK/Templates/ExtMem_Boot/Src/stm32h7xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../Drivers/BSP/STM32H750B-DK -I../../../../../../Drivers/BSP/Components -I../../../../../../Utilities -I../../../../../../Utilities/Fonts -I../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../Middlewares/Third_Party/FatFs/src/drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o Application/User/%.su: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../../Inc -I../../../../../../Drivers/CMSIS/Include -I../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../Drivers/BSP/STM32H750B-DK -I../../../../../../Drivers/BSP/Components -I../../../../../../Utilities -I../../../../../../Utilities/Fonts -I../../../../../../Middlewares/Third_Party/FatFs/src -I../../../../../../Middlewares/Third_Party/FatFs/src/drivers -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/fmc.d ./Application/User/fmc.o ./Application/User/fmc.su ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/memory_msp.d ./Application/User/memory_msp.o ./Application/User/memory_msp.su ./Application/User/mmc.d ./Application/User/mmc.o ./Application/User/mmc.su ./Application/User/qspi.d ./Application/User/qspi.o ./Application/User/qspi.su ./Application/User/stm32h7xx_it.d ./Application/User/stm32h7xx_it.o ./Application/User/stm32h7xx_it.su ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su

.PHONY: clean-Application-2f-User
