#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height, bool resizable = true, bool adjustViewportOnResize = true);
    ~Window();

    bool Initialize();
    void SwapBuffers();
    void PollEvents(bool& isRunning);

    // Additional methods
    void Resize(int width, int height);
    void SetVSync(bool enabled);
    void SetResizable(bool resizable);
    void SetViewportAdjustment(bool enabled);

    // Accessors
    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    bool IsResizable() const { return resizable; }
    bool IsViewportAdjustmentEnabled() const { return adjustViewport; }

private:
    std::string title;
    int width;
    int height;
    bool resizable;
    bool adjustViewport;  // Flag to enable or disable viewport adjustment
    SDL_Window* sdlWindow;
    SDL_GLContext glContext;
};

#endif // WINDOW_HPP
