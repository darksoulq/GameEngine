#ifndef SCENE_HPP
#define SCENE_HPP

#include "InputManager.hpp"

class Scene {
public:
    virtual ~Scene() = default;

    virtual void Initialize() = 0;
    virtual void Update(InputManager* inputManager) = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;
};

#endif // SCENE_HPP
