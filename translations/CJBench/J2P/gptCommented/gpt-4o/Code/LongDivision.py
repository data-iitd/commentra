class DivisionByZeroError(Exception):
    pass

def divide(dividend, divisor):
    # Check for division by zero and raise an exception if true
    if divisor == 0:
        raise DivisionByZeroError("Division by zero")

    # Convert dividend and divisor to positive if they're negative
    new_dividend = abs(dividend)
    new_divisor = abs(divisor)

    # If dividend is zero or less than divisor, return 0
    if new_dividend == 0 or new_dividend < new_divisor:
        return 0

    # String to build the quotient as a string
    answer = ""
    dividend_string = str(new_dividend)  # Convert dividend to string for processing
    last_index = 0  # Track the last processed index in the dividend string
    remainder = ""  # To hold the remainder during division

    # Loop through each digit of the dividend
    for i in range(len(dividend_string)):
        # Create the current part of the dividend to be divided
        part = remainder + dividend_string[last_index:i + 1]
        part_value = int(part)  # Convert the current part to int

        # If the current part is greater than or equal to the divisor
        if part_value >= new_divisor:
            quotient = 0  # Initialize quotient for this part
            # Subtract the divisor from the part until it's less than the divisor
            while part_value >= new_divisor:
                part_value -= new_divisor
                quotient += 1
            # Append the quotient to the answer
            answer += str(quotient)
        else:
            # If the part is less than the divisor, append 0 to the answer
            answer += "0"

        # Update the remainder for the next iteration
        remainder = str(part_value) if part_value != 0 else ""
        last_index += 1  # Move to the next index

    # Adjust the sign of the result based on the original signs of dividend and divisor
    if (dividend < 0) ^ (divisor < 0):  # XOR to check if signs are different
        return -int(answer) if answer else 0

    # Return the computed quotient as an integer
    return int(answer) if answer else 0

# Main function to execute the program
if __name__ == "__main__":
    try:
        dividend = int(input("Enter dividend: "))  # Read the dividend from input
        divisor = int(input("Enter divisor: "))  # Read the divisor from input

        # Try to perform the division
        result = divide(dividend, divisor)  # Call the divide method
        print("Result:", result)  # Print the result
    except DivisionByZeroError as e:
        # Print error message if division by zero occurs
        print("Error:", e)
    except ValueError:
        print("Error: Invalid input. Please enter integers.")
        
# <END-OF-CODE>
