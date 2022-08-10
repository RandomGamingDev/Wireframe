#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#ifdef GL_API_GLAD_OPENGL_3
#include<glad/glad.h>
#endif

#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>

class Camera {
public:
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	const glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

	int width, height;

	void Resize(int width, int height, glm::vec3 position);
	void Resize(int width, int height);

	void Matrix(float FOVdeg, float nearPlane, float farPlane, GLuint shader, const char* uniform);
};
#endif