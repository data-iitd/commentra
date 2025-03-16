
import re

# Main algorithm implementation to validate credit card numbers
def luhn_check(digits):
    numbers = digits[:] # Copy the input list
    sum = 0
    for i in range(len(numbers) - 1, -1, -1):
        if (len(numbers) - i) % 2 == 0:
            temp = numbers[i] * 2
            if temp > 9:
                temp = temp - 9
            numbers[i] = temp
        sum += numbers[i]
    return sum % 10 == 0

# Main method to run the program
def main():
    n = int(input("Enter the number of digits: ")) # Read the number of digits
    digits = [int(x) for x in input("Enter the digits: ").split()] # Read the digits
    if luhn_check(digits): # Validate the card number using the Main algorithm
        print("The input is valid according to the Main algorithm.")
    else:
        print("The input is not valid according to the Main algorithm.")
    card_number = input("Enter the credit card number: ") # Read the credit card number as a string
    try:
        credit_card = CreditCard.from_string(card_number) # Create a CreditCard object
        print("Credit card is valid: " + str(credit_card)) # Print whether the card is valid
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
    def from_string(card_number):
        card_number = re.sub(r'\s', '', card_number) # Remove spaces from the card number
        if len(card_number)!= CreditCard.DIGITS_COUNT or not card_number.isdigit():
            raise Exception("{" + card_number + "} - is not a valid card number") # Validate the card number format
        card_numbers = [int(x) for x in card_number] # Convert the card number string to an array of digits
        if not luhn_check(card_numbers): # Validate the card number using the Main algorithm
            raise Exception("Credit card number {" + card_number + "} failed the Main check") # Throw an exception if the card number is invalid
        return CreditCard(card_numbers) # Return the CreditCard object

    # Method to format the card number for display
    def number(self):
        result = ""
        for i in range(CreditCard.DIGITS_COUNT):
            if i % 4 == 0 and i!= 0:
                result += " " # Add a space every four digits
            result += str(self.digits[i]) # Append the digit to the result
        return result # Return the formatted card number

    # Override the __str__ method to provide a string representation of the CreditCard object
    def __str__(self):
        return "CreditCard[number=" + self.number() + "]" # Return the formatted string

if __name__ == "__main__":
    main() # Call the main method to run the program

# End of code