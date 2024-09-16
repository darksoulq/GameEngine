#include "Texture.hpp"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

bool Texture::LoadFromFile(const std::string& filePath) {
    std::cout << "Attempting to load texture from: " << filePath << std::endl;

    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    // Load image using stb_image
    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);

    if (!data) {
        std::cerr << "Error: Failed to load image. Reason: " << stbi_failure_reason() << std::endl;
        
        // Cleanup: delete the texture ID and unbind
        glBindTexture(GL_TEXTURE_2D, 0);
        glDeleteTextures(1, &ID);
        
        return false;
    }

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D); // Generate mipmaps

    // Set default texture parameters
    SetWrapS(GL_REPEAT);
    SetWrapT(GL_REPEAT);
    SetMinFilter(GL_LINEAR_MIPMAP_LINEAR);
    SetMagFilter(GL_LINEAR);

    stbi_image_free(data);
    std::cout << "Texture loaded successfully!" << std::endl;
    
    // Unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);

    return true;
}

void Texture::Bind() const {
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Cleanup() {
    if (ID != 0) {
        glDeleteTextures(1, &ID);
        ID = 0;  // Mark as deleted
    }
}
