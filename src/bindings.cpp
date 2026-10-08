#include <pybind11/pybind11.h>
#include "window.hpp"
#include "error.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_pywindraw, m) {
    m.doc() = "Graphics for Python with SFML";

    py::register_exception<WindowError>(m, "WindowError");

    py::class_<Window>(m, "Window")
        .def(py::init<std::string, int, int>())
        .def("update", &Window::update)
        .def("close", &Window::close)
        .def("get_width", &Window::get_width).def("set_width", &Window::set_width).def("get_height", &Window::get_height).def("set_height", &Window::set_height)
    ;
}
