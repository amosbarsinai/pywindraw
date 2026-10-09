#pragma once

#include <stdexcept>

class WindowError : public std::runtime_error {
    public:
        using std::runtime_error::runtime_error;
};
