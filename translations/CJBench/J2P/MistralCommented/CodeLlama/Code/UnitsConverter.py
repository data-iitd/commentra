
import decimal

class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __eq__(self, other):
        return self.key == other.key and self.value == other.value

    def __hash__(self):
        return hash(self.key) ^ hash(self.value)

class AffineConverter:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def convert(self, value):
        return self.a * value + self.b

    def invert(self):
        return AffineConverter(1 / self.a, -self.b / self.a)

    def compose(self, other):
        return AffineConverter(self.a * other.a, self.a * other.b + self.b)

class Main:
    def __init__(self, basic_conversions):
        self.conversions = self.compute_all_conversions(basic_conversions)
        self.units = self.extract_units(self.conversions)

    def convert(self, input_unit, output_unit, value):
        if input_unit == output_unit:
            raise ValueError("Input and output units must be different.")

        # Look up the conversion from input_unit to output_unit in the conversions map
        conversion_key = Pair(input_unit, output_unit)
        converter = self.conversions.get(conversion_key)

        if converter is None:
            raise KeyError("No converter for: " + str(conversion_key))

        result = converter.convert(value)
        return float(decimal.Decimal(str(result)).quantize(decimal.Decimal('0.01')))

    def available_units(self):
        return self.units

    def put_if_needed(conversions, input_unit, output_unit, converter):
        if input_unit != output_unit:
            conversions[Pair(input_unit, output_unit)] = converter

    def add_inversions(known_conversions):
        conversions = {}
        for entry in known_conversions.items():
            input_unit = entry[0].key
            output_unit = entry[0].value
            converter = entry[1]
            put_if_needed(conversions, input_unit, output_unit, converter)
            put_if_needed(conversions, output_unit, input_unit, converter.invert())
        return conversions

    def add_compositions(known_conversions):
        conversions = {}
        for first in known_conversions.items():
            first_key = first[0]
            put_if_needed(conversions, first_key.key, first_key.value, first[1])
            for second in known_conversions.items():
                second_key = second[0]
                if first_key.value == second_key.key:
                    composed_converter = second[1].compose(first[1])
                    put_if_needed(conversions, first_key.key, second_key.value, composed_converter)
        return conversions

    def compute_all_conversions(basic_conversions):
        tmp = basic_conversions
        conversions = add_all(tmp)
        while len(conversions) != len(tmp):
            tmp = conversions
            conversions = add_all(tmp)
        return conversions

    def add_all(known_conversions):
        conversions = add_inversions(known_conversions)
        return add_compositions(conversions)

    def extract_units(conversions):
        units = set()
        for entry in conversions.items():
            units.add(entry[0].key)
            units.add(entry[0].value)
        return units

    # Main method to read user input and perform unit conversions
    def main():
        # Initialize a map of basic conversions
        basic_conversions = {}
        basic_conversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basic_conversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)

        # Create an instance of Main with the basic conversions
        converter = Main(basic_conversions)

        # Read user input for input_unit, output_unit, and value
        input_unit = input()
        output_unit = input()
        value = float(input())

        try:
            # Perform the unit conversion and print the result
            result = converter.convert(input_unit, output_unit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            # Print an error message if an exception occurs
            print("Error: " + str(e))

    # Run the main method
    main()

