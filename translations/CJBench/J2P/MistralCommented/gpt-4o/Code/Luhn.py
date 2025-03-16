import re

class CreditCard:
    DIGITS_COUNT = 16  # Constant representing the number of digits in a credit card number

    def __init__(self, digits):
        self.digits = digits  # Store the digits of the credit card number

    @staticmethod
    def from_string(card_number):
        if card_number is None:  # Check if the input string is not None
            raise ValueError("Card number cannot be None")

        trimmed_card_number = card_number.replace(" ", "")  # Remove any spaces from the input string

        if len(trimmed_card_number) != CreditCard.DIGITS_COUNT or not trimmed_card_number.isdigit():
            raise ValueError(f"{{{card_number}}} - is not a valid card number")  # Throw an exception if the input is invalid

        card_numbers = CreditCard.to_int_array(trimmed_card_number)  # Convert the input string to an array of integers

        if not Main.luhn_check(card_numbers):  # Check if the input digits form a valid number according to the Luhn algorithm
            raise ValueError(f"Credit card number {{{card_number}}} failed the Luhn check")  # Throw an exception if the input is invalid

        return CreditCard(card_numbers)  # Return a new CreditCard object with the valid digits

    def number(self):
        result = []
        for i in range(CreditCard.DIGITS_COUNT):  # Iterate through each digit and add a space every 4 digits (except for the last one)
            if i % 4 == 0 and i != 0:
                result.append(" ")
            result.append(str(self.digits[i]))
        return ''.join(result)

    def __str__(self):
        return f"CreditCard[number={self.number()}]"  # Override the default __str__ method to return a meaningful string representation of the CreditCard object

    @staticmethod
    def to_int_array(string):
        return [int(char) for char in string]  # Helper method to convert a string to an array of integers


class Main:
    @staticmethod
    def luhn_check(digits):
        numbers = digits[:]  # Create a copy of the input array to modify it in place
        sum_ = 0  # Initialize sum variable to store the sum of digits

        for i in range(len(numbers) - 1, -1, -1):  # Iterate through the array from the last digit to the first one
            if (len(numbers) - i) % 2 == 0:  # If the current index is even
                temp = numbers[i] * 2  # Multiply the current digit by 2
                if temp > 9:  # If the result is greater than 9
                    temp -= 9  # Subtract 9 to get the first digit of the result
                numbers[i] = temp  # Update the current digit with the first digit of the result
            sum_ += numbers[i]  # Add the current digit (or its doubled value) to the sum

        return sum_ % 10 == 0  # Return true if the sum is a multiple of 10, indicating a valid number according to the Luhn algorithm

    @staticmethod
    def main():
        n = int(input("Enter the number of digits in the card number: "))  # Read the number of digits in the input card number
        input_digits = []

        # Read the input digits from the console
        for _ in range(n):
            input_digits.append(int(input()))

        is_valid = Main.luhn_check(input_digits)  # Check if the input digits form a valid number according to the Luhn algorithm
        print(f"The input is {'valid' if is_valid else 'not valid'} according to the Luhn algorithm.")  # Print the result

        card_number = input("Enter the credit card number: ")  # Read the credit card number as a string from the console

        try:
            credit_card = CreditCard.from_string(card_number)  # Create a CreditCard object from the input string
            print(f"Credit card is valid: {credit_card}")  # Print the valid credit card object
        except ValueError as e:
            print(f"Error: {e}")  # Print the error message if the input is invalid


if __name__ == "__main__":
    Main.main()  # Run the main method

# <END-OF-CODE>
