
import sys

def divide(dividend, divisor):
    # Convert dividend and divisor to long to handle overflow
    new_dividend = dividend
    new_divisor = divisor

    # Check for division by zero and throw an exception if true
    if divisor == 0:
        raise ArithmeticError("Division by zero")

    # Convert dividend to positive if it's negative
    if dividend < 0:
        new_dividend = new_dividend * -1

    # Convert divisor to positive if it's negative
    if divisor < 0:
        new_divisor = new_divisor * -1

    # If dividend is zero or less than divisor, return 0
    if dividend == 0 or new_dividend < new_divisor:
        return 0

    # StringBuilder to build the quotient as a string
    answer = []
    dividend_string = str(new_dividend)  # Convert dividend to string for processing
    last_index = 0  # Track the last processed index in the dividend string
    remainder = ""  # To hold the remainder during division

    # Loop through each digit of the dividend
    for i in range(len(dividend_string)):
        # Create the current part of the dividend to be divided
        part = remainder + dividend_string[last_index:i + 1]
        part_int = int(part)  # Convert the current part to int

        # If the current part is greater than or equal to the divisor
        if part_int >= new_divisor:
            quotient = 0  # Initialize quotient for this part
            # Subtract the divisor from the part until it's less than the divisor
            while part_int >= new_divisor:
                part_int = part_int - new_divisor
                quotient += 1
            # Append the quotient to the answer
            answer.append(str(quotient))
        else:
            # If the part is less than the divisor, append 0 to the answer
            answer.append("0")

        # Update the remainder for the next iteration
        remainder = part_int == 0? "" : str(part_int)
        last_index += 1  # Move to the next index

    # Adjust the sign of the result based on the original signs of dividend and divisor
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        try:
            # Return the negative of the computed quotient
            return int("".join(answer)) * (-1)
        except ValueError:
            # Handle overflow by returning sys.maxsize
            return sys.maxsize
    else:
        # Attempt to return the computed quotient as an integer
        try:
            return int("".join(answer))
        except ValueError:
            # Handle overflow by returning sys.maxsize
            return sys.maxsize

# Main method to execute the program
if __name__ == "__main__":
    dividend = int(input("Enter dividend: "))  # Read the dividend from input
    divisor = int(input("Enter divisor: "))  # Read the divisor from input

    # Try to perform the division and catch any arithmetic exceptions
    try:
        result = divide(dividend, divisor)  # Call the divide method
        print("Result: ", result)  # Print the result
    except ArithmeticError as e:
        # Print error message if division by zero occurs
        print("Error: ", e)

