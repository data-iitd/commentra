
import math

class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def getKey(self):
        return self.key

    def getValue(self):
        return self.value

    def __eq__(self, other):
        return self.key == other.key and self.value == other.value

    def __hash__(self):
        return hash((self.key, self.value))

    def __str__(self):
        return "Pair(" + str(self.key) + ", " + str(self.value) + ")"

    def __repr__(self):
        return str(self)

    @staticmethod
    def of(key, value):
        return Pair(key, value)

class AffineConverter:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def convert(self, value):
        return self.a * value + self.b

    def invert(self):
        return AffineConverter(1.0 / self.a, -self.b / self.a)

    def compose(self, other):
        return AffineConverter(self.a * other.a, self.a * other.b + self.b)

    def __str__(self):
        return "AffineConverter(" + str(self.a) + ", " + str(self.b) + ")"

    def __repr__(self):
        return str(self)

class Main:
    def __init__(self, basicConversions):
        self.conversions = self.computeAllConversions(basicConversions)
        self.units = self.extractUnits(self.conversions)

    def convert(self, inputUnit, outputUnit, value):
        if inputUnit == outputUnit:
            raise Exception("Input and output units must be different.")

        conversionKey = Pair.of(inputUnit, outputUnit)
        converter = self.conversions.get(conversionKey)

        if converter == None:
            raise Exception("No converter for: " + str(conversionKey))

        result = converter.convert(value)
        return round(result, 2)

    def availableUnits(self):
        return self.units

    def computeAllConversions(self, basicConversions):
        tmp = basicConversions
        res = self.addAll(tmp)
        while len(res)!= len(tmp):
            tmp = res
            res = self.addAll(tmp)
        return res

    def addAll(self, knownConversions):
        res = self.addInversions(knownConversions)
        return self.addCompositions(res)

    def addInversions(self, knownConversions):
        res = {}
        for entry in knownConversions.items():
            inputUnit = entry[0].getKey()
            outputUnit = entry[0].getValue()
            converter = entry[1]
            self.putIfNeeded(res, inputUnit, outputUnit, converter)
            self.putIfNeeded(res, outputUnit, inputUnit, converter.invert())
        return res

    def addCompositions(self, knownConversions):
        res = {}
        for first in knownConversions.items():
            firstKey = first[0]
            self.putIfNeeded(res, firstKey.getKey(), firstKey.getValue(), first[1])
            for second in knownConversions.items():
                secondKey = second[0]
                if firstKey.getValue() == secondKey.getKey():
                    composedConverter = second[1].compose(first[1])
                    self.putIfNeeded(res, firstKey.getKey(), secondKey.getValue(), composedConverter)
        return res

    def putIfNeeded(self, conversions, inputUnit, outputUnit, converter):
        if inputUnit!= outputUnit:
            conversions.setdefault(Pair.of(inputUnit, outputUnit), converter)

    def extractUnits(self, conversions):
        res = set()
        for entry in conversions.items():
            res.add(entry[0].getKey())
            res.add(entry[0].getValue())
        return res

if __name__ == "__main__":
    scanner = Scanner(System.in)

    basicConversions = {}
    basicConversions[Pair.of("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
    basicConversions[Pair.of("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)

    converter = Main(basicConversions)

    inputUnit = scanner.nextLine()
    outputUnit = scanner.nextLine()
    value = scanner.nextDouble()

    try:
        result = converter.convert(inputUnit, outputUnit, value)
        print("Converted value: " + str(result))
    except Exception as e:
        print("Error: " + str(e))

    scanner.close()

