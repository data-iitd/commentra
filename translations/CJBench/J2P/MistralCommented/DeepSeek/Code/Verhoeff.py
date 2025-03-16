import re
from typing import List

class Main:
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

    MULTIPLICATIVE_INVERSE = [0, 4, 3, 2, 1, 5, 6, 7, 8, 9]

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
    def verhoeff_check(digits: str) -> bool:
        Main.check_input(digits)
        numbers = Main.to_int_array(digits)
        checksum = 0
        for i in range(len(numbers)):
            index = len(numbers) - i - 1
            b = Main.PERMUTATION_TABLE[i % 8][numbers[index]]
            checksum = Main.MULTIPLICATION_TABLE[checksum][b]
        return checksum == 0

    @staticmethod
    def add_main_checksum(initial_digits: str) -> str:
        Main.check_input(initial_digits)
        modified_digits = initial_digits + "0"
        checksum = 0
        for i in range(len(modified_digits)):
            index = len(modified_digits) - i - 1
            b = Main.PERMUTATION_TABLE[i % 8][int(modified_digits[index]) if modified_digits[index].isdigit() else 10]
            checksum = Main.MULTIPLICATION_TABLE[checksum][b]
        checksum = Main.MULTIPLICATIVE_INVERSE[checksum]
        return initial_digits + str(checksum)

    @staticmethod
    def main():
        input_to_validate = input("Enter a number to validate: ")
        is_valid = Main.verhoeff_check(input_to_validate)
        print("Input is " + ("valid" if is_valid else "not valid"))

        input_to_generate_checksum = input("Enter a number to generate a checksum: ")
        checksum_result = Main.add_main_checksum(input_to_generate_checksum)
        print("Number with checksum: " + checksum_result)

    @staticmethod
    def check_input(input_str: str):
        if input_str is None:
            raise ValueError("Input cannot be None")
        if not re.match(r'^\d+$', input_str):
            raise ValueError("Input must contain only digits")

    @staticmethod
    def to_int_array(string: str) -> List[int]:
        return [int(char) for char in string]

if __name__ == "__main__":
    Main.main()
