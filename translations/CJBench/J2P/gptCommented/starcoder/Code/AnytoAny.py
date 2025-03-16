# Private constructor to prevent instantiation of the class
class Main:
    # Method to convert a number from one base to another
    def convertBase(self, sourceNumber, sourceBase, destBase):
        # Validate that the source and destination bases are within the acceptable range
        if sourceBase < 2 or sourceBase > 10 or destBase < 2 or destBase > 10:
            raise Exception("Bases must be between 2 and 10.")
        # Convert the source number to decimal
        decimalValue = self.toDecimal(sourceNumber, sourceBase)
        # Convert the decimal value to the destination base
        return self.fromDecimal(decimalValue, destBase)

    # Helper method to convert a number from a specified base to decimal
    def toDecimal(self, number, base):
        decimalValue = 0 # Variable to hold the decimal value
        multiplier = 1   # Multiplier for the current base power
        # Loop until the number is reduced to zero
        while number!= 0:
            # Add the current digit's contribution to the decimal value
            decimalValue += (number % 10) * multiplier
            # Update the multiplier for the next digit
            multiplier *= base
            # Remove the last digit from the number
            number /= 10
        return decimalValue # Return the converted decimal value

    # Helper method to convert a decimal number to a specified base
    def fromDecimal(self, decimal, base):
        result = 0 # Variable to hold the result in the new base
        multiplier = 1 # Multiplier for the current base power
        # Loop until the decimal value is reduced to zero
        while decimal!= 0:
            # Add the current digit's contribution to the result
            result += (decimal % base) * multiplier
            # Update the multiplier for the next digit
            multiplier *= 10
            # Remove the last digit from the decimal value
            decimal /= base
        return result # Return the converted value in the new base

    # Main method to execute the program
    def main(self):
        # Create a scanner for user input
        scanner = Scanner(System.in)
        # Read the source number, source base, and destination base from input
        sourceNumber = scanner.nextInt()
        sourceBase = scanner.nextInt()
        destBase = scanner.nextInt()
        try:
            # Convert the number and print the result
            result = self.convertBase(sourceNumber, sourceBase, destBase)
            print("Converted number: " + result)
        except Exception as e:
            # Handle invalid base input by printing an error message
            print("Error: " + e.getMessage())
        finally:
            # Close the scanner to free resources
            scanner.close()

# 