
import decimal

class Pair:
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
    def __init__(self, basicConversions):
        self.conversions = self.compute_all_conversions(basicConversions)
        self.units = self.extract_units(self.conversions)

    def convert(self, inputUnit, outputUnit, value):
        if inputUnit == outputUnit:
            raise ValueError("Input and output units must be different.")
        conversionKey = Pair.of(inputUnit, outputUnit)
        result = self.conversions.get(conversionKey, None)
        if result is None:
            raise ValueError(f"No converter for: {conversionKey}")
        return result.convert(value)

    def available_units(self):
        return self.units

    @staticmethod
    def add_inversions(knownConversions):
        res = {}
        for key, converter in knownConversions.items():
            inputUnit = key.key
            outputUnit = key.value
            res[key] = converter
            res[Pair.of(outputUnit, inputUnit)] = converter.invert()
        return res

    @staticmethod
    def add_compositions(knownConversions):
        res = {}
        for firstKey, firstConverter in knownConversions.items():
            firstInputUnit = firstKey.key
            firstOutputUnit = firstKey.value
            res[firstKey] = firstConverter
            for secondKey, secondConverter in knownConversions.items():
                secondInputUnit = secondKey.key
                secondOutputUnit = secondKey.value
                if firstOutputUnit == secondInputUnit:
                    composedConverter = secondConverter.compose(firstConverter)
                    res[Pair.of(firstInputUnit, secondOutputUnit)] = composedConverter
        return res

    @staticmethod
    def compute_all_conversions(basicConversions):
        tmp = basicConversions
        res = Main.add_all(tmp)
        while len(res)!= len(tmp):
            tmp = res
            res = Main.add_all(tmp)
        return res

    @staticmethod
    def add_all(knownConversions):
        res = Main.add_inversions(knownConversions)
        return Main.add_compositions(res)

    @staticmethod
    def extract_units(conversions):
        res = set()
        for key in conversions.keys():
            res.add(key.key)
            res.add(key.value)
        return res

if __name__ == "__main__":
    import sys
    basicConversions = {
        Pair.of("Celsius", "Fahrenheit"): AffineConverter(9.0 / 5.0, 32.0),
        Pair.of("Kelvin", "Celsius"): AffineConverter(1.0, -273.15)
    }
    converter = Main(basicConversions)
    inputUnit = sys.stdin.readline().strip()
    outputUnit = sys.stdin.readline().strip()
    value = decimal.Decimal(sys.stdin.readline().strip())
    try:
        result = converter.convert(inputUnit, outputUnit, value)
        print(f"Converted value: {result}")
    except Exception as e:
        print(f"Error: {e}")