# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)
# Create the project
project(p7 VERSION 0.1)
# Set the C_STANDAR compiler version
# set(CMAKE_C_STANDARD 11)
# set(CMAKE_C_STANDARD_REQUIRED True)
add_library(compiler_flags INTERFACE)
# Specify the c standar
target_compile_features(compiler_flags INTERFACE c_std_11)
# Create a list with extra libs
list(APPEND EXTRA_LIBS -lpthread)
# Configure my src directory by creating a variable
set(C_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(C_HDR_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include)
# Add the executable to the project
add_executable(${PROJECT_NAME} ${C_SRC_FILES}/${PROJECT_NAME}.c)

target_link_libraries(${PROJECT_NAME} PUBLIC compiler_flags ${EXTRA_LIBS})
# Add the target include directories to include the SRC and INCLUDE paths
target_include_directories(${PROJECT_NAME} PRIVATE ${C_HDR_FILES})