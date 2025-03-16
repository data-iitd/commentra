from typing import Dict, Set, Tuple
from decimal import Decimal
import sys

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    @staticmethod
    def of(first, second):
        return Pair(first, second)

class AffineConverter:
    def __init__(self, slope, intercept):
        self.slope = slope
        self.intercept = intercept

    def convert(self, value):
        return self.slope * value + self.intercept

    def invert(self):
        return AffineConverter(1 / self.slope, -self.intercept / self.slope)

    def compose(self, other):
        new_slope = self.slope * other.slope
        new_intercept = self.slope * other.intercept + self.intercept
        return AffineConverter(new_slope, new_intercept)

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
            raise ValueError(f"No converter for: {conversion_key}")

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
        for key, converter in known_conversions.items():
            input_unit, output_unit = key.first, key.second
            Main.put_if_needed(res, input_unit, output_unit, converter)
            Main.put_if_needed(res, output_unit, input_unit, converter.invert())
        return res

    @staticmethod
    def add_compositions(known_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        res = {}
        for first_key, first_converter in known_conversions.items():
            input_unit, output_unit = first_key.first, first_key.second
            Main.put_if_needed(res, input_unit, output_unit, first_converter)
            for second_key, second_converter in known_conversions.items():
                if first_key.second == second_key.first:
                    composed_converter = second_converter.compose(first_converter)
                    Main.put_if_needed(res, first_key.first, second_key.second, composed_converter)
        return res

    @staticmethod
    def compute_all_conversions(basic_conversions: Dict[Pair, AffineConverter]) -> Dict[Pair, AffineConverter]:
        tmp = basic_conversions
        res = Main.add_all(tmp)
        while len(res) != len(tmp):
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
        for key in conversions.keys():
            res.add(key.first)
            res.add(key.second)
        return res

    @staticmethod
    def main():
        # Initialize a map of basic conversions
        basic_conversions = {
            Pair.of("Celsius", "Fahrenheit"): AffineConverter(9 / 5, 32),
            Pair.of("Kelvin", "Celsius"): AffineConverter(1, -273.15)
        }

        # Create an instance of Main with the basic conversions
        converter = Main(basic_conversions)

        # Read user input for inputUnit, outputUnit, and value
        input_unit = input()
        output_unit = input()
        value = float(input())

        try:
            # Perform the unit conversion and print the result
            result = converter.convert(input_unit, output_unit, value)
            print(f"Converted value: {result}")
        except Exception as e:
            # Print an error message if an exception occurs
            print(f"Error: {e}")

if __name__ == "__main__":
    Main.main()
