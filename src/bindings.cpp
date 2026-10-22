//      Bindings for pybind11

#include "color.hpp"
#include "error.hpp"
#include "image.hpp"
#include "sprite.hpp"
#include "window.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/native_enum.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace py = pybind11;

PYBIND11_MODULE(pywindraw, m) {
    m.doc() = "Graphics for Python with SFML";

    auto sub_color = m.def_submodule("color", "Color-related objects and definitions");

    py::class_<pywindraw::color::Color>(sub_color, "Color")
        .def(py::init<>(), "Initialize an opaque white color.")
        .def(
            py::init<float, float, float, float>(),
            py::arg("r"),
            py::arg("g"),
            py::arg("b"),
            py::arg("a") = 255 // expose a default argument for the alpha value to python, default value for alpha internally is unrelated and introduced to simplify development
        )
        .def_property("red", &pywindraw::color::Color::get_r, &pywindraw::color::Color::set_r)
        .def_property("green", &pywindraw::color::Color::get_g, &pywindraw::color::Color::set_g)
        .def_property("blue", &pywindraw::color::Color::get_b, &pywindraw::color::Color::set_b)
        .def_readonly_static("RED", &pywindraw::color::Color::RED)
        .def_readonly_static("GREEN", &pywindraw::color::Color::GREEN)
        .def_readonly_static("BLUE", &pywindraw::color::Color::BLUE)
        .def_readonly_static("YELLOW", &pywindraw::color::Color::YELLOW)
        .def_readonly_static("CYAN", &pywindraw::color::Color::CYAN)
        .def_readonly_static("MAGENTA", &pywindraw::color::Color::MAGENTA)
        .def_readonly_static("ORANGE", &pywindraw::color::Color::ORANGE)
        .def_readonly_static("BROWN", &pywindraw::color::Color::BROWN)
        .def_readonly_static("BLACK", &pywindraw::color::Color::BLACK)
        .def_readonly_static("GREY", &pywindraw::color::Color::GREY)
        .def_readonly_static("WHITE", &pywindraw::color::Color::WHITE)
        .doc() = "RGBA color."
    ;

    auto sub_error = m.def_submodule("error", "Specific error types");

    py::register_exception<pywindraw::error::WindowError>(sub_error, "WindowError").doc() =  "Logic errors related to window handling.";
    py::register_exception<pywindraw::error::ImageError>(sub_error, "ImageError").doc() = "Logic errors related to image handling.";

    auto sub_image = m.def_submodule("image", "Image-related objects and definitions.");

    py::class_<pywindraw::image::Image>(sub_image, "Image")
        .def(py::init<const std::string&>(), "Load an image from a file.")
        .def(py::init<pywindraw::color::Color, int, int>(), "Create an image with a uniform color.")
        .def("crop", &pywindraw::image::Image::crop, "Crop the image to an inner rectangle.")
        .def("__getitem__", &pywindraw::image::Image::get_pixel)
        .def("__setitem__", &pywindraw::image::Image::set_pixel)
        .def("__delitem__", &pywindraw::image::Image::del_pixel)
        .doc() = "Class used to handle images, attachable to sprites."
    ;
    
    auto keyboard = m.def_submodule("keyboard", "Submodule containing keyboard data.");

    py::native_enum<sf::Keyboard::Key>(keyboard, "Key", "enum.IntEnum")
        .value("A", sf::Keyboard::Key::A)
        .value("B", sf::Keyboard::Key::B)
        .value("C", sf::Keyboard::Key::C)
        .value("D", sf::Keyboard::Key::D)
        .value("E", sf::Keyboard::Key::E)
        .value("F", sf::Keyboard::Key::F)
        .value("G", sf::Keyboard::Key::G)
        .value("H", sf::Keyboard::Key::H)
        .value("I", sf::Keyboard::Key::I)
        .value("J", sf::Keyboard::Key::J)
        .value("K", sf::Keyboard::Key::K)
        .value("L", sf::Keyboard::Key::L)
        .value("M", sf::Keyboard::Key::M)
        .value("N", sf::Keyboard::Key::N)
        .value("O", sf::Keyboard::Key::O)
        .value("P", sf::Keyboard::Key::P)
        .value("Q", sf::Keyboard::Key::Q)
        .value("R", sf::Keyboard::Key::R)
        .value("S", sf::Keyboard::Key::S)
        .value("T", sf::Keyboard::Key::T)
        .value("U", sf::Keyboard::Key::U)
        .value("V", sf::Keyboard::Key::V)
        .value("W", sf::Keyboard::Key::W)
        .value("X", sf::Keyboard::Key::X)
        .value("Y", sf::Keyboard::Key::Y)
        .value("Z", sf::Keyboard::Key::Z)
        .value("Num0", sf::Keyboard::Key::Num0)
        .value("Num1", sf::Keyboard::Key::Num1)
        .value("Num2", sf::Keyboard::Key::Num2)
        .value("Num3", sf::Keyboard::Key::Num3)
        .value("Num4", sf::Keyboard::Key::Num4)
        .value("Num5", sf::Keyboard::Key::Num5)
        .value("Num6", sf::Keyboard::Key::Num6)
        .value("Num7", sf::Keyboard::Key::Num7)
        .value("Num8", sf::Keyboard::Key::Num8)
        .value("Num9", sf::Keyboard::Key::Num9)
        .value("Escape", sf::Keyboard::Key::Escape)
        .value("LControl", sf::Keyboard::Key::LControl)
        .value("LShift", sf::Keyboard::Key::LShift)
        .value("LAlt", sf::Keyboard::Key::LAlt)
        .value("LSystem", sf::Keyboard::Key::LSystem)
        .value("RControl", sf::Keyboard::Key::RControl)
        .value("RShift", sf::Keyboard::Key::RShift)
        .value("RAlt", sf::Keyboard::Key::RAlt)
        .value("RSystem", sf::Keyboard::Key::RSystem)
        .value("Menu", sf::Keyboard::Key::Menu)
        .value("LBracket", sf::Keyboard::Key::LBracket)
        .value("RBracket", sf::Keyboard::Key::RBracket)
        .value("Semicolon", sf::Keyboard::Key::Semicolon)
        .value("Comma", sf::Keyboard::Key::Comma)
        .value("Period", sf::Keyboard::Key::Period)
        .value("Slash", sf::Keyboard::Key::Slash)
        .value("Backslash", sf::Keyboard::Key::Backslash)
        .value("Equal", sf::Keyboard::Key::Equal)
        .value("Hyphen", sf::Keyboard::Key::Hyphen)
        .value("Space", sf::Keyboard::Key::Space)
        .value("Enter", sf::Keyboard::Key::Enter)
        .value("Backspace", sf::Keyboard::Key::Backspace)
        .value("Tab", sf::Keyboard::Key::Tab)
        .value("PageUp", sf::Keyboard::Key::PageUp)
        .value("PageDown", sf::Keyboard::Key::PageDown)
        .value("End", sf::Keyboard::Key::End)
        .value("Home", sf::Keyboard::Key::Home)
        .value("Insert", sf::Keyboard::Key::Insert)
        .value("Delete", sf::Keyboard::Key::Delete)
        .value("Add", sf::Keyboard::Key::Add)
        .value("Subtract", sf::Keyboard::Key::Subtract)
        .value("Multiply", sf::Keyboard::Key::Multiply)
        .value("Divide", sf::Keyboard::Key::Divide)
        .value("Left", sf::Keyboard::Key::Left)
        .value("Right", sf::Keyboard::Key::Right)
        .value("Up", sf::Keyboard::Key::Up)
        .value("Down", sf::Keyboard::Key::Down)
        .value("Numpad0", sf::Keyboard::Key::Numpad0)
        .value("Numpad1", sf::Keyboard::Key::Numpad1)
        .value("Numpad2", sf::Keyboard::Key::Numpad2)
        .value("Numpad3", sf::Keyboard::Key::Numpad3)
        .value("Numpad4", sf::Keyboard::Key::Numpad4)
        .value("Numpad5", sf::Keyboard::Key::Numpad5)
        .value("Numpad6", sf::Keyboard::Key::Numpad6)
        .value("Numpad7", sf::Keyboard::Key::Numpad7)
        .value("Numpad8", sf::Keyboard::Key::Numpad8)
        .value("Numpad9", sf::Keyboard::Key::Numpad9)
        .value("F1", sf::Keyboard::Key::F1)
        .value("F2", sf::Keyboard::Key::F2)
        .value("F3", sf::Keyboard::Key::F3)
        .value("F4", sf::Keyboard::Key::F4)
        .value("F5", sf::Keyboard::Key::F5)
        .value("F6", sf::Keyboard::Key::F6)
        .value("F7", sf::Keyboard::Key::F7)
        .value("F8", sf::Keyboard::Key::F8)
        .value("F9", sf::Keyboard::Key::F9)
        .value("F10", sf::Keyboard::Key::F10)
        .value("F11", sf::Keyboard::Key::F11)
        .value("F12", sf::Keyboard::Key::F12)
        .value("F13", sf::Keyboard::Key::F13)
        .value("F14", sf::Keyboard::Key::F14)
        .value("F15", sf::Keyboard::Key::F15)
        .value("Pause", sf::Keyboard::Key::Pause)
        .finalize();

    auto sub_sprite = m.def_submodule("sprite", "Sprite-related objects and definitions.");

    py::class_<pywindraw::sprite::Sprite>(sub_sprite, "Sprite")
        .def(py::init<const pywindraw::image::Image&>(), "Initialize a sprite from an image.")
        .doc() = "Class used to handle drawable, movable sprites."
    ;

    auto sub_window = m.def_submodule("window", "Window-related objects and definitions.");

    py::class_<pywindraw::window::Window>(sub_window, "Window")
        .def(py::init<std::string, int, int, bool>(),
            py::arg("title"),
            py::arg("initial_window_width"),
            py::arg("initial_window_height"),
            py::arg("resizable") = false,
            "Initialize a window from some basic parameters."
        )
        .def("update", &pywindraw::window::Window::update, "Update, draw and display the window.")
        .def("close", &pywindraw::window::Window::close, "Close and destroy the window.")
        .def("is_open", &pywindraw::window::Window::is_open, "Return whether the window is open.")
        .def("is_focused", &pywindraw::window::Window::is_focused, "Return whether the window is focused.")
        .def("request_focus", &pywindraw::window::Window::request_focus, "Attempt to focus this window.")
        .def("set_title", &pywindraw::window::Window::set_title, "Set the title of the window.")
        .def_property("width", &pywindraw::window::Window::get_width, &pywindraw::window::Window::set_width)
        .def_property("height", &pywindraw::window::Window::get_height, &pywindraw::window::Window::set_height)
        .def("get_color", &pywindraw::window::Window::get_color).def("set_color", &pywindraw::window::Window::set_color)
        .def("set_icon", &pywindraw::window::Window::set_icon, "Set the icon of the window.")
        .def("get_delta", &pywindraw::window::Window::get_delta, "Return the elapsed time since the last frame was drawn.")
        .def_readwrite("sprites", &pywindraw::window::Window::sprites)
        .doc() = "Class used to handle windows, containing sprites."
    ;

}
