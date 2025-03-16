import decimal
from collections import defaultdict

class AffineConverter:
    def __init__(self, scale, offset):
        self.scale = scale
        self.offset = offset

    def convert(self, value):
        return value * self.scale + self.offset

    def invert(self):
        return AffineConverter(1 / self.scale, -self.offset / self.scale)

    def compose(self, other):
        return AffineConverter(self.scale * other.scale, self.offset + other.convert(0))

class Main:
    def __init__(self, basic_conversions):
        self.conversions = self.compute_all_conversions(basic_conversions)
        self.units = self.extract_units(self.conversions)

    def convert(self, input_unit, output_unit, value):
        if input_unit == output_unit:
            raise ValueError("Input and output units must be different.")

        conversion_key = (input_unit, output_unit)
        converter = self.conversions.get(conversion_key)

        if converter is None:
            raise KeyError(f"No converter for: {conversion_key}")

        result = converter.convert(value)
        return round(result, 2)

    def available_units(self):
        return self.units

    @staticmethod
    def put_if_needed(conversions, input_unit, output_unit, converter):
        if input_unit != output_unit:
            conversions.setdefault((input_unit, output_unit), converter)

    @staticmethod
    def add_inversions(known_conversions):
        res = {}
        for (input_unit, output_unit), converter in known_conversions.items():
            Main.put_if_needed(res, input_unit, output_unit, converter)
            Main.put_if_needed(res, output_unit, input_unit, converter.invert())
        return res

    @staticmethod
    def add_compositions(known_conversions):
        res = {}
        for (first_input, first_output), first_converter in known_conversions.items():
            Main.put_if_needed(res, first_input, first_output, first_converter)
            for (second_input, second_output), second_converter in known_conversions.items():
                if first_output == second_input:
                    composed_converter = second_converter.compose(first_converter)
                    Main.put_if_needed(res, first_input, second_output, composed_converter)
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
        for (input_unit, output_unit) in conversions.keys():
            res.add(input_unit)
            res.add(output_unit)
        return res

if __name__ == "__main__":
    basic_conversions = {
        ("Celsius", "Fahrenheit"): AffineConverter(9.0 / 5.0, 32.0),
        ("Kelvin", "Celsius"): AffineConverter(1.0, -273.15)
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
