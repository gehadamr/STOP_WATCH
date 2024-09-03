################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../GIE_Program.c \
../Keypad_program.c \
../LCD_program.c \
../TIMER0_Program.c \
../maain.c 

OBJS += \
./DIO_program.o \
./GIE_Program.o \
./Keypad_program.o \
./LCD_program.o \
./TIMER0_Program.o \
./maain.o 

C_DEPS += \
./DIO_program.d \
./GIE_Program.d \
./Keypad_program.d \
./LCD_program.d \
./TIMER0_Program.d \
./maain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


