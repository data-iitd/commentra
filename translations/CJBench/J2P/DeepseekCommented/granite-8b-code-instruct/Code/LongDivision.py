
import sys

def divide(dividend, divisor):
    # Check for division by zero and handle it by throwing a ZeroDivisionError.
    if divisor == 0:
        raise ZeroDivisionError("Division by zero")

    # Handle negative numbers by converting them to positive.
    if dividend < 0:
        dividend = dividend * -1
    if divisor < 0:
        divisor = divisor * -1

    # If dividend is zero or dividend is less than divisor, return 0.
    if dividend == 0 or dividend < divisor:
        return 0

    # Use StringBuilder to build the result of the division.
    answer = []
    dividend_string = str(dividend)
    last_index = 0
    remainder = ""

    # Loop through each digit of the dividend.
    for i in range(len(dividend_string)):
        part_v1 = remainder + dividend_string[last_index:i + 1]
        part_1 = int(part_v1)

        # Check if the current part is greater than or equal to the divisor.
        if part_1 >= divisor:
            quotient = 0
            while part_1 >= divisor:
                part_1 = part_1 - divisor
                quotient += 1
            answer.append(str(quotient))
        else:
            answer.append("0")

        # Update the remainder for the next iteration.
        remainder = part_1 == 0? "" : str(part_1)
        last_index += 1

    # Handle the sign of the result based on the signs of the dividend and divisor.
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        result = int("".join(answer)) * (-1)
    else:
        result = int("".join(answer))

    # Return the result.
    return result

# The main method is the entry point of the program.
# It reads two integers from the user, calls the divide method, and prints the result.
def main():
    dividend = int(input("Enter dividend: "))
    divisor = int(input("Enter divisor: "))
    try:
        result = divide(dividend, divisor)
        print("Result: ", result)
    except ZeroDivisionError as e:
        print("Error: ", e)

if __name__ == "__main__":
    main()

