#include "pch.h"
#include "glad/glad.h"
#include "stb_image.h"

#include "OpenGLImage.h"
#include "MarioRPGUtils.h"

namespace Mario_RPG_Engine
{
	OpenGLImage::OpenGLImage(const std::string& imageFile)
	{
		glGenTextures(1, &mImageFile);
		glBindTexture(GL_TEXTURE_2D, mImageFile);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);

		int nrChannels;
		unsigned char* data = stbi_load(imageFile.c_str(), &mWidth, &mHeight, &nrChannels, 0);

		if (data == nullptr)
		{
			MARIO_ERROR("Could not load image!");
		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		stbi_image_free(data);
	}

	OpenGLImage::OpenGLImage(std::string&& imageFile)
	{
		glGenTextures(1, &mImageFile);
		glBindTexture(GL_TEXTURE_2D, mImageFile);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);

		int nrChannels;
		unsigned char* data = stbi_load(imageFile.c_str(), &mWidth, &mHeight, &nrChannels, 0);

		if (data == nullptr)
		{
			MARIO_ERROR("Could not load image!");
		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		stbi_image_free(data);
	}

	void OpenGLImage::Activate()
	{
		glBindTexture(GL_TEXTURE_2D, mImageFile);
	}

	int OpenGLImage::GetWidth() const
	{
		return mWidth;
	}

	int OpenGLImage::GetHeight() const
	{
		return mHeight;
	}

	OpenGLImage::~OpenGLImage()
	{
		glDeleteTextures(1, &mImageFile);
	}
}