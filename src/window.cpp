#include "window.hpp"
#include "error.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <pybind11/pybind11.h>
#include <optional>

namespace pywindraw {
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
        _window.clear(bg.get_internal_sf_color());
        for (const auto& item : sprites) {
            pywindraw::Sprite& sprite = pybind11::cast<pywindraw::Sprite&>(item.first);
            pybind11::sequence position = pybind11::cast<pybind11::sequence>(item.second);
            if (position.size() != 2) {
                throw pybind11::value_error("Sprite coordinates must contain exactly two values");
            }
            sf::Sprite& drawable = sprite.get_internal_sf_sprite();
            drawable.setPosition({
                pybind11::cast<float>(position[0]),
                pybind11::cast<float>(position[1])
            });
            _window.draw(drawable);
        }
        delta = clock.restart().asSeconds();
        _window.display();
    }

    double Window::get_delta() {
        return delta;
    }

    void Window::close() { _window.close(); }

    bool Window::is_open() { return _window.isOpen(); }

    int  Window::get_width()        { return _window.getSize().x; }
    int  Window::get_height()       { return _window.getSize().y; }
    void Window::set_width(int x)   { _window.setSize({x, get_height()}); }
    void Window::set_height(int y)  { _window.setSize({get_width(),  y}); }

    Color Window::get_color() { return bg; }
    void Window::set_color(Color color) { bg = color; }

    void Window::set_icon(const pywindraw::Image& icon) {
        _window.setIcon(icon.get_internal_sf_image());
    }
}
