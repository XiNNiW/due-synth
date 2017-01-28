################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/factorial.test.cpp \
../src/run-all-tests.cpp 

OBJS += \
./src/factorial.test.o \
./src/run-all-tests.o 

CPP_DEPS += \
./src/factorial.test.d \
./src/run-all-tests.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/davidminnix/Documents/workspace-due-custom/due-custom-sketch-test/libTest" -I"/Users/davidminnix/Documents/workspace-due-custom/due-custom-sketch/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


