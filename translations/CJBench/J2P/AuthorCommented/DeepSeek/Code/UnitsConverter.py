class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    @staticmethod
    def of(key, value):
        return Pair(key, value)

    def get_key(self):
        return self.key

    def get_value(self):
        return self.value

    def __eq__(self, other):
        if isinstance(other, Pair):
            return self.key == other.key and self.value == other.value
        return False

    def __hash__(self):
        return hash(self.key) * 31 + hash(self.value)

    def __repr__(self):
        return f"({self.key}, {self.value})"


class AffineConverter:
    def __init__(self, scale, offset):
        self.scale = scale
        self.offset = offset

    def convert(self, value):
        return self.scale * value + self.offset

    def invert(self):
        if self.scale == 0:
            raise ArithmeticError("Cannot invert a scale of zero.")
        return AffineConverter(1 / self.scale, -self.offset / self.scale)

    def compose(self, other):
        return AffineConverter(self.scale * other.scale, self.scale * other.offset + self.offset)

    def __repr__(self):
        return f"AffineConverter(scale={self.scale}, offset={self.offset})"


from decimal import Decimal
from typing import Dict, Set, Tuple
from collections import defaultdict
import sys


class Main:
    def __init__(self, basic_conversions: Dict[Pair, AffineConverter]):
        self.conversions = self.compute_all_conversions(basic_conversions)
        self.units = self.extract_units(self.conversions)

    def convert(self, input_unit: str, output_unit: str, value: float) -> float:
        if input_unit == output_unit:
            raise ValueError("Input and output units must be different.")
        conversion_key = Pair.of(input_unit, output_unit)
        converter = self.conversions.get(conversion_key)
        if converter is None:
            raise KeyError(f"No converter for: {conversion_key}")
        result = converter.convert(value)
        return float(Decimal(str(result)).quantize(Decimal('0.00')))

    def available_units(self) -> Set[str]:
        return self.units

    def put_if_needed(self, conversions: Dict[Pair, AffineConverter], input_unit: str, output_unit: str, converter: AffineConverter):
        if input_unit != output_unit:
            conversions[Pair.of(input_unit, output_unit)] = converter

    def add_inversions(self, known_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        res = {}
        for entry in known_conversions.items():
            input_unit, output_unit = entry[0].get_key(), entry[0].get_value()
            converter = entry[1]
            self.put_if_needed(res, input_unit, output_unit, converter)
            self.put_if_needed(res, output_unit, input_unit, converter.invert())
        return res

    def add_compositions(self, known_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        res = {}
        for first in known_conversions.items():
            first_key = first[0]
            self.put_if_needed(res, first_key.get_key(), first_key.get_value(), first[1])
            for second in known_conversions.items():
                second_key = second[0]
                if first_key.get_value() == second_key.get_key():
                    composed_converter = second[1].compose(first[1])
                    self.put_if_needed(res, first_key.get_key(), second_key.get_value(), composed_converter)
        return res

    def compute_all_conversions(self, basic_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        tmp = basic_conversions
        res = self.add_all(tmp)
        while len(res) != len(tmp):
            tmp = res
            res = self.add_all(tmp)
        return res

    def add_all(self, known_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        res = self.add_inversions(known_conversions)
        return self.add_compositions(res)

    def extract_units(self, conversions: Dict[Pair, AffineConverter]) -> Set[str]:
        res = set()
        for entry in conversions.items():
            res.add(entry[0].get_key())
            res.add(entry[0].get_value())
        return res


if __name__ == "__main__":
    basic_conversions = {
        Pair.of("Celsius", "Fahrenheit"): AffineConverter(9.0 / 5.0, 32.0),
        Pair.of("Kelvin", "Celsius"): AffineConverter(1.0, -273.15)
    }

    converter = Main(basic_conversions)

    input_unit = input()
    output_unit = input()
    value = float(input())

    try:
        result = converter.convert(input_unit, output_unit, value)
        print(f"Converted value: {result}")
    except (ValueError, KeyError) as e:
        print(f"Error: {e}")
