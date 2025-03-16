def luhn_check(digits):
    numbers = digits[:]
    sum_ = 0

    for i in range(len(numbers) - 1, -1, -1):
        if (len(numbers) - i) % 2 == 0:  # Alternate digits from right
            temp = numbers[i] * 2
            if temp > 9:
                temp = temp - 9
            numbers[i] = temp
        sum_ += numbers[i]

    return sum_ % 10 == 0


class CreditCard:
    DIGITS_COUNT = 16

    def __init__(self, digits):
        self.digits = digits

    @staticmethod
    def from_string(card_number):
        card_number = card_number.replace(" ", "")
        if len(card_number) != CreditCard.DIGITS_COUNT or not card_number.isdigit():
            raise ValueError(f"{{{card_number}}} - is not a valid card number")

        card_numbers = [int(char) for char in card_number]
        if not luhn_check(card_numbers):
            raise ValueError(f"Credit card number {{ {card_number} }} failed the Main check")

        return CreditCard(card_numbers)

    def number(self):
        result = []
        for i in range(CreditCard.DIGITS_COUNT):
            if i % 4 == 0 and i != 0:
                result.append(" ")
            result.append(str(self.digits[i]))
        return ''.join(result)

    def __str__(self):
        return f"CreditCard[number={self.number()}]"


def main():
    n = int(input())
    input_digits = [int(input()) for _ in range(n)]

    is_valid = luhn_check(input_digits)
    print("The input is " + ("valid" if is_valid else "not valid") + " according to the Main algorithm.")

    card_number = input()

    try:
        credit_card = CreditCard.from_string(card_number)
        print("Credit card is valid: " + str(credit_card))
    except ValueError as e:
        print("Error: " + str(e))


if __name__ == "__main__":
    main()
