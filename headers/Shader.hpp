#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <string>

class Shader {
public:
    Shader() : ProgramID(0) {}

    bool LoadFromFile(const std::string& vertexPath, const std::string& fragmentPath); // Load and compile shaders
    void Use() const;  // Use the shader program

    GLuint GetID() const { return ProgramID; }
    void Cleanup();  // Cleanup shader program

    // Set uniform variables
    void SetUniform1i(const std::string& name, int value) const;
    void SetUniform1f(const std::string& name, float value) const;
    void SetUniform3f(const std::string& name, float v0, float v1, float v2) const;

private:
    GLuint ProgramID;

    std::string LoadSource(const std::string& filePath);  // Load shader source code from a file
    bool CompileShader(const std::string& source, GLenum type, GLuint& shaderID); // Compile a shader
};

#endif // SHADER_HPP
