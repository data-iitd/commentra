

import sys

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
    print("The input is {} according to the Main algorithm.".format("valid" if is_valid else "not valid"))

    card_number = input()

    try:
        credit_card = CreditCard(card_number)
        print("Credit card is valid: {}".format(credit_card))
    except Exception as e:
        print("Error: {}".format(e))

class CreditCard:
    DIGITS_COUNT = 16

    def __init__(self, card_number):
        self.digits = [int(digit) for digit in card_number]
        if len(self.digits)!= self.DIGITS_COUNT or not all(str(digit).isdigit() for digit in self.digits):
            raise Exception("{} is not a valid card number".format(card_number))

        if not luhn_check(self.digits):
            raise Exception("Credit card number {} failed the Main check".format(card_number))

    def number(self):
        return " ".join(str(digit) for digit in self.digits)

    def __str__(self):
        return "CreditCard[number={}]".format(self.number())

if __name__ == "__main__":
    main()

