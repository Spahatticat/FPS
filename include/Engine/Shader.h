#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>

class Shader
{
public:
	unsigned int ID;

	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void use() const;

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec2(const std::string& name, const glm::vec2& value) const;
	void setVec3(const std::string& name, const glm::vec3& value) const;
	void setVec4(const std::string& name, const glm::vec4& value) const;
	void setMat4(const std::string& name, const glm::mat4& value) const;

private:
	void compile(const std::string& vertexSource, const std::string& fragmentSource);
	std::string readFile(const std::string& filePath) const;
	unsigned int compileShader(const char* source, GLenum type) const;
	void checkCompileErrors(unsigned int object, const std::string& type) const;
};

#endif