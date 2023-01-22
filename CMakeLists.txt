# EAAPMST3923A2 Arduino
# https://github.com/skerr92/EAAPMST3923A2-Arduino
# MIT License

cmake_minimum_required(VERSION 3.5)

idf_component_register(SRCS "EAAPMST3923A2.cpp" 
                       INCLUDE_DIRS "."
                       REQUIRES arduino)

project(EAAPMST3923A2)
