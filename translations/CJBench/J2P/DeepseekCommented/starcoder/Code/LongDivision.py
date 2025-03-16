import sys

# This method takes two integers, dividend and divisor, and returns their division result.
# It handles various edge cases, including division by zero and negative numbers.
def divide(dividend, divisor):
    # Check for division by zero and handle it by throwing an ArithmeticException.
    if divisor == 0:
        raise ArithmeticError("Division by zero")

    # Handle negative numbers by converting them to positive.
    if dividend < 0:
        dividend = dividend * -1
    if divisor < 0:
        divisor = divisor * -1

    # If dividend is zero or dividend is less than divisor, return 0.
    if dividend == 0 or dividend < divisor:
        return 0

    # Use StringBuilder to build the result of the division.
    answer = ""
    dividendString = str(dividend)
    lastIndex = 0
    remainder = ""

    # Loop through each digit of the dividend.
    for i in range(len(dividendString)):
        partV1 = remainder + dividendString[lastIndex:i + 1]
        part1 = int(partV1)

        # Check if the current part is greater than or equal to the divisor.
        if part1 >= divisor:
            quotient = 0
            while part1 >= divisor:
                part1 = part1 - divisor
                quotient = quotient + 1
            answer = answer + str(quotient)
        else:
            answer = answer + "0"

        # Update the remainder for the next iteration.
        remainder = part1 == 0 and "" or str(part1)
        lastIndex = i + 1

    # Handle the sign of the result based on the signs of the dividend and divisor.
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        return int(answer) * -1

    # Convert the result to an integer and return it.
    return int(answer)

# The main method is the entry point of the program.
# It reads two integers from the user, calls the divide method, and prints the result.
def main():
    dividend = int(sys.stdin.readline())
    divisor = int(sys.stdin.readline())
    try:
        result = divide(dividend, divisor)
        print("Result: " + str(result))
    except ArithmeticError as e:
        print("Error: " + e.message)

if __name__ == "__main__":
    main()

