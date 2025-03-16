import re

class Main:
    @staticmethod
    def luhn_check(digits):
        # Create a copy of the input digits to avoid modifying the original list
        numbers = digits.copy()
        total_sum = 0  # Initialize sum to accumulate the processed digits

        # Iterate over the digits from right to left
        for i in range(len(numbers) - 1, -1, -1):
            # Double every second digit from the right
            if (len(numbers) - i) % 2 == 0:
                temp = numbers[i] * 2  # Double the digit
                # If the result is greater than 9, subtract 9
                if temp > 9:
                    temp -= 9
                numbers[i] = temp  # Update the digit in the list
            total_sum += numbers[i]  # Add the processed digit to the sum

        # Return true if the sum is a multiple of 10 (valid Main number)
        return total_sum % 10 == 0

    @staticmethod
    def main():
        n = int(input("Enter the number of digits: "))  # Read the number of digits
        input_digits = list(map(int, input("Enter the digits: ").split()))  # Read the digits from input

        # Perform Main check on the input digits and store the result
        is_valid = Main.luhn_check(input_digits)
        # Output the validity of the input according to the Main algorithm
        print(f"The input is {'valid' if is_valid else 'not valid'} according to the Main algorithm.")

        card_number = input("Enter the credit card number: ")  # Read the credit card number from input

        # Try to create a CreditCard object from the input string
        try:
            credit_card = CreditCard.from_string(card_number)
            # Output the validity of the credit card
            print(f"Credit card is valid: {credit_card}")
        except ValueError as e:
            # Handle invalid credit card input
            print(f"Error: {e}")

class CreditCard:
    DIGITS_COUNT = 16  # Constant for the number of digits in a credit card

    def __init__(self, digits):
        self.digits = digits  # Initialize the CreditCard with digits

    @staticmethod
    def from_string(card_number):
        # Ensure the card number is not null
        if card_number is None:
            raise ValueError("Card number cannot be null")
        # Remove spaces from the card number
        trimmed_card_number = card_number.replace(" ", "")
        # Validate the length and format of the card number
        if len(trimmed_card_number) != CreditCard.DIGITS_COUNT or not re.match(r'^\d+$', trimmed_card_number):
            raise ValueError(f"{{{card_number}}} - is not a valid card number")
        # Convert the trimmed card number to an integer list
        card_numbers = CreditCard.to_int_array(trimmed_card_number)
        # Perform Main check on the card numbers
        if not Main.luhn_check(card_numbers):
            raise ValueError(f"Credit card number {{{card_number}}} failed the Main check")
        # Return a new CreditCard object if valid
        return CreditCard(card_numbers)

    def number(self):
        # Return the credit card number as a formatted string
        return ' '.join(str(self.digits[i]) for i in range(self.DIGITS_COUNT))

    def __str__(self):
        return f"CreditCard[number={self.number()}]"

    @staticmethod
    def to_int_array(string):
        return list(map(int, string))  # Convert each character to its numeric value

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
