

import re

def luhn_check(digits):
    numbers = digits[:] # Create a copy of the input list to modify it in place
    sum = 0 # Initialize sum variable to store the sum of digits

    for i in range(len(numbers) - 1, -1, -1): # Iterate through the list from the last digit to the first one
        if (len(numbers) - i) % 2 == 0: # If the current index is even
            temp = numbers[i] * 2 # Multiply the current digit by 2
            if temp > 9: # If the result is greater than 9
                temp -= 9 # Subtract 9 to get the first digit of the result
            numbers[i] = temp # Update the current digit with the first digit of the result
        sum += numbers[i] # Add the current digit (or its doubled value) to the sum

    return sum % 10 == 0 # Return true if the sum is a multiple of 10, indicating a valid number according to the Main algorithm

def main():
    n = int(input("Enter the number of digits in the input card number: ")) # Read the number of digits in the input card number

    input_digits = [int(input("Enter digit " + str(i + 1) + ": ")) for i in range(n)] # Read the input digits from the console

    is_valid = luhn_check(input_digits) # Check if the input digits form a valid number according to the Main algorithm

    print("The input is " + ("valid" if is_valid else "not valid") + " according to the Main algorithm.") # Print the result

    card_number = input("Enter the credit card number: ") # Read the credit card number as a string from the console

    try:
        credit_card = CreditCard(card_number) # Create a CreditCard object from the input string
        print("Credit card is valid: " + str(credit_card)) # Print the valid credit card object
    except ValueError as e:
        print("Error: " + str(e)) # Print the error message if the input is invalid

class CreditCard:
    DIGITS_COUNT = 16 # Constant representing the number of digits in a credit card number

    def __init__(self, digits):
        self.digits = digits # Store the digits of the credit card number

    @staticmethod
    def from_string(card_number):
        card_number = re.sub(r"\s", "", card_number) # Remove any spaces from the input string

        if len(card_number)!= CreditCard.DIGITS_COUNT or not card_number.isdigit(): # Check if the input string has the correct length and is composed only of digits
            raise ValueError("{" + card_number + "} - is not a valid card number") # Throw a ValueError exception if the input is invalid

        card_numbers = [int(digit) for digit in card_number] # Convert the input string to a list of integers

        if not luhn_check(card_numbers): # Check if the input digits form a valid number according to the Main algorithm
            raise ValueError("Credit card number {" + card_number + "} failed the Main check") # Throw a ValueError exception if the input is invalid

        return CreditCard(card_numbers) # Return a new CreditCard object with the valid digits

    def number(self): # Method to format and return the credit card number as a string
        return " ".join(str(digit) for digit in self.digits) # Format the digits into a string with spaces every 4 digits (except for the last one)

    def __str__(self): # Override the default __str__ method to return a meaningful string representation of the CreditCard object
        return "CreditCard[number=" + self.number() + "]"

if __name__ == "__main__":
    main() # Call the main function to execute the program

