from . import _pywindraw

class Window:
    """Base class for Window objects."""
    def __init__(self, title: str, width: int = 600, height: int = 600) -> None:
        """Initialize the window."""
        self._window = _pywindraw.Window(title, width, height)

    def update(self) -> None:
        """Update the window and draw all new data."""
        self._window.update()

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
