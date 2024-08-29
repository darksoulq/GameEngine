#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    bool Initialize();
    void SwapBuffers();
    void PollEvents(bool& isRunning);

private:
    std::string title;
    int width;
    int height;
    SDL_Window* sdlWindow;
    SDL_GLContext glContext;
};

#endif // WINDOW_HPP