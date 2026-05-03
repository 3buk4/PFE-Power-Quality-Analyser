cmake_minimum_required(VERSION 3.1)
project(PFE_Power_Quality_Analyser)

set(CMAKE_C_STANDARD 99)

add_executable(PFE_Power_Quality_Analyser main.c
        Waveform.c
        io.h
        io.c
        Waveform.h)

target_link_libraries(PFE_Power_Quality_Analyser m)
