#include "Shader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

std::string Shader::LoadSource(const std::string& filePath) {
    std::ifstream file(filePath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

bool Shader::CompileShader(const std::string& source, GLenum type, GLuint& shaderID) {
    shaderID = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shaderID, 1, &src, nullptr);
    glCompileShader(shaderID);

    GLint success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Error: " << infoLog << std::endl;
        return false;
    }
    return true;
}

bool Shader::LoadFromFile(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string vertexSource = LoadSource(vertexPath);
    std::string fragmentSource = LoadSource(fragmentPath);

    GLuint vertexShader, fragmentShader;
    if (!CompileShader(vertexSource, GL_VERTEX_SHADER, vertexShader) ||
        !CompileShader(fragmentSource, GL_FRAGMENT_SHADER, fragmentShader)) {
        return false;
    }

    ProgramID = glCreateProgram();
    glAttachShader(ProgramID, vertexShader);
    glAttachShader(ProgramID, fragmentShader);
    glLinkProgram(ProgramID);

    GLint success;
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(ProgramID, 512, nullptr, infoLog);
        std::cerr << "Shader Linking Error: " << infoLog << std::endl;
        return false;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return true;
}

void Shader::Use() const {
    glUseProgram(ProgramID);
}

void Shader::Cleanup() {
    glDeleteProgram(ProgramID);
}

void Shader::SetUniform1i(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(ProgramID, name.c_str()), value);
}

void Shader::SetUniform1f(const std::string& name, float value) const {
    glUniform1f(glGetUniformLocation(ProgramID, name.c_str()), value);
}

void Shader::SetUniform3f(const std::string& name, float v0, float v1, float v2) const {
    glUniform3f(glGetUniformLocation(ProgramID, name.c_str()), v0, v1, v2);
}
