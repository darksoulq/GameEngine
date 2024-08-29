#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include <string>

class Texture {
public:
    Texture() : ID(0), Width(0), Height(0) {}

    bool LoadFromFile(const std::string& filePath); // Loads the texture from a file
    void Bind() const;  // Bind the texture for use

    GLuint GetID() const { return ID; }
    int GetWidth() const { return Width; }
    int GetHeight() const { return Height; }

    void Cleanup();  // Cleanup texture from OpenGL memory

    // Set texture parameters
    void SetWrapS(GLenum wrap) { glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap); }
    void SetWrapT(GLenum wrap) { glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap); }
    void SetMinFilter(GLenum filter) { glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter); }
    void SetMagFilter(GLenum filter) { glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter); }
    
private:
    GLuint ID;
    int Width, Height;
};

#endif // TEXTURE_HPP
