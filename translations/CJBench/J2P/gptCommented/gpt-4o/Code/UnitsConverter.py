import decimal
from collections import defaultdict

class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    @staticmethod
    def of(key, value):
        return Pair(key, value)

    def __eq__(self, other):
        return isinstance(other, Pair) and self.key == other.key and self.value == other.value

    def __hash__(self):
        return hash((self.key, self.value))

    def __str__(self):
        return f"({self.key}, {self.value})"


class AffineConverter:
    def __init__(self, scale, offset):
        self.scale = scale
        self.offset = offset

    def convert(self, value):
        return self.scale * value + self.offset

    def invert(self):
        if self.scale == 0:
            raise ZeroDivisionError("Cannot invert a scale of zero.")
        return AffineConverter(1 / self.scale, -self.offset / self.scale)

    def compose(self, other):
        return AffineConverter(self.scale * other.scale, self.scale * other.offset + self.offset)

    def __str__(self):
        return f"AffineConverter(scale={self.scale}, offset={self.offset})"


class Main:
    def __init__(self, basic_conversions):
        self.conversions = self.compute_all_conversions(basic_conversions)
        self.units = self.extract_units(self.conversions)

    def convert(self, input_unit, output_unit, value):
        if input_unit == output_unit:
            raise ValueError("Input and output units must be different.")
        conversion_key = Pair.of(input_unit, output_unit)
        if conversion_key not in self.conversions:
            raise KeyError(f"No converter for: {conversion_key}")
        result = self.conversions[conversion_key].convert(value)
        return round(result, 2)

    def available_units(self):
        return self.units

    @staticmethod
    def put_if_needed(conversions, input_unit, output_unit, converter):
        if input_unit != output_unit:
            conversions[Pair.of(input_unit, output_unit)] = converter

    @staticmethod
    def add_inversions(known_conversions):
        res = {}
        for key, converter in known_conversions.items():
            input_unit = key.key
            output_unit = key.value
            Main.put_if_needed(res, input_unit, output_unit, converter)
            Main.put_if_needed(res, output_unit, input_unit, converter.invert())
        return res

    @staticmethod
    def add_compositions(known_conversions):
        res = {}
        for first_key, first_converter in known_conversions.items():
            Main.put_if_needed(res, first_key.key, first_key.value, first_converter)
            for second_key, second_converter in known_conversions.items():
                if first_key.value == second_key.key:
                    composed_converter = second_converter.compose(first_converter)
                    Main.put_if_needed(res, first_key.key, second_key.value, composed_converter)
        return res

    @staticmethod
    def compute_all_conversions(basic_conversions):
        tmp = basic_conversions
        res = Main.add_all(tmp)
        while len(res) != len(tmp):
            tmp = res
            res = Main.add_all(tmp)
        return res

    @staticmethod
    def add_all(known_conversions):
        res = Main.add_inversions(known_conversions)
        return Main.add_compositions(res)

    @staticmethod
    def extract_units(conversions):
        res = set()
        for key in conversions.keys():
            res.add(key.key)
            res.add(key.value)
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
    except Exception as e:
        print(f"Error: {e}")

# <END-OF-CODE>
