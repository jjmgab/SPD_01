cmake_minimum_required (VERSION 2.6)
project (program)

#Bring the headers into the project
include_directories(include)
 
#The file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")
 
add_executable(program ${SOURCES})

