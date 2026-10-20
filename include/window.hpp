//      window.hpp: describes the pywindraw::Window class, directly exposed to python

#pragma once

#include "color.hpp"
#include "sprite.hpp"

#include <string>

#include <pybind11/pybind11.h>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace pywindraw {
    /**
     * @brief Class used to handle a basic window.
     * 
     * @details This class expands SFML's RenderWindow.
     */
    class Window {
        public:
            /**
             * @brief Create a new window with basic parameters.
             */
            Window(
                std::string title,
                int initial_window_width,
                int initial_window_height
            );
            /**
             * @brief Update, draw and display the window.
             */
            void update();
            /**
             * @brief Close and destroy the window.
             */
            void close();
            /**
             * @brief Returns whether the window is still open.
             * 
             * @returns whether the window is open.
             */
            bool is_open();
            /**
             * @brief Returns the width of the window.
             * 
             * @returns the width of the window.
             */
            int        get_width();
            /**
             * @brief Returns the height of the window.
             * 
             * @returns the height of the window.
             */
            int       get_height();
            /**
             * @brief Sets the width of the window.
             */
            void  set_width(int x);
            /**
             * @brief Sets the height of the window.
             */
            void set_height(int y);
            /**
             * @brief Returns the set background color of the window.
             * 
             * @returns the background color of the window.
             */
            pywindraw::Color get_color();
            /**
             * @brief Sets the background color of the window.
             */
            void set_color(pywindraw::Color color);
            /**
             * @brief Sets the window icon.
             */
            void set_icon(const pywindraw::Image& image);
            /**
             * @brief Returns the elapsed time since the last frame, in seconds.
             * 
             * This resets every frame, and any time-dependent game element that is changed every update should be multiplied by this vaule.
             */
            double get_delta();

            pybind11::dict sprites;
        private:
            sf::RenderWindow _window;
            pywindraw::Color bg = pywindraw::Color::WHITE;
            sf::Clock clock;
            double delta;
    };
}
