import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Constants for minimum and maximum base values
    MINIMUM_BASE = 2
    MAXIMUM_BASE = 36

    def main(self):
        # Create a Scanner object for user input
        in = Scanner(System.in)
        
        # Read the number to be converted
        n = in.next()
        
        # Read the source base and validate it
        b1 = in.nextInt()
        while b1 < self.MINIMUM_BASE or b1 > self.MAXIMUM_BASE:
            print("Invalid base! Please enter again.")
            b1 = in.nextInt()

        # Validate the number for the specified source base
        if not self.validForBase(n, b1):
            print("The number is invalid for this base!")
            return # Exit if the number is invalid

        # Read the target base and validate it
        b2 = in.nextInt()
        while b2 < self.MINIMUM_BASE or b2 > self.MAXIMUM_BASE:
            print("Invalid base! Please enter again.")
            b2 = in.nextInt()

        # Convert the number from base b1 to base b2
        result = self.base2base(n, b1, b2)
        
        # Output the converted number
        print("Converted number: " + result)
        
        # Close the scanner to prevent resource leaks
        in.close()

    # Method to validate if the number is valid for the given base
    def validForBase(self, n, base):
        # Define valid digits for bases up to 36
        validDigits = [
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        ]
        
        # Create an array of valid digits for the specified base
        digitsForBase = validDigits[0:base]
        
        # Use a HashSet for quick lookup of valid digits
        digitsList = HashSet()
        for c in digitsForBase:
            digitsList.add(c)

        # Check if each character in the number is valid for the base
        for c in n.upper():
            if not digitsList.contains(c):
                return False # Return false if an invalid character is found
        return True # Return true if all characters are valid

    # Method to convert a number from base b1 to base b2
    def base2base(self, n, b1, b2):
        decimalValue = 0 # Variable to hold the decimal value
        output = StringBuilder() # StringBuilder to build the output

        # Convert the number from base b1 to decimal
        for charB1 in n.upper():
            # Convert character to its integer value based on the base
            charB2 = ord(charB1) - ord('A') if charB1 >= 'A' and charB1 <= 'Z' else ord(charB1) - ord('0')
            decimalValue = decimalValue * b1 + charB2 # Update decimal value

        # Handle the case where the number is zero
        if decimalValue == 0:
            return "0" # Return "0" if the decimal value is zero

        # Convert the decimal value to the target base b2
        while decimalValue!= 0:
            remainder = decimalValue % b2 # Get the remainder
            # Convert remainder to the appropriate character and insert at the beginning
            output.insert(0, chr(remainder + ord('0') if remainder < 10 else remainder + ord('A') - 10))
            decimalValue /= b2 # Update decimal value for the next iteration
        return output.toString() # Return the final converted number

# 