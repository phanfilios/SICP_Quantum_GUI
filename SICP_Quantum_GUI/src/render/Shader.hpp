#pragma once
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use() const;

    void setFloat(const std::string& name, float value) const;
    void setVec2(const std::string& name, const glm::vec2& value) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

private:
    unsigned int m_id;
};