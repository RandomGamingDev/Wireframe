#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

out vec4 color;

layout (std140) uniform paddles {
	vec2 paddleYs;
};
uniform mat4 camMatrix;

void main() {
	// for first param of vec3 use instance ID
	gl_Position = camMatrix * vec4(aPos + vec3(-0.7f + 1.4f * gl_InstanceID, paddleYs[gl_InstanceID], 0.0f), 1.0f);
	//gl_Position = camMatrix * vec4(aPos, 1.0f);
	color = aColor;
}