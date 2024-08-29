#include "Engine.hpp"

Engine::Engine() : window(nullptr), inputManager(nullptr), sceneManager(nullptr), isRunning(true) {}

Engine::~Engine() {
    if (window) delete window;
    if (inputManager) delete inputManager;
    if (sceneManager) delete sceneManager;
    SDL_Quit();
}

bool Engine::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    window = new Window("Game Engine", 800, 600);
    if (!window->Initialize()) {
        return false;
    }

    inputManager = new InputManager();
    sceneManager = new SceneManager();
    return true;
}

void Engine::SetUpdateFunction(const std::function<void()>& updateFunc) {
    updateFunction = updateFunc;
}

void Engine::PollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Engine::Update() {
    if (updateFunction) {
        updateFunction();
    } else {
        sceneManager->Update(inputManager);
    }
}

void Engine::Start() {
    while (isRunning) {
        inputManager->Update();
        PollEvents();

        Update();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        sceneManager->Render();

        window->SwapBuffers();
    }
}

SceneManager* Engine::GetSceneManager() {
    return sceneManager;
}
