cmake_minimum_required(VERSION 3.15)

project(archivator
    VERSION 1
    LANGUAGES C
)

add_executable(archivator
    main.c
    arch_logic.c
    file_in_out.c
    information.c
    math_func.c
)
