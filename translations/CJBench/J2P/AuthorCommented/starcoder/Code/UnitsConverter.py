import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Set;

class Main:
    def __init__(self, basicConversions):
        self.conversions = self.computeAllConversions(basicConversions)
        self.units = self.extractUnits(conversions)

    def convert(self, inputUnit, outputUnit, value):
        if inputUnit.equals(outputUnit):
            raise ValueError("Input and output units must be different.")
        conversionKey = Pair.of(inputUnit, outputUnit)
        result = self.conversions.get(conversionKey)
        if result is None:
            raise NoSuchElementException("No converter for: " + conversionKey)
        result = result.convert(value)

        # Format the result to two decimal places
        df = DecimalFormat("#.##")
        return Double.parseDouble(df.format(result))

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
                if firstKey.getValue().equals(secondKey.getKey()):
                    composedConverter = second[1].compose(first[1])
                    self.putIfNeeded(res, firstKey.getKey(), secondKey.getValue(), composedConverter)
        return res

    def putIfNeeded(self, conversions, inputUnit, outputUnit, converter):
        if not inputUnit.equals(outputUnit):
            conversions.putIfAbsent(Pair.of(inputUnit, outputUnit), converter)

    def extractUnits(self, conversions):
        res = set()
        for entry in conversions.items():
            res.add(entry[0].getKey())
            res.add(entry[0].getValue())
        return res

class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    @staticmethod
    def of(key, value):
        return Pair(key, value)

    def getKey(self):
        return self.key

    def getValue(self):
        return self.value

    def equals(self, o):
        if self == o: return True
        if o == None or getClass()!= o.getClass(): return False
        pair = (Pair) o
        return key.equals(pair.key) and value.equals(pair.value)

    def hashCode(self):
        return self.key.hashCode() * 31 + self.value.hashCode()

    def toString(self):
        return "(" + self.key + ", " + self.value + ")"

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

    def toString(self):
        return "AffineConverter(scale=" + self.scale + ", offset=" + self.offset + ")"

if __name__ == "__main__":
    scanner = Scanner(System.in)
    basicConversions = HashMap()

    basicConversions.put(Pair.of("Celsius", "Fahrenheit"), AffineConverter(9.0 / 5.0, 32.0))
    basicConversions.put(Pair.of("Kelvin", "Celsius"), AffineConverter(1.0, -273.15))

    converter = Main(basicConversions)

    inputUnit = scanner.nextLine()

    outputUnit = scanner.nextLine()

    value = scanner.nextDouble()

    try:
        result = converter.convert(inputUnit, outputUnit, value)
        print("Converted value: " + result)
    except Exception as e:
        print("Error: " + e.getMessage())

    scanner.close()

