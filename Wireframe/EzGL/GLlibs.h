#ifndef GLLIBS_HEADER
#define GLLIBS_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif

#ifdef WINDOW_API_GLFW
#include <GLFW/glfw3.h>
typedef GLFWwindow Window;
#endif

#endif