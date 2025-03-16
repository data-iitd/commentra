import re

class Main:
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

    @staticmethod
    def damm_check(digits):
        Main.check_input(digits)  # Validate input format
        numbers = Main.to_int_array(digits)  # Convert input string to an integer array
        checksum = 0  # Initialize checksum

        # Calculate checksum using the Main table
        for number in numbers:
            checksum = Main.DAMM_TABLE[checksum][number]
        # Return true if checksum is 0 (valid), false otherwise
        return checksum == 0

    @staticmethod
    def add_main_checksum(initial_digits):
        Main.check_input(initial_digits)  # Validate input format
        numbers = Main.to_int_array(initial_digits)  # Convert input string to an integer array
        checksum = 0  # Initialize checksum

        # Calculate checksum using the Main table
        for number in numbers:
            checksum = Main.DAMM_TABLE[checksum][number]
        # Return the original digits concatenated with the checksum
        return initial_digits + str(checksum)

    @staticmethod
    def check_input(input):
        if input is None:  # Ensure input is not null
            raise ValueError("Input cannot be None")
        if not re.match(r'^\d+$', input):  # Check if input contains only digits
            raise ValueError(f"Input '{input}' contains not only digits")

    @staticmethod
    def to_int_array(string):
        return [int(char) for char in string]  # Convert each character to its integer value

if __name__ == "__main__":
    operation = input("Enter operation (check or generate): ")  # Read the operation type (check or generate)

    # Check operation: Validate input digits
    if operation.lower() == "check":
        digits = input("Enter the digits to check: ")  # Read the digits to check
        try:
            is_valid = Main.damm_check(digits)  # Validate the digits
            # Output the result of the validation
            print(f"The input '{digits}' is {'valid' if is_valid else 'not valid'}")
        except Exception as e:
            # Handle any exceptions that occur during validation
            print(f"Error: {e}")
    # Generate operation: Create a checksum for the input digits
    elif operation.lower() == "generate":
        digits = input("Enter the input digits to generate checksum: ")  # Read the digits to generate checksum
        try:
            result = Main.add_main_checksum(digits)  # Generate the checksum
            # Output the result with the checksum
            print(f"Generated value with checksum: {result}")
        except Exception as e:
            # Handle any exceptions that occur during checksum generation
            print(f"Error: {e}")
    else:
        # Handle invalid operation input
        print("Invalid operation. Please enter 'check' or 'generate'.")
        
# <END-OF-CODE>
