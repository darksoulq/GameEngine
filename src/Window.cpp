#include "Window.hpp"

Window::Window(const std::string& title, int width, int height) 
    : title(title), width(width), height(height), sdlWindow(nullptr), glContext(nullptr) {}

Window::~Window() {
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(sdlWindow);
}

bool Window::Initialize() {
    sdlWindow = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if (!sdlWindow) {
        return false;
    }

    glContext = SDL_GL_CreateContext(sdlWindow);
    if (!glContext) {
        return false;
    }

    if (glewInit() != GLEW_OK) {
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    return true;
}

void Window::SwapBuffers() {
    SDL_GL_SwapWindow(sdlWindow);
}

void Window::PollEvents(bool& isRunning) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}
