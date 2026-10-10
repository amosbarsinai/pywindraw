#pragma once
#include <SFML/Graphics/Color.hpp>

namespace pywindraw {
    class Color {
        public:
            Color(float r, float g, float b, float a = 255);
            int   get_r();
            int   get_g();
            int   get_b();
            int   get_a();
            void set_r(float r);
            void set_g(float g);
            void set_b(float b);
            void set_a(float a);
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
