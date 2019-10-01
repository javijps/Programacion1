################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Pantallas.c \
../src/Publicidades.c \
../src/TP_2.c \
../src/empleados.c \
../src/utn.c 

OBJS += \
./src/Pantallas.o \
./src/Publicidades.o \
./src/TP_2.o \
./src/empleados.o \
./src/utn.o 

C_DEPS += \
./src/Pantallas.d \
./src/Publicidades.d \
./src/TP_2.d \
./src/empleados.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


