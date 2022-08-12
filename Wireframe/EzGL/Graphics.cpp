#include "Graphics.h"

#ifdef GL_API_GLAD_OPENGL_3

#ifdef WINDOW_API_GLFW

Graphics::Graphics() {}

Graphics::Graphics(const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data) {
	Init(title, width, height, fullDisplay, GraphicsCode, data);
}

Graphics::~Graphics() {
	DestroyWindow();
}

void Graphics::Init(const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data) {
	StaticInit(this, title, width, height, fullDisplay, GraphicsCode, data, &this->window, &this->title, &this->width, &this->height, &this->data);
}

void Graphics::StaticInit(Graphics* graphics, const char* title, int width, int height, GLFWmonitor* fullDisplay, void(*GraphicsCode)(Graphics*), std::any data, GLFWwindow** windowVar, const char** titleVar, int* widthVar, int* heightVar, std::any* dataVar) {
	CreateWindow(title, width, height, fullDisplay, windowVar, titleVar, widthVar, heightVar);
	MakeContextCurrent(*windowVar);
	LoadGL();
	Viewport(0, 0, width, height);
	SetWindowPointer<Graphics>(*windowVar, graphics);
	*dataVar = data;
	GraphicsCode(graphics);
}

bool Graphics::WindowLibInit() {
	return glfwInit();
}

void Graphics::Draw(GLenum mode,GLsizei size, GLenum type) {
	glDrawElements(mode, size, type, 0);
}

void Graphics::DrawInstanced(GLenum mode, GLsizei size, GLenum type, GLsizei numInstances) {
	glDrawElementsInstanced(mode, size, type, 0, numInstances);
}

void Graphics::PollEvents() {
	glfwPollEvents();
}

void Graphics::OnResizeEvent(GLFWwindowsizefun onResize) {
	OnResizeEvent(window, onResize);
}

void Graphics::OnResizeEvent(GLFWwindow* window, GLFWwindowsizefun onResize) {
	glfwSetWindowSizeCallback(window, onResize);
}

void Graphics::SwapBuffers() {
	SwapBuffers(window);
}

void Graphics::SwapBuffers(GLFWwindow* window) {
	glfwSwapBuffers(window);
}

void Graphics::Enable(GLenum toEnable) {
	glEnable(toEnable);
}

void Graphics::Disable(GLenum toDisable) {
	glDisable(toDisable);
}

void Graphics::ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	glClearColor(r, g, b, a);
}

void Graphics::Clear(GLbitfield toClear) {
	glClear(toClear);
}

void Graphics::Blend(GLenum toBlend, GLenum howBlend) {
	glBlendFunc(toBlend, howBlend);
}

void Graphics::WindowHint(int toHint, int value) {
	glfwWindowHint(toHint, value);
}

void Graphics::CreateWindow(const char* title, int width, int height, GLFWmonitor* fullDisplay) {
	CreateWindow(title, width, height, fullDisplay, &this->window, &this->title, &this->width, &this->height);
}

void Graphics::CreateWindow(const char* title, int width, int height, GLFWmonitor* fullDisplay, GLFWwindow** windowVar, const char** titleVar, int* widthVar, int* heightVar) {
	*titleVar = title;
	*widthVar = width;
	*heightVar = height;
	*windowVar = glfwCreateWindow(width, height, title, fullDisplay, nullptr);
	if (windowVar == nullptr) {
		std::cout << "Failed to create window\n";
		return;
	}
}

void Graphics::MakeContextCurrent() {
	MakeContextCurrent(window);
}

void Graphics::MakeContextCurrent(GLFWwindow* window) {
	glfwMakeContextCurrent(window);
}

void Graphics::LoadGL() {
	gladLoadGL();
}

void Graphics::Viewport(GLsizei topLeftX, GLsizei topLeftY, GLsizei bottomRightX, GLsizei bottomRightY) {
	glViewport(topLeftX, topLeftY, bottomRightX, bottomRightY);
}

void Graphics::DestroyWindow() {
	DestroyWindow(window);
}

void Graphics::DestroyWindow(GLFWwindow* window) {
	glfwDestroyWindow(window);
}

void Graphics::SetTitle(const char* title) {
	SetTitle(window, title);
}

void Graphics::SetTitle(GLFWwindow* window, const char* title) {
	glfwSetWindowTitle(window, title);
}

int Graphics::WindowShouldClose() {
	return WindowShouldClose(window);
}

int Graphics::WindowShouldClose(GLFWwindow* window) {
	return glfwWindowShouldClose(window);
}

void Graphics::Terminate() {
	glfwTerminate();
}

void Graphics::SetWindowSize(int width, int height) {
	SetWindowSize(window, width, height);
}

void Graphics::SetWindowSize(GLFWwindow* window, int width, int height) {
	glfwSetWindowSize(window, width, height);
}

std::array<float, 2> Graphics::GetContentScale(float xScale, float yScale) {
	return GetContentScale(window, xScale, yScale);
}

std::array<float, 2> Graphics::GetContentScale(GLFWwindow* window, float xScale, float yScale) {
	glfwGetWindowContentScale(window, &xScale, &yScale);
	return { xScale, yScale };
}

void Graphics::SetWindowSizeLimits(int minWidth, int minHeight, int maxWidth, int maxHeight) {
	SetWindowSizeLimits(window, minWidth, minHeight, maxWidth, maxHeight);
}

void Graphics::SetWindowSizeLimits(GLFWwindow* window, int minWidth, int minHeight, int maxWidth, int maxHeight) {
	glfwSetWindowSizeLimits(window, minWidth, minHeight, maxWidth, maxHeight);
}

void Graphics::SetWindowPos(int xPos, int yPos) {
	SetWindowPos(window, xPos, yPos);
}

void Graphics::SetWindowPos(GLFWwindow* window, int xPos, int yPos) {
	glfwSetWindowPos(window, xPos, yPos);
}

void Graphics::OnWindowMoveEvent(GLFWwindowposfun onMove) {
	OnWindowMoveEvent(window, onMove);
}

void Graphics::OnWindowMoveEvent(GLFWwindow* window, GLFWwindowposfun onMove) {
	glfwSetWindowPosCallback(window, onMove);
}

void Graphics::SetWindowIcon(int size, GLFWimage images[]) {
	SetWindowIcon(window, size, images);
}

void Graphics::SetWindowIcon(GLFWwindow* window, int size, GLFWimage images[]) {
	glfwSetWindowIcon(window, size, images);
}

GLFWmonitor* Graphics::GetWindowMonitor() {
	return GetWindowMonitor(window);
}

GLFWmonitor* Graphics::GetWindowMonitor(GLFWwindow* window) {
	return glfwGetWindowMonitor(window);
}

void Graphics::SetWindowMonitor(GLFWmonitor* monitor, int xPos, int yPos, int width, int height, int refreshRate) {
	GetWindowMonitor(window, monitor, xPos, yPos, width, height, refreshRate);
}

void Graphics::GetWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, int xPos, int yPos, int width, int height, int refreshRate) {
	glfwSetWindowMonitor(window, monitor, xPos, yPos, width, height, refreshRate);
}

void Graphics::IconifyWindow() {
	IconifyWindow(window);
}

void Graphics::IconifyWindow(GLFWwindow* window) {
	glfwIconifyWindow(window);
}

void Graphics::RestoreWindow() {
	RestoreWindow(window);
}

void Graphics::RestoreWindow(GLFWwindow* window) {
	glfwRestoreWindow(window);
}

void Graphics::OnSetWindowIconificationEvent(GLFWwindowiconifyfun onIconification) {
	OnSetWindowIconificationEvent(window, onIconification);
}

void Graphics::OnSetWindowIconificationEvent(GLFWwindow* window, GLFWwindowiconifyfun onIconification) {
	glfwSetWindowIconifyCallback(window, onIconification);
}

void Graphics::MaximizeWindow() {
	MaximizeWindow(window);
}

void Graphics::MaximizeWindow(GLFWwindow* window) {
	glfwMaximizeWindow(window);
}

void Graphics::OnSetWindowwMaxificationEvent(GLFWwindowmaximizefun onMaxification) {
	OnSetWindowMaxificationEvent(window, onMaxification);
}

void Graphics::OnSetWindowMaxificationEvent(GLFWwindow* window, GLFWwindowmaximizefun onMaxification) {
	glfwSetWindowMaximizeCallback(window, onMaxification);
}

void Graphics::HideWindow() {
	HideWindow(window);
}

void Graphics::HideWindow(GLFWwindow* window) {
	glfwHideWindow(window);
}

void Graphics::ShowWindow() {
	ShowWindow(window);
}

void Graphics::ShowWindow(GLFWwindow* window) {
	glfwShowWindow(window);
}

int Graphics::GetWindowAttrib(int attrib) {
	return GetWindowAttrib(window, attrib);
}

int Graphics::GetWindowAttrib(GLFWwindow* window, int attrib) {
	return glfwGetWindowAttrib(window, attrib);
}

void Graphics::FocusWindow() {
	FocusWindow(window);
}

void Graphics::FocusWindow(GLFWwindow* window) {
	glfwFocusWindow(window);
}

void Graphics::OnSetWindowFocusEvent(GLFWwindowfocusfun onFocus) {
	OnSetWindowFocusEvent(window, onFocus);
}

void Graphics::OnSetWindowFocusEvent(GLFWwindow* window, GLFWwindowfocusfun onFocus) {
	glfwSetWindowFocusCallback(window, onFocus);
}

void Graphics::SetWindowAttrib(int attrib, int value) {
	SetWindowAttrib(window, attrib, value);
}

void Graphics::SetWindowAttrib(GLFWwindow* window, int attrib, int value) {
	glfwSetWindowAttrib(window, attrib, value);
}

void Graphics::RequestWindowAttention() {
	RequestWindowAttention(window);
}

void Graphics::RequestWindowAttention(GLFWwindow* window) {
	glfwRequestWindowAttention(window);
}

void Graphics::SwapInterval(int interval) {
	glfwSwapInterval(interval);
}

void Graphics::SetWindowOpacity(float opacity) {
	SetWindowOpacity(window, opacity);
}

void Graphics::SetWindowOpacity(GLFWwindow* window, float opacity) {
	glfwSetWindowOpacity(window, 0.5f);
}

void Graphics::OnWindowCloseEvent(GLFWwindowclosefun onClose) {
	OnWindowCloseEvent(window, onClose);
}

void Graphics::OnWindowCloseEvent(GLFWwindow* window, GLFWwindowclosefun onClose) {
	glfwSetWindowCloseCallback(window, onClose);
}

void Graphics::OnSetWindowRefreshEvent(GLFWwindowrefreshfun onRefresh) {
	OnSetWindowRefreshEvent(window, onRefresh);
}

void Graphics::OnSetWindowRefreshEvent(GLFWwindow* window, GLFWwindowrefreshfun onRefresh) {
	glfwSetWindowRefreshCallback(window, onRefresh);
}

GLFWmonitor** Graphics::GetMonitors(int* count) {
	return glfwGetMonitors(count);
}

GLFWmonitor* Graphics::GetPrimaryMonitor() {
	return glfwGetPrimaryMonitor();
}

const GLFWvidmode* Graphics::GetVideoMode(GLFWmonitor* monitor) {
	return glfwGetVideoMode(monitor);
}

const GLFWvidmode* Graphics::GetVideoModes(GLFWmonitor* monitor, int* count) {
	return glfwGetVideoModes(monitor, count);
}

#endif

#endif
