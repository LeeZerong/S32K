################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 5
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
APP_S32K144_LED_V089.elf \

EXECUTABLES_QUOTED += \
"APP_S32K144_LED_V089.elf" \

EXECUTABLES_OS_FORMAT += \
APP_S32K144_LED_V089.elf \

SECONDARY_FLASH += \
APP_S32K144_LED_V089.bin \

SECONDARY_FLASH_QUOTED += \
"APP_S32K144_LED_V089.bin" \

SECONDARY_FLASH_OS_FORMAT += \
APP_S32K144_LED_V089.bin \

SECONDARY_SIZE += \
APP_S32K144_LED_V089.siz \

SECONDARY_SIZE_QUOTED += \
"APP_S32K144_LED_V089.siz" \

SECONDARY_SIZE_OS_FORMAT += \
APP_S32K144_LED_V089.siz \


# All Target
all: warning-messages explicit-dependencies APP_S32K144_LED_V089.elf secondary-outputs

# Tool invocations
APP_S32K144_LED_V089.elf: $(OBJS) C:/Users/Administrator/Desktop/BootLoader_S32K144\ \ 20180711(zlg)/BootLoader_S32K144\ \ 20180711/APP_S32K144_LED_V089/Project_Settings/Linker_Files/S32K1xx_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #6 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "APP_S32K144_LED_V089.elf" "@APP_S32K144_LED_V089.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

APP_S32K144_LED_V089.bin: $(EXECUTABLES)
	@echo 'Executing target #7 $@'
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O binary $(EXECUTABLES)  "APP_S32K144_LED_V089.bin"
	@echo 'Finished building: $@'
	@echo ' '

APP_S32K144_LED_V089.siz: $(EXECUTABLES)
	@echo 'Executing target #8 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_FLASH_QUOTED) ./*/*.d ./*/*/*.d  ./*/*.o ./*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

