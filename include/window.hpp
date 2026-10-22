//      window.hpp: describes the pywindraw::Window class, directly exposed to python

#pragma once

#include "color.hpp"
#include "sprite.hpp"

#include <string>

#include <pybind11/pybind11.h>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace pywindraw::window {
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
                int initial_window_height,
                bool resizable
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
             * @brief Returns whether the window is focused.
             * 
             * @returns whether the window is focused.
             */
            bool is_focused();
            /**
             * @brief Requests a window focus from the window manager.
             * 
             * Raises a WindowError if the request is denied.
             */
            void request_focus();
            /**
             * @brief Sets the title of the window.
             */
            void set_title(std::string title);
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
            color::Color get_color();
            /**
             * @brief Sets the background color of the window.
             */
            void set_color(color::Color color);
            /**
             * @brief Sets the window icon.
             */
            void set_icon(const image::Image& image);
            /**
             * @brief Returns the elapsed time since the last frame, in seconds.
             * 
             * This resets every frame, and any time-dependent game element that is changed every update should be multiplied by this vaule.
             */
            double get_delta();

            pybind11::dict sprites;
        private:
            sf::RenderWindow _window;
            color::Color bg = color::Color::WHITE;
            sf::Clock clock;
            double delta = 0.0;
    };
}
