################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
matrix_test.lss \

FLASH_IMAGE += \
matrix_test.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: matrix_test.elf secondary-outputs

# Tool invocations
matrix_test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,matrix_test.map -L"C:\Users\Aleksa\Desktop\FTN 2021\RAZVOJ SOFTVERA\ECLIPSE\timer0\Debug" -L"C:\Users\Aleksa\Desktop\FTN 2021\RAZVOJ SOFTVERA\ECLIPSE\usart\Release" -L"C:\Users\Aleksa\Desktop\FTN 2021\RAZVOJ SOFTVERA\ECLIPSE\matrix\Release" -mmcu=atmega328p -o "matrix_test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

matrix_test.lss: matrix_test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S matrix_test.elf  >"matrix_test.lss"
	@echo 'Finished building: $@'
	@echo ' '

matrix_test.hex: matrix_test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex matrix_test.elf  "matrix_test.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: matrix_test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p matrix_test.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: matrix_test.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm328p -carduino -PCOM4 -Uflash:w:matrix_test.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) matrix_test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
