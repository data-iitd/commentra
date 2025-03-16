
import math

# Pair class to hold a key-value pair
class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    # Static factory method to create a Pair
    @staticmethod
    def of(key, value):
        return Pair(key, value)

    # Getter for the key
    def get_key(self):
        return self.key

    # Getter for the value
    def get_value(self):
        return self.value

    # Override equals method for proper comparison
    def __eq__(self, other):
        if self is other:
            return True
        if other is None or type(self) != type(other):
            return False
        return self.key == other.key and self.value == other.value

    # Override hashCode method for proper hashing
    def __hash__(self):
        return hash(self.key) * 31 + hash(self.value)

    # Override toString method for better representation
    def __str__(self):
        return "(" + str(self.key) + ", " + str(self.value) + ")"

# AffineConverter class to handle unit conversions
class AffineConverter:
    def __init__(self, scale, offset):
        self.scale = scale
        self.offset = offset

    # Method to convert a value using the scale and offset
    def convert(self, value):
        return self.scale * value + self.offset

    # Method to invert the conversion
    def invert(self):
        if self.scale == 0:
            raise ArithmeticError("Cannot invert a scale of zero.")
        return AffineConverter(1 / self.scale, -self.offset / self.scale)

    # Method to compose this converter with another
    def compose(self, other):
        return AffineConverter(self.scale * other.scale, self.scale * other.offset + self.offset)

    # Override toString method for better representation
    def __str__(self):
        return "AffineConverter(scale=" + str(self.scale) + ", offset=" + str(self.offset) + ")"

# Main class to handle unit conversions
class Main:
    # Constructor that initializes conversions and units based on provided basic conversions
    def __init__(self, basic_conversions):
        self.conversions = self.compute_all_conversions(basic_conversions)
        self.units = self.extract_units(self.conversions)

    # Method to convert a value from one unit to another
    def convert(self, input_unit, output_unit, value):
        # Check if input and output units are the same, which is not allowed
        if input_unit == output_unit:
            raise ValueError("Input and output units must be different.")
        # Create a key for the conversion
        conversion_key = Pair.of(input_unit, output_unit)
        # Perform the conversion using the appropriate converter
        result = self.conversions.get(conversion_key, None)
        if result is None:
            raise ValueError("No converter for: " + str(conversion_key))
        return round(result.convert(value), 2)

    # Method to retrieve the set of available units for conversion
    def available_units(self):
        return self.units

    # Helper method to add a conversion to the map if input and output units are different
    @staticmethod
    def put_if_needed(conversions, input_unit, output_unit, converter):
        if input_unit != output_unit:
            conversions[Pair.of(input_unit, output_unit)] = converter

    # Method to add inverses of known conversions to the conversion map
    @staticmethod
    def add_inversions(known_conversions):
        conversions = {}
        # Iterate through known conversions to add both directions
        for entry in known_conversions.items():
            input_unit = entry[0].get_key()
            output_unit = entry[0].get_value()
            converter = entry[1]
            Main.put_if_needed(conversions, input_unit, output_unit, converter)
            Main.put_if_needed(conversions, output_unit, input_unit, converter.invert())
        return conversions

    # Method to add compositions of known conversions to the conversion map
    @staticmethod
    def add_compositions(known_conversions):
        conversions = {}
        # Iterate through known conversions to find compositions
        for first in known_conversions.items():
            first_key = first[0]
            Main.put_if_needed(conversions, first_key.get_key(), first_key.get_value(), first[1])
            for second in known_conversions.items():
                second_key = second[0]
                # Check if the output unit of the first conversion matches the input unit of the second
                if first_key.get_value() == second_key.get_key():
                    composed_converter = second[1].compose(first[1])
                    Main.put_if_needed(conversions, first_key.get_key(), second_key.get_value(), composed_converter)
        return conversions

    # Method to compute all conversions by adding inverses and compositions iteratively
    @staticmethod
    def compute_all_conversions(basic_conversions):
        tmp = basic_conversions
        res = Main.add_all(tmp)
        # Continue adding conversions until no new conversions are found
        while len(res) != len(tmp):
            tmp = res
            res = Main.add_all(tmp)
        return res

    # Method to add all known conversions, including inverses and compositions
    @staticmethod
    def add_all(known_conversions):
        res = Main.add_inversions(known_conversions)
        return Main.add_compositions(res)

    # Method to extract unique units from the conversion map
    @staticmethod
    def extract_units(conversions):
        units = set()
        # Add both input and output units to the set
        for entry in conversions.items():
            units.add(entry[0].get_key())
            units.add(entry[0].get_value())
        return units

    # Main method to run the conversion program
    def main(self):
        # Initialize basic conversions
        basic_conversions = {Pair.of("Celsius", "Fahrenheit"): AffineConverter(9.0 / 5.0, 32.0),
                             Pair.of("Kelvin", "Celsius"): AffineConverter(1.0, -273.15)}
        # Create a converter instance with the basic conversions
        converter = Main(basic_conversions)
        # Read input unit, output unit, and value from the user
        input_unit = input()
        output_unit = input()
        value = float(input())
        try:
            # Perform the conversion and display the result
            result = converter.convert(input_unit, output_unit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            # Handle any exceptions that occur during conversion
            print("Error: " + str(e))

# Run the main method
Main().main()

