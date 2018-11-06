################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../config/ \
../Debug/ \
../documentation/ \
../headers/ \
../sources/ \
../__vm/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../sources/config.cpp \
../sources/driver.cpp \
../sources/encoder.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
sources/config.o \
sources/driver.o \
sources/encoder.o

OBJS_AS_ARGS +=  \
sources/config.o \
sources/driver.o \
sources/encoder.o

C_DEPS +=  \
sources/config.d \
sources/driver.d \
sources/encoder.d

C_DEPS_AS_ARGS +=  \
sources/config.d \
sources/driver.d \
sources/encoder.d

OUTPUT_FILE_PATH +=driversL298.elf

OUTPUT_FILE_PATH_AS_ARGS +=driversL298.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler







sources/%.o: ../sources/%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)Y:\atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -D__AVR_ATmega328p__ -D__AVR_ATmega328P__ -DARDUINO=10803 -DARDUINO_MAIN -DF_CPU=16000000L -D__AVR__ -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR  -I"q:/Arduino/libraries" -I"q:/Arduino/hardware/arduino/avr/libraries" -I"C:/Users/User/Documents/Arduino/libraries" -I"q:/Arduino/hardware/arduino/avr/cores/arduino" -I"q:/Arduino/hardware/arduino/avr/variants/standard" -I"../../../driversL298" -I"q:/Arduino/hardware/tools/avr/avr/include" -I"q:/Arduino/hardware/tools/avr/avr/include/avr" -I"q:/Arduino/hardware/tools/avr/lib/gcc/avr/4.8.1/include" -I"q:/Arduino/hardware/tools/avr/lib/gcc/avr/4.9.2/include" -I"q:/Arduino/hardware/tools/avr/lib/gcc/avr/4.9.3/include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)Y:\atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="driversL298.map" -Wl,--start-group  -Wl,--end-group -Wl,--gc-sections  
	@echo Finished building target: $@
	"Y:\atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "driversL298.elf" "driversL298.hex"
	"Y:\atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "driversL298.elf" "driversL298.eep" || exit 0
	"Y:\atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "driversL298.elf" > "driversL298.lss"
	"Y:\atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "driversL298.elf" "driversL298.srec"
	"Y:\atmel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "driversL298.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "driversL298.elf" "driversL298.a" "driversL298.hex" "driversL298.lss" "driversL298.eep" "driversL298.map" "driversL298.srec" "driversL298.usersignatures"
	