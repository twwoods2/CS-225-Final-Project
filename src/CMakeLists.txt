cmake_minimum_required(VERSION 2.8)

if(POLICY CMP0015)
    cmake_policy(SET CMP0015 NEW)
endif()

# if(POLICY CMP0079)
#     cmake_policy(SET CMP0079 NEW)
# endif()

########################################################################
add_compile_options(-std=c++11)

set(UTILS util.cpp util.h)
add_library(Utils ${UTILS})

target_include_directories(src PUBLIC "../src/include")

link_directories("../src")
target_link_libraries(src)

add_executable(main /src/main.cpp)
target_link_libraries(main Utils)

# link_directories("../parsing" "../bfs" "../a_star")
# target_link_libraries(main Utils ParsingLib BFSLib AStarLib) # <-- Automatically sets the correct include directories!!