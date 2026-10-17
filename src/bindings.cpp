#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "window.hpp"
#include "color.hpp"
#include "error.hpp"
#include "image.hpp"
#include "sprite.hpp"

namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<pywindraw::Sprite>);

PYBIND11_MODULE(_pywindraw, m) {
    m.doc() = "Graphics for Python with SFML";

    py::register_exception<pywindraw::WindowError>(m, "WindowError");

    py::class_<pywindraw::Color>(m, "Color")
        .def(py::init<>())
        .def(
            py::init<float, float, float, float>(),
            py::arg("r"),
            py::arg("g"),
            py::arg("b"),
            py::arg("a") = 255
        )
        .def_property("red", &pywindraw::Color::get_r, &pywindraw::Color::set_r)
        .def_property("green", &pywindraw::Color::get_g, &pywindraw::Color::set_g)
        .def_property("blue", &pywindraw::Color::get_b, &pywindraw::Color::set_b)
        .def_readonly_static("RED", &pywindraw::Color::RED)
        .def_readonly_static("GREEN", &pywindraw::Color::GREEN)
        .def_readonly_static("BLUE", &pywindraw::Color::BLUE)
        .def_readonly_static("YELLOW", &pywindraw::Color::YELLOW)
        .def_readonly_static("CYAN", &pywindraw::Color::CYAN)
        .def_readonly_static("MAGENTA", &pywindraw::Color::MAGENTA)
        .def_readonly_static("ORANGE", &pywindraw::Color::ORANGE)
        .def_readonly_static("BROWN", &pywindraw::Color::BROWN)
        .def_readonly_static("BLACK", &pywindraw::Color::BLACK)
        .def_readonly_static("GREY", &pywindraw::Color::GREY)
        .def_readonly_static("WHITE", &pywindraw::Color::WHITE)
    ;
    py::class_<pywindraw::Image>(m, "Image")
        .def(py::init<std::string&>())
        .def(py::init<pywindraw::Color, int, int>())
        .def("__getitem__", &pywindraw::Image::get_pixel)
        .def("__setitem__", &pywindraw::Image::set_pixel)
        .def("__delitem__", &pywindraw::Image::del_pixel)
    ;
    py::class_<pywindraw::Sprite>(m, "Sprite")
        .def(py::init<pywindraw::Image>())
    ;
    py::bind_vector<std::vector<pywindraw::Sprite>>(m, "SpriteVector");
    py::class_<pywindraw::Window>(m, "Window")
        .def(py::init<std::string, int, int>())
        .def("update", &pywindraw::Window::update)
        .def("close", &pywindraw::Window::close)
        .def("is_open", &pywindraw::Window::is_open)
        .def("get_width", &pywindraw::Window::get_width)
        .def("set_width", &pywindraw::Window::set_width)
        .def("get_height", &pywindraw::Window::get_height)
        .def("set_height", &pywindraw::Window::set_height)
        .def("get_color", &pywindraw::Window::get_color).def("set_color", &pywindraw::Window::set_color)
        .def("set_icon", &pywindraw::Window::set_icon)
        .def_readwrite("sprites", &pywindraw::Window::sprites);
    ;
}
