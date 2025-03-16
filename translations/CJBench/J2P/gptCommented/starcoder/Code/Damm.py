import java.util.Objects;
import java.util.Scanner;

class Main:
    # Private constructor to prevent instantiation of the class
    def __init__(self):
        pass

    # Main algorithm checksum lookup table
    DAMM_TABLE = [
        [0, 3, 1, 7, 5, 9, 8, 6, 4, 2],
        [7, 0, 9, 2, 1, 5, 4, 8, 6, 3],
        [4, 2, 0, 6, 8, 7, 1, 3, 5, 9],
        [1, 7, 5, 0, 9, 8, 3, 4, 2, 6],
        [6, 1, 2, 3, 0, 4, 5, 9, 7, 8],
        [3, 6, 7, 4, 2, 0, 9, 5, 8, 1],
        [5, 8, 6, 9, 7, 2, 0, 1, 3, 4],
        [8, 9, 4, 5, 3, 6, 2, 0, 1, 7],
        [9, 4, 3, 8, 6, 1, 7, 2, 0, 5],
        [2, 5, 8, 1, 4, 3, 6, 7, 9, 0],
    ]

    # Method to check if the input digits are valid according to the Main algorithm
    def dammCheck(self, digits):
        self.checkInput(digits) # Validate input format
        numbers = self.toIntArray(digits) # Convert input string to an integer array
        checksum = 0 # Initialize checksum

        # Calculate checksum using the Main table
        for number in numbers:
            checksum = self.DAMM_TABLE[checksum][number]
        # Return true if checksum is 0 (valid), false otherwise
        return checksum == 0

    # Method to generate a checksum for the given initial digits
    def addMainChecksum(self, initialDigits):
        self.checkInput(initialDigits) # Validate input format
        numbers = self.toIntArray(initialDigits) # Convert input string to an integer array
        checksum = 0 # Initialize checksum

        # Calculate checksum using the Main table
        for number in numbers:
            checksum = self.DAMM_TABLE[checksum][number]
        # Return the original digits concatenated with the checksum
        return initialDigits + checksum

    # Main method to handle user input and execute operations
    def main(self):
        sc = Scanner(System.in) # Create a scanner for user input
        operation = sc.nextLine() # Read the operation type (check or generate)

        # Check operation: Validate input digits
        if operation.equalsIgnoreCase("check"):
            digits = sc.nextLine() # Read the digits to check
            try:
                isValid = dammCheck(digits) # Validate the digits
                # Output the result of the validation
                print("The input '" + digits + "' is " + (isValid? "valid" : "not valid"))
            except Exception as e:
                # Handle any exceptions that occur during validation
                print("Error: " + e.getMessage())
        # Generate operation: Create a checksum for the input digits
        else if operation.equalsIgnoreCase("generate"):
            print("Enter the input digits to generate checksum:")
            digits = sc.nextLine() # Read the digits to generate checksum
            try:
                result = addMainChecksum(digits) # Generate the checksum
                # Output the result with the checksum
                print("Generated value with checksum: " + result)
            except Exception as e:
                # Handle any exceptions that occur during checksum generation
                print("Error: " + e.getMessage())
        else:
            # Handle invalid operation input
            print("Invalid operation. Please enter 'check' or 'generate'.")
        sc.close() # Close the scanner

    # Method to check if the input is valid (not null and contains only digits)
    def checkInput(self, input):
        Objects.requireNonNull(input) # Ensure input is not null
        if not input.matches("\\d+"): # Check if input contains only digits
            raise IllegalArgumentException("Input '" + input + "' contains not only digits")

    # Method to convert a string of digits into an integer array
    def toIntArray(self, string):
        return string.chars().map(i -> Character.digit(i, 10)).toArray() # Convert each character to its integer value

# 