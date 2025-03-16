import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Set;

class Main:
    # Map to hold conversions between unit pairs and their corresponding converters
    conversions: Map[Pair[str, str], AffineConverter]
    # Set to hold all unique units available for conversion
    units: Set[str]

    # Constructor that initializes conversions and units based on provided basic conversions
    def __init__(self, basicConversions: Map[Pair[str, str], AffineConverter]):
        self.conversions = self.computeAllConversions(basicConversions)
        self.units = self.extractUnits(conversions)

    # Method to convert a value from one unit to another
    def convert(self, inputUnit: str, outputUnit: str, value: float) -> float:
        # Check if input and output units are the same, which is not allowed
        if inputUnit == outputUnit:
            raise ValueError("Input and output units must be different.")
        # Create a key for the conversion
        conversionKey = Pair.of(inputUnit, outputUnit)
        # Perform the conversion using the appropriate converter
        result = self.conversions.get(conversionKey)
        if result is None:
            raise NoSuchElementException("No converter for: " + conversionKey)
        result = result.convert(value)
        # Format the result to two decimal places
        df = DecimalFormat("#.##")
        return float(df.format(result))

    # Method to retrieve the set of available units for conversion
    def availableUnits(self) -> Set[str]:
        return self.units

    # Helper method to add a conversion to the map if input and output units are different
    def putIfNeeded(self, conversions: Map[Pair[str, str], AffineConverter], inputUnit: str, outputUnit: str, converter: AffineConverter):
        if inputUnit!= outputUnit:
            conversions.putIfAbsent(Pair.of(inputUnit, outputUnit), converter)

    # Method to add inverses of known conversions to the conversion map
    def addInversions(self, knownConversions: Map[Pair[str, str], AffineConverter]) -> Map[Pair[str, str], AffineConverter]:
        res = {}
        # Iterate through known conversions to add both directions
        for entry in knownConversions.items():
            inputUnit = entry[0].getKey()
            outputUnit = entry[0].getValue()
            converter = entry[1]
            self.putIfNeeded(res, inputUnit, outputUnit, converter)
            self.putIfNeeded(res, outputUnit, inputUnit, converter.invert())
        return res

    # Method to add compositions of known conversions to the conversion map
    def addCompositions(self, knownConversions: Map[Pair[str, str], AffineConverter]) -> Map[Pair[str, str], AffineConverter]:
        res = {}
        # Iterate through known conversions to find compositions
        for first in knownConversions.items():
            firstKey = first[0]
            self.putIfNeeded(res, firstKey.getKey(), firstKey.getValue(), first[1])
            for second in knownConversions.items():
                secondKey = second[0]
                # Check if the output unit of the first conversion matches the input unit of the second
                if firstKey.getValue() == secondKey.getKey():
                    composedConverter = second[1].compose(first[1])
                    self.putIfNeeded(res, firstKey.getKey(), secondKey.getValue(), composedConverter)
        return res

    # Method to compute all conversions by adding inverses and compositions iteratively
    def computeAllConversions(self, basicConversions: Map[Pair[str, str], AffineConverter]) -> Map[Pair[str, str], AffineConverter]:
        tmp = basicConversions
        res = self.addAll(tmp)
        # Continue adding conversions until no new conversions are found
        while res.size()!= tmp.size():
            tmp = res
            res = self.addAll(tmp)
        return res

    # Method to add all known conversions, including inverses and compositions
    def addAll(self, knownConversions: Map[Pair[str, str], AffineConverter]) -> Map[Pair[str, str], AffineConverter]:
        res = self.addInversions(knownConversions)
        return self.addCompositions(res)

    # Method to extract unique units from the conversion map
    def extractUnits(self, conversions: Map[Pair[str, str], AffineConverter]) -> Set[str]:
        res = set()
        # Add both input and output units to the set
        for entry in conversions.items():
            res.add(entry[0].getKey())
            res.add(entry[0].getValue())
        return res

# Pair class to hold a key-value pair
class Pair(Generic[K, V]):
    key: K
    value: V

    # Constructor for Pair
    def __init__(self, key: K, value: V):
        self.key = key
        self.value = value

    # Static factory method to create a Pair
    @staticmethod
    def of(key: K, value: V) -> 'Pair[K, V]':
        return Pair(key, value)

    # Getter for the key
    def getKey(self) -> K:
        return self.key

    # Getter for the value
    def getValue(self) -> V:
        return self.value

    # Override equals method for proper comparison
    def __eq__(self, o: object) -> bool:
        if self == o: return True
        if o is None or type(self)!= type(o): return False
        pair = o
        return self.key == pair.key and self.value == pair.value

    # Override hashCode method for proper hashing
    def __hash__(self) -> int:
        return self.key.__hash__() * 31 + self.value.__hash__()

    # Override toString method for better representation
    def __str__(self) -> str:
        return "(" + self.key.__str__() + ", " + self.value.__str__() + ")"

# AffineConverter class to handle unit conversions
class AffineConverter:
    scale: float # Scale factor for conversion
    offset: float # Offset for conversion

    # Constructor for AffineConverter
    def __init__(self, scale: float, offset: float):
        self.scale = scale
        self.offset = offset

    # Method to convert a value using the scale and offset
    def convert(self, value: float) -> float:
        return self.scale * value + self.offset

    # Method to invert the conversion
    def invert(self) -> 'AffineConverter':
        if self.scale == 0:
            raise ArithmeticError("Cannot invert a scale of zero.")
        return AffineConverter(1 / self.scale, -self.offset / self.scale)

    # Method to compose this converter with another
    def compose(self, other: 'AffineConverter') -> 'AffineConverter':
        return AffineConverter(self.scale * other.scale, self.scale * other.offset + self.offset)

    # Override toString method for better representation
    def __str__(self) -> str:
        return "AffineConverter(scale=" + self.scale.__str__() + ", offset=" + self.offset.__str__() + ")"

# Main method to run the conversion program
if __name__ == "__main__":
    scanner = Scanner(System.in)
    # Initialize basic conversions
    basicConversions = {}
    basicConversions[Pair.of("Celsius", "Fahrenheit")] = AffineConverter(9.0 / 5.0, 32.0)
    basicConversions[Pair.of("Kelvin", "Celsius")] = AffineConverter(1.0, -273.15)
    # Create a converter instance with the basic conversions
    converter = Main(basicConversions)
    # Read input unit, output unit, and value from the user
    inputUnit = scanner.nextLine()
    outputUnit = scanner.nextLine()
    value = scanner.nextDouble()
    try:
        # Perform the conversion and display the result
        result = converter.convert(inputUnit, outputUnit, value)
        print("Converted value: " + result.__str__())
    except Exception as e:
        # Handle any exceptions that occur during conversion
        print("Error: " + e.getMessage())
    # Close the scanner to free resources
    scanner.close()

