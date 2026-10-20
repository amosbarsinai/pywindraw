from .color import Color
from typing import overload

class Image:
    """Class for handling images, stored in system RAM and cached in VRAM."""
    @overload
    def __init__(self, filepath: str):
        """Initialize an image from a path to an image file."""
        ...
    @overload
    def __init__(self, color: Color, width: int, height: int):
        """Initialize an image with a monochrome."""
        ...

    def crop(self, x: int, y: int, width: int, height: int):
        """Crop this image to an inner rectangle."""

    def __getitem__(self, key: tuple[int, int]) -> Color:
        """Return the color of the pixel at [x, y]."""
        ...
    def __setitem__(self, key: tuple[int, int], color: Color) -> None:
        """Set the color of the pixel at [x, y]."""
        ...
    def __delitem__(self, key: tuple[int, int]) -> None:
        """Set the color of the pixel at [x, y] to be 0, 0, 0, 0 (transparent)."""
