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
    void PollEvents();
    void Update();
    void Start();

    SceneManager* GetSceneManager();
    Window* GetWindow() const { return window; }  // Add this method

private:
    Window* window;
    InputManager* inputManager;
    SceneManager* sceneManager;
    std::function<void()> updateFunction;
    bool isRunning;
};

#endif // ENGINE_HPP
