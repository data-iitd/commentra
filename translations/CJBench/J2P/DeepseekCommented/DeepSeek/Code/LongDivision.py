def divide(dividend, divisor):
    new_dividend = dividend
    new_divisor = divisor

    # Check for division by zero and handle it by raising a ValueError.
    if divisor == 0:
        raise ValueError("Division by zero")

    # Handle negative numbers by converting them to positive.
    if dividend < 0:
        new_dividend = new_dividend * -1
    if divisor < 0:
        new_divisor = new_divisor * -1

    # If dividend is zero or dividend is less than divisor, return 0.
    if dividend == 0 or new_dividend < new_divisor:
        return 0

    # Use a list to build the result of the division.
    answer = []
    dividend_str = str(new_dividend)
    last_index = 0
    remainder = ""

    # Loop through each digit of the dividend.
    for i in range(len(dividend_str)):
        part_v1 = remainder + dividend_str[last_index:i+1]
        part1 = int(part_v1)

        # Check if the current part is greater than or equal to the divisor.
        if part1 >= new_divisor:
            quotient = 0
            while part1 >= new_divisor:
                part1 -= new_divisor
                quotient += 1
            answer.append(str(quotient))
        else:
            answer.append('0')

        # Update the remainder for the next iteration.
        remainder = str(part1) if part1 != 0 else ""
        last_index += 1

    # Handle the sign of the result based on the signs of the dividend and divisor.
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        result = int(''.join(answer)) * -1
    else:
        result = int(''.join(answer))

    # Return the result.
    return result


# The main function is the entry point of the program.
# It reads two integers from the user, calls the divide method, and prints the result.
def main():
    try:
        dividend = int(input())
        divisor = int(input())
        result = divide(dividend, divisor)
        print("Result:", result)
    except ValueError as e:
        print("Error:", e)


main()
