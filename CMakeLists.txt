cmake_minimum_required(VERSION 3.15)
project(DataBases C)

set(CMAKE_C_STANDARD 11)

add_executable(DataBases main.c dbReading.c dbReading.h dbStructures.h filesHandler.c filesHandler.h dbDeletion.c dbDeletion.h)