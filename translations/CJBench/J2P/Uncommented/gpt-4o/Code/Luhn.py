import re

class Main:
    @staticmethod
    def luhn_check(digits):
        numbers = digits.copy()
        sum_ = 0
        for i in range(len(numbers) - 1, -1, -1):
            if (len(numbers) - i) % 2 == 0:
                temp = numbers[i] * 2
                if temp > 9:
                    temp -= 9
                numbers[i] = temp
            sum_ += numbers[i]
        return sum_ % 10 == 0

    @staticmethod
    def main():
        n = int(input())
        input_digits = [int(input()) for _ in range(n)]
        is_valid = Main.luhn_check(input_digits)
        print(f"The input is {'valid' if is_valid else 'not valid'} according to the Main algorithm.")
        
        card_number = input().strip()
        try:
            credit_card = CreditCard.from_string(card_number)
            print(f"Credit card is valid: {credit_card}")
        except ValueError as e:
            print(f"Error: {e}")

class CreditCard:
    DIGITS_COUNT = 16

    def __init__(self, digits):
        self.digits = digits

    @staticmethod
    def from_string(card_number):
        if card_number is None:
            raise ValueError("Card number cannot be None")
        
        trimmed_card_number = re.sub(r'\s+', '', card_number)
        if len(trimmed_card_number) != CreditCard.DIGITS_COUNT or not trimmed_card_number.isdigit():
            raise ValueError(f"{{{card_number}}} - is not a valid card number")
        
        card_numbers = CreditCard.to_int_array(trimmed_card_number)
        if not Main.luhn_check(card_numbers):
            raise ValueError(f"Credit card number {{{card_number}}} failed the Main check")
        
        return CreditCard(card_numbers)

    def number(self):
        result = []
        for i in range(self.DIGITS_COUNT):
            if i % 4 == 0 and i != 0:
                result.append(" ")
            result.append(str(self.digits[i]))
        return ''.join(result)

    def __str__(self):
        return f"CreditCard[number={self.number()}]"

    @staticmethod
    def to_int_array(string):
        return [int(char) for char in string]

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
