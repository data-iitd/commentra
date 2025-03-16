class DivisionError(Exception):
    pass

def divide(dividend: int, divisor: int) -> int:
    new_dividend = dividend
    new_divisor = divisor

    # Check for division by zero
    if divisor == 0:
        raise DivisionError("Division by zero")

    # Convert both dividend and divisor to positive for simplicity
    if dividend < 0:
        new_dividend = -new_dividend
    if divisor < 0:
        new_divisor = -new_divisor

    # If dividend is 0 or smaller than divisor, return 0
    if dividend == 0 or new_dividend < new_divisor:
        return 0

    # To store the result as a string during long division
    answer = []

    # Convert dividend to a string for digit-by-digit processing
    dividend_string = str(new_dividend)
    last_index = 0

    remainder = ""

    # Iterate through each digit of the dividend string
    for i in range(len(dividend_string)):
        # Extract the current part of the dividend
        part = remainder + dividend_string[last_index:i + 1]
        part_value = int(part)
        if part_value >= new_divisor:
            quotient = 0
            while part_value >= new_divisor:
                part_value -= new_divisor
                quotient += 1
            answer.append(str(quotient))
        else:
            answer.append('0')
        remainder = str(part_value) if part_value != 0 else ""
        last_index += 1

    # Handle negative results based on the original signs of the dividend and divisor
    if (dividend < 0) != (divisor < 0):
        try:
            return -int(''.join(answer))
        except ValueError:
            return -2**31  # Simulating Integer.MIN_VALUE
    # Return the result as an integer
    try:
        return int(''.join(answer))
    except ValueError:
        return 2**31 - 1  # Simulating Integer.MAX_VALUE

if __name__ == "__main__":
    dividend = int(input())
    divisor = int(input())

    try:
        result = divide(dividend, divisor)
        print("Result:", result)
    except DivisionError as e:
        print("Error:", e)

# <END-OF-CODE>
