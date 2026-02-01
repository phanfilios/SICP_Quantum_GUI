#pragma once
#include <string>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const std::string& vertexPath,
           const std::string& fragmentPath);

    void use() const;

    void setFloat(const std::string& name, float value) const;
    void setVec2(const std::string& name, const glm::vec2& value) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;

private:
    unsigned int m_id;

    std::string loadFile(const std::string& path);
    unsigned int compile(unsigned int type, const std::string& src);
};