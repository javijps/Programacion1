################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Clase\ 11.c \
../src/clase11.c \
../src/clase12.c 

OBJS += \
./src/Clase\ 11.o \
./src/clase11.o \
./src/clase12.o 

C_DEPS += \
./src/Clase\ 11.d \
./src/clase11.d \
./src/clase12.d 


# Each subdirectory must supply rules for building sources it contributes
src/Clase\ 11.o: ../src/Clase\ 11.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Clase 11.d" -MT"src/Clase\ 11.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


