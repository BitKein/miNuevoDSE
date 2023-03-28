#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/P6_OCPWM_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/P6_OCPWM_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../ADC1.c ../CN.c ../GPIO.c ../LCD.c ../OCPWM.c ../UART2_RS232.c ../main_P6_OCPWM_v1.c ../memoria.c ../oscilator.c ../timers.c ../utilidades.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/ADC1.o ${OBJECTDIR}/_ext/1472/CN.o ${OBJECTDIR}/_ext/1472/GPIO.o ${OBJECTDIR}/_ext/1472/LCD.o ${OBJECTDIR}/_ext/1472/OCPWM.o ${OBJECTDIR}/_ext/1472/UART2_RS232.o ${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o ${OBJECTDIR}/_ext/1472/memoria.o ${OBJECTDIR}/_ext/1472/oscilator.o ${OBJECTDIR}/_ext/1472/timers.o ${OBJECTDIR}/_ext/1472/utilidades.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/ADC1.o.d ${OBJECTDIR}/_ext/1472/CN.o.d ${OBJECTDIR}/_ext/1472/GPIO.o.d ${OBJECTDIR}/_ext/1472/LCD.o.d ${OBJECTDIR}/_ext/1472/OCPWM.o.d ${OBJECTDIR}/_ext/1472/UART2_RS232.o.d ${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o.d ${OBJECTDIR}/_ext/1472/memoria.o.d ${OBJECTDIR}/_ext/1472/oscilator.o.d ${OBJECTDIR}/_ext/1472/timers.o.d ${OBJECTDIR}/_ext/1472/utilidades.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/ADC1.o ${OBJECTDIR}/_ext/1472/CN.o ${OBJECTDIR}/_ext/1472/GPIO.o ${OBJECTDIR}/_ext/1472/LCD.o ${OBJECTDIR}/_ext/1472/OCPWM.o ${OBJECTDIR}/_ext/1472/UART2_RS232.o ${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o ${OBJECTDIR}/_ext/1472/memoria.o ${OBJECTDIR}/_ext/1472/oscilator.o ${OBJECTDIR}/_ext/1472/timers.o ${OBJECTDIR}/_ext/1472/utilidades.o

# Source Files
SOURCEFILES=../ADC1.c ../CN.c ../GPIO.c ../LCD.c ../OCPWM.c ../UART2_RS232.c ../main_P6_OCPWM_v1.c ../memoria.c ../oscilator.c ../timers.c ../utilidades.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/P6_OCPWM_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ256GP610A
MP_LINKER_FILE_OPTION=,--script=p24HJ256GP610A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/ADC1.o: ../ADC1.c  .generated_files/flags/default/262a7c246bc721cdea0442609b144dbcf9fdc77e .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ADC1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ADC1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ADC1.c  -o ${OBJECTDIR}/_ext/1472/ADC1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ADC1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/CN.o: ../CN.c  .generated_files/flags/default/79e6cbe08535b37105690bd47724754d451c7ff3 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CN.c  -o ${OBJECTDIR}/_ext/1472/CN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/CN.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/GPIO.o: ../GPIO.c  .generated_files/flags/default/ca0bd5a20484a4b8b6af1a4ec45e8a2b71c4f41b .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GPIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GPIO.c  -o ${OBJECTDIR}/_ext/1472/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/GPIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/LCD.o: ../LCD.c  .generated_files/flags/default/3353ee049e4b1136ed8203fbfcd485c255c08b6f .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../LCD.c  -o ${OBJECTDIR}/_ext/1472/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/OCPWM.o: ../OCPWM.c  .generated_files/flags/default/9cc1151e8cae0447f92b63c9fcb4f6d89ec849c2 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/OCPWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/OCPWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../OCPWM.c  -o ${OBJECTDIR}/_ext/1472/OCPWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/OCPWM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/UART2_RS232.o: ../UART2_RS232.c  .generated_files/flags/default/13a2313e7dc5ccde180f81ac2e0d44fdfa8f5a23 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UART2_RS232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UART2_RS232.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../UART2_RS232.c  -o ${OBJECTDIR}/_ext/1472/UART2_RS232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/UART2_RS232.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o: ../main_P6_OCPWM_v1.c  .generated_files/flags/default/b3de58b2b367e3e01f534d14f4a959a286da37a2 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main_P6_OCPWM_v1.c  -o ${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/memoria.o: ../memoria.c  .generated_files/flags/default/9259000eec68ab8576858ad5c3d86881e7796f0a .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../memoria.c  -o ${OBJECTDIR}/_ext/1472/memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/memoria.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/oscilator.o: ../oscilator.c  .generated_files/flags/default/ba76e3c5be96f0018bbabed097d7d24e523637f2 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../oscilator.c  -o ${OBJECTDIR}/_ext/1472/oscilator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/oscilator.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/timers.o: ../timers.c  .generated_files/flags/default/4974a1acd55c10b29a6866f8212d0842816a1497 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../timers.c  -o ${OBJECTDIR}/_ext/1472/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/timers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/utilidades.o: ../utilidades.c  .generated_files/flags/default/aca2e72a4245def7181dee086169c696c4049f1b .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/utilidades.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/utilidades.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../utilidades.c  -o ${OBJECTDIR}/_ext/1472/utilidades.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/utilidades.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/_ext/1472/ADC1.o: ../ADC1.c  .generated_files/flags/default/2ce6fbdd23ac39ca9daee51fc510d9040c616cef .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ADC1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ADC1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ADC1.c  -o ${OBJECTDIR}/_ext/1472/ADC1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ADC1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/CN.o: ../CN.c  .generated_files/flags/default/de3fb41756e7df0d3e60db5cf6c72d9f33550956 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CN.c  -o ${OBJECTDIR}/_ext/1472/CN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/CN.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/GPIO.o: ../GPIO.c  .generated_files/flags/default/c6e4f67f8a76aa82e6694b9cc7d74014e03d507a .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GPIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GPIO.c  -o ${OBJECTDIR}/_ext/1472/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/GPIO.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/LCD.o: ../LCD.c  .generated_files/flags/default/4ca7e12a05bf4a74f15678b35e40b2c094ce244b .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../LCD.c  -o ${OBJECTDIR}/_ext/1472/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/LCD.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/OCPWM.o: ../OCPWM.c  .generated_files/flags/default/6c87f09291432e5b5430758629a5fe3273f6f59e .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/OCPWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/OCPWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../OCPWM.c  -o ${OBJECTDIR}/_ext/1472/OCPWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/OCPWM.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/UART2_RS232.o: ../UART2_RS232.c  .generated_files/flags/default/e4a1b1977b18518fb9595e003cd34c4326586bb8 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UART2_RS232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UART2_RS232.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../UART2_RS232.c  -o ${OBJECTDIR}/_ext/1472/UART2_RS232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/UART2_RS232.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o: ../main_P6_OCPWM_v1.c  .generated_files/flags/default/8af105a315cfd75c121de5d4ef364ba6ea6b85f8 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main_P6_OCPWM_v1.c  -o ${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/main_P6_OCPWM_v1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/memoria.o: ../memoria.c  .generated_files/flags/default/e6960f3081ccfccf7c93e90a2d02bc662c3bfac9 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../memoria.c  -o ${OBJECTDIR}/_ext/1472/memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/memoria.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/oscilator.o: ../oscilator.c  .generated_files/flags/default/3986eae63ffc4d137f09e5f0011b32abc4b3a2ca .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../oscilator.c  -o ${OBJECTDIR}/_ext/1472/oscilator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/oscilator.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/timers.o: ../timers.c  .generated_files/flags/default/9e8fd8b57b21ae3d6e2033f66c8d40d51aaecfc2 .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../timers.c  -o ${OBJECTDIR}/_ext/1472/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/timers.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1472/utilidades.o: ../utilidades.c  .generated_files/flags/default/357c9a1f923a175571639883ef5df16a4c6bd9fb .generated_files/flags/default/7dab310884e5de58b737751714b62c5515706f0f
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/utilidades.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/utilidades.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../utilidades.c  -o ${OBJECTDIR}/_ext/1472/utilidades.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/utilidades.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -O0 -I"../" -msmart-io=1 -Wall -msfr-warn=off   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/P6_OCPWM_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/P6_OCPWM_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/P6_OCPWM_v1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/P6_OCPWM_v1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"../../../../../../../../Program Files (x86)/Microchip/xc16/v1.36/support/PIC24H/h" -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/P6_OCPWM_v1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
