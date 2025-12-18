cmake_minimum_required(VERSION 4.0)

project(raven LANGUAGES C)

if (PROJECT_IS_TOP_LEVEL)
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(raven INTERFACE)
