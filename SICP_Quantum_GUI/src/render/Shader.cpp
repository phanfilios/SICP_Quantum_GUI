#include "render/Shader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/gl.h>

Shader::Shader(const std::string& vPath, const std::string& fPath)
{
    std::string vCode = loadFile(vPath);
    std::string fCode = loadFile(fPath);

    unsigned int vs = compile(GL_VERTEX_SHADER, vCode);
    unsigned int fs = compile(GL_FRAGMENT_SHADER, fCode);

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

void Shader::setFloat(const std::string& name, float v) const
{
    glUniform1f(glGetUniformLocation(m_id, name.c_str()), v);
}

void Shader::setVec2(const std::string& name, const glm::vec2& v) const
{
    glUniform2f(glGetUniformLocation(m_id, name.c_str()), v.x, v.y);
}

void Shader::setMat4(const std::string& name, const glm::mat4& m) const
{
    glUniformMatrix4fv(
        glGetUniformLocation(m_id, name.c_str()),
        1, GL_FALSE, &m[0][0]
    );
}

std::string Shader::loadFile(const std::string& path)
{
    std::ifstream file(path);
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

unsigned int Shader::compile(unsigned int type, const std::string& src)
{
    unsigned int id = glCreateShader(type);
    const char* c = src.c_str();
    glShaderSource(id, 1, &c, nullptr);
    glCompileShader(id);
    return id;
}