#ifndef TEXTURE1D_TEMPLATE
#define TEXTURE1D_TEMPLATE

#ifdef GL_API_GLAD_OPENGL_3

template <typename type>
Texture1D::Texture1D(type* pixels, GLsizei width, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType) {
	Init<type>(pixels, width, slot, internalFormat, format, pixelType);
}

template <typename type>
void Texture1D::Init(type* pixels, GLint width, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType) {
	Init<type>(&ID, pixels, width, slot, internalFormat, format, pixelType, &this->width);
}

template <typename type>
void Texture1D::Init(GLuint* ID, type* pixels, GLsizei width, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType, GLsizei* widthVar) {
	*widthVar = width;

	glGenTextures(1, ID);
	glActiveTexture(slot);
	Bind(*ID);
	Data<type>(width, 0, internalFormat, format, pixelType, pixels);
	glGenerateMipmap(bufferType);
}

template <typename type>
void Texture1D::Data(GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* pixels) {
	Data<type>(width, level, internalFormat, format, pixelType, pixels);
}

template <typename type>
void Texture1D::Data(GLsizei width, GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* pixels) {
	if (level) {
		GLint detail = 2 * level;
		glTexImage1D(bufferType, level, internalFormat, width / detail, 0, format, pixelType, pixels);
	}
	else {
		glTexImage1D(bufferType, level, internalFormat, width, 0, format, pixelType, pixels);
		glGenerateMipmap(bufferType);
	}
}

template <typename type>
void Texture1D::SubData(GLint xOffset, GLsizei width, GLint level, GLenum format, GLenum pixelType, type* pixels) {
	glTexSubImage1D(bufferType, level, xOffset, width, 0, format, pixelType, pixels);
	if (!level)
		glGenerateMipmap(bufferType);
}

#endif

#endif
