cmake_minimum_required(VERSION 3.29)
project(Eksempler)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "*.cpp" "../Oppgaver/*.cpp" "../Obliger/*.cpp" "../Eksamen/*.cpp")
include_directories(../Oppgaver)
include_directories(../Eksamen)
include_directories(../Obliger)



foreach(SOURCE ${SOURCES})
    get_filename_component(EXE_NAME ${SOURCE} NAME_WE)
    add_executable(${EXE_NAME} ${SOURCE})
endforeach()
