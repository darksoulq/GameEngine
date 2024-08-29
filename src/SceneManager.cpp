#include "SceneManager.hpp"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {
    while (!sceneStack.empty()) {
        sceneStack.top()->Cleanup();
        delete sceneStack.top();
        sceneStack.pop();
    }
}

void SceneManager::PushScene(Scene* scene) {
    if (!sceneStack.empty()) {
        sceneStack.top()->Cleanup();
    }
    sceneStack.push(scene);
    scene->Initialize();
}

void SceneManager::PopScene() {
    if (!sceneStack.empty()) {
        sceneStack.top()->Cleanup();
        delete sceneStack.top();
        sceneStack.pop();
        if (!sceneStack.empty()) {
            sceneStack.top()->Initialize();
        }
    }
}

void SceneManager::ChangeScene(Scene* scene) {
    if (!sceneStack.empty()) {
        sceneStack.top()->Cleanup();
        delete sceneStack.top();
        sceneStack.pop();
    }
    sceneStack.push(scene);
    scene->Initialize();
}

void SceneManager::Update(InputManager* inputManager) {
    if (!sceneStack.empty()) {
        sceneStack.top()->Update(inputManager);
    }
}

void SceneManager::Render() {
    if (!sceneStack.empty()) {
        sceneStack.top()->Render();
    }
}
