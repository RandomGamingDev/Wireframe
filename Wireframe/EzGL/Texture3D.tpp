#ifndef TEXTURE3D_TEMPLATE
#define TEXTURE3D_TEMPLATE

#ifdef GL_API_GLAD_OPENGL_3

template <typename type>
Texture3D::Texture3D(type* pixels, GLsizei width, GLsizei height, GLsizei length, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType) {
	Init<type>(pixels, width, height, length, slot, internalFormat, format, pixelType);
}

template <typename type>
void Texture3D::Init(type* pixels, GLint width, GLsizei height, GLsizei length, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType) {
	Init<type>(&ID, pixels, width, height, length, slot, internalFormat, format, pixelType, &this->width, &this->height, &this->length);
}

template <typename type>
void Texture3D::Init(GLuint* ID, type* pixels, GLsizei width, GLsizei height, GLsizei length, GLenum slot, GLint internalFormat, GLenum format, GLenum pixelType, GLsizei* widthVar, GLsizei* heightVar, GLsizei* lengthVar) {
	*widthVar = width;
	*heightVar = height;
	*lengthVar = length;

	glGenTextures(1, ID);
	glActiveTexture(slot);
	Bind(*ID);
	Data<type>(width, height, length, 0, internalFormat, format, pixelType, pixels);
	glGenerateMipmap(bufferType);
}

template <typename type>
void Texture3D::Data(GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* pixels) {
	Data<type>(width, height, length, level, internalFormat, format, pixelType, pixels);
}

template <typename type>
void Texture3D::Data(GLsizei width, GLsizei height, GLsizei length, GLint level, GLint internalFormat, GLenum format, GLenum pixelType, type* pixels) {
	if (level) {
		GLint detail = 2 * level;
		glTexImage3D(bufferType, level, internalFormat, width / detail, height / detail, length / detail, 0, format, pixelType, pixels);
	}
	else {
		glTexImage3D(bufferType, level, internalFormat, width, height, length, 0, format, pixelType, pixels);
		glGenerateMipmap(bufferType);
	}
}

template <typename type>
void Texture3D::SubData(GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei length, GLint level, GLenum format, GLenum pixelType, type* pixels) {
	glTexSubImage3D(bufferType, level, xOffset, yOffset, zOffset, width, height, length, 0, format, pixelType, pixels);
	if (!level)
		glGenerateMipmap(bufferType);
}

#endif

#endif
