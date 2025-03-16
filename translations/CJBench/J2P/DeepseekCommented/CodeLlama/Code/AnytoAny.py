
# Import the Scanner class from the java.util package
from java.util import Scanner

# Private constructor to prevent instantiation
class Main:
    def __init__(self):
        pass

    # Main method to convert a number from a source base to a destination base
    @staticmethod
    def convertBase(sourceNumber, sourceBase, destBase):
        # Check if the source and destination bases are within the valid range (2 to 10)
        if sourceBase < 2 or sourceBase > 10 or destBase < 2 or destBase > 10:
            raise ValueError("Bases must be between 2 and 10.")

        # Convert the source number to its decimal (base 10) equivalent
        decimalValue = Main.toDecimal(sourceNumber, sourceBase)

        # Convert the decimal value to the destination base
        return Main.fromDecimal(decimalValue, destBase)

    # Private method to convert a number from a given base to its decimal (base 10) equivalent
    @staticmethod
    def toDecimal(number, base):
        decimalValue = 0
        multiplier = 1
        while number != 0:
            decimalValue += (number % 10) * multiplier
            multiplier *= base
            number //= 10
        return decimalValue

    # Private method to convert a decimal number to a number in a given base
    @staticmethod
    def fromDecimal(decimal, base):
        result = 0
        multiplier = 1
        while decimal != 0:
            result += (decimal % base) * multiplier
            multiplier *= 10
            decimal //= base
        return result

    # Main method to run the program
    @staticmethod
    def main(args):
        scanner = Scanner(System.in)
        sourceNumber = scanner.nextInt()
        sourceBase = scanner.nextInt()
        destBase = scanner.nextInt()
        try:
            result = Main.convertBase(sourceNumber, sourceBase, destBase)
            print("Converted number: " + str(result))
        except ValueError as e:
            print("Error: " + str(e))
        finally:
            scanner.close()

# Main method to run the program
if __name__ == "__main__":
    Main.main(None)

