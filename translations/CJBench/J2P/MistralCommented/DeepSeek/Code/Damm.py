import re
from typing import List

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
    def damm_check(digits: str) -> bool:
        Main.check_input(digits)
        numbers = Main.to_int_array(digits)
        checksum = 0
        for number in numbers:
            checksum = Main.DAMM_TABLE[checksum][number]
        return checksum == 0

    @staticmethod
    def add_main_checksum(initial_digits: str) -> str:
        Main.check_input(initial_digits)
        numbers = Main.to_int_array(initial_digits)
        checksum = 0
        for number in numbers:
            checksum = Main.DAMM_TABLE[checksum][number]
        return initial_digits + str(checksum)

    @staticmethod
    def main(args: List[str]):
        if len(args) == 0:
            print("Please provide an operation: 'check' or 'generate'.")
            return

        operation = args[0].lower()
        if operation == "check":
            if len(args) < 2:
                print("Please provide the digits to check.")
                return
            digits = args[1]
            try:
                is_valid = Main.damm_check(digits)
                print(f"The input '{digits}' is {'valid' if is_valid else 'not valid'}")
            except Exception as e:
                print(f"Error: {e}")
        elif operation == "generate":
            if len(args) < 2:
                print("Please provide the digits to generate checksum for.")
                return
            digits = args[1]
            try:
                result = Main.add_main_checksum(digits)
                print(f"Generated value with checksum: {result}")
            except Exception as e:
                print(f"Error: {e}")
        else:
            print("Invalid operation. Please enter 'check' or 'generate'.")

    @staticmethod
    def check_input(input_str: str):
        if input_str is None:
            raise ValueError("Input cannot be None")
        if not re.match(r'^\d+$', input_str):
            raise ValueError(f"Input '{input_str}' contains not only digits")

    @staticmethod
    def to_int_array(string: str) -> List[int]:
        return [int(char) for char in string]

# Example usage:
# python Main.py check 123456
# python Main.py generate 123456
