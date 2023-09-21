# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)


project ("ByteConvert")

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Compiling with C++ standard: ${CMAKE_CXX_STANDARD}")



option(MAIN_TEST "Test" ON)
option(UNIT_TEST "Test" ON)

## Включите подпроекты.
#
add_subdirectory ("ByteConvert")

add_subdirectory("Test")

