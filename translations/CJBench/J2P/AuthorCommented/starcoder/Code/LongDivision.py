# <START-OF-CODE>

def divide(dividend, divisor):
    # Check for division by zero
    if divisor == 0:
        raise ArithmeticError("Division by zero")
    # Convert both dividend and divisor to positive for simplicity
    if dividend < 0:
        dividend = dividend * -1
    if divisor < 0:
        divisor = divisor * -1
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
                quotient = quotient + 1
            answer = answer + str(quotient)
        else:
            answer = answer + "0"
        remainder = part1 == 0 and "" or str(part1)
        lastIndex = lastIndex + 1
    # Handle negative results based on the original signs of the dividend and divisor
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        return int(answer) * -1
    # Return the result as an integer
    return int(answer)

# 