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
class Main:
    def __init__(self, basicConversions):
        self.conversions = self.computeAllConversions(basicConversions)
        self.units = self.extractUnits(self.conversions)
    def convert(self, inputUnit, outputUnit, value):
        if inputUnit == outputUnit:
            raise ValueError("Input and output units must be different.")
        conversionKey = Pair(inputUnit, outputUnit)
        result = self.conversions.get(conversionKey, None)
        if result is None:
            raise ValueError("No converter for: " + str(conversionKey))
        return round(result.convert(value), 2)
    def availableUnits(self):
        return self.units
    @staticmethod
    def addInversions(knownConversions):
        res = {}
        for entry in knownConversions.items():
            inputUnit = entry[0].key
            outputUnit = entry[0].value
            converter = entry[1]
            if inputUnit != outputUnit:
                res[Pair(inputUnit, outputUnit)] = converter
            res[Pair(outputUnit, inputUnit)] = converter.invert()
        return res
    @staticmethod
    def addCompositions(knownConversions):
        res = {}
        for first in knownConversions.items():
            firstKey = first[0]
            res[firstKey] = first[1]
            for second in knownConversions.items():
                secondKey = second[0]
                if firstKey.value == secondKey.key:
                    composedConverter = second[1].compose(first[1])
                    res[Pair(firstKey.key, secondKey.value)] = composedConverter
        return res
    @staticmethod
    def computeAllConversions(basicConversions):
        tmp = basicConversions
        res = Main.addAll(tmp)
        while len(res) != len(tmp):
            tmp = res
            res = Main.addAll(tmp)
        return res
    @staticmethod
    def addAll(knownConversions):
        res = Main.addInversions(knownConversions)
        return Main.addCompositions(res)
    @staticmethod
    def extractUnits(conversions):
        res = set()
        for entry in conversions.items():
            res.add(entry[0].key)
            res.add(entry[0].value)
        return res
    @staticmethod
    def main(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @staticmethod
    def main2(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @staticmethod
    def main3(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @staticmethod
    def main4(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @staticmethod
    def main5(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @staticmethod
    def main6(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @staticmethod
    def main7(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @staticmethod
    def main8(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @staticmethod
    def main9(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @staticmethod
    def main10(args):
        scanner = Scanner(System.in)
        basicConversions = {}
        basicConversions[Pair("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
        basicConversions[Pair("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
        converter = Main(basicConversions)
        inputUnit = scanner.nextLine()
        outputUnit = scanner.nextLine()
        value = scanner.nextDouble()
        try:
            result = converter.convert(inputUnit, outputUnit, value)
            print("Converted value: " + str(result))
        except Exception as e:
            print("Error: " + str(e.getMessage()))
        scanner.close()
    @stati