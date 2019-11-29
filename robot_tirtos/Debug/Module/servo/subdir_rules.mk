################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Module/servo/%.obj: ../Module/servo/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Justin/workspace_v9/uartecho_MSP_EXP432P401R_tirtos_ccs/App" --include_path="C:/Users/Justin/workspace_v9/uartecho_MSP_EXP432P401R_tirtos_ccs/Basic/Delay" --include_path="C:/Users/Justin/workspace_v9/uartecho_MSP_EXP432P401R_tirtos_ccs/Basic/SystemInit" --include_path="C:/Users/Justin/workspace_v9/uartecho_MSP_EXP432P401R_tirtos_ccs/Module/pca9685" --include_path="C:/Users/Justin/workspace_v9/uartecho_MSP_EXP432P401R_tirtos_ccs/Module/servo" --include_path="C:/Users/Justin/workspace_v9/uartecho_MSP_EXP432P401R_tirtos_ccs/Hardware/myiic" --include_path="C:/Users/Justin/workspace_v9/uartecho_MSP_EXP432P401R_tirtos_ccs" --include_path="C:/Users/Justin/workspace_v9/uartecho_MSP_EXP432P401R_tirtos_ccs/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/ti/posix/ccs" --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --advice:power=none --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="Module/servo/$(basename $(<F)).d_raw" --include_path="C:/Users/Justin/workspace_v9/uartecho_MSP_EXP432P401R_tirtos_ccs/Debug/syscfg" --obj_directory="Module/servo" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


