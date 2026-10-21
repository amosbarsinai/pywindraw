//      Bindings for pybind11

#include "color.hpp"
#include "error.hpp"
#include "image.hpp"
#include "sprite.hpp"
#include "window.hpp"

#include <pybind11/pybind11.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace py = pybind11;

PYBIND11_MODULE(_pywindraw, m) {
    m.doc() = "Graphics for Python with SFML";

    py::register_exception<pywindraw::WindowError>(m, "WindowError").doc() =  "Logic errors related to window handling.";
    py::register_exception<pywindraw::ImageError>(m, "ImageError").doc() = "Logic errors related to image handling.";

    py::class_<pywindraw::Color>(m, "Color")
        .def(py::init<>(), "Initialize an opaque white color.")
        .def(
            py::init<float, float, float, float>(),
            py::arg("r"),
            py::arg("g"),
            py::arg("b"),
            py::arg("a") = 255 // expose a default argument for the alpha value to python, default value for alpha internally is unrelated and introduced to simplify development
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
        .doc() = "RGBA color."
    ;
    py::class_<pywindraw::Image>(m, "Image")
        .def(py::init<const std::string&>(), "Load an image from a file.")
        .def(py::init<pywindraw::Color, int, int>(), "Create an image with a uniform color.")
        .def("crop", &pywindraw::Image::crop, "Crop the image to an inner rectangle.")
        .def("__getitem__", &pywindraw::Image::get_pixel)
        .def("__setitem__", &pywindraw::Image::set_pixel)
        .def("__delitem__", &pywindraw::Image::del_pixel)
        .doc() = "Class used to handle images, attachable to sprites."
    ;
    py::class_<pywindraw::Sprite>(m, "Sprite")
        .def(py::init<const pywindraw::Image&>(), "Initialize a sprite from an image.")
        .doc() = "Class used to handle drawable, movable sprites."
    ;

    py::class_<pywindraw::Window>(m, "Window")
        .def(py::init<std::string, int, int, bool>(),
            py::arg("title"),
            py::arg("initial_window_width"),
            py::arg("initial_window_height"),
            py::arg("resizable") = false,
            "Initialize a window from some basic parameters."
        )
        .def("update", &pywindraw::Window::update, "Update, draw and display the window.")
        .def("close", &pywindraw::Window::close, "Close and destroy the window.")
        .def("is_open", &pywindraw::Window::is_open, "Return whether the window is open.")
        .def("is_focused", &pywindraw::Window::is_focused, "Return whether the window is focused.")
        .def("request_focus", &pywindraw::Window::request_focus, "Attempt to focus this window.")
        .def("set_title", &pywindraw::Window::set_title, "Set the title of the window.")
        .def_property("width", &pywindraw::Window::get_width, &pywindraw::Window::set_width)
        .def_property("height", &pywindraw::Window::get_height, &pywindraw::Window::set_height)
        .def("get_color", &pywindraw::Window::get_color).def("set_color", &pywindraw::Window::set_color)
        .def("set_icon", &pywindraw::Window::set_icon, "Set the icon of the window.")
        .def("get_delta", &pywindraw::Window::get_delta, "Return the elapsed time since the last frame was drawn.")
        .def_readwrite("sprites", &pywindraw::Window::sprites)
        .doc() = "Class used to handle windows, containing sprites."
    ;
}
