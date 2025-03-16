
# Import the Scanner class from the java.util package
from java.util import Scanner

# Private constructor to prevent instantiation of the class
class Main:
    def __init__(self):
        pass

    # Method to perform division of two integers without using the division operator
    @staticmethod
    def divide(dividend, divisor):
        # Convert dividend and divisor to long to handle overflow
        new_dividend1 = dividend
        new_divisor1 = divisor

        # Check for division by zero and throw an exception if true
        if divisor == 0:
            raise ArithmeticError("Division by zero")

        # Convert dividend to positive if it's negative
        if dividend < 0:
            new_dividend1 = new_dividend1 * -1

        # Convert divisor to positive if it's negative
        if divisor < 0:
            new_divisor1 = new_divisor1 * -1

        # If dividend is zero or less than divisor, return 0
        if dividend == 0 or new_dividend1 < new_divisor1:
            return 0

        # StringBuilder to build the quotient as a string
        answer = ""
        dividend_string = str(new_dividend1)  # Convert dividend to string for processing
        last_index = 0  # Track the last processed index in the dividend string
        remainder = ""  # To hold the remainder during division

        # Loop through each digit of the dividend
        for i in range(len(dividend_string)):
            # Create the current part of the dividend to be divided
            part_v1 = remainder + dividend_string[last_index:i + 1]
            part1 = int(part_v1)  # Convert the current part to long

            # If the current part is greater than or equal to the divisor
            if part1 >= new_divisor1:
                quotient = 0  # Initialize quotient for this part
                # Subtract the divisor from the part until it's less than the divisor
                while part1 >= new_divisor1:
                    part1 = part1 - new_divisor1
                    quotient += 1
                # Append the quotient to the answer
                answer += str(quotient)
            else:
                # If the part is less than the divisor, append 0 to the answer
                answer += "0"

            # Update the remainder for the next iteration
            remainder = str(part1) if part1 != 0 else ""
            last_index += 1  # Move to the next index

        # Adjust the sign of the result based on the original signs of dividend and divisor
        if ((dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0)):
            try:
                # Return the negative of the computed quotient
                return -int(answer)
            except ValueError:
                # Handle overflow by returning Integer.MIN_VALUE
                return -2147483648

        # Attempt to return the computed quotient as an integer
        try:
            return int(answer)
        except ValueError:
            # Handle overflow by returning Integer.MAX_VALUE
            return 2147483647

    # Main method to execute the program
    @staticmethod
    def main(args):
        scanner = Scanner(System.in)  # Create a scanner to read input
        dividend = scanner.nextInt()  # Read the dividend from input
        divisor = scanner.nextInt()  # Read the divisor from input

        # Try to perform the division and catch any arithmetic exceptions
        try:
            result = Main.divide(dividend, divisor)  # Call the divide method
            print("Result: " + str(result))  # Print the result
        except ArithmeticError as e:
            # Print error message if division by zero occurs
            print("Error: " + str(e))
        finally:
            # Close the scanner resource
            scanner.close()


# End of code
