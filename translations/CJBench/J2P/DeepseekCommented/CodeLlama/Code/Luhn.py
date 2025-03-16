import re

# Main algorithm implementation to validate credit card numbers
def luhn_check(digits):
    numbers = list(digits) # Copy the input array
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
def main():
    n = int(input()) # Read the number of digits
    input_digits = list(map(int, input().split()))
    is_valid = luhn_check(input_digits) # Validate the card number using Main algorithm
    print("The input is " + ("valid" if is_valid else "not valid") + " according to the Main algorithm.")
    card_number = input() # Read the card number as a string
    try:
        credit_card = CreditCard(card_number) # Create a CreditCard object
        print("Credit card is valid: " + str(credit_card)) # Print whether the card is valid
    except ValueError as e:
        print("Error: " + str(e)) # Print error message if the card number is invalid

# Private nested class to encapsulate credit card logic
class CreditCard:
    DIGITS_COUNT = 16 # Number of digits in a credit card number

    # Constructor for CreditCard
    def __init__(self, card_number):
        self.card_number = card_number
        self.digits = self.to_int_array(self.card_number) # Convert the card number string to an array of digits
        if not self.is_valid(): # Validate the card number using the Main algorithm
            raise ValueError("Credit card number {" + self.card_number + "} failed the Main check") # Throw an exception if the card number is invalid

    # Method to format the card number for display
    def number(self):
        result = ""
        for i in range(self.DIGITS_COUNT):
            if i % 4 == 0 and i != 0:
                result += " " # Add a space every four digits
            result += str(self.digits[i]) # Append the digit to the result
        return result # Return the formatted card number

    # Override the toString method to provide a string representation of the CreditCard object
    def __str__(self):
        return "CreditCard[number=" + self.number() + "]" # Return the formatted string

    # Method to convert a string of digits to an array of integers
    def to_int_array(self, string):
        return [int(c) for c in string] # Convert each character to its numeric value and return the array

    # Method to validate the card number using the Main algorithm
    def is_valid(self):
        return luhn_check(self.digits) # Validate the card number using the Main algorithm

if __name__ == "__main__":
    main()

