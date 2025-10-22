################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/arbre.c \
../Src/gpio.c \
../Src/interrupt.c \
../Src/main.c \
../Src/occurence.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/timer.c \
../Src/usart.c \
../Src/util.c 

OBJS += \
./Src/arbre.o \
./Src/gpio.o \
./Src/interrupt.o \
./Src/main.o \
./Src/occurence.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/timer.o \
./Src/usart.o \
./Src/util.o 

C_DEPS += \
./Src/arbre.d \
./Src/gpio.d \
./Src/interrupt.d \
./Src/main.d \
./Src/occurence.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/timer.d \
./Src/usart.d \
./Src/util.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I../Inc -I"D:/Utilisateurs/formation/Documents/Desktop/huffman/Huffman/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Utilisateurs/formation/Documents/Desktop/huffman/Huffman/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/arbre.cyclo ./Src/arbre.d ./Src/arbre.o ./Src/arbre.su ./Src/gpio.cyclo ./Src/gpio.d ./Src/gpio.o ./Src/gpio.su ./Src/interrupt.cyclo ./Src/interrupt.d ./Src/interrupt.o ./Src/interrupt.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/occurence.cyclo ./Src/occurence.d ./Src/occurence.o ./Src/occurence.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/timer.cyclo ./Src/timer.d ./Src/timer.o ./Src/timer.su ./Src/usart.cyclo ./Src/usart.d ./Src/usart.o ./Src/usart.su ./Src/util.cyclo ./Src/util.d ./Src/util.o ./Src/util.su

.PHONY: clean-Src

