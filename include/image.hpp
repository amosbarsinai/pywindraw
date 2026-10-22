//      image.hpp: describes the pywindraw::Image class, directly exposed to python.

#pragma once

#include "color.hpp"

#include <memory>
#include <string>

#include <pybind11/pybind11.h>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace py = pybind11;

namespace pywindraw::image {
    /**
     * @brief Class used to handle images.
     * 
     * @details
     * This class holds a CPU-side sf::Image and a shared GPU texture.
     * 
    */
    class Image {
        public:
            /**
             * @brief Load an image from filepath.
             */
            Image(const std::string &filepath);
            /**
             * @brief Create a new image with a uniform color.
             */
            Image(color::Color color, int width, int height);
            /**
             * @brief Crop the image to a defined rectangle inside.
             * 
             * Raises an ImageError if the rectangle is not inside the image.
             */
            void crop(int x, int y, int width, int height);
            /**
             * @brief Fetch the color of a pixel.
             * 
             * This function is exposed to python as the getter method of the pywindraw::Image class.
             */
            color::Color get_pixel(py::tuple index);
            /**
             * @brief Set the color of a pixel.
             * 
             * This function is exposed to python as the setter method of the pywindraw::Image class.
             */
            void set_pixel(py::tuple index, color::Color color);
            /**
             * @brief Set the color of a pixel to transparent (black).
             * 
             * This function is exposed to python as the getter method of the pywindraw::Image class.
             */
            void del_pixel(py::tuple index);
            /**
             * @brief Assert the index given is inside the image.
             * 
             * For internal use only, not exposed to python
             */
            void assert_pixel_valid(py::tuple index);
            /**
             * @brief Assert the coordinates given are inside the image.
             * 
             * For internal use only, not exposed to python
             */
            void assert_pixel_valid(int x, int y);
            /**
             * @brief Get private _texture variable
             * 
             * For internal use only, not exposed to python
             */
            const std::shared_ptr<sf::Texture>& get_internal_sf_texture() const;
            /**
             * @brief Get private _image variable
             * 
             * For internal use only, not exposed to python
             */
            const sf::Image& get_internal_sf_image() const;
            /**
             * @brief Move internal _image to VRAM
             * 
             * Update _texture to match _image
             */
            void update_texture();
        private:
            sf::Image _image;
            std::shared_ptr<sf::Texture> _texture = std::make_shared<sf::Texture>();
    };
}
