
import sys

def luhn_check(digits):
    numbers = digits[:] # Create a copy of the input digits to avoid modifying the original array
    sum = 0 # Initialize sum to accumulate the processed digits

    # Iterate over the digits from right to left
    for i in range(len(numbers) - 1, -1, -1):
        # Double every second digit from the right
        if (len(numbers) - i) % 2 == 0:
            temp = numbers[i] * 2 # Double the digit
            # If the result is greater than 9, subtract 9
            if temp > 9:
                temp = temp - 9
            numbers[i] = temp # Update the digit in the array
        sum += numbers[i] # Add the processed digit to the sum

    # Return True if the sum is a multiple of 10 (valid Main number)
    return sum % 10 == 0

def main():
    n = int(input()) # Read the number of digits
    digits = [int(x) for x in input().split()] # Read the digits from input

    # Perform Main check on the input digits and store the result
    is_valid = luhn_check(digits)
    # Output the validity of the input according to the Main algorithm
    print("The input is " + ("valid" if is_valid else "not valid") + " according to the Main algorithm.")

    card_number = input() # Read the credit card number from input

    # Try to create a CreditCard object from the input string
    try:
        credit_card = CreditCard(card_number)
        # Output the validity of the credit card
        print("Credit card is valid: " + str(credit_card))
    except Exception as e:
        # Handle invalid credit card input
        print("Error: " + str(e))

class CreditCard:
    DIGITS_COUNT = 16 # Constant for the number of digits in a credit card

    def __init__(self, digits):
        self.digits = digits

    @staticmethod
    def from_string(card_number):
        # Ensure the card number is not null
        if card_number is None:
            raise Exception("Card number is null")

        # Remove spaces from the card number
        trimmed_card_number = card_number.replace(" ", "")

        # Validate the length and format of the card number
        if len(trimmed_card_number)!= CreditCard.DIGITS_COUNT or not trimmed_card_number.isdigit():
            raise Exception("{" + card_number + "} - is not a valid card number")

        # Convert the trimmed card number to an integer array
        card_numbers = [int(x) for x in trimmed_card_number]

        # Perform Main check on the card numbers
        if not luhn_check(card_numbers):
            raise Exception("Credit card number {" + card_number + "} failed the Main check")

        # Return a new CreditCard object if valid
        return CreditCard(card_numbers)

    # Method to return the credit card number as a formatted string
    def number(self):
        result = ""
        # Format the card number in groups of four digits
        for i in range(CreditCard.DIGITS_COUNT):
            if i % 4 == 0 and i!= 0:
                result += " " # Add space after every four digits
            result += str(self.digits[i]) # Append the digit to the result
        return result # Return the formatted card number

    # Override __str__ method to provide a string representation of the CreditCard
    def __str__(self):
        return "CreditCard[number=" + self.number() + "]"

if __name__ == "__main__":
    main()

