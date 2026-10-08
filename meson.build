project(
  'my_pybind11_meson_project', 'cpp',
  version : '0.1.0',
  default_options : ['cpp_std=c++17']
)

py = import('python').find_installation(pure: false)
pybind11_dep = dependency('pybind11')

sources = files('src/bindings.cpp', 'src/my_impl.cpp')
inc = include_directories('include')

py.extension_module(
  '_my_cpp_extension_module',
  sources,
  include_directories: inc,
  dependencies: [pybind11_dep],
  install: true,
  subdir: 'my_pybind11_meson_project'
)

py.install_sources(
  'my_pybind11_meson_project/__init__.py',
  subdir: 'my_pybind11_meson_project'
)
