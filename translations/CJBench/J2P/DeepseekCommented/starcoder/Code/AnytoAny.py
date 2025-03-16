# Private constructor to prevent instantiation
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Main method to convert a number from a source base to a destination base
    def convertBase(self, sourceNumber, sourceBase, destBase):
        # Check if the source and destination bases are within the valid range (2 to 10)
        if sourceBase < 2 or sourceBase > 10 or destBase < 2 or destBase > 10:
            raise Exception("Bases must be between 2 and 10.")

        # Convert the source number to its decimal (base 10) equivalent
        decimalValue = self.toDecimal(sourceNumber, sourceBase)

        # Convert the decimal value to the destination base
        return self.fromDecimal(decimalValue, destBase)

    # Private method to convert a number from a given base to its decimal (base 10) equivalent
    def toDecimal(self, number, base):
        decimalValue = 0
        multiplier = 1
        while number!= 0:
            decimalValue += (number % 10) * multiplier
            multiplier *= base
            number /= 10
        return decimalValue

    # Private method to convert a decimal number to a number in a given base
    def fromDecimal(self, decimal, base):
        result = 0
        multiplier = 1
        while decimal!= 0:
            result += (decimal % base) * multiplier
            multiplier *= 10
            decimal /= base
        return result

    # Main method to run the program
    def main(self):
        sourceNumber = int(input("Enter a number: "))
        sourceBase = int(input("Enter the source base: "))
        destBase = int(input("Enter the destination base: "))
        try:
            result = self.convertBase(sourceNumber, sourceBase, destBase)
            print("Converted number: " + str(result))
        except Exception as e:
            print("Error: " + str(e))

# 