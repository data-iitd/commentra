import re

class Main:
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
    MULTIPLICATIVE_INVERSE = [0, 4, 3, 2, 1, 5, 6, 7, 8, 9]

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

    @staticmethod
    def verhoeff_check(digits):
        # Validate input format
        Main.check_input(digits)
        # Convert input string to an integer array
        numbers = Main.to_int_array(digits)
        checksum = 0

        # Calculate checksum using the multiplication and permutation tables
        for i in range(len(numbers)):
            index = len(numbers) - i - 1
            b = Main.PERMUTATION_TABLE[i % 8][numbers[index]]
            checksum = Main.MULTIPLICATION_TABLE[checksum][b]
        # Return true if checksum is zero (valid), false otherwise
        return checksum == 0

    @staticmethod
    def add_main_checksum(initial_digits):
        # Validate input format
        Main.check_input(initial_digits)
        # Append a placeholder '0' for checksum calculation
        modified_digits = initial_digits + "0"
        # Convert modified string to an integer array
        numbers = Main.to_int_array(modified_digits)
        checksum = 0

        # Calculate checksum using the multiplication and permutation tables
        for i in range(len(numbers)):
            index = len(numbers) - i - 1
            b = Main.PERMUTATION_TABLE[i % 8][numbers[index]]
            checksum = Main.MULTIPLICATION_TABLE[checksum][b]
        # Get the multiplicative inverse of the checksum
        checksum = Main.MULTIPLICATIVE_INVERSE[checksum]
        # Return the original digits with the calculated checksum appended
        return initial_digits + str(checksum)

    @staticmethod
    def check_input(input):
        if input is None:
            raise ValueError("Input cannot be null")
        # Throw an exception if input contains invalid characters
        if not re.match(r'^\d+$', input):
            raise ValueError(f"Input contains invalid characters: {input}")

    @staticmethod
    def to_int_array(string):
        return list(map(int, string))

# Main execution
if __name__ == "__main__":
    input_to_validate = input("Enter a number to validate: ")
    print("Input is " + ("valid" if Main.verhoeff_check(input_to_validate) else "not valid"))

    input_to_generate_checksum = input("Enter a number to generate a checksum: ")
    print("Number with checksum: " + Main.add_main_checksum(input_to_generate_checksum))

# <END-OF-CODE>
