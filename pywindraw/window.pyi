from .color import Color
from .sprite import Sprite

class Window:
    """Basic window class."""

    sprites: dict[Sprite, list[float]]

    def __init__(self, title: str, width: int, height: int):
        """Initialize a new window with default SFML properties."""
        ...

    def update(self) -> None:
        """Update the window and draw new frames. This needs to be called inside the game loop to update the window state."""
        ...

    def close(self) -> None:
        """Close this window. After calling this function, window operations and updates are not permitted and will raise a WindowError."""
        ...

    def is_open(self) -> bool:
        """Return whether the window is open. Can be used as a condition for a game loop."""
        ...

    def get_width(self) -> int:
        """Return the current width of the window, in pixels."""
        ...

    def set_width(self, width: int) -> None:
        """Set the current width of the window."""
        ...

    def get_height(self) -> int:
        """Return the current height of the window, in pixels."""
        ...

    def set_height(self, height: int) -> None:
        """Set the current height of the window."""
        ...

    def get_color(self) -> Color:
        """Return the background color of the window."""
        ...

    def set_color(self, color: Color) -> None:
        """Set the background color of the window."""
        ...

    def get_delta(self) -> float:
        """Returns the elapsed time since the last frame."""
        ...
