cmake_minimum_required(VERSION 3.8)
project(cproj)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp src/StudentAVTF.cpp include/StudentAVTF.h src/StudentFPMI.cpp include/StudentFPMI.h src/Student.cpp include/Student.h src/ListS.cpp include/ListS.h include/MyList.h)
add_executable(cproj ${SOURCE_FILES})