import math

class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __eq__(self, other):
        return self.key == other.key and self.value == other.value

    def __hash__(self):
        return hash(self.key) * 31 + hash(self.value)

    def __str__(self):
        return "(" + str(self.key) + ", " + str(self.value) + ")"

    def __repr__(self):
        return "Pair(" + repr(self.key) + ", " + repr(self.value) + ")"


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

    def __str__(self):
        return "AffineConverter(scale=" + str(self.scale) + ", offset=" + str(self.offset) + ")"

    def __repr__(self):
        return "AffineConverter(" + repr(self.scale) + ", " + repr(self.offset) + ")"


class Main:
    def __init__(self, basic_conversions):
        self.conversions = self.compute_all_conversions(basic_conversions)
        self.units = self.extract_units(self.conversions)

    def convert(self, input_unit, output_unit, value):
        if input_unit == output_unit:
            raise ValueError("Input and output units must be different.")
        conversion_key = Pair(input_unit, output_unit)
        result = self.conversions.get(conversion_key, None)
        if result is None:
            raise ValueError("No converter for: " + str(conversion_key))
        return result.convert(value)

    def available_units(self):
        return self.units

    def compute_all_conversions(self, basic_conversions):
        tmp = basic_conversions
        res = self.add_all(tmp)
        while len(res) != len(tmp):
            tmp = res
            res = self.add_all(tmp)
        return res

    def add_all(self, known_conversions):
        res = self.add_inversions(known_conversions)
        return self.add_compositions(res)

    def add_inversions(self, known_conversions):
        res = {}
        for entry in known_conversions.items():
            input_unit = entry[0].key
            output_unit = entry[0].value
            converter = entry[1]
            self.put_if_needed(res, input_unit, output_unit, converter)
            self.put_if_needed(res, output_unit, input_unit, converter.invert())
        return res

    def put_if_needed(self, conversions, input_unit, output_unit, converter):
        if input_unit != output_unit:
            conversions[Pair(input_unit, output_unit)] = converter

    def add_compositions(self, known_conversions):
        res = {}
        for first in known_conversions.items():
            first_key = first[0]
            self.put_if_needed(res, first_key.key, first_key.value, first[1])
            for second in known_conversions.items():
                second_key = second[0]
                if first_key.value == second_key.key:
                    composed_converter = second[1].compose(first[1])
                    self.put_if_needed(res, first_key.key, second_key.value, composed_converter)
        return res

    def extract_units(self, conversions):
        res = set()
        for entry in conversions.items():
            res.add(entry[0].key)
            res.add(entry[0].value)
        return res

    def main(self):
        scanner = input()
        basic_conversions = {}

        basic_conversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basic_conversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)

        converter = Main(basic_conversions)

        input_unit = input()

        output_unit = input()

        value = float(input())

        try:
            result = converter.convert(input_unit, output_unit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e))

        scanner.close()

    def __init__(self):
        self.main()


if __name__ == "__main__":
    Main()

