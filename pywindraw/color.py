from . import _pywindraw

class Color:
    def __init__(self, r: int, g: int, b: int, a: int = 255):
        self._color: _pywindraw.SfColor = _pywindraw.SfColor(int(r), int(g), int(b), int(a))
    def _from_sf(self, sfcolor: _pywindraw.SfColor):
        self._color = sfcolor
