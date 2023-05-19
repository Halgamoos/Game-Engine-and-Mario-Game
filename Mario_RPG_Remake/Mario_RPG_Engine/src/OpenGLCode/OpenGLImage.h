#pragma once

#include "pch.h"
#include "ImplImage.h"

namespace Mario_RPG_Engine
{
	class OpenGLImage : public ImplImage
	{
	public:
		OpenGLImage(const std::string& imageFile);
		OpenGLImage(std::string&& imageFile);

		virtual void Activate() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		~OpenGLImage();
	private:
		unsigned int mImageFile{ 0 };
		int mWidth{ 0 }, mHeight{ 0 };
	};
}