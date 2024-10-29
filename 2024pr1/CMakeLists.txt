cmake_minimum_required( VERSION 3.10)
project(calculator)
# 指定编译为c标准。而非c++
set(CMAKE_C_STANDARD 99)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/inc)

#设置输出文件位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 将源文件汇总
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SRC_LIST})