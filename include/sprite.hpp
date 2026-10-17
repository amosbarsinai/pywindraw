#pragma once

#include "image.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <memory>

namespace pywindraw {
    class Sprite {
        public:
            Sprite(pywindraw::Image image);
            sf::Sprite get_internal_sf_sprite();
        private:
            std::shared_ptr<sf::Texture> _texture;
            sf::Sprite _sprite;
    };
}
