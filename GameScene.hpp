#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "Engine.hpp"
#include "Scene.hpp"
#include <iostream>

class MenuScene;  // Forward declaration

class GameScene : public Scene {
public:
    GameScene(Engine* engine) : engine(engine) {}

    void Initialize() override {
        std::cout << "Game Scene Initialized\n";
    }

    void Update(InputManager* inputManager) override;

    void Render() override {
        std::cout << "Rendering Game Scene\n";
    }

    void Cleanup() override {
        std::cout << "Game Scene Cleaned Up\n";
    }

private:
    Engine* engine;
};

#endif // GAMESCENE_HPP
