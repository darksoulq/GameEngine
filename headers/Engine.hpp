#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Window.hpp"
#include "InputManager.hpp"
#include "SceneManager.hpp"
#include <functional>

class Engine {
public:
    Engine();
    ~Engine();

    bool Initialize();
    void SetUpdateFunction(const std::function<void()>& updateFunc);
    void Start();

    SceneManager* GetSceneManager(); // Accessor for SceneManager

private:
    Window* window;
    InputManager* inputManager;
    SceneManager* sceneManager;
    bool isRunning;
    std::function<void()> updateFunction;

    void PollEvents();
    void Update();
};

#endif // ENGINE_HPP
