cmake_minimum_required(VERSION 3.25)
project(RSA C)

set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/lib/gmp/include)

add_executable(RSA
        rsa.c
        test.c)

target_link_libraries(RSA ${PROJECT_SOURCE_DIR}/lib/gmp/lib/libgmp.a)

