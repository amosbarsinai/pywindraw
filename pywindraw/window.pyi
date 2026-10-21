from .color import Color
from .sprite import Sprite

class Window:
    """Basic window class."""

    width: int
    height: int

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

    def is_focused(self) -> bool:
        """Return whether the window is focused."""
        ...

    def request_focus(self) -> None:
        """Attempt to focus this window."""
        ...

    def set_title(self, title: str) -> None:
        """Set the title of this window."""
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
