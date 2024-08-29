#include "ResourceManager.hpp"

Texture* ResourceManager::LoadTexture2D(const std::string& name, const std::string& filePath) {
    if (textures2D.find(name) != textures2D.end()) {
        return &textures2D[name];  // Return existing texture if already loaded
    }

    Texture texture;
    if (texture.LoadFromFile(filePath)) {
        textures2D[name] = texture;
        return &textures2D[name];
    }
    return nullptr;
}

Shader* ResourceManager::LoadShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath) {
    if (shaders.find(name) != shaders.end()) {
        return &shaders[name];  // Return existing shader if already loaded
    }

    Shader shader;
    if (shader.LoadFromFile(vertexPath, fragmentPath)) {
        shaders[name] = shader;
        return &shaders[name];
    }
    return nullptr;
}

Texture* ResourceManager::GetTexture2D(const std::string& name) {
    return textures2D.find(name) != textures2D.end() ? &textures2D[name] : nullptr;
}

Shader* ResourceManager::GetShader(const std::string& name) {
    return shaders.find(name) != shaders.end() ? &shaders[name] : nullptr;
}

void ResourceManager::Cleanup() {
    for (auto& texture : textures2D) {
        texture.second.Cleanup();
    }
    for (auto& shader : shaders) {
        shader.second.Cleanup();
    }
    textures2D.clear();
    shaders.clear();
}
