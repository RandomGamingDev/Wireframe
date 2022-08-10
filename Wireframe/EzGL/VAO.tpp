#ifndef VAO_TEMPLATE
#define VAO_TEMPLATE

#ifdef GL_API_GLAD_OPENGL_3

template <typename type>
void VAO::LinkAttrib(GLuint VBO, GLuint layout, GLuint numComponents, GLenum varType, GLsizeiptr stride, GLsizeiptr offset) {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(layout, numComponents, varType , GL_FALSE, stride * sizeof(type), (void*)(offset * sizeof(type)));
	glEnableVertexAttribArray(layout);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

#endif

#endif
