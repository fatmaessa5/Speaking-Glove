################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC_Driver_V1/ADC_prg.c 

OBJS += \
./MCAL/ADC_Driver_V1/ADC_prg.o 

C_DEPS += \
./MCAL/ADC_Driver_V1/ADC_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/ADC_Driver_V1/%.o: ../MCAL/ADC_Driver_V1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


