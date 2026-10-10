#include <pybind11/pybind11.h>
#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "error.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_pywindraw, m) {
    m.doc() = "Graphics for Python with SFML";

    py::register_exception<pywindraw::WindowError>(m, "WindowError");

    py::class_<pywindraw::Window>(m, "Window")
        .def(py::init<std::string, int, int>())
        .def("update", &pywindraw::Window::update)
        .def("close", &pywindraw::Window::close)
        .def("is_open", &pywindraw::Window::is_open)
        .def("get_width", &pywindraw::Window::get_width).def("set_width", &pywindraw::Window::set_width).def("get_height", &pywindraw::Window::get_height).def("set_height", &pywindraw::Window::set_height)
        .def("get_color", &pywindraw::Window::get_color).def("set_color", &pywindraw::Window::set_color)
    ;
    py::class_<sf::Color>(m, "SfColor") /* let python touch sfcolors too */
        .def(py::init<std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>())
    ;
}
