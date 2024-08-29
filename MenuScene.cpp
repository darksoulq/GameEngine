#include "MenuScene.hpp"
#include "GameScene.hpp"
#include "ResourceManager.hpp"
#include "InputManager.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include <iostream>

void MenuScene::Initialize() {
    // Load resources
    shader = ResourceManager::GetInstance().GetShader("basicShader");
    texture = ResourceManager::GetInstance().GetTexture2D("testTexture");

    // Set up full-screen quad
    float vertices[] = {
        // positions         // texture coords
        -1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
        -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,
         1.0f, -1.0f, 0.0f,  1.0f, 0.0f,

        -1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
         1.0f, -1.0f, 0.0f,  1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,  1.0f, 1.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void MenuScene::Update(InputManager* inputManager) {
    if (inputManager->IsKeyPressed(Key::W)) {
        std::cout << "Switching to Game Scene\n";
        engine->GetSceneManager()->ChangeScene(new GameScene(engine));
    }
}

void MenuScene::Render() {
    if (shader) {
        shader->Use();
    }

    if (texture) {
        texture->Bind();
    }

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void MenuScene::Cleanup() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    std::cout << "Menu Scene Cleaned Up\n";
}
