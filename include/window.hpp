#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "color.hpp"

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
            void set_color(pywindraw::Color color);
            pywindraw::Color get_color();
        private:
            sf::RenderWindow _window;
            pywindraw::Color bg = pywindraw::Color::WHITE;
    };
}
