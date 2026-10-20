#include "color.hpp"
#include "error.hpp"
#include "image.hpp"
#include "rect.hpp"

#include <stdexcept>
#include <string>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace py = pybind11;

namespace pywindraw {
    Image::Image(const std::string &filepath) {
        if (!_image.loadFromFile(filepath))
            throw pywindraw::ImageError("Could not load an image from '" + filepath + "', ensure it is the correct path and that it is an image file");
        update_texture();
    }

    Image::Image(pywindraw::Color color, int width, int height) {
        if (width <= 0 || height <= 0)
            throw std::invalid_argument("Image dimensions must be positive");
        _image = sf::Image(
            sf::Vector2u{
                static_cast<unsigned int>(width),
                static_cast<unsigned int>(height)
            },
            color.get_internal_sf_color()
        );
        update_texture();
    }

    void Image::crop(int x, int y, int width, int height) {
        const sf::Vector2u image_size = _image.getSize();
        if (!fits_within_rect(x, y, width, height, image_size.x, image_size.y))
            throw std::invalid_argument("Crop rectangle must be inside the image");

        sf::Image cropped(sf::Vector2u{
            static_cast<unsigned int>(width),
            static_cast<unsigned int>(height)
        });
        sf::IntRect source_rect(sf::Vector2{x, y}, sf::Vector2{width, height});

        if (!cropped.copy(_image, sf::Vector2u{0, 0}, source_rect, true))
            throw std::runtime_error("Could not copy the requested image crop");
        _image = cropped;
        update_texture();
    }

    pywindraw::Color Image::get_pixel(py::tuple index) {
        assert_pixel_valid(index);
        return _image.getPixel(sf::Vector2u{
            static_cast<unsigned int>(index[0].cast<int>()),
            static_cast<unsigned int>(index[1].cast<int>())
        });
    }

    void Image::set_pixel(py::tuple index, pywindraw::Color color) {
        assert_pixel_valid(index);
        _image.setPixel(
            sf::Vector2u{
                static_cast<unsigned int>(index[0].cast<int>()),
                static_cast<unsigned int>(index[1].cast<int>())
            },
            color.get_internal_sf_color()
        );
        update_texture();
    }

    void Image::del_pixel(py::tuple index) {
        assert_pixel_valid(index);
        set_pixel(index, Color(0, 0, 0, 0));
        update_texture();
    }

    void Image::assert_pixel_valid(py::tuple index) {
        if (index.size() != 2)
            throw std::invalid_argument("Expected an x and y value for pixel index (num of arguments recieved: " + std::to_string(index.size()) + ")");
        assert_pixel_valid(index[0].cast<int>(), index[1].cast<int>());
    }
    void Image::assert_pixel_valid(int x, int y) {
        const sf::Vector2u size = _image.getSize();
        if (!fits_within_rect(x, y, 1, 1, size.x, size.y))
            throw std::invalid_argument(
                "Pixel must be inside the image (recieved " +
                std::to_string(x) +
                ", " +
                std::to_string(y) +
                "), image size is " +
                std::to_string(size.x) +
                " by " +
                std::to_string(size.y)
            );
    }

    const std::shared_ptr<sf::Texture>& Image::get_internal_sf_texture() const {
        return _texture;
    }

    const sf::Image& Image::get_internal_sf_image() const {
        return _image;
    }

    void Image::update_texture() {
        if (!_texture->loadFromImage(_image))
            throw std::runtime_error("An internal error occured when trying to load the texture of an image");
    }
}
