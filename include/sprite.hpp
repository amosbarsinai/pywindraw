//      sprite.hpp: describes the pywindraw::Sprite class, directly exposed to python.

#pragma once

#include "image.hpp"

#include <memory>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace pywindraw::sprite {
    /**
     * @brief Class used to handle sprites.
     * 
     * @details This class wraps an sf::Sprite and shares its image's texture.
     */
    class Sprite {
        public:
            /**
             * @brief Construct a sprite from an image.
             */
            Sprite(const image::Image& image);
            /**
             * @brief Get private _sprite variable.
             * 
             * Internal use only, not exposed to python.
             */
            sf::Sprite& get_internal_sf_sprite();
        private:
            std::shared_ptr<sf::Texture> _texture;
            sf::Sprite _sprite;
    };
}
