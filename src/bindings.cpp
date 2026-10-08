#include <pybind11/pybind11.h>
#include "my_header.hpp"

PYBIND11_MODULE(_my_cpp_extension_module, m) {
    m.doc() = "My C++ module exposed to Python using pybind11";

    m.def("add", &add, "Add two numbers");
}
