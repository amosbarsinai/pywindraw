#include "image.hpp"
#include "color.hpp"
#include <string>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdexcept>
#include "error.hpp"

namespace py = pybind11;

namespace pywindraw {
    void Image::assert_pixel_valid(py::tuple index) {
        if (index.size() != 2)
            throw std::invalid_argument("Expected an x and y value for pixel index (num of arguments recieved: " + std::to_string(index.size()) + ")");
        sf::Vector2u size = _image.getSize();
        if (index[0].cast<int>() < 0 || index[1].cast<int>() < 0)
            throw std::invalid_argument(
                "Pixel coordinates must both be positive (recieved " +
                std::to_string(index[0].cast<int>()) +
                ", " +
                std::to_string(index[1].cast<int>()) + 
                ")"
            );
        if (index[0].cast<int>() > size.x || index[1].cast<int>() > size.y)
            throw std::invalid_argument(
                "Pixel must be inside the image (recieved " +
                std::to_string(index[0].cast<int>()) +
                ", " +
                std::to_string(index[1].cast<int>()) +
                "), image size is " +
                std::to_string(size.x) +
                " by " +
                std::to_string(size.y)
            );
    }

    void Image::update_texture() {
        if (!_texture.loadFromImage(_image))
            throw std::runtime_error("An internal error occured when trying to load the texture of an image");
    }

    sf::Texture Image::get_texture() { return _texture; }

    Image::Image(std::string &filepath) {
        if (!_image.loadFromFile(filepath))
            throw pywindraw::ImageError("Could not load an image from '" + filepath + "', ensure it is the correct path and that it is an image file");
        update_texture();
    }

    Image::Image(pywindraw::Color color, int width, int height) {
        _image = sf::Image({width, height}, color.get_internal_sf_color());
    }

    pywindraw::Color Image::get_pixel(py::tuple index) {
        assert_pixel_valid(index);
        return _image.getPixel(sf::Vector2u{index[0].cast<std::size_t>(), index[1].cast<std::size_t>()});
    }

    void Image::set_pixel(py::tuple index, pywindraw::Color color) {
        assert_pixel_valid(index);
        _image.setPixel(sf::Vector2u{index[0].cast<std::size_t>(), index[1].cast<std::size_t>()}, color.get_internal_sf_color());
    }

    void Image::del_pixel(py::tuple index) {
        assert_pixel_valid(index);
        set_pixel(index, Color(0, 0, 0, 0));
    }

    sf::Image Image::get_internal_sf_image() {
        return _image;
    }

    void Image::crop(int x, int y, int width, int height) {
        sf::Image cropped(sf::Vector2u{width, height});
        sf::IntRect source_rect(sf::Vector2{x, y}, sf::Vector2{width, height});

        _image.copy(cropped, sf::Vector2u{0, 0}, source_rect, true);
    }
}
