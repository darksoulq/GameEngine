#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <string>
#include "Texture.hpp"
#include "Shader.hpp"

class ResourceManager {
public:
    static ResourceManager& GetInstance() {
        static ResourceManager instance;
        return instance;
    }

    // Load and retrieve 2D textures
    Texture* LoadTexture2D(const std::string& name, const std::string& filePath);
    Texture* GetTexture2D(const std::string& name);

    // Load and retrieve shaders
    Shader* LoadShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
    Shader* GetShader(const std::string& name);

    // Cleanup all loaded resources
    void Cleanup();

private:
    ResourceManager() = default;
    ~ResourceManager() = default;

    std::map<std::string, Texture> textures2D;
    std::map<std::string, Shader> shaders;
};

#endif // RESOURCE_MANAGER_HPP
