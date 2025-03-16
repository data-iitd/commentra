import java.util.Objects; // Importing Objects class to use its methods
import java.util.Scanner; // Importing Scanner class for input

class Main:
    # Multiplication table for the Main algorithm
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

    # Multiplicative inverse table for the Main algorithm
    MULTIPLICATIVE_INVERSE = [
        0, 4, 3, 2, 1, 5, 6, 7, 8, 9
    ]

    # Permutation table for the Main algorithm
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

    # Constructor to prevent instantiation
    def __init__(self):
        pass

    # Main method to check if the input string is valid according to the Main algorithm
    def verhoeffCheck(self, digits):
        self.checkInput(digits) # Check if the input is valid
        numbers = self.toIntArray(digits) # Convert input string to an array of integers
        checksum = 0 # Initialize checksum to 0
        for i in range(len(numbers)):
            index = len(numbers) - i - 1 # Calculate the index for the permutation table
            b = self.PERMUTATION_TABLE[i % 8][numbers[index]] # Get the permuted value
            checksum = self.MULTIPLICATION_TABLE[checksum][b] # Update the checksum using the multiplication table
        return checksum == 0 # Return true if checksum is 0, otherwise false

    # Method to add a checksum to the input string using the Main algorithm
    def addMainChecksum(self, initialDigits):
        self.checkInput(initialDigits) # Check if the input is valid
        modifiedDigits = initialDigits + "0" # Append "0" to the input string
        numbers = self.toIntArray(modifiedDigits) # Convert the modified string to an array of integers
        checksum = 0 # Initialize checksum to 0
        for i in range(len(numbers)):
            index = len(numbers) - i - 1 # Calculate the index for the permutation table
            b = self.PERMUTATION_TABLE[i % 8][numbers[index]] # Get the permuted value
            checksum = self.MULTIPLICATION_TABLE[checksum][b] # Update the checksum using the multiplication table
        checksum = self.MULTIPLICATIVE_INVERSE[checksum] # Get the multiplicative inverse of the checksum
        return initialDigits + checksum # Return the input string with the appended checksum

    # Main method to interact with the user
    def main(self):
        scanner = Scanner(System.in) # Create a Scanner object for input
        print("Enter a number to validate: ") # Prompt the user to enter a number
        inputToValidate = scanner.nextLine() # Read the input string
        print("Input is " + ("valid" if self.verhoeffCheck(inputToValidate) else "not valid")) # Validate the input and print the result
        print("Enter a number to generate a checksum: ") # Prompt the user to enter a number
        inputToGenerateChecksum = scanner.nextLine() # Read the input string
        print("Number with checksum: " + self.addMainChecksum(inputToGenerateChecksum)) # Generate and print the checksum
        scanner.close() # Close the Scanner object

    # Helper method to check if the input string contains only digits
    def checkInput(self, input):
        Objects.requireNonNull(input) # Check if the input is not null
        if not input.matches("\\d+"): # Check if the input matches the pattern of digits
            raise IllegalArgumentException("Input contains invalid characters: " + input) # Throw an exception if the input is invalid

    # Helper method to convert a string of digits to an array of integers
    def toIntArray(self, string):
        return list(map(lambda c: int(c), string)) # Convert the string to an array of integers

# Main method to interact with the user
if __name__ == "__main__":
    Main().main()

