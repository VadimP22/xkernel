cmake_minimum_required(VERSION 3.25.2)
project(qkernel CXX ASM)
include("${CMAKE_SOURCE_DIR}/utils.cmake")


# Setting up target
file(GLOB_RECURSE KERNEL_SOURCES "${CMAKE_SOURCE_DIR}/source/*.cpp")

add_executable(kernel ${KERNEL_SOURCES} "${CMAKE_SOURCE_DIR}/multiboot.S")
target_include_directories(kernel PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_ffreestand(kernel)
target_cxx_disable_runtime(kernel)

target_link_options(kernel PUBLIC "-m32")

target_compile_options(kernel PUBLIC "-m32")
target_compile_options(kernel PUBLIC "-O0")

target_linker_script(kernel "${CMAKE_SOURCE_DIR}/link.ld")

# End of setting up target

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)