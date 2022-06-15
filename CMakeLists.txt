cmake_minimum_required(VERSION 3.21)
project(Y_X__Oscillograph_2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Debug)

add_executable(Y_X__Oscillograph_2_0
        Debug/Oscillograph.pch
        adcconf.cpp
        adcconf.h
        B181.h
        cmnconf.cpp
        cmnconf.h
        dacconf.cpp
        dacconf.h
        DevDef.h
        Device.cpp
        Device.h
        DevTypes.h
        exporting.cpp
        exporting.h
        FStartD.cpp
        FStartD.h
        generator.cpp
        generator.h
        level.cpp
        level.h
        numexport.cpp
        numexport.h
        Oscillograph.cpp
        Oscilloscope.cpp
        Oscilloscope.h
        progress.cpp
        progress.h
        UniLPTX.h)
