
import re
import sys

def luhn_check(digits):
    numbers = list(digits)
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
        credit_card = CreditCard(card_number)
        print("Credit card is valid: " + str(credit_card))
    except ValueError as e:
        print("Error: " + str(e))

class CreditCard:
    DIGITS_COUNT = 16
    def __init__(self, card_number):
        self.card_number = card_number
        self.digits = self.to_int_array(self.card_number)
        if len(self.digits) != self.DIGITS_COUNT or not re.match("\\d+", self.card_number):
            raise ValueError("{" + self.card_number + "} - is not a valid card number")
        if not luhn_check(self.digits):
            raise ValueError("Credit card number {" + self.card_number + "} failed the Main check")

    def number(self):
        result = ""
        for i in range(self.DIGITS_COUNT):
            if i % 4 == 0 and i != 0:
                result += " "
            result += str(self.digits[i])
        return result

    def __str__(self):
        return "CreditCard[number={}]".format(self.number())

    @staticmethod
    def to_int_array(string):
        return [ord(c) - ord('0') for c in string]

if __name__ == "__main__":
    main()

