#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "Scene.hpp"  // Ensure Scene.hpp is included
#include <stack>

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

    void PushScene(Scene* scene);
    void PopScene();
    void ChangeScene(Scene* scene);

    void Update(InputManager* inputManager);
    void Render();

private:
    std::stack<Scene*> sceneStack;
};

#endif // SCENEMANAGER_HPP
