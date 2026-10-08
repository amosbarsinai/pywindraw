from ._my_cpp_extension_module import add

def add_three_numbers(a, b, c):
    return add(add(a, b), c)
