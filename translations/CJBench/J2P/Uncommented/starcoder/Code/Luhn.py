
import re

def luhnCheck(digits):
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
    input = input()
    input = input.split()
    digits = [int(x) for x in input]
    isValid = luhnCheck(digits)
    print("The input is " + ("valid" if isValid else "not valid") + " according to the Main algorithm.")
    cardNumber = input()
    try:
        creditCard = CreditCard.fromString(cardNumber)
        print("Credit card is valid: " + creditCard)
    except Exception as e:
        print("Error: " + str(e))

class CreditCard:
    DIGITS_COUNT = 16
    def __init__(self, digits):
        self.digits = digits
    @staticmethod
    def fromString(cardNumber):
        cardNumber = cardNumber.replace(" ", "")
        if len(cardNumber)!= CreditCard.DIGITS_COUNT or not re.match("\\d+", cardNumber):
            raise Exception("{" + cardNumber + "} - is not a valid card number")
        cardNumbers = [int(x) for x in cardNumber]
        if not luhnCheck(cardNumbers):
            raise Exception("Credit card number {" + cardNumber + "} failed the Main check")
        return CreditCard(cardNumbers)
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

