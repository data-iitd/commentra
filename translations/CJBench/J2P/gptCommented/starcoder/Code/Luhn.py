import re

class Main:
    # Private constructor to prevent instantiation of the Main class
    def __init__(self):
        pass

    # Method to perform Main check on an array of digits
    def luhnCheck(self, digits):
        # Create a copy of the input digits to avoid modifying the original array
        numbers = digits[:]
        sum = 0 # Initialize sum to accumulate the processed digits

        # Iterate over the digits from right to left
        for i in range(len(numbers) - 1, -1, -1):
            # Double every second digit from the right
            if ((len(numbers) - i) % 2 == 0):
                temp = numbers[i] * 2 # Double the digit
                # If the result is greater than 9, subtract 9
                if (temp > 9):
                    temp = temp - 9
                numbers[i] = temp # Update the digit in the array
            sum += numbers[i] # Add the processed digit to the sum
        # Return true if the sum is a multiple of 10 (valid Main number)
        return sum % 10 == 0

    # Main method to execute the program
    def main(self):
        sc = Scanner(System.in) # Create a Scanner object for input
        n = sc.nextInt() # Read the number of digits
        inputDigits = [] # Initialize an array to hold the digits

        # Read the digits from input
        for i in range(n):
            inputDigits.append(sc.nextInt())

        # Perform Main check on the input digits and store the result
        isValid = self.luhnCheck(inputDigits)
        # Output the validity of the input according to the Main algorithm
        print("The input is " + ("valid" if isValid else "not valid") + " according to the Main algorithm.")

        sc.nextLine() # Consume the newline character after the integer input
        cardNumber = sc.nextLine() # Read the credit card number from input

        # Try to create a CreditCard object from the input string
        try:
            creditCard = CreditCard.fromString(cardNumber)
            # Output the validity of the credit card
            print("Credit card is valid: " + creditCard)
        except Exception as e:
            # Handle invalid credit card input
            print("Error: " + str(e))
        sc.close() # Close the scanner to free resources

    # Nested class to represent a Credit Card
    class CreditCard:
        DIGITS_COUNT = 16 # Constant for the number of digits in a credit card

        # Constructor to initialize the CreditCard with digits
        def __init__(self, digits):
            self.digits = digits

        # Static method to create a CreditCard object from a string representation
        @staticmethod
        def fromString(cardNumber):
            # Ensure the card number is not null
            if (cardNumber == None):
                raise Exception("{" + cardNumber + "} - is not a valid card number")
            # Remove spaces from the card number
            trimmedCardNumber = cardNumber.replace(" ", "")
            # Validate the length and format of the card number
            if (len(trimmedCardNumber)!= CreditCard.DIGITS_COUNT or not re.match("\\d+", trimmedCardNumber)):
                raise Exception("{" + cardNumber + "} - is not a valid card number")
            # Convert the trimmed card number to an integer array
            cardNumbers = [int(c) for c in trimmedCardNumber]
            # Perform Main check on the card numbers
            if (not self.luhnCheck(cardNumbers)):
                raise Exception("Credit card number {" + cardNumber + "} failed the Main check")
            # Return a new CreditCard object if valid
            return CreditCard(cardNumbers)

        # Method to return the credit card number as a formatted string
        def number(self):
            result = ""
            # Format the card number in groups of four digits
            for i in range(CreditCard.DIGITS_COUNT):
                if (i % 4 == 0 and i!= 0):
                    result += " " # Add space after every four digits
                result += str(self.digits[i]) # Append the digit to the result
            return result # Return the formatted card number

        # Override toString method to provide a string representation of the CreditCard
        def __str__(self):
            return "CreditCard[number=" + self.number() + "]"

# Main method to execute the program
if __name__ == "__main__":
    Main().main()

