cmake_minimum_required (VERSION 3.8)

add_subdirectory("EzGL")
add_subdirectory("EzAL")

add_library(Wireframe Wireframe.h Wireframe.cpp)

target_include_directories(Wireframe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/EzGL)
target_include_directories(Wireframe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/EzAL)

target_link_libraries(Wireframe PUBLIC EzGL)
target_link_libraries(Wireframe PUBLIC EzAL)
