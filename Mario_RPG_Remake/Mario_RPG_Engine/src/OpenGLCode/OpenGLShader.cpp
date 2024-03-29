#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"

namespace Mario_RPG_Engine
{
	OpenGLShader::OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile)
	{
		std::string vShader;
		std::ifstream ifile{ vertexFile };
		std::string line;

		while (std::getline(ifile, line))
		{
			vShader += line;
			vShader += "\n";
		}
		ifile.close();
		const char* cVShader = vShader.c_str();

		unsigned int vertex;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &cVShader, NULL);
		glCompileShader(vertex);

		int success;
		char infoLog[1024];
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMILATION_ERROR of type VERTEX:" << infoLog << "\n -------------------" << std::endl;
		}

		std::string fShader;
		std::ifstream i2file{ fragmentFile };

		while (std::getline(i2file, line))
		{
			fShader += line;
			fShader += "\n";
		}
		i2file.close();
		const char* cFShader = fShader.c_str();

		unsigned int fragment;
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &cFShader, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMILATION_ERROR of type FRAGMENT:" << infoLog << "\n ---------------" << std::endl;
		}

		mProgram = glCreateProgram();
		glAttachShader(mProgram, vertex);
		glAttachShader(mProgram, fragment);
		glLinkProgram(mProgram);

		glGetProgramiv(mProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(mProgram, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type PROGRAM: \n" << infoLog << "\n ----------------" << std::endl;;
		}
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	OpenGLShader::OpenGLShader(std::string&& vertexFile, std::string&& fragmentFile)
	{
		std::string vShader;
		std::ifstream ifile{ vertexFile };
		std::string line;

		while (std::getline(ifile, line))
		{
			vShader += line;
			vShader += "\n";
		}
		ifile.close();
		const char* cVShader = vShader.c_str();

		unsigned int vertex;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &cVShader, NULL);
		glCompileShader(vertex);

		int success;
		char infoLog[1024];
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMILATION_ERROR of type VERTEX:" << infoLog << "\n -------------------" << std::endl;
		}

		std::string fShader;
		std::ifstream i2file{ fragmentFile };

		while (std::getline(i2file, line))
		{
			fShader += line;
			fShader += "\n";
		}
		i2file.close();
		const char* cFShader = fShader.c_str();

		unsigned int fragment;
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &cFShader, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMILATION_ERROR of type FRAGMENT:" << infoLog << "\n ---------------" << std::endl;
		}

		mProgram = glCreateProgram();
		glAttachShader(mProgram, vertex);
		glAttachShader(mProgram, fragment);
		glLinkProgram(mProgram);

		glGetProgramiv(mProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(mProgram, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type PROGRAM: \n" << infoLog << "\n ----------------" << std::endl;;
		}
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(mProgram);
	}
	void OpenGLShader::Activate()
	{
		glUseProgram(mProgram);
	}

	void OpenGLShader::Pass2FLoatValues(const std::string& name, float val1, float val2)
	{
		glUseProgram(mProgram);
		GLint location{ glGetUniformLocation(mProgram, name.c_str()) };
		glUniform2f(location, val1, val2);
	}

	void OpenGLShader::Pass2FLoatValues(std::string&& name, float val1, float val2)
	{
		glUseProgram(mProgram);
		GLint location{ glGetUniformLocation(mProgram, name.c_str()) };
		glUniform2f(location, val1, val2);
	}

}