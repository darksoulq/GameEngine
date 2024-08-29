#include "GameScene.hpp"
#include "MenuScene.hpp"
#include <iostream>

void GameScene::Update(InputManager* inputManager) {
    if (inputManager->IsKeyPressed(Key::ESC)) {
        std::cout << "Switching to Menu Scene\n";
        engine->GetSceneManager()->ChangeScene(new MenuScene(engine));
    }
}
