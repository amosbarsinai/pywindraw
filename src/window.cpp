#include "window.hpp"
#include "error.hpp"
#include "rect.hpp"

#include <optional>
#include <stdexcept>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <pybind11/pybind11.h>

namespace pywindraw::window {
    Window::Window(
        std::string title,
        int initial_window_width,
        int initial_window_height,
        bool resizable
    ) {
        const sf::Vector2u desktop_size = sf::VideoMode::getDesktopMode().size;
        if (!fits_within_rect(
                0, 0, initial_window_width, initial_window_height,
                desktop_size.x, desktop_size.y
            ))
            throw std::invalid_argument(
                "Window dimensions must fit within the desktop (" + std::to_string(desktop_size.x) + "x" + std::to_string(desktop_size.y) + ")"
            );

        if (!resizable)
            _window.create(
                sf::VideoMode {
                    {
                        static_cast<unsigned int>(initial_window_width),
                        static_cast<unsigned int>(initial_window_height)
                    },
                    sf::VideoMode::getDesktopMode().bitsPerPixel
                },
                title
            );
        else
            _window.create(
                sf::VideoMode {
                    {
                        static_cast<unsigned int>(initial_window_width),
                        static_cast<unsigned int>(initial_window_height)
                    },
                    sf::VideoMode::getDesktopMode().bitsPerPixel
                },
                title,
                sf::Style::Resize
            );
    }

    void Window::update() {
        if (! _window.isOpen() ) {
            throw error::WindowError("Tried to call update() on a closed window");
        }
        while (const std::optional event = _window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                _window.close();
                return;
            }
        }
        if (!_window.isOpen()) {
            throw error::WindowError("Tried to call update() on a closed window");
        }
        _window.clear(bg.get_internal_sf_color());
        for (const auto& item : sprites) {
            sprite::Sprite& sprite = pybind11::cast<sprite::Sprite&>(item.first);
            pybind11::sequence position = pybind11::cast<pybind11::sequence>(item.second);
            if (position.size() != 2) {
                throw pybind11::value_error("Sprite coordinates must contain exactly two values (found " + std::to_string(position.size()) + ")");
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

    bool Window::is_focused() { return _window.hasFocus(); }
    void Window::request_focus() {
        _window.requestFocus();
        if (!_window.hasFocus())
            throw error::WindowError("A request to focus a window has been denied.");
    }

    void Window::set_title(std::string title) { _window.setTitle(title); }

    int  Window::get_width()        { return _window.getSize().x; }
    int  Window::get_height()       { return _window.getSize().y; }
    void Window::set_width(int x)   {
        const sf::Vector2u desktop_size = sf::VideoMode::getDesktopMode().size;
        if (!fits_within_rect(0, 0, x, 1, desktop_size.x, desktop_size.y))
            throw std::invalid_argument(
                "Window dimensions must fit within the desktop (" + std::to_string(desktop_size.x) + "x" + std::to_string(desktop_size.y) + ")"
            );
        sf::Vector2u size = _window.getSize();
        size.x = static_cast<unsigned int>(x);
        _window.setSize(size);
    }
    void Window::set_height(int y)  {
        const sf::Vector2u desktop_size = sf::VideoMode::getDesktopMode().size;
        if (!fits_within_rect(0, 0, 1, y, desktop_size.x, desktop_size.y))
            throw std::invalid_argument(
                "Window dimensions must fit within the desktop (" + std::to_string(desktop_size.x) + "x" + std::to_string(desktop_size.y) + ")"
            );
        sf::Vector2u size = _window.getSize();
        size.y = static_cast<unsigned int>(y);
        _window.setSize(size);
    }

    color::Color Window::get_color() { return bg; }
    void Window::set_color(color::Color color) { bg = color; }

    void Window::set_icon(const image::Image& icon) {
        _window.setIcon(icon.get_internal_sf_image());
    }
}
