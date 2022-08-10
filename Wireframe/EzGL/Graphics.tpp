#ifndef GRAPHICS_TEMPLATE
#define GRAPHICS_TEMPLATE

#ifdef GL_API_GLAD_OPENGL_3

#ifdef WINDOW_API_GLFW

template <typename type>
type Graphics::GetData() {
	return GetData<type>(data);
}

template <typename type>
type Graphics::GetData(std::any data) {
	return std::any_cast<type>(data);
}

template <typename type>
void Graphics::SetWindowPointer(type* ptr) {
	SetWindowPointer<type>(window, ptr);
}

template <typename type>
void Graphics::SetWindowPointer(GLFWwindow* window, type* ptr) {
	glfwSetWindowUserPointer(window, ptr);
}

template <typename type>
type* Graphics::GetWindowPointer() {
	return GetWindowPointer<type*>(window);
}

template <typename type>
type* Graphics::GetWindowPointer(GLFWwindow* window) {
	return static_cast<type*>(glfwGetWindowUserPointer(window));
}

#endif

#endif

#endif
