from typing import Dict, Set, Tuple
from decimal import Decimal
import sys

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
        return self.key == other.key and self.value == other.value

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

class Main:
    def __init__(self, basic_conversions: Dict[Pair, AffineConverter]):
        self.conversions = self.compute_all_conversions(basic_conversions)
        self.units = self.extract_units(self.conversions)

    def convert(self, input_unit: str, output_unit: str, value: float) -> float:
        if input_unit == output_unit:
            raise ValueError("Input and output units must be different.")
        conversion_key = Pair.of(input_unit, output_unit)
        converter = self.conversions.get(conversion_key, None)
        if converter is None:
            raise KeyError(f"No converter for: {conversion_key}")
        result = converter.convert(value)
        return float(Decimal(str(result)).quantize(Decimal('0.00')))

    def available_units(self) -> Set[str]:
        return self.units

    @staticmethod
    def put_if_needed(conversions: Dict[Pair, AffineConverter], input_unit: str, output_unit: str, converter: AffineConverter):
        if input_unit != output_unit:
            conversions[Pair.of(input_unit, output_unit)] = converter

    @staticmethod
    def add_inversions(known_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        res = {}
        for input_unit, output_unit in known_conversions:
            Main.put_if_needed(res, input_unit, output_unit, known_conversions[Pair.of(input_unit, output_unit)])
            Main.put_if_needed(res, output_unit, input_unit, known_conversions[Pair.of(input_unit, output_unit)].invert())
        return res

    @staticmethod
    def add_compositions(known_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        res = {}
        for first in known_conversions:
            Main.put_if_needed(res, first.get_key(), first.get_value(), known_conversions[Pair.of(first.get_key(), first.get_value())])
            for second in known_conversions:
                if first.get_value() == second.get_key():
                    composed_converter = known_conversions[Pair.of(second.get_key(), second.get_value())].compose(known_conversions[Pair.of(first.get_key(), first.get_value())])
                    Main.put_if_needed(res, first.get_key(), second.get_value(), composed_converter)
        return res

    @staticmethod
    def compute_all_conversions(basic_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        tmp = basic_conversions
        res = Main.add_all(tmp)
        while res != tmp:
            tmp = res
            res = Main.add_all(tmp)
        return res

    @staticmethod
    def add_all(known_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        res = Main.add_inversions(known_conversions)
        return Main.add_compositions(res)

    @staticmethod
    def extract_units(conversions: Dict[Pair, AffineConverter]) -> Set[str]:
        res = set()
        for conversion in conversions:
            res.add(conversion.get_key())
            res.add(conversion.get_value())
        return res

    @staticmethod
    def main():
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
        except (ValueError, KeyError, ArithmeticError) as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    Main.main()
