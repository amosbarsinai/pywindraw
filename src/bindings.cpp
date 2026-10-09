#include <pybind11/pybind11.h>
#include <SFML/Graphics.hpp>
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
        .def("is_open", &Window::is_open)
        .def("get_width", &Window::get_width).def("set_width", &Window::set_width).def("get_height", &Window::get_height).def("set_height", &Window::set_height)
        .def("get_color", &Window::get_color).def("set_color", &Window::set_color)
    ;
    py::class_<sf::Color>(m, "SfColor") /* let python touch sfcolors too */
        .def(py::init<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>())
    ;
}
