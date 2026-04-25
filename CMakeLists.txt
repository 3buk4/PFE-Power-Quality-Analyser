cmake_minimum_required(VERSION 4.2)
project(PFE_Power_Quality_Analyser)

set(CMAKE_CXX_STANDARD 99)

add_executable(PFE_Power_Quality_Analyser main.c
        Waveform.c
        io.h
        io.c
        Waveform.h)

target_link_libraries(PFE_Power_Quality_Analyser m)
