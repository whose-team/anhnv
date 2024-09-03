cmake_minimum_required(VERSION 3.16)

project(TryTest_B3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TryTest_B3 main.cpp
    input_b3_test.txt)

include(GNUInstallDirs)
install(TARGETS TryTest_B3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
