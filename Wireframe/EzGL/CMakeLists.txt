cmake_minimum_required (VERSION 3.8)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_path(STB_INCLUDE_DIRS stb.h)
find_package(glm CONFIG REQUIRED)

add_library(EzGL 
	Camera.cpp
	Camera.h
	EBO.h
	EBO.tpp
	FBO.cpp
	FBO.h
	Graphics.cpp
	Graphics.h
	Graphics.tpp
	RBO.cpp
	RBO.h
	Shader.cpp
	Shader.h
	Texture2D.cpp
	Texture2D.h
	Texture2D.tpp
	UBO.cpp
	UBO.h
	UBO.tpp
	VAO.cpp
	VAO.h
	VAO.tpp
	VBO.h
	VBO.tpp
	EzGL.h
	GLlibs.h
	EzGLlibs.h
	Texture2DMultisample.cpp
	Texture2DMultisample.h
	RBOMultisample.cpp
	RBOMultisample.h
	Texture1D.cpp
	Texture1D.h
	Texture1D.tpp
	Texture3D.cpp
	Texture3D.h
	Texture3D.tpp
)

target_compile_definitions(EzGL PUBLIC GL_API_GLAD_OPENGL_3)
target_compile_definitions(EzGL PUBLIC WINDOW_API_GLFW)

target_link_libraries(EzGL PUBLIC glad::glad)
target_link_libraries(EzGL PUBLIC glfw)
target_include_directories(EzGL PUBLIC ${STB_INCLUDE_DIRS})
target_link_libraries(EzGL PUBLIC glm::glm)
