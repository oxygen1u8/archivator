cmake_minimum_required(VERSION 3.15)

project(archivator
    VERSION 1
    LANGUAGES C
)

set(CMAKE_C_COMPILER gcc)

add_executable(archivator
    information.c
    math_func.c
    arch_logic.c
    file_in_out.c
    main.c
)

target_link_libraries(archivator m)
