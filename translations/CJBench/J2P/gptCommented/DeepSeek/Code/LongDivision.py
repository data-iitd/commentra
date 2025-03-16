def divide(dividend, divisor):
    # Convert dividend and divisor to long to handle overflow
    new_dividend = dividend
    new_divisor = divisor

    # Check for division by zero and raise an exception if true
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

    # Initialize the quotient and remainder
    quotient = 0
    remainder = 0

    # Loop through each digit of the dividend
    for i in range(len(str(new_dividend))):
        # Create the current part of the dividend to be divided
        part = remainder * 10 + int(str(new_dividend)[i])

        # If the current part is greater than or equal to the divisor
        if part >= new_divisor:
            # Subtract the divisor from the part until it's less than the divisor
            while part >= new_divisor:
                part -= new_divisor
                quotient += 1

        # Update the remainder for the next iteration
        remainder = part

    # Adjust the sign of the result based on the original signs of dividend and divisor
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        quotient = -quotient

    # Check for overflow and return the appropriate result
    if quotient < -2**31:
        return -2**31
    elif quotient > 2**31 - 1:
        return 2**31 - 1
    else:
        return quotient

# Main method to execute the program
def main():
    # Read the dividend and divisor from input
    dividend = int(input())
    divisor = int(input())

    # Try to perform the division and catch any arithmetic exceptions
    try:
        result = divide(dividend, divisor)  # Call the divide method
        print("Result:", result)  # Print the result
    except ArithmeticError as e:
        # Print error message if division by zero occurs
        print("Error:", e)

# Call the main method
if __name__ == "__main__":
    main()
