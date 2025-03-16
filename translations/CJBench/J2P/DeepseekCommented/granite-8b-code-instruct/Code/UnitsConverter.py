
import decimal

class Pair:
    # Generic Pair class to represent pairs of keys and values
    def __init__(self, key, value):
        self.key = key
        self.value = value

    @staticmethod
    def of(key, value):
        return Pair(key, value)

    def __eq__(self, other):
        return self.key == other.key and self.value == other.value

    def __hash__(self):
        return hash((self.key, self.value))

    def __str__(self):
        return f"({self.key}, {self.value})"

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
        return f"AffineConverter(scale={self.scale}, offset={self.offset})"

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
            raise ValueError(f"No converter for: {conversion_key}")
        # Computes the conversion using the AffineConverter and throws an exception if no converter is found
        return decimal.Decimal(result.convert(value))

    def available_units(self):
        return self.units

    @staticmethod
    def put_if_needed(conversions, input_unit, output_unit, converter):
        # Helper method to add conversions only if input and output units are different
        if input_unit!= output_unit:
            conversions[Pair.of(input_unit, output_unit)] = converter

    @staticmethod
    def add_inversions(known_conversions):
        # Helper method to add inversions of known conversions
        res = {}
        for input_unit, output_unit, converter in known_conversions:
            Main.put_if_needed(res, input_unit, output_unit, converter)
            Main.put_if_needed(res, output_unit, input_unit, converter.invert())
        return res

    @staticmethod
    def add_compositions(known_conversions):
        # Helper method to add compositions of known conversions
        res = {}
        for first_input_unit, first_output_unit, first_converter in known_conversions:
            Main.put_if_needed(res, first_input_unit, first_output_unit, first_converter)
            for second_input_unit, second_output_unit, second_converter in known_conversions:
                if first_output_unit == second_input_unit:
                    composed_converter = second_converter.compose(first_converter)
                    Main.put_if_needed(res, first_input_unit, second_output_unit, composed_converter)
        return res

    @staticmethod
    def compute_all_conversions(basic_conversions):
        known_conversions = basic_conversions
        res = Main.add_all(known_conversions)
        while len(res)!= len(known_conversions):
            known_conversions = res
            res = Main.add_all(known_conversions)
        return res

    @staticmethod
    def add_all(known_conversions):
        res = Main.add_inversions(known_conversions)
        return Main.add_compositions(res)

    @staticmethod
    def extract_units(conversions):
        units = set()
        for (input_unit, output_unit), _ in conversions.items():
            units.add(input_unit)
            units.add(output_unit)
        return units

if __name__ == "__main__":
    import sys
    basic_conversions = {
        ("Celsius", "Fahrenheit"): AffineConverter(9.0 / 5.0, 32.0),
        ("Kelvin", "Celsius"): AffineConverter(1.0, -273.15)
    }
    converter = Main(basic_conversions)
    input_unit = sys.stdin.readline().strip()
    output_unit = sys.stdin.readline().strip()
    value = float(sys.stdin.readline().strip())
    try:
        result = converter.convert(input_unit, output_unit, value)
        print(f"Converted value: {result}")
    except Exception as e:
        print(f"Error: {e}")

