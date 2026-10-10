#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

namespace pywindraw {
    class Window {
        public:
            Window(
                std::string title,
                int initial_window_width,
                int initial_window_height
            );
            void update();
            void close();
            bool is_open();
            int        get_width();
            int       get_height();
            void  set_width(int x);
            void set_height(int y);
            void set_color(sf::Color color);
            sf::Color get_color();
        private:
            sf::RenderWindow _window;
            sf::Color bg = sf::Color::White;
    };
}
