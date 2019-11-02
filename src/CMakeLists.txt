cmake_minimum_required(VERSION 3.12)

add_library(csr)
target_sources(csr PRIVATE csr_matrix.c)
target_include_directories(csr INTERFACE "${PROJECT_SOURCE_DIR}/src")
