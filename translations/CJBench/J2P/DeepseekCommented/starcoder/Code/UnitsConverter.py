import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Set;
# Import statements for necessary classes

class Main:
    # The Main class is the entry point of the application

    def __init__(self, basicConversions):
        # Constructor initializes the conversions and units
        self.conversions = self.computeAllConversions(basicConversions)
        self.units = self.extractUnits(conversions)
    # Constructor that takes a map of basic conversions and computes all possible conversions

    def convert(self, inputUnit, outputUnit, value):
        # Method to convert a value from one unit to another
        if inputUnit.equals(outputUnit):
            raise Exception("Input and output units must be different.")
        # Throws an exception if the input and output units are the same
        conversionKey = Pair.of(inputUnit, outputUnit)
        result = self.conversions.computeIfAbsent(conversionKey, k -> {
            raise Exception("No converter for: " + k)
        }).convert(value)
        # Computes the conversion using the AffineConverter and throws an exception if no converter is found
        df = DecimalFormat("#.##")
        return Double.parseDouble(df.format(result))
        # Formats the result to two decimal places

    def availableUnits(self):
        return self.units
    # Method to return all available units

    def putIfNeeded(self, conversions, inputUnit, outputUnit, converter):
        # Helper method to add conversions only if input and output units are different
        if not inputUnit.equals(outputUnit):
            conversions.putIfAbsent(Pair.of(inputUnit, outputUnit), converter)
    # Helper method to add conversions only if input and output units are different

    def addInversions(self, knownConversions):
        # Helper method to add inversions of known conversions
        res = HashMap()
        for entry in knownConversions.entrySet():
            inputUnit = entry.getKey().getKey()
            outputUnit = entry.getKey().getValue()
            converter = entry.getValue()
            self.putIfNeeded(res, inputUnit, outputUnit, converter)
            self.putIfNeeded(res, outputUnit, inputUnit, converter.invert())
        return res
    # Helper method to add inversions of known conversions

    def addCompositions(self, knownConversions):
        # Helper method to add compositions of known conversions
        res = HashMap()
        for first in knownConversions.entrySet():
            firstKey = first.getKey()
            self.putIfNeeded(res, firstKey.getKey(), firstKey.getValue(), first.getValue())
            for second in knownConversions.entrySet():
                secondKey = second.getKey()
                if firstKey.getValue().equals(secondKey.getKey()):
                    composedConverter = second.getValue().compose(first.getValue())
                    self.putIfNeeded(res, firstKey.getKey(), secondKey.getValue(), composedConverter)
        return res
    # Helper method to add compositions of known conversions

    def computeAllConversions(self, basicConversions):
        tmp = basicConversions
        res = self.addAll(tmp)
        while res.size()!= tmp.size():
            tmp = res
            res = self.addAll(tmp)
        return res
    # Helper method to compute all possible conversions

    def addAll(self, knownConversions):
        res = self.addInversions(knownConversions)
        return self.addCompositions(res)
    # Helper method to add inversions and compositions of known conversions

    def extractUnits(self, conversions):
        res = HashSet()
        for entry in conversions.entrySet():
            res.add(entry.getKey().getKey())
            res.add(entry.getKey().getValue())
        return res
    # Helper method to extract all units from the conversions map

    def main(self):
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
    # Main method to read input units, output units, and values from the user and convert the value

class Pair(K, V):
    # Generic Pair class to represent pairs of keys and values
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
        pair = (Pair, o)
        return key.equals(pair.key) and value.equals(pair.value)
    def hashCode(self):
        return key.hashCode() * 31 + value.hashCode()
    def toString(self):
        return "(" + key + ", " + value + ")"
# Pair class to represent pairs of keys and values

class AffineConverter:
    # Class to perform affine transformations (linear transformations with an offset)
    def __init__(self, scale, offset):
        self.scale = scale
        self.offset = offset
    def convert(self, value):
        return self.scale * value + self.offset
    def invert(self):
        if self.scale == 0:
            raise Exception("Cannot invert a scale of zero.")
        return AffineConverter(1 / self.scale, -self.offset / self.scale)
    def compose(self, other):
        return AffineConverter(self.scale * other.scale, self.scale * other.offset + self.offset)
    def toString(self):
        return "AffineConverter(scale=" + self.scale + ", offset=" + self.offset + ")"
# AffineConverter class to perform affine transformations (linear transformations with an offset)

if __name__ == "__main__":
    Main().main()
# Main method to read input units, output units, and values from the user and convert the value

