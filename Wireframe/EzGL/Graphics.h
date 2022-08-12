#ifndef GRAPHICS_HEADER
#define GRAPHICS_HEADER

#include <iostream>
#include <any>
#include <array>

#ifdef GL_API_GLAD_OPENGL_3
#include <glad/glad.h>
#endif
#ifdef WINDOW_API_GLFW
#include <GLFW/glfw3.h>
#endif

#include"Camera.h"

#define arrsize(arr) sizeof(arr) / sizeof(arr[0])

class Graphics {
public:
	#ifdef WINDOW_API_GLFW
	GLFWwindow* window;
	#endif
	const char* title;
	int width, height;
	#ifdef WINDOW_API_GLFW
	#endif
	Camera camera;
	std::any data;

	Graphics();
	#ifdef WINDOW_API_GLFW
	Graphics(const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data);
	#endif
	~Graphics();

	#ifdef WINDOW_API_GLFW
	void Init(const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data);
	static void StaticInit(Graphics* graphics, const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data, GLFWwindow** windowVar, const char** titleVar, int* widthVar, int* heightVar, std::any* dataVar);
	#endif
	static bool WindowLibInit();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Draw(GLenum mode, GLsizei size, GLenum type);
	static void DrawInstanced(GLenum mode, GLsizei size, GLenum type, GLsizei numInstances);
	#endif
	static void PollEvents();
	#ifdef WINDOW_API_GLFW
	void OnResizeEvent(GLFWwindowsizefun onResize);
	static void OnResizeEvent(GLFWwindow* window, GLFWwindowsizefun onResize);
	#endif
	void SwapBuffers();
	#ifdef WINDOW_API_GLFW
	static void SwapBuffers(GLFWwindow* window);
	#endif
	#ifdef GL_API_GLAD_OPENGL_3
	static void Enable(GLenum toEnable);
	static void Disable(GLenum toDisable);
	static void ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	static void Clear(GLbitfield toClear);
	static void Blend(GLenum toBlend, GLenum howBlend);
	#endif
	static void WindowHint(int toHint, int value);
	#ifdef WINDOW_API_GLFW
	void CreateWindow(const char* title, int width, int height, GLFWmonitor* fullDisplay);
	static void CreateWindow(const char* title, int width, int height, GLFWmonitor* fullDisplay, GLFWwindow** windowVar, const char** titleVar, int* widthVar, int* heightVar);
	#endif
	void MakeContextCurrent();
	#ifdef WINDOW_API_GLFW
	static void MakeContextCurrent(GLFWwindow* window);
	#endif
	static void LoadGL();
	#ifdef GL_API_GLAD_OPENGL_3
	static void Viewport(GLsizei topLeftX, GLsizei topLeftY, GLsizei bottomRightX, GLsizei bottomRightY);
	#endif
	void DestroyWindow();
	#ifdef WINDOW_API_GLFW
	static void DestroyWindow(GLFWwindow* window);
	#endif
	void SetTitle(const char* title);
	#ifdef WINDOW_API_GLFW
	static void SetTitle(GLFWwindow* window, const char* title);
	#endif
	int WindowShouldClose();
	#ifdef WINDOW_API_GLFW
	static int WindowShouldClose(GLFWwindow* window);
	#endif
	static void Terminate();
	template <typename type>
	type GetData();
	template <typename type>
	static type GetData(std::any data);
	template <typename type>
	void SetWindowPointer(type* ptr);
	#ifdef WINDOW_API_GLFW
	template <typename type>
	static void SetWindowPointer(GLFWwindow* window, type* ptr);
	#endif
	template <typename type>
	type* GetWindowPointer();
	#ifdef WINDOW_API_GLFW
	template <typename type>
	static type* GetWindowPointer(GLFWwindow* window);
	#endif
	void SetWindowSize(int width, int height);
	#ifdef WINDOW_API_GLFW
	static void SetWindowSize(GLFWwindow* window, int width, int height);
	#endif
	std::array<float, 2> GetContentScale(float xScale, float yScale);
	#ifdef WINDOW_API_GLFW
	static std::array<float, 2> GetContentScale(GLFWwindow* window, float xScale, float yScale);
	#endif
	void SetWindowSizeLimits(int minWidth, int minHeight, int maxWidth, int maxHeight);
	#ifdef WINDOW_API_GLFW
	static void SetWindowSizeLimits(GLFWwindow* window, int minWidth, int minHeight, int maxWidth, int maxHeight);
	#endif
	void SetWindowPos(int xPos, int yPos);
	#ifdef WINDOW_API_GLFW
	static void SetWindowPos(GLFWwindow* window, int xPos, int yPos);
	#endif
	void OnWindowMoveEvent(GLFWwindowposfun onMove);
	#ifdef WINDOW_API_GLFW
	static void OnWindowMoveEvent(GLFWwindow* window, GLFWwindowposfun onMove);
	#endif
	void SetWindowIcon(int size, GLFWimage images[]);
	#ifdef WINDOW_API_GLFW
	static void SetWindowIcon(GLFWwindow* window, int size, GLFWimage images[]);
	#endif
	GLFWmonitor* GetWindowMonitor();
	#ifdef WINDOW_API_GLFW
	static GLFWmonitor* GetWindowMonitor(GLFWwindow* windoww);
	#endif
	void SetWindowMonitor(GLFWmonitor* monitor, int xPos, int yPos, int width, int height, int refreshRate);
	#ifdef WINDOW_API_GLFW
	static void GetWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, int xPos, int yPos, int width, int height, int refreshRate);
	#endif
	void IconifyWindow();
	#ifdef WINDOW_API_GLFW
	static void IconifyWindow(GLFWwindow* window);
	#endif
	void RestoreWindow();
	#ifdef WINDOW_API_GLFW
	static void RestoreWindow(GLFWwindow* window);
	#endif
	void OnSetWindowIconificationEvent(GLFWwindowiconifyfun onIconification);
	#ifdef WINDOW_API_GLFW
	static void OnSetWindowIconificationEvent(GLFWwindow* window, GLFWwindowiconifyfun onIconification);
	#endif
	void MaximizeWindow();
	#ifdef WINDOW_API_GLFW
	static void MaximizeWindow(GLFWwindow* window);
	#endif
	void OnSetWindowwMaxificationEvent(GLFWwindowmaximizefun onMaxification);
	#ifdef WINDOW_API_GLFW
	static void OnSetWindowMaxificationEvent(GLFWwindow* window, GLFWwindowmaximizefun onMaxification);
	#endif
	void HideWindow();
	#ifdef WINDOW_API_GLFW
	static void HideWindow(GLFWwindow* window);
	#endif
	void ShowWindow();
	#ifdef WINDOW_API_GLFW
	static void ShowWindow(GLFWwindow* window);
	#endif
	int GetWindowAttrib(int attrib);
	#ifdef WINDOW_API_GLFW
	static int GetWindowAttrib(GLFWwindow* window, int attrib);
	#endif
	void FocusWindow();
	#ifdef WINDOW_API_GLFW
	static void FocusWindow(GLFWwindow* window);
	#endif
	void OnSetWindowFocusEvent(GLFWwindowfocusfun onFocus);
	#ifdef WINDOW_API_GLFW
	static void OnSetWindowFocusEvent(GLFWwindow* window, GLFWwindowfocusfun onFocus);
	#endif
	void SetWindowAttrib(int attrib, int value);
	#ifdef WINDOW_API_GLFW
	static void SetWindowAttrib(GLFWwindow* window, int attrib, int value);
	#endif
	void RequestWindowAttention();
	#ifdef WINDOW_API_GLFW
	static void RequestWindowAttention(GLFWwindow* window);
	#endif
	static void SwapInterval(int interval);
	void SetWindowOpacity(float opacity);
	#ifdef WINDOW_API_GLFW
	static void SetWindowOpacity(GLFWwindow* window, float opacity);
	#endif
	void OnWindowCloseEvent(GLFWwindowclosefun onClose);
	#ifdef WINDOW_API_GLFW
	static void OnWindowCloseEvent(GLFWwindow* window, GLFWwindowclosefun onClose);
	#endif
	void OnSetWindowRefreshEvent(GLFWwindowrefreshfun onRefresh);
	#ifdef WINDOW_API_GLFW
	void OnSetWindowRefreshEvent(GLFWwindow* window, GLFWwindowrefreshfun onRefresh);
	#endif
	static GLFWmonitor** GetMonitors(int* count);
	static GLFWmonitor* GetPrimaryMonitor();
	static const GLFWvidmode* GetVideoMode(GLFWmonitor* monitor);
	static const GLFWvidmode* GetVideoModes(GLFWmonitor* monitor, int* count);
};

#include "Graphics.tpp"

#endif