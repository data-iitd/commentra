
import re

class Main:
    def __init__(self):
        pass

    def luhnCheck(self, digits):
        numbers = digits[:]
        sum = 0

        for i in range(len(numbers) - 1, -1, -1):
            if (len(numbers) - i) % 2 == 0: # Alternate digits from right
                temp = numbers[i] * 2
                if temp > 9:
                    temp = temp - 9
                numbers[i] = temp
            sum += numbers[i]

        return sum % 10 == 0

    def main(self):
        n = int(input())
        inputDigits = [int(x) for x in input().split()]

        isValid = self.luhnCheck(inputDigits)
        print("The input is " + ("valid" if isValid else "not valid") + " according to the Main algorithm.")

        cardNumber = input()
        if re.match(r"^\d{16}$", cardNumber):
            try:
                creditCard = CreditCard.fromString(cardNumber)
                print("Credit card is valid: " + creditCard)
            except Exception as e:
                print("Error: " + str(e))
        else:
            print("Error: {" + cardNumber + "} - is not a valid card number")

class CreditCard:
    def __init__(self, digits):
        self.digits = digits

    @staticmethod
    def fromString(cardNumber):
        cardNumber = cardNumber.replace(" ", "")
        if not re.match(r"^\d{16}$", cardNumber):
            raise Exception("{" + cardNumber + "} - is not a valid card number")

        cardNumbers = [int(x) for x in cardNumber]
        if not Main().luhnCheck(cardNumbers):
            raise Exception("Credit card number {" + cardNumber + "} failed the Main check")

        return CreditCard(cardNumbers)

    def number(self):
        result = ""
        for i in range(0, 16):
            if i % 4 == 0 and i!= 0:
                result += " "
            result += str(self.digits[i])
        return result

    def __str__(self):
        return "CreditCard[number=" + self.number() + "]"

# 