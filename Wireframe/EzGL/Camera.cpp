#include"Camera.h"

void Camera::Resize(int width, int height, glm::vec3 position) {
	Camera::width = width;
	Camera::height = height;
	Camera::Position = position;
}
void Camera::Resize(int width, int height) {
	Camera::width = width;
	Camera::height = height;
}

void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, GLuint shader, const char* uniform) {
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	#ifdef GL_API_GLAD_OPENGL_3
	// Make it so that it returns this to be used in a UBO instead
	glUniformMatrix4fv(glGetUniformLocation(shader, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
	#endif
}