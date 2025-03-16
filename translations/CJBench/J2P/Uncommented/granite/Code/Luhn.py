

import re

def luhn_check(digits):
    numbers = digits[:]
    sum = 0
    for i in range(len(numbers) - 1, -1, -1):
        if (len(numbers) - i) % 2 == 0:
            temp = numbers[i] * 2
            if temp > 9:
                temp = temp - 9
            numbers[i] = temp
        sum += numbers[i]
    return sum % 10 == 0

def main():
    n = int(input())
    input_digits = list(map(int, input().split()))
    is_valid = luhn_check(input_digits)
    print("The input is " + ("valid" if is_valid else "not valid") + " according to the Main algorithm.")
    card_number = input()
    try:
        credit_card = CreditCard.from_string(card_number)
        print("Credit card is valid: " + str(credit_card))
    except Exception as e:
        print("Error: " + str(e))

class CreditCard:
    DIGITS_COUNT = 16

    def __init__(self, digits):
        self.digits = digits

    @staticmethod
    def from_string(card_number):
        trimmed_card_number = re.sub(r"\s", "", card_number)
        if len(trimmed_card_number)!= CreditCard.DIGITS_COUNT or not trimmed_card_number.isdigit():
            raise Exception("{" + card_number + "} - is not a valid card number")
        card_numbers = list(map(int, trimmed_card_number))
        if not luhn_check(card_numbers):
            raise Exception("Credit card number {" + card_number + "} failed the Main check")
        return CreditCard(card_numbers)

    def number(self):
        result = ""
        for i in range(CreditCard.DIGITS_COUNT):
            if i % 4 == 0 and i!= 0:
                result += " "
            result += str(self.digits[i])
        return result

    def __str__(self):
        return "CreditCard[number=" + self.number() + "]"

if __name__ == "__main__":
    main()

