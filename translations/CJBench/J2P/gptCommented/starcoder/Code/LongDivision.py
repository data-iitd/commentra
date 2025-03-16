# Private constructor to prevent instantiation of the class
class Main:
    def __init__(self):
        pass

    # Method to perform division of two integers without using the division operator
    def divide(self, dividend, divisor):
        # Convert dividend and divisor to long to handle overflow
        newDividend1 = dividend
        newDivisor1 = divisor

        # Check for division by zero and throw an exception if true
        if divisor == 0:
            raise ArithmeticError("Division by zero")

        # Convert dividend to positive if it's negative
        if dividend < 0:
            newDividend1 = newDividend1 * -1

        # Convert divisor to positive if it's negative
        if divisor < 0:
            newDivisor1 = newDivisor1 * -1

        # If dividend is zero or less than divisor, return 0
        if dividend == 0 or newDividend1 < newDivisor1:
            return 0

        # StringBuilder to build the quotient as a string
        answer = ""
        dividendString = str(newDividend1) # Convert dividend to string for processing
        lastIndex = 0 # Track the last processed index in the dividend string
        remainder = "" # To hold the remainder during division

        # Loop through each digit of the dividend
        for i in range(0, len(dividendString)):
            # Create the current part of the dividend to be divided
            partV1 = remainder + dividendString[lastIndex:i + 1]
            part1 = int(partV1) # Convert the current part to long

            # If the current part is greater than or equal to the divisor
            if part1 >= newDivisor1:
                quotient = 0 # Initialize quotient for this part
                # Subtract the divisor from the part until it's less than the divisor
                while part1 >= newDivisor1:
                    part1 = part1 - newDivisor1
                    quotient = quotient + 1
                # Append the quotient to the answer
                answer = answer + str(quotient)
            else:
                # If the part is less than the divisor, append 0 to the answer
                answer = answer + "0"

            # Update the remainder for the next iteration
            remainder = part1 == 0? "" : str(part1)
            lastIndex = lastIndex + 1 # Move to the next index

        # Adjust the sign of the result based on the original signs of dividend and divisor
        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
            # Return the negative of the computed quotient
            return int(answer) * (-1)

        # Attempt to return the computed quotient as an integer
        return int(answer)

# Main method to execute the program
if __name__ == '__main__':
    scanner = Scanner(System.in) # Create a scanner to read input
    dividend = scanner.nextInt() # Read the dividend from input
    divisor = scanner.nextInt() # Read the divisor from input

    # Try to perform the division and catch any arithmetic exceptions
    try:
        result = divide(dividend, divisor) # Call the divide method
        print("Result: " + result) # Print the result
    except ArithmeticError as e:
        # Print error message if division by zero occurs
        print("Error: " + e.getMessage())
    finally:
        # Close the scanner resource
        scanner.close()

