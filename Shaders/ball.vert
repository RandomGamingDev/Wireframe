#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

out vec4 color;

uniform mat4 camMatrix;
layout (std140) uniform ball {
	vec2 coords;
	vec2 velocity;
};

void main() {
	gl_Position = camMatrix * vec4(aPos + vec3(coords, 0.0f), 1.0f);
	color = aColor;
}