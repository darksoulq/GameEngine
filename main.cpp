#include "Engine.hpp"
#include "MenuScene.hpp"
#include "GameScene.hpp"
#include "ResourceManager.hpp"

int main() {
    Engine engine;

    if (!engine.Initialize()) {
        return -1;
    }

    Scene* initialScene = new MenuScene(&engine);
    engine.GetSceneManager()->PushScene(initialScene);

    // Load resources
    ResourceManager::GetInstance().LoadTexture2D("testTexture", "images/test.png");
    ResourceManager::GetInstance().LoadShader("basicShader", "shaders/vertex.glsl", "shaders/fragment.glsl");

    // Get the loaded resources
    Shader* shader = ResourceManager::GetInstance().GetShader("basicShader");
    Texture* texture = ResourceManager::GetInstance().GetTexture2D("testTexture");

    if (shader) {
        shader->Use();
    }

    if (texture) {
        texture->Bind();
    }

    // Start the engine and enter the main loop
    engine.Start();

    return 0;
}
