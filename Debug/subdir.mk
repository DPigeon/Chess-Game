################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Board.cpp \
../Game.cpp \
../Pawn.cpp \
../Player.cpp 

OBJS += \
./Board.o \
./Game.o \
./Pawn.o \
./Player.o 

CPP_DEPS += \
./Board.d \
./Game.d \
./Pawn.d \
./Player.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


