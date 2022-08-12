#ifndef TEXTURE2D_TEMPLATE
#define TEXTURE2D_TEMPLATE

#ifdef GL_API_GLAD_OPENGL_3

template <typename type>
Texture2D::Texture2D(type* pixels, GLsizei width, GLsizei height, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType) {
	Init<type>(pixels, width, height, slot, internalFormat, format, pixelType);
}

template <typename type>
void Texture2D::Init(type* pixels, GLint width, GLsizei height, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType) {
	Init<type>(&ID, pixels, width, height, slot, internalFormat, format, pixelType, &this->width, &this->height);
}

template <typename type>
void Texture2D::Init(GLuint* ID, type* pixels, GLsizei width, GLsizei height, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType, GLsizei* widthVar, GLsizei* heightVar) {
	*widthVar = width;
	*heightVar = height;

	glGenTextures(1, ID);
	glActiveTexture(slot);
	Bind(*ID);
	Data<type>(width, height, 0, internalFormat, format, pixelType, pixels);
	glGenerateMipmap(bufferType);
}

template <typename type>
void Texture2D::Data(GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* pixels) {
	Data<type>(width, height, level, internalFormat, format, pixelType, pixels);
}

template <typename type>
void Texture2D::Data(GLsizei width, GLsizei height, GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* pixels) {
	GLint detail = level == 0 ? 1 : 2 * level;
	glTexImage2D(bufferType, level, internalFormat, width / detail, height / detail, 0, format, pixelType, pixels);
	if (level) {
		GLint detail = 2 * level;
		glTexImage2D(bufferType, level, internalFormat, width / detail, height / detail, 0, format, pixelType, pixels);
	}
	else {
		glTexImage2D(bufferType, level, internalFormat, width, height, 0, format, pixelType, pixels);
		glGenerateMipmap(bufferType);
	}
}

template <typename type>
void Texture2D::SubData(GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLint level, GLenum format, GLenum pixelType, type* pixels) {
	glTexSubImage2D(bufferType, level, xOffset, yOffset, width, height, 0, format, pixelType, pixels);
	if (!level)
		glGenerateMipmap(bufferType);
}

#endif

#endif
