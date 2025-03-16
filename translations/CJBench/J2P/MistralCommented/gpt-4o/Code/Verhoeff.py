import re

class Main:
    # Initialize a 2D array representing the multiplication table
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

    # Initialize an array representing the multiplicative inverse
    MULTIPLICATIVE_INVERSE = [0, 4, 3, 2, 1, 5, 6, 7, 8, 9]

    # Initialize a 2D array representing the permutation table
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

    @staticmethod
    def verhoeff_check(digits):
        # Check input validity
        Main.check_input(digits)

        # Convert the string to an integer array
        numbers = Main.to_int_array(digits)

        # Initialize checksum variable
        checksum = 0

        # Iterate through the digits in reverse order and calculate the checksum
        for i in range(len(numbers)):
            index = len(numbers) - i - 1
            b = Main.PERMUTATION_TABLE[i % 8][numbers[index]]
            checksum = Main.MULTIPLICATION_TABLE[checksum][b]

        # Return true if the checksum is zero, indicating valid digits
        return checksum == 0

    @staticmethod
    def add_main_checksum(initial_digits):
        # Check input validity
        Main.check_input(initial_digits)

        # Concatenate the input with a zero to prepare for the checksum calculation
        modified_digits = initial_digits + "0"

        # Initialize checksum variable
        checksum = 0

        # Iterate through the digits in reverse order and calculate the checksum
        for i in range(len(modified_digits)):
            index = len(modified_digits) - i - 1
            b = Main.PERMUTATION_TABLE[i % 8][int(modified_digits[index])]
            checksum = Main.MULTIPLICATION_TABLE[checksum][b]

        # Calculate the multiplicative inverse of the checksum and append it to the result
        checksum = Main.MULTIPLICATIVE_INVERSE[checksum]

        # Return the original input with the checksum appended
        return initial_digits + str(checksum)

    @staticmethod
    def check_input(input):
        if input is None:
            raise ValueError("Input cannot be None")

        # Use a regular expression to check if the input consists only of digits
        if not re.match(r'^\d+$', input):
            raise ValueError(f"Input contains invalid characters: {input}")

    @staticmethod
    def to_int_array(string):
        return [int(char) for char in string]

# Main execution
if __name__ == "__main__":
    input_to_validate = input("Enter a number to validate: ")
    is_valid = Main.verhoeff_check(input_to_validate)
    print("Input is " + ("valid" if is_valid else "not valid"))

    input_to_generate_checksum = input("Enter a number to generate a checksum: ")
    checksum_result = Main.add_main_checksum(input_to_generate_checksum)
    print("Number with checksum: " + checksum_result)

# <END-OF-CODE>
