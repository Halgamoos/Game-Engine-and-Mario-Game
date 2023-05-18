#pragma once

#include "pch.h"
#include "MarioRPGUtils.h"
#include "ImplImage.h"

namespace Mario_RPG_Engine
{
	class MARIORPG_API Image
	{
	public:
		Image(const std::string& imageFile);
		Image(std::string&& imageFile);

		void Activate();

		int GetWidth() const;
		int GetHeight() const;

	private:
		ImplImage* mImplementation{ nullptr };
	};
}