def divide(dividend, divisor):
    new_dividend = dividend
    new_divisor = divisor

    # Check for division by zero
    if divisor == 0:
        raise ArithmeticError("Division by zero")

    # Convert both dividend and divisor to positive for simplicity
    if dividend < 0:
        new_dividend = new_dividend * -1
    if divisor < 0:
        new_divisor = new_divisor * -1

    # If dividend is 0 or smaller than divisor, return 0
    if dividend == 0 or new_dividend < new_divisor:
        return 0

    # To store the result as a string during long division
    answer = ""

    # Convert dividend to a string for digit-by-digit processing
    dividend_str = str(new_dividend)
    last_index = 0

    remainder = ""

    # Iterate through each digit of the dividend string
    for i in range(len(dividend_str)):
        # Extract the current part of the dividend
        part_v1 = remainder + dividend_str[last_index:i+1]
        part1 = int(part_v1)
        if part1 >= new_divisor:
            quotient = 0
            while part1 >= new_divisor:
                part1 -= new_divisor
                quotient += 1
            answer += str(quotient)
        else:
            answer += "0"
        remainder = "" if part1 == 0 else str(part1)
        last_index += 1

    # Handle negative results based on the original signs of the dividend and divisor
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        try:
            return int(answer) * (-1)
        except ValueError:
            return -2**31

    # Return the result as an integer
    try:
        return int(answer)
    except ValueError:
        return 2**31 - 1


# Main function to take input and print the result
def main():
    dividend = int(input())
    divisor = int(input())

    try:
        result = divide(dividend, divisor)
        print("Result:", result)
    except ArithmeticError as e:
        print("Error:", e)


if __name__ == "__main__":
    main()
