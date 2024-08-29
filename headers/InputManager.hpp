#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SDL2/SDL.h>
#include <unordered_map>

enum class Key {
    ESC, SPACE, ENTER, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
    LCTRL, RCTRL, LALT, RALT, TAB, BACKSPACE, DELETE, HOME, END, PAGEUP, PAGEDOWN, UP, DOWN, LEFT, RIGHT,
    NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
    LSHIFT, RSHIFT, LGUI, RGUI, CAPSLOCK, SCROLLLOCK, NUMLOCK,
    PAUSE, PRINTSCREEN, INSERT, KP0, KP1, KP2, KP3, KP4, KP5, KP6, KP7, KP8, KP9, KPENTER, KPDECIMAL,
    KPADD, KPSUBTRACT, KPMULTIPLY, KPDIVIDE,
    MEDIA_PLAY_PAUSE, MEDIA_STOP, MEDIA_NEXT_TRACK, MEDIA_PREV_TRACK, VOLUME_MUTE, VOLUME_UP, VOLUME_DOWN,
    ESCAPE, KP_PLUS, KP_MINUS, KP_MULTIPLY, KP_DIVIDE, KP_PERIOD, KP_EQUALS, KP_ENTER, LEFTBRACKET, RIGHTBRACKET,
    BACKSLASH, SEMICOLON, APOSTROPHE, COMMA, PERIOD, SLASH, GRAVE, EQUALS, MINUS, APPLICATION, POWER,
    HELP, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
};


enum class MouseButton {
    LEFT, RIGHT, MIDDLE // Add more buttons if needed
};

class InputManager {
public:
    InputManager();
    ~InputManager();

    void Update();
    bool IsKeyPressed(Key key) const;
    bool IsMouseButtonPressed(MouseButton button) const;
    int GetMouseX() const;
    int GetMouseY() const;

private:
    std::unordered_map<Key, bool> keyStates;
    std::unordered_map<MouseButton, bool> mouseButtonStates;
    int mouseX, mouseY;
};

#endif // INPUTMANAGER_HPP
