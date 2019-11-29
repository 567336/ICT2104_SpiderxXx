################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Module/pca9685/%.obj: ../Module/pca9685/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/ICT2104_SpiderxXx/robot_tirtos/App" --include_path="D:/ICT2104_SpiderxXx/robot_tirtos/Basic/Delay" --include_path="D:/ICT2104_SpiderxXx/robot_tirtos/Basic/SystemInit" --include_path="D:/ICT2104_SpiderxXx/robot_tirtos/Module/pca9685" --include_path="D:/ICT2104_SpiderxXx/robot_tirtos/Module/servo" --include_path="D:/ICT2104_SpiderxXx/robot_tirtos/Hardware/myiic" --include_path="D:/ICT2104_SpiderxXx/robot_tirtos" --include_path="D:/ICT2104_SpiderxXx/robot_tirtos/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/ti/posix/ccs" --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --advice:power=none --define=__MSP432P401R__ -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="Module/pca9685/$(basename $(<F)).d_raw" --include_path="D:/ICT2104_SpiderxXx/robot_tirtos/Debug/syscfg" --obj_directory="Module/pca9685" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


