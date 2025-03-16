
import re

class Main:
    def __init__(self):
        pass

    # Private constructor to prevent instantiation of the class from outside

    @staticmethod
    def luhnCheck(digits):
        numbers = digits[:] # Create a copy of the input array to modify it in place
        sum = 0 # Initialize sum variable to store the sum of digits

        for i in range(len(numbers) - 1, -1, -1): # Iterate through the array from the last digit to the first one
            if ((len(numbers) - i) % 2 == 0): # If the current index is even
                temp = numbers[i] * 2 # Multiply the current digit by 2
                if (temp > 9): # If the result is greater than 9
                    temp -= 9 # Subtract 9 to get the first digit of the result
                numbers[i] = temp # Update the current digit with the first digit of the result
            sum += numbers[i] # Add the current digit (or its doubled value) to the sum

        return sum % 10 == 0 # Return true if the sum is a multiple of 10, indicating a valid number according to the Main algorithm

    @staticmethod
    def main():
        sc = input() # Create a Scanner object to read input from the console

        # Read the number of digits in the input card number
        n = int(sc.next())

        inputDigits = [] # Create an array to store the input digits

        # Read the input digits from the console
        for i in range(n):
            inputDigits.append(int(sc.next()))

        isValid = luhnCheck(inputDigits) # Check if the input digits form a valid number according to the Main algorithm

        print("The input is " + ("valid" if isValid else "not valid") + " according to the Main algorithm.") # Print the result

        sc.close() # Close the Scanner object

        # Read the credit card number as a string from the console
        cardNumber = input()

        try:
            creditCard = CreditCard.fromString(cardNumber) # Create a CreditCard object from the input string
            print("Credit card is valid: " + creditCard) # Print the valid credit card object
        except ValueError as e:
            print("Error: " + e.args[0]) # Print the error message if the input is invalid

    class CreditCard:
        DIGITS_COUNT = 16 # Constant representing the number of digits in a credit card number

        def __init__(self, digits): # Constructor to initialize the CreditCard object with the input digits
            self.digits = digits

        @staticmethod
        def fromString(cardNumber): # Static method to create a CreditCard object from a string representation of the card number
            if (cardNumber is None): # Check if the input string is not null
                raise ValueError("{" + cardNumber + "} - is not a valid card number") # Throw an exception if the input is invalid

            trimmedCardNumber = re.sub(r"\s+", "", cardNumber) # Remove any spaces from the input string

            if (len(trimmedCardNumber)!= CreditCard.DIGITS_COUNT or not re.match(r"\d+", trimmedCardNumber)): # Check if the input string has the correct length and is composed only of digits
                raise ValueError("{" + cardNumber + "} - is not a valid card number") # Throw an exception if the input is invalid

            cardNumbers = list(map(int, trimmedCardNumber)) # Convert the input string to an array of integers

            if (not luhnCheck(cardNumbers)): # Check if the input digits form a valid number according to the Main algorithm
                raise ValueError("Credit card number {" + cardNumber + "} failed the Main check") # Throw an exception if the input is invalid

            return CreditCard(cardNumbers) # Return a new CreditCard object with the valid digits

        def number(self): # Method to format and return the credit card number as a string
            result = ""

            for i in range(CreditCard.DIGITS_COUNT): # Iterate through each digit and add a space every 4 digits (except for the last one)
                if (i % 4 == 0 and i!= 0):
                    result += " "
                result += str(self.digits[i])

            return result

        def __str__(self): # Override the default toString method to return a meaningful string representation of the CreditCard object
            return "CreditCard[number=" + self.number() + "]"

if __name__ == "__main__":
    Main.main()

