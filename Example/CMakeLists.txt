cmake_minimum_required(VERSION 3.8)

add_executable(Example 
Main.cpp
GameGraphics.h
GameGraphics.cpp 
GameAudio.h
GameAudio.cpp
GameCode.cpp
GameCode.h
Assets.h
)

target_include_directories(Example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Wireframe)
target_link_libraries(Example PRIVATE Wireframe)
