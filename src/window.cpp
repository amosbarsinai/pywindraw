#include "window.hpp"
#include "error.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <optional>

Window::Window(
    std::string title,
    int initial_window_width,
    int initial_window_height
) {
    _window.create(
        sf::VideoMode {
            { initial_window_width, initial_window_height },
            sf::VideoMode::getDesktopMode().bitsPerPixel
        },
        title
    );
}

void Window::update() {
    if (! _window.isOpen() ) {
        throw WindowError("Tried to call update() on a closed window");
    }
    while (const std::optional event = _window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            _window.close();
        }
    }
    _window.clear(bg);
    _window.display();
}

bool Window::is_open() { return _window.isOpen(); }

int  Window::get_width()        { return _window.getSize().x; }
int  Window::get_height()       { return _window.getSize().y; }
void Window::set_width(int x)   { _window.setSize({x, get_height()}); }
void Window::set_height(int y)  { _window.setSize({get_width(),  y}); }
void Window::set_color(sf::Color color) { bg = color; }
sf::Color Window::get_color() { return bg; }

void Window::close() { _window.close(); }
