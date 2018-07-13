################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/FlexCAN.c" \
"../src/LPSPI.c" \
"../src/clocks_and_modes.c" \
"../src/config.c" \
"../src/crc16.c" \
"../src/flash.c" \
"../src/flash_driver.c" \
"../src/main.c" \
"../src/sbc_uja11691.c" \
"../src/sbc_uja1169_driver.c" \
"../src/xmodem.c" \

C_SRCS += \
../src/FlexCAN.c \
../src/LPSPI.c \
../src/clocks_and_modes.c \
../src/config.c \
../src/crc16.c \
../src/flash.c \
../src/flash_driver.c \
../src/main.c \
../src/sbc_uja11691.c \
../src/sbc_uja1169_driver.c \
../src/xmodem.c \

C_DEPS_QUOTED += \
"./src/FlexCAN.d" \
"./src/LPSPI.d" \
"./src/clocks_and_modes.d" \
"./src/config.d" \
"./src/crc16.d" \
"./src/flash.d" \
"./src/flash_driver.d" \
"./src/main.d" \
"./src/sbc_uja11691.d" \
"./src/sbc_uja1169_driver.d" \
"./src/xmodem.d" \

OBJS_QUOTED += \
"./src/FlexCAN.o" \
"./src/LPSPI.o" \
"./src/clocks_and_modes.o" \
"./src/config.o" \
"./src/crc16.o" \
"./src/flash.o" \
"./src/flash_driver.o" \
"./src/main.o" \
"./src/sbc_uja11691.o" \
"./src/sbc_uja1169_driver.o" \
"./src/xmodem.o" \

C_DEPS += \
./src/FlexCAN.d \
./src/LPSPI.d \
./src/clocks_and_modes.d \
./src/config.d \
./src/crc16.d \
./src/flash.d \
./src/flash_driver.d \
./src/main.d \
./src/sbc_uja11691.d \
./src/sbc_uja1169_driver.d \
./src/xmodem.d \

OBJS_OS_FORMAT += \
./src/FlexCAN.o \
./src/LPSPI.o \
./src/clocks_and_modes.o \
./src/config.o \
./src/crc16.o \
./src/flash.o \
./src/flash_driver.o \
./src/main.o \
./src/sbc_uja11691.o \
./src/sbc_uja1169_driver.o \
./src/xmodem.o \

OBJS += \
./src/FlexCAN.o \
./src/LPSPI.o \
./src/clocks_and_modes.o \
./src/config.o \
./src/crc16.o \
./src/flash.o \
./src/flash_driver.o \
./src/main.o \
./src/sbc_uja11691.o \
./src/sbc_uja1169_driver.o \
./src/xmodem.o \


# Each subdirectory must supply rules for building sources it contributes
src/FlexCAN.o: ../src/FlexCAN.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/FlexCAN.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/FlexCAN.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/LPSPI.o: ../src/LPSPI.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/LPSPI.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/LPSPI.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/clocks_and_modes.o: ../src/clocks_and_modes.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/clocks_and_modes.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/clocks_and_modes.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/config.o: ../src/config.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/config.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/crc16.o: ../src/crc16.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/crc16.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/crc16.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/flash.o: ../src/flash.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/flash.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/flash.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/flash_driver.o: ../src/flash_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/flash_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/flash_driver.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sbc_uja11691.o: ../src/sbc_uja11691.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/sbc_uja11691.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/sbc_uja11691.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sbc_uja1169_driver.o: ../src/sbc_uja1169_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/sbc_uja1169_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/sbc_uja1169_driver.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xmodem.o: ../src/xmodem.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/xmodem.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/xmodem.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


