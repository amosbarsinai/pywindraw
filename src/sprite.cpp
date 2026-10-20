#include "sprite.hpp"
#include "image.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace pywindraw {
    Sprite::Sprite(const pywindraw::Image& image) :
            _texture(image.get_internal_sf_texture()),
            _sprite(*_texture) {}
    sf::Sprite& Sprite::get_internal_sf_sprite() {
        return _sprite;
    }
}
