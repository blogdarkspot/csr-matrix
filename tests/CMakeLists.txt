cmake_minimum_required(VERSION 3.12)

add_executable(test)
target_sources(test PRIVATE main.c)
target_link_libraries(test csr)
