project(
  'my_pybind11_meson_project', 'cpp',
  version : '0.1.0',
  default_options : ['cpp_std=c++17']
)

py = import('python').find_installation(pure: false)
pybind11_dep = dependency('pybind11')
sfml_graphics_dep = dependency('sfml-graphics')

sources = files('src/bindings.cpp', 'src/window.cpp', 'src/color.cpp')
inc = include_directories('include')

py.extension_module(
  '_pywindraw',
  sources,
  include_directories: inc,
  dependencies: [pybind11_dep, sfml_graphics_dep],
  install: true,
  subdir: 'pywindraw'
)

py.install_sources(
  'pywindraw/__init__.py',
  'pywindraw/color.py',
  'pywindraw/window.py',
  subdir: 'pywindraw'
)
