
import math

class Pair:
    # Generic Pair class to represent pairs of keys and values
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __eq__(self, other):
        return self.key == other.key and self.value == other.value

    def __hash__(self):
        return hash(self.key) * 31 + hash(self.value)

    def __str__(self):
        return "(" + str(self.key) + ", " + str(self.value) + ")"

    @staticmethod
    def of(key, value):
        return Pair(key, value)

class AffineConverter:
    # Class to perform affine transformations (linear transformations with an offset)
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

class Main:
    # The Main class is the entry point of the application
    def __init__(self, basic_conversions):
        # Constructor initializes the conversions and units
        self.conversions = self.compute_all_conversions(basic_conversions)
        self.units = self.extract_units(self.conversions)

    def convert(self, input_unit, output_unit, value):
        # Method to convert a value from one unit to another
        if input_unit == output_unit:
            raise ValueError("Input and output units must be different.")
        # Throws an exception if the input and output units are the same
        conversion_key = Pair.of(input_unit, output_unit)
        result = self.conversions.get(conversion_key, None)
        if result is None:
            raise KeyError("No converter for: " + str(conversion_key))
        # Computes the conversion using the AffineConverter and throws an exception if no converter is found
        return round(result.convert(value), 2)
        # Formats the result to two decimal places

    def available_units(self):
        return self.units
    # Method to return all available units

    @staticmethod
    def put_if_needed(conversions, input_unit, output_unit, converter):
        # Helper method to add conversions only if input and output units are different
        if input_unit != output_unit:
            conversions[Pair.of(input_unit, output_unit)] = converter

    @staticmethod
    def add_inversions(known_conversions):
        # Helper method to add inversions of known conversions
        res = {}
        for entry in known_conversions.items():
            input_unit = entry[0].key
            output_unit = entry[0].value
            converter = entry[1]
            Main.put_if_needed(res, input_unit, output_unit, converter)
            Main.put_if_needed(res, output_unit, input_unit, converter.invert())
        return res

    @staticmethod
    def add_compositions(known_conversions):
        # Helper method to add compositions of known conversions
        res = {}
        for first in known_conversions.items():
            first_key = first[0]
            Main.put_if_needed(res, first_key.key, first_key.value, first[1])
            for second in known_conversions.items():
                second_key = second[0]
                if first_key.value == second_key.key:
                    composed_converter = second[1].compose(first[1])
                    Main.put_if_needed(res, first_key.key, second_key.value, composed_converter)
        return res

    @staticmethod
    def compute_all_conversions(basic_conversions):
        # Helper method to compute all possible conversions
        tmp = basic_conversions
        res = Main.add_all(tmp)
        while len(res) != len(tmp):
            tmp = res
            res = Main.add_all(tmp)
        return res

    @staticmethod
    def add_all(known_conversions):
        # Helper method to add inversions and compositions of known conversions
        res = Main.add_inversions(known_conversions)
        return Main.add_compositions(res)

    @staticmethod
    def extract_units(conversions):
        # Helper method to extract all units from the conversions map
        res = set()
        for entry in conversions.items():
            res.add(entry[0].key)
            res.add(entry[0].value)
        return res

    @staticmethod
    def main():
        # Main method to read input units, output units, and values from the user and convert the value
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
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e))

    if __name__ == "__main__":
        Main.main()

