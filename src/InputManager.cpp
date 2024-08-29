#include "InputManager.hpp"

InputManager::InputManager() : mouseX(0), mouseY(0) {
    // Initialize keyStates and mouseButtonStates
    keyStates[Key::W] = false;
    keyStates[Key::A] = false;
    keyStates[Key::S] = false;
    keyStates[Key::D] = false;
    keyStates[Key::ESC] = false;
    mouseButtonStates[MouseButton::LEFT] = false;
    mouseButtonStates[MouseButton::RIGHT] = false;
    mouseButtonStates[MouseButton::MIDDLE] = false;
}

InputManager::~InputManager() {}

void InputManager::Update() {
    SDL_PumpEvents(); // Update internal event state

    // Poll keyboard state
    const Uint8* state = SDL_GetKeyboardState(NULL);
    keyStates[Key::SPACE] = state[SDL_SCANCODE_SPACE];
    keyStates[Key::ESCAPE] = state[SDL_SCANCODE_ESCAPE];
    keyStates[Key::F1] = state[SDL_SCANCODE_F1];
    keyStates[Key::F2] = state[SDL_SCANCODE_F2];
    keyStates[Key::F3] = state[SDL_SCANCODE_F3];
    keyStates[Key::F4] = state[SDL_SCANCODE_F4];
    keyStates[Key::F5] = state[SDL_SCANCODE_F5];
    keyStates[Key::F6] = state[SDL_SCANCODE_F6];
    keyStates[Key::F7] = state[SDL_SCANCODE_F7];
    keyStates[Key::F8] = state[SDL_SCANCODE_F8];
    keyStates[Key::F9] = state[SDL_SCANCODE_F9];
    keyStates[Key::F10] = state[SDL_SCANCODE_F10];
    keyStates[Key::F11] = state[SDL_SCANCODE_F11];
    keyStates[Key::F12] = state[SDL_SCANCODE_F12];
    keyStates[Key::LSHIFT] = state[SDL_SCANCODE_LSHIFT];
    keyStates[Key::RSHIFT] = state[SDL_SCANCODE_RSHIFT];
    keyStates[Key::LCTRL] = state[SDL_SCANCODE_LCTRL];
    keyStates[Key::RCTRL] = state[SDL_SCANCODE_RCTRL];
    keyStates[Key::LALT] = state[SDL_SCANCODE_LALT];
    keyStates[Key::RALT] = state[SDL_SCANCODE_RALT];
    keyStates[Key::TAB] = state[SDL_SCANCODE_TAB];
    keyStates[Key::BACKSPACE] = state[SDL_SCANCODE_BACKSPACE];
    keyStates[Key::DELETE] = state[SDL_SCANCODE_DELETE];
    keyStates[Key::HOME] = state[SDL_SCANCODE_HOME];
    keyStates[Key::END] = state[SDL_SCANCODE_END];
    keyStates[Key::PAGEUP] = state[SDL_SCANCODE_PAGEUP];
    keyStates[Key::PAGEDOWN] = state[SDL_SCANCODE_PAGEDOWN];
    keyStates[Key::UP] = state[SDL_SCANCODE_UP];
    keyStates[Key::DOWN] = state[SDL_SCANCODE_DOWN];
    keyStates[Key::LEFT] = state[SDL_SCANCODE_LEFT];
    keyStates[Key::RIGHT] = state[SDL_SCANCODE_RIGHT];
    keyStates[Key::NUM0] = state[SDL_SCANCODE_0];
    keyStates[Key::NUM1] = state[SDL_SCANCODE_1];
    keyStates[Key::NUM2] = state[SDL_SCANCODE_2];
    keyStates[Key::NUM3] = state[SDL_SCANCODE_3];
    keyStates[Key::NUM4] = state[SDL_SCANCODE_4];
    keyStates[Key::NUM5] = state[SDL_SCANCODE_5];
    keyStates[Key::NUM6] = state[SDL_SCANCODE_6];
    keyStates[Key::NUM7] = state[SDL_SCANCODE_7];
    keyStates[Key::NUM8] = state[SDL_SCANCODE_8];
    keyStates[Key::NUM9] = state[SDL_SCANCODE_9];
    keyStates[Key::KP0] = state[SDL_SCANCODE_KP_0];
    keyStates[Key::KP1] = state[SDL_SCANCODE_KP_1];
    keyStates[Key::KP2] = state[SDL_SCANCODE_KP_2];
    keyStates[Key::KP3] = state[SDL_SCANCODE_KP_3];
    keyStates[Key::KP4] = state[SDL_SCANCODE_KP_4];
    keyStates[Key::KP5] = state[SDL_SCANCODE_KP_5];
    keyStates[Key::KP6] = state[SDL_SCANCODE_KP_6];
    keyStates[Key::KP7] = state[SDL_SCANCODE_KP_7];
    keyStates[Key::KP8] = state[SDL_SCANCODE_KP_8];
    keyStates[Key::KP9] = state[SDL_SCANCODE_KP_9];
    keyStates[Key::KP_PLUS] = state[SDL_SCANCODE_KP_PLUS];
    keyStates[Key::KP_MINUS] = state[SDL_SCANCODE_KP_MINUS];
    keyStates[Key::KP_MULTIPLY] = state[SDL_SCANCODE_KP_MULTIPLY];
    keyStates[Key::KP_DIVIDE] = state[SDL_SCANCODE_KP_DIVIDE];
    keyStates[Key::KP_PERIOD] = state[SDL_SCANCODE_KP_PERIOD];
    keyStates[Key::KP_ENTER] = state[SDL_SCANCODE_KP_ENTER];
    keyStates[Key::KP_EQUALS] = state[SDL_SCANCODE_KP_EQUALS];
    keyStates[Key::LEFTBRACKET] = state[SDL_SCANCODE_LEFTBRACKET];
    keyStates[Key::RIGHTBRACKET] = state[SDL_SCANCODE_RIGHTBRACKET];
    keyStates[Key::BACKSLASH] = state[SDL_SCANCODE_BACKSLASH];
    keyStates[Key::SEMICOLON] = state[SDL_SCANCODE_SEMICOLON];
    keyStates[Key::APOSTROPHE] = state[SDL_SCANCODE_APOSTROPHE];
    keyStates[Key::COMMA] = state[SDL_SCANCODE_COMMA];
    keyStates[Key::PERIOD] = state[SDL_SCANCODE_PERIOD];
    keyStates[Key::SLASH] = state[SDL_SCANCODE_SLASH];
    keyStates[Key::GRAVE] = state[SDL_SCANCODE_GRAVE];
    keyStates[Key::MINUS] = state[SDL_SCANCODE_MINUS];
    keyStates[Key::EQUALS] = state[SDL_SCANCODE_EQUALS];
    keyStates[Key::CAPSLOCK] = state[SDL_SCANCODE_CAPSLOCK];
    keyStates[Key::NUMLOCK] = state[SDL_SCANCODE_NUMLOCKCLEAR];
    keyStates[Key::SCROLLLOCK] = state[SDL_SCANCODE_SCROLLLOCK];
    keyStates[Key::PRINTSCREEN] = state[SDL_SCANCODE_PRINTSCREEN];
    keyStates[Key::PAUSE] = state[SDL_SCANCODE_PAUSE];
    keyStates[Key::INSERT] = state[SDL_SCANCODE_INSERT];
    keyStates[Key::LGUI] = state[SDL_SCANCODE_LGUI];
    keyStates[Key::RGUI] = state[SDL_SCANCODE_RGUI];
    keyStates[Key::APPLICATION] = state[SDL_SCANCODE_APPLICATION];
    keyStates[Key::POWER] = state[SDL_SCANCODE_POWER];
    keyStates[Key::HELP] = state[SDL_SCANCODE_HELP];
    keyStates[Key::A] = state[SDL_SCANCODE_A];
    keyStates[Key::B] = state[SDL_SCANCODE_B];
    keyStates[Key::C] = state[SDL_SCANCODE_C];
    keyStates[Key::D] = state[SDL_SCANCODE_D];
    keyStates[Key::E] = state[SDL_SCANCODE_E];
    keyStates[Key::F] = state[SDL_SCANCODE_F];
    keyStates[Key::G] = state[SDL_SCANCODE_G];
    keyStates[Key::H] = state[SDL_SCANCODE_H];
    keyStates[Key::I] = state[SDL_SCANCODE_I];
    keyStates[Key::J] = state[SDL_SCANCODE_J];
    keyStates[Key::K] = state[SDL_SCANCODE_K];
    keyStates[Key::L] = state[SDL_SCANCODE_L];
    keyStates[Key::M] = state[SDL_SCANCODE_M];
    keyStates[Key::N] = state[SDL_SCANCODE_N];
    keyStates[Key::O] = state[SDL_SCANCODE_O];
    keyStates[Key::P] = state[SDL_SCANCODE_P];
    keyStates[Key::Q] = state[SDL_SCANCODE_Q];
    keyStates[Key::R] = state[SDL_SCANCODE_R];
    keyStates[Key::S] = state[SDL_SCANCODE_S];
    keyStates[Key::T] = state[SDL_SCANCODE_T];
    keyStates[Key::U] = state[SDL_SCANCODE_U];
    keyStates[Key::V] = state[SDL_SCANCODE_V];
    keyStates[Key::W] = state[SDL_SCANCODE_W];
    keyStates[Key::X] = state[SDL_SCANCODE_X];
    keyStates[Key::Y] = state[SDL_SCANCODE_Y];
    keyStates[Key::Z] = state[SDL_SCANCODE_Z];


    // Poll mouse state
    Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
    mouseButtonStates[MouseButton::LEFT] = (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
    mouseButtonStates[MouseButton::RIGHT] = (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0;
    mouseButtonStates[MouseButton::MIDDLE] = (mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0;
}

bool InputManager::IsKeyPressed(Key key) const {
    auto it = keyStates.find(key);
    return it != keyStates.end() && it->second;
}

bool InputManager::IsMouseButtonPressed(MouseButton button) const {
    auto it = mouseButtonStates.find(button);
    return it != mouseButtonStates.end() && it->second;
}

int InputManager::GetMouseX() const {
    return mouseX;
}

int InputManager::GetMouseY() const {
    return mouseY;
}
