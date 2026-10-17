#pragma once

#include "color.hpp"
#include <string>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace pywindraw {
    class Image {
        public:
            Image(std::string &filepath);
            Image(pywindraw::Color color, int width, int height);
            pywindraw::Color get_pixel(py::tuple index);
            void set_pixel(py::tuple index, pywindraw::Color color);
            void del_pixel(py::tuple index);
            void assert_pixel_valid(py::tuple index);
            sf::Texture get_texture(); // for internal use only
            void crop(int x, int y, int width, int height);
            sf::Image get_internal_sf_image(); // for internal use only
        private:
            sf::Image _image;
            sf::Texture _texture;
            void update_texture();
    };
}
