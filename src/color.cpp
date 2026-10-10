#include "color.hpp"
#include <stdexcept>
#include <string>

void pywindraw::Color::set_r(float r) {
    if (r < 0) throw new std::invalid_argument("Red RGB value received was less than 0 (" + std::to_string(r) + ')');
    if (r > 255) throw new std::invalid_argument("Red RGB value received was greater than 255 (" + std::to_string(r) + ')');
    _color.r = r;
}
int pywindraw::Color::get_r() { return _color.r; }

void pywindraw::Color::set_g(float g) {
    if (g < 0) throw new std::invalid_argument("Green RGB value received was less than 0 (" + std::to_string(g) + ')');
    if (g > 255) throw new std::invalid_argument("Green RGB value received was greater than 255 (" + std::to_string(g) + ')');
    _color.g = g;
}
int pywindraw::Color::get_g() { return _color.g; }

void pywindraw::Color::set_b(float b) {
    if (b < 0) throw new std::invalid_argument("Blue RGB value received was less than 0 (" + std::to_string(b) + ')');
    if (b > 255) throw new std::invalid_argument("Blue RGB value received was greater than 255 (" + std::to_string(b) + ')');
    _color.b = b;
}
int pywindraw::Color::get_b() { return _color.b; }

void pywindraw::Color::set_a(float a) {
    if (a < 0) throw new std::invalid_argument("Alpha RGB value received was less than 0 (" + std::to_string(a) + ')');
    if (a > 255) throw new std::invalid_argument("Alpha RGB value received was greater than 255 (" + std::to_string(a) + ')');
    _color.a = a;
}
int pywindraw::Color::get_a() { return _color.a; }

pywindraw::Color::Color(float r, float g, float b, float a) /* accept float and cast to nearest legal int as so not to confuse users with "Invoked with" errors */ {
    _color = sf::Color();
    set_r(r);
    set_b(b);
    set_g(g);
    set_a(a);
}

sf::Color pywindraw::Color::get_internal_sf_color() { return _color; } // intentionally don't expose to pythonn

// KDE color widget
const pywindraw::Color pywindraw::Color::RED(255, 0, 0);
const pywindraw::Color pywindraw::Color::GREEN(0, 255, 0);
const pywindraw::Color pywindraw::Color::BLUE(0, 0, 255);
const pywindraw::Color pywindraw::Color::YELLOW(255, 255, 0);
const pywindraw::Color pywindraw::Color::CYAN(0, 255, 255);
const pywindraw::Color pywindraw::Color::MAGENTA(255, 0, 255);
const pywindraw::Color pywindraw::Color::ORANGE(255, 165, 0);
const pywindraw::Color pywindraw::Color::BROWN(165, 42, 42);
const pywindraw::Color pywindraw::Color::BLACK(0, 0, 0);
const pywindraw::Color pywindraw::Color::GREY(128, 128, 128);
const pywindraw::Color pywindraw::Color::WHITE(255, 255, 255);
