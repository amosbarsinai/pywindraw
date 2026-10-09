from . import _pywindraw
from . import color

class Window:
    """Base class for Window objects."""
    def __init__(self, title: str, width: int = 600, height: int = 600) -> None:
        """Initialize the window."""
        self._window = _pywindraw.Window(title, width, height)

    def update(self) -> None:
        """Update the window and draw all new data."""
        self._window.update()

    def is_open(self) -> bool:
        """Return whether the window is open."""
        return self._window.is_open()

    def get_width(self) -> int:
        return self._window.get_width()

    def set_width(self, width: int) -> None:
        self._window.set_width(width)

    def get_height(self) -> int:
        return self._window.get_height()

    def set_height(self, height: int) -> None:
        self._window.set_height(height)

    def close(self) -> None:
        """Close the window and dispose of its elements."""
        self._window.close()

    def get_color(self) -> color.Color:
        """Returns the background color of the window."""
        return self._window.get_color()

    def set_color(self, color: color.Color) -> None:
        """Set the background color of the window."""
        self._window.set_color(color._color)
