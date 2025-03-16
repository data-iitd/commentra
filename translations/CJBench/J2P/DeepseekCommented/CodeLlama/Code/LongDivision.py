
# This method takes two integers, dividend and divisor, and returns their division result.
# It handles various edge cases, including division by zero and negative numbers.
def divide(dividend, divisor):
    # Check for division by zero and handle it by raising an ArithmeticError.
    if divisor == 0:
        raise ArithmeticError("Division by zero")

    # Handle negative numbers by converting them to positive.
    if dividend < 0:
        dividend = abs(dividend)
    if divisor < 0:
        divisor = abs(divisor)

    # If dividend is zero or dividend is less than divisor, return 0.
    if dividend == 0 or dividend < divisor:
        return 0

    # Use a string to build the result of the division.
    answer = ""
    dividend_string = str(dividend)
    last_index = 0
    remainder = ""

    # Loop through each digit of the dividend.
    for i in range(len(dividend_string)):
        part_v1 = remainder + dividend_string[last_index:i + 1]
        part1 = int(part_v1)

        # Check if the current part is greater than or equal to the divisor.
        if part1 >= divisor:
            quotient = 0
            while part1 >= divisor:
                part1 -= divisor
                quotient += 1
            answer += str(quotient)
        else:
            answer += "0"

        # Update the remainder for the next iteration.
        remainder = str(part1) if part1 != 0 else ""
        last_index += 1

    # Handle the sign of the result based on the signs of the dividend and divisor.
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        try:
            return -int(answer)
        except ValueError:
            return -sys.maxsize

    # Convert the result to an integer and return it.
    try:
        return int(answer)
    except ValueError:
        return sys.maxsize


# The main method is the entry point of the program.
# It reads two integers from the user, calls the divide method, and prints the result.
def main():
    dividend = int(input("Enter the dividend: "))
    divisor = int(input("Enter the divisor: "))
    try:
        result = divide(dividend, divisor)
        print("Result:", result)
    except ArithmeticError as e:
        print("Error:", e)


if __name__ == "__main__":
    main()

