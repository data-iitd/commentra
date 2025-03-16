

import decimal

class AffineConverter:
    def __init__(self, slope, intercept):
        self.slope = slope
        self.intercept = intercept

    def convert(self, value):
        return self.slope * value + self.intercept

    def invert(self):
        return AffineConverter(1 / self.slope, -self.intercept / self.slope)

    def compose(self, other):
        return AffineConverter(self.slope * other.slope, self.slope * other.intercept + self.intercept)

class Main:
    def __init__(self, basicConversions):
        self.conversions = self.compute_all_conversions(basicConversions)
        self.units = self.extract_units(self.conversions)

    def convert(self, inputUnit, outputUnit, value):
        if inputUnit == outputUnit:
            raise ValueError("Input and output units must be different.")

        conversion_key = (inputUnit, outputUnit)
        converter = self.conversions.get(conversion_key)

        if converter is None:
            raise ValueError(f"No converter for: {conversion_key}")

        result = converter.convert(value)
        return decimal.Decimal(result).quantize(decimal.Decimal('0.00'))

    def available_units(self):
        return self.units

    @staticmethod
    def put_if_needed(conversions, inputUnit, outputUnit, converter):
        if inputUnit!= outputUnit:
            conversions[inputUnit, outputUnit] = converter

    @staticmethod
    def add_inversions(known_conversions):
        res = {}
        for (inputUnit, outputUnit), converter in known_conversions.items():
            Main.put_if_needed(res, inputUnit, outputUnit, converter)
            Main.put_if_needed(res, outputUnit, inputUnit, converter.invert())
        return res

    @staticmethod
    def add_compositions(known_conversions):
        res = {}
        for (firstInputUnit, firstOutputUnit), firstConverter in known_conversions.items():
            res[firstInputUnit, firstOutputUnit] = firstConverter
            for (secondInputUnit, secondOutputUnit), secondConverter in known_conversions.items():
                if firstOutputUnit == secondInputUnit:
                    composed_converter = secondConverter.compose(firstConverter)
                    Main.put_if_needed(res, firstInputUnit, secondOutputUnit, composed_converter)
        return res

    @staticmethod
    def compute_all_conversions(basic_conversions):
        tmp = basic_conversions
        res = Main.add_all(tmp)
        while len(res)!= len(tmp):
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
        for (inputUnit, outputUnit), _ in conversions.items():
            res.add(inputUnit)
            res.add(outputUnit)
        return res

if __name__ == "__main__":
    import sys

    # Initialize a map of basic conversions
    basic_conversions = {
        ("Celsius", "Fahrenheit"): AffineConverter(9.0 / 5.0, 32.0),
        ("Kelvin", "Celsius"): AffineConverter(1.0, -273.15)
    }

    # Create an instance of Main with the basic conversions
    converter = Main(basic_conversions)

    # Read user input for inputUnit, outputUnit, and value
    input_unit = input("Enter input unit: ")
    output_unit = input("Enter output unit: ")
    value = float(input("Enter value: "))

    try:
        # Perform the unit conversion and print the result
        result = converter.convert(input_unit, output_unit, value)
        print(f"Converted value: {result}")
    except Exception as e:
        # Print an error message if an exception occurs
        print(f"Error: {e}")

