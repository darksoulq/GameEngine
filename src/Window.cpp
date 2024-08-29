#include "Window.hpp"
#include <iostream>

Window::Window(const std::string& title, int width, int height, bool resizable, bool adjustViewportOnResize)
    : title(title), width(width), height(height), resizable(resizable), adjustViewport(adjustViewportOnResize), sdlWindow(nullptr), glContext(nullptr) {}

Window::~Window() {
    if (glContext) {
        SDL_GL_DeleteContext(glContext);
    }
    if (sdlWindow) {
        SDL_DestroyWindow(sdlWindow);
    }
    SDL_Quit();
}

bool Window::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    if (resizable) {
        windowFlags |= SDL_WINDOW_RESIZABLE;
    }

    sdlWindow = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        windowFlags
    );

    if (!sdlWindow) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    glContext = SDL_GL_CreateContext(sdlWindow);
    if (!glContext) {
        std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
        return false;
    }

    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        std::cerr << "GLEW Error: " << glewGetErrorString(glewError) << std::endl;
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    SetVSync(true);  // Enable V-Sync by default
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
        // Additional event handling if needed
    }
}

void Window::Resize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
    SDL_SetWindowSize(sdlWindow, width, height);

    if (adjustViewport) {
        glViewport(0, 0, width, height);  // Adjust the OpenGL viewport
    }
}

void Window::SetVSync(bool enabled) {
    if (SDL_GL_SetSwapInterval(enabled ? 1 : 0) < 0) {
        std::cerr << "SDL_GL_SetSwapInterval Error: " << SDL_GetError() << std::endl;
    }
}

void Window::SetResizable(bool resizable) {
    this->resizable = resizable;
    SDL_SetWindowResizable(sdlWindow, resizable ? SDL_TRUE : SDL_FALSE);
}

void Window::SetViewportAdjustment(bool enabled) {
    adjustViewport = enabled;
}

