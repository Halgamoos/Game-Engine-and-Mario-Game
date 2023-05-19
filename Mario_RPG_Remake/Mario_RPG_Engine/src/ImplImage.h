#pragma once

#include "pch.h"

namespace Mario_RPG_Engine
{
	class ImplImage
	{
	public:
		virtual void Activate() = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};
}