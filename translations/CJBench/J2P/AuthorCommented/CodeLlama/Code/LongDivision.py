#        Given two integers dividend and divisor, divide two integers without using multiplication,
#        division, and mod operator.
#
#        The integer division should truncate toward zero, which means losing its fractional part.
#        For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2. My
#        method used Long Division, here is the source
#        "https://en.wikipedia.org/wiki/Long_division"

import math

def divide(dividend, divisor):
    # Check for division by zero
    if divisor == 0:
        raise ArithmeticError("Division by zero")

    # Convert both dividend and divisor to positive for simplicity
    if dividend < 0:
        dividend = abs(dividend)
    if divisor < 0:
        divisor = abs(divisor)

    # If dividend is 0 or smaller than divisor, return 0
    if dividend == 0 or dividend < divisor:
        return 0

    # To store the result as a string during long division
    answer = ""

    # Convert dividend to a string for digit-by-digit processing
    dividendString = str(dividend)
    lastIndex = 0

    remainder = ""

    # Iterate through each digit of the dividend string
    for i in range(len(dividendString)):
        # Extract the current part of the dividend
        partV1 = remainder + dividendString[lastIndex:i + 1]
        part1 = int(partV1)
        if part1 >= divisor:
            quotient = 0
            while part1 >= divisor:
                part1 = part1 - divisor
                quotient += 1
            answer += str(quotient)
        else:
            answer += "0"
        remainder = str(part1) if part1 != 0 else ""
        lastIndex += 1

    # Handle negative results based on the original signs of the dividend and divisor
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        return -1 * int(answer)

    # Return the result as an integer
    return int(answer)


def main():
    dividend = int(input("Enter dividend: "))
    divisor = int(input("Enter divisor: "))

    try:
        result = divide(dividend, divisor)
        print("Result:", result)
    except ArithmeticError as e:
        print("Error:", e)


if __name__ == "__main__":
    main()


