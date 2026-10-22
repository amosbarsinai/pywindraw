import sys as _sys

from . import pywindraw as _native

color = _native.color
image = _native.image
sprite = _native.sprite
window = _native.window

for _name in ("color", "image", "sprite", "window"):
    _sys.modules[f"{__name__}.{_name}"] = globals()[_name]

__all__ = ["color", "image", "sprite", "window"]
__version__ = "0.1.0"
