//      color.hpp: describes the pywindraw::Color class, directly exposed to python.

#pragma once

#include <SFML/Graphics/Color.hpp>

namespace pywindraw {
    /**
     * @brief Class used to handle RGBA values, wrapping an sf::Color for simplicity
     *  
    */
    class Color {
        public:
            /**
             * @brief Constructs an opaque white color.
             * 
             */
            Color();
            /**
             * @brief Constructs an RGBA color.
             * 
             */
            Color(float r, float g, float b, float a = 255); // Default C++ values are not visible to Python, a = 255 is to simplify C++ code
            /**
             * @brief Wraps an existing sf::Color object.
             * 
             * This is intentionally not exposed.
             * 
             */
            Color(sf::Color);

            /**
             * @brief Returns the R value of this color.
             * 
             * @return the R value of this color
             * 
             */
            int get_r();
            /**
             * @brief Returns the G value of this color.
             * 
             * @return the G value of this color
             * 
             */
            int get_g();
            /**
             * @brief Returns the B value of this color.
             * 
             * @return the B value of this color
             * 
             */
            int get_b();
            /**
             * @brief Returns the A value of this color.
             * 
             * @return the A value of this color
             * 
             */
            int get_a();
            /**
             * @brief Sets the R value of this color.
             * 
             */
            void set_r(float r);
            /**
             * @brief Sets the G value of this color.
             * 
             */
            void set_g(float g);
            /**
             * @brief Sets the B value of this color.
             * 
             */
            void set_b(float b);
            /**
             * @brief Sets the A value of this color.
             * 
             */
            void set_a(float a);

            /**
             * @brief Returns the internal sf::Color this object wraps.
             * 
             * This is intentionally not exposed.
             * 
             */
            sf::Color get_internal_sf_color();

            static const Color RED;
            static const Color GREEN;
            static const Color BLUE;
            static const Color YELLOW;
            static const Color CYAN;
            static const Color MAGENTA;
            static const Color ORANGE;
            static const Color BROWN;
            static const Color BLACK;
            static const Color GREY;
            static const Color WHITE;
        private:
            sf::Color _color;
    };
}
