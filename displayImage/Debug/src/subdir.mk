################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/displayImage.cpp 

OBJS += \
./src/displayImage.o 

CPP_DEPS += \
./src/displayImage.d 


# Each subdirectory must supply rules for building sources it contributes
src/displayImage.o: ../src/displayImage.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/displayImage.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


