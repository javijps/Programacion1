################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Biblioteca1.c \
../src/BibliotecaEstructuras.c \
../src/utn.c 

OBJS += \
./src/Biblioteca1.o \
./src/BibliotecaEstructuras.o \
./src/utn.o 

C_DEPS += \
./src/Biblioteca1.d \
./src/BibliotecaEstructuras.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


