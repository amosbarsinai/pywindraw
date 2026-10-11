#include "color.hpp"
#include <stdexcept>
#include <string>

namespace pywindraw {
    void Color::set_r(float r) {
        if (r < 0) throw std::invalid_argument("Red RGB value received was less than 0 (recieved " + std::to_string(r) + ')');
        if (r > 255) throw std::invalid_argument("Red RGB value received was greater than 255 (recieved " + std::to_string(r) + ')');
        _color.r = r;
    }
    int Color::get_r() { return _color.r; }

    void Color::set_g(float g) {
        if (g < 0) throw std::invalid_argument("Green RGB value received was less than 0 (recieved " + std::to_string(g) + ')');
        if (g > 255) throw std::invalid_argument("Green RGB value received was greater than 255 (recieved " + std::to_string(g) + ')');
        _color.g = g;
    }
    int Color::get_g() { return _color.g; }

    void Color::set_b(float b) {
        if (b < 0) throw std::invalid_argument("Blue RGB value received was less than 0 (recieved " + std::to_string(b) + ')');
        if (b > 255) throw std::invalid_argument("Blue RGB value received was greater than 255 (recieved " + std::to_string(b) + ')');
        _color.b = b;
    }
    int Color::get_b() { return _color.b; }

    void Color::set_a(float a) {
        if (a < 0) throw std::invalid_argument("Alpha RGB value received was less than 0 (recieved " + std::to_string(a) + ')');
        if (a > 255) throw std::invalid_argument("Alpha RGB value received was greater than 255 (recieved " + std::to_string(a) + ')');
        _color.a = a;
    }
    int Color::get_a() { return _color.a; }

    Color::Color() {
        _color = sf::Color::White;
    }

    Color::Color(sf::Color color) {
        _color = color;
    }

    Color::Color(float r, float g, float b, float a) /* accept float and cast to nearest legal int as so not to confuse users with "Invoked with" errors */ {
        _color = sf::Color();
        set_r(r);
        set_b(b);
        set_g(g);
        set_a(a);
    }

    sf::Color Color::get_internal_sf_color() { return _color; } // intentionally don't expose to python

    // KDE color widget
    const Color Color::RED     (255, 0, 0);
    const Color Color::GREEN   (0, 255, 0);
    const Color Color::BLUE    (0, 0, 255);
    const Color Color::YELLOW  (255, 255, 0);
    const Color Color::CYAN    (0, 255, 255);
    const Color Color::MAGENTA (255, 0, 255);
    const Color Color::ORANGE  (255, 165, 0);
    const Color Color::BROWN   (165, 42, 42);
    const Color Color::BLACK   (0, 0, 0);
    const Color Color::GREY    (128, 128, 128);
    const Color Color::WHITE   (255, 255, 255);
}
