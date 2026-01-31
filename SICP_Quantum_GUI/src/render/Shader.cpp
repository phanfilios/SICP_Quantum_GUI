#include "render/Shader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>

static std::string loadFile(const char* path)
{
    std::ifstream file(path);
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

Shader::Shader(const char* vPath, const char* fPath)
{
    std::string vCode = loadFile(vPath);
    std::string fCode = loadFile(fPath);

    const char* vSrc = vCode.c_str();
    const char* fSrc = fCode.c_str();

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vSrc, nullptr);
    glCompileShader(vs);

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fSrc, nullptr);
    glCompileShader(fs);

    m_id = glCreateProgram();
    glAttachShader(m_id, vs);
    glAttachShader(m_id, fs);
    glLinkProgram(m_id);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

void Shader::use() const
{
    glUseProgram(m_id);
}

void Shader::setFloat(const std::string& n, float v) const
{
    glUniform1f(glGetUniformLocation(m_id, n.c_str()), v);
}

void Shader::setVec2(const std::string& n, const glm::vec2& v) const
{
    glUniform2fv(glGetUniformLocation(m_id, n.c_str()), 1, glm::value_ptr(v));
}

void Shader::setMat4(const std::string& n, const glm::mat4& m) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_id, n.c_str()), 1, GL_FALSE, glm::value_ptr(m));
}