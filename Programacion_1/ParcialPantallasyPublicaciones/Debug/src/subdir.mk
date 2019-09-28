################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BibliotecaEstructuras.c \
../src/Pantallas.c \
../src/ParcialPantallasyPublicaciones.c \
../src/Publicidades.c \
../src/utn.c 

OBJS += \
./src/BibliotecaEstructuras.o \
./src/Pantallas.o \
./src/ParcialPantallasyPublicaciones.o \
./src/Publicidades.o \
./src/utn.o 

C_DEPS += \
./src/BibliotecaEstructuras.d \
./src/Pantallas.d \
./src/ParcialPantallasyPublicaciones.d \
./src/Publicidades.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


