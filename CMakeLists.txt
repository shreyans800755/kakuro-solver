cmake_minimum_required(VERSION 2.8)

## Use the variable PROJECT_NAME for changing the target name
set( PROJECT_NAME "KakuroSolver" )

## Set our project name
project(${PROJECT_NAME})

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "src/*.cpp")

add_compile_options(-std=c++1z)

## Define the executable
add_executable(${PROJECT_NAME} ${SRCS})
