//      error.hpp: describes the multiple custom-named exceptions pywindraw can raise.

#pragma once

#include <stdexcept>

namespace pywindraw {

    /**
     * @brief Raised when a window-related logic error occurs.
     * 
     */
    class WindowError : public std::runtime_error {
        public:
            using std::runtime_error::runtime_error;
    };

    /**
     * @brief Raised when an image-related logic error occurs.
     * 
     */
    class ImageError : public std::runtime_error {
        public:
            using std::runtime_error::runtime_error;
    };

}
