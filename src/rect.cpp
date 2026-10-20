#include "rect.hpp"

bool fits_within_rect(
    int x,
    int y,
    int width,
    int height,
    unsigned int container_width,
    unsigned int container_height
) noexcept {
    if (x < 0 || y < 0 || width <= 0 || height <= 0)
        return false;

    const unsigned int unsigned_x = static_cast<unsigned int>(x);
    const unsigned int unsigned_y = static_cast<unsigned int>(y);
    const unsigned int unsigned_width = static_cast<unsigned int>(width);
    const unsigned int unsigned_height = static_cast<unsigned int>(height);

    return unsigned_x <= container_width &&
        unsigned_y <= container_height &&
        unsigned_width <= container_width - unsigned_x &&
        unsigned_height <= container_height - unsigned_y;
}
