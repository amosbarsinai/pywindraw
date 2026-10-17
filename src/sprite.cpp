#include "sprite.hpp"
#include "image.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace pywindraw {
    Sprite::Sprite(pywindraw::Image image) :
            _texture(std::make_shared<sf::Texture>(image.get_texture())),
            _sprite(*_texture) {}
    sf::Sprite Sprite::get_internal_sf_sprite() {
        return _sprite;
    }
}
