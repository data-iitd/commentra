import re

class Main:
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
        Main.check_input(digits)
        numbers = Main.to_int_array(digits)

        checksum = 0
        for number in numbers:
            checksum = Main.DAMM_TABLE[checksum][number]

        return checksum == 0

    @staticmethod
    def add_main_checksum(initial_digits):
        Main.check_input(initial_digits)
        numbers = Main.to_int_array(initial_digits)

        checksum = 0
        for number in numbers:
            checksum = Main.DAMM_TABLE[checksum][number]

        return initial_digits + str(checksum)

    @staticmethod
    def check_input(input):
        if input is None:
            raise ValueError("Input cannot be null")
        if not re.match(r'^\d+$', input):
            raise ValueError(f"Input '{input}' contains not only digits")

    @staticmethod
    def to_int_array(string):
        return [int(char) for char in string]

if __name__ == "__main__":
    operation = input().strip()

    if operation.lower() == "check":
        digits = input().strip()
        try:
            is_valid = Main.damm_check(digits)
            print(f"The input '{digits}' is {'valid' if is_valid else 'not valid'}")
        except Exception as e:
            print(f"Error: {e}")
    elif operation.lower() == "generate":
        print("Enter the input digits to generate checksum:")
        digits = input().strip()
        try:
            result = Main.add_main_checksum(digits)
            print(f"Generated value with checksum: {result}")
        except Exception as e:
            print(f"Error: {e}")
    else:
        print("Invalid operation. Please enter 'check' or 'generate'.")

# <END-OF-CODE>
