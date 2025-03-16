import re

class Main:
    def __init__(self):
        pass

    # Main algorithm implementation to validate credit card numbers
    def luhnCheck(self, digits):
        numbers = digits[:] # Copy the input array
        sum = 0
        for i in range(len(numbers) - 1, -1, -1):
            if (len(numbers) - i) % 2 == 0:
                temp = numbers[i] * 2 # Double every second digit from the right
                if temp > 9:
                    temp = temp - 9 # If doubling results in a number greater than 9, subtract 9
                numbers[i] = temp # Update the digit
            sum += numbers[i] # Add the digit to the sum
        return sum % 10 == 0 # Check if the sum is divisible by 10

    # Main method to run the program
    def main(self):
        n = int(input()) # Read the number of digits
        inputDigits = list(map(int, input().split()))
        isValid = self.luhnCheck(inputDigits) # Validate the card number using Main algorithm
        print("The input is " + ("valid" if isValid else "not valid") + " according to the Main algorithm.")
        cardNumber = input() # Read the card number as a string
        try:
            creditCard = CreditCard.fromString(cardNumber) # Create a CreditCard object
            print("Credit card is valid: " + creditCard) # Print whether the card is valid
        except Exception as e:
            print("Error: " + str(e)) # Print error message if the card number is invalid

# Private nested class to encapsulate credit card logic
class CreditCard:
    DIGITS_COUNT = 16 # Number of digits in a credit card number

    # Constructor for CreditCard
    def __init__(self, digits):
        self.digits = digits

    # Method to create a CreditCard object from a string
    @staticmethod
    def fromString(cardNumber):
        if cardNumber is None:
            raise Exception("{" + cardNumber + "} - is not a valid card number") # Validate the card number format
        trimmedCardNumber = re.sub(r"\s+", "", cardNumber) # Remove spaces from the card number
        if len(trimmedCardNumber)!= CreditCard.DIGITS_COUNT or not re.match(r"\d+", trimmedCardNumber):
            raise Exception("{" + cardNumber + "} - is not a valid card number") # Validate the card number format
        cardNumbers = list(map(int, trimmedCardNumber)) # Convert the card number string to an array of digits
        if not Main().luhnCheck(cardNumbers): # Validate the card number using the Main algorithm
            raise Exception("Credit card number {" + cardNumber + "} failed the Main check") # Throw an exception if the card number is invalid
        return CreditCard(cardNumbers) # Return the CreditCard object

    # Method to format the card number for display
    def number(self):
        result = ""
        for i in range(CreditCard.DIGITS_COUNT):
            if i % 4 == 0 and i!= 0:
                result += " " # Add a space every four digits
            result += str(self.digits[i]) # Append the digit to the result
        return result

    # Override the toString method to provide a string representation of the CreditCard object
    def __str__(self):
        return "CreditCard[number=" + self.number() + "]" # Return the formatted string

if __name__ == "__main__":
    Main().main()

