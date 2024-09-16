#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "Engine.hpp"
#include "Scene.hpp"
#include "InputManager.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include <iostream>

class GameScene;  // Forward declaration

class MenuScene : public Scene {
public:
    MenuScene(Engine* engine) : engine(engine) {}

    void Initialize() override;
    void Update(InputManager* inputManager) override;
    void Render() override;
    void Cleanup() override;

private:
    Engine* engine;
    GLuint VAO, VBO;
    Shader* shader;
    Texture* texture;
};

#endif // MENUSCENE_HPP
