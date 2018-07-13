################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 14
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
S32K_boot_b170718.elf \

EXECUTABLES_QUOTED += \
"S32K_boot_b170718.elf" \

EXECUTABLES_OS_FORMAT += \
S32K_boot_b170718.elf \

SECONDARY_FLASH += \
S32K_boot_b170718.srec \

SECONDARY_FLASH_QUOTED += \
"S32K_boot_b170718.srec" \

SECONDARY_FLASH_OS_FORMAT += \
S32K_boot_b170718.srec \

SECONDARY_SIZE += \
S32K_boot_b170718.siz \

SECONDARY_SIZE_QUOTED += \
"S32K_boot_b170718.siz" \

SECONDARY_SIZE_OS_FORMAT += \
S32K_boot_b170718.siz \


# All Target
all: warning-messages explicit-dependencies S32K_boot_b170718.elf secondary-outputs

# Tool invocations
S32K_boot_b170718.elf: $(OBJS) D:/S32K_JN/S32K_CANbootloader/S32K_boot_b170718/Project_Settings/Linker_Files/S32K1xx_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #15 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "S32K_boot_b170718.elf" "@S32K_boot_b170718.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

S32K_boot_b170718.srec: $(EXECUTABLES)
	@echo 'Executing target #16 $@'
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O srec $(EXECUTABLES)  "S32K_boot_b170718.srec"
	@echo 'Finished building: $@'
	@echo ' '

S32K_boot_b170718.siz: $(EXECUTABLES)
	@echo 'Executing target #17 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_FLASH_QUOTED) ./*/*/*.d ./*/*.d  ./*/*/*.o ./*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

