import re
from typing import List

class CreditCard:
    DIGITS_COUNT = 16

    def __init__(self, digits: List[int]):
        self.digits = digits

    @staticmethod
    def from_string(card_number: str) -> 'CreditCard':
        card_number = card_number.replace(" ", "")
        if len(card_number) != CreditCard.DIGITS_COUNT or not re.match(r'^\d+$', card_number):
            raise ValueError(f"{{{card_number}}} - is not a valid card number")
        card_numbers = [int(digit) for digit in card_number]
        if not luhn_check(card_numbers):
            raise ValueError(f"Credit card number {{card_number}} failed the Luhn check")
        return CreditCard(card_numbers)

    def number(self) -> str:
        result = []
        for i in range(len(self.digits)):
            if i % 4 == 0 and i != 0:
                result.append(" ")
            result.append(str(self.digits[i]))
        return ''.join(result)

    def __str__(self) -> str:
        return f"CreditCard[number={self.number()}]"

def luhn_check(digits: List[int]) -> bool:
    numbers = digits[:]
    sum_ = 0
    for i in range(len(numbers) - 1, -1, -1):
        if (len(numbers) - i) % 2 == 0:
            temp = numbers[i] * 2
            if temp > 9:
                temp -= 9
            numbers[i] = temp
        sum_ += numbers[i]
    return sum_ % 10 == 0

class Main:
    @staticmethod
    def main():
        import sys
        input_lines = sys.stdin.readlines()
        n = int(input_lines[0].strip())
        input_digits = [int(digit) for digit in input_lines[1].strip().split()]
        if luhn_check(input_digits):
            print("The input is valid according to the Luhn algorithm.")
        else:
            print("The input is not valid according to the Luhn algorithm.")

        card_number = input_lines[2].strip()
        try:
            credit_card = CreditCard.from_string(card_number)
            print(f"Credit card is valid: {credit_card}")
        except ValueError as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    Main.main()
