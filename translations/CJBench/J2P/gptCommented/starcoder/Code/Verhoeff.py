import java.util.Objects;
import java.util.Scanner;

class Main:
    # Private constructor to prevent instantiation of this utility class
    def __init__(self):
        pass

    # Multiplication table used for the Main algorithm
    MULTIPLICATION_TABLE = [
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 2, 3, 4, 0, 6, 7, 8, 9, 5],
        [2, 3, 4, 0, 1, 7, 8, 9, 5, 6],
        [3, 4, 0, 1, 2, 8, 9, 5, 6, 7],
        [4, 0, 1, 2, 3, 9, 5, 6, 7, 8],
        [5, 9, 8, 7, 6, 0, 4, 3, 2, 1],
        [6, 5, 9, 8, 7, 1, 0, 4, 3, 2],
        [7, 6, 5, 9, 8, 2, 1, 0, 4, 3],
        [8, 7, 6, 5, 9, 3, 2, 1, 0, 4],
        [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    ]

    # Multiplicative inverse table used for the Main algorithm
    MULTIPLICATIVE_INVERSE = [
        0, 4, 3, 2, 1, 5, 6, 7, 8, 9
    ]

    # Permutation table used for the Main algorithm
    PERMUTATION_TABLE = [
        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
        [1, 5, 7, 6, 2, 8, 3, 0, 9, 4],
        [5, 8, 0, 3, 7, 9, 6, 1, 4, 2],
        [8, 9, 1, 6, 0, 4, 3, 5, 2, 7],
        [9, 4, 5, 3, 1, 2, 6, 8, 7, 0],
        [4, 2, 8, 6, 5, 7, 3, 9, 0, 1],
        [2, 7, 9, 3, 8, 0, 6, 4, 1, 5],
        [7, 0, 4, 6, 9, 1, 3, 2, 5, 8]
    ]

    # Method to validate a number using the Main algorithm
    def verhoeffCheck(self, digits):
        # Validate input format
        self.checkInput(digits)
        # Convert input string to an integer array
        numbers = self.toIntArray(digits)
        checksum = 0

        # Calculate checksum using the multiplication and permutation tables
        for i in range(0, len(numbers)):
            index = len(numbers) - i - 1
            b = self.PERMUTATION_TABLE[i % 8][numbers[index]]
            checksum = self.MULTIPLICATION_TABLE[checksum][b]
        # Return true if checksum is zero (valid), false otherwise
        return checksum == 0

    # Method to add a checksum to the initial digits using the Main algorithm
    def addMainChecksum(self, initialDigits):
        # Validate input format
        self.checkInput(initialDigits)
        # Append a placeholder '0' for checksum calculation
        modifiedDigits = initialDigits + "0"
        # Convert modified string to an integer array
        numbers = self.toIntArray(modifiedDigits)
        checksum = 0

        # Calculate checksum using the multiplication and permutation tables
        for i in range(0, len(numbers)):
            index = len(numbers) - i - 1
            b = self.PERMUTATION_TABLE[i % 8][numbers[index]]
            checksum = self.MULTIPLICATION_TABLE[checksum][b]
        # Get the multiplicative inverse of the checksum
        checksum = self.MULTIPLICATIVE_INVERSE[checksum]
        # Return the original digits with the calculated checksum appended
        return initialDigits + checksum

    # Main method to run the application
    def main(self):
        scanner = Scanner(System.in)
        
        # Prompt user for input to validate
        print("Enter a number to validate: ")
        inputToValidate = scanner.nextLine()
        # Validate the input and display the result
        print("Input is " + ("valid" if self.verhoeffCheck(inputToValidate) else "not valid"))
        
        # Prompt user for input to generate a checksum
        print("Enter a number to generate a checksum: ")
        inputToGenerateChecksum = scanner.nextLine()
        # Generate and display the number with checksum
        print("Number with checksum: " + self.addMainChecksum(inputToGenerateChecksum))
        
        # Close the scanner to prevent resource leaks
        scanner.close()

    # Method to check if the input string is valid (non-null and numeric)
    def checkInput(self, input):
        Objects.requireNonNull(input) # Ensure input is not null
        # Throw an exception if input contains invalid characters
        if not input.matches("\\d+"):
            raise IllegalArgumentException("Input contains invalid characters: " + input)

    # Method to convert a string of digits into an integer array
    def toIntArray(self, string):
        return list(map(lambda c: int(c), string))

# 