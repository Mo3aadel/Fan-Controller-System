################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application.c \
../DC_Motor.c \
../PWM_Timer.c \
../adc.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c 

OBJS += \
./Application.o \
./DC_Motor.o \
./PWM_Timer.o \
./adc.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o 

C_DEPS += \
./Application.d \
./DC_Motor.d \
./PWM_Timer.d \
./adc.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


