
import sys

def divide(dividend, divisor):
    if divisor == 0:
        raise ArithmeticError("Division by zero")

    if dividend < 0:
        dividend = dividend * -1

    if divisor < 0:
        divisor = divisor * -1

    if dividend == 0 or dividend < divisor:
        return 0

    answer = ""
    dividendString = str(dividend)
    lastIndex = 0
    remainder = ""

    for i in range(len(dividendString)):
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

    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        try:
            return int(answer) * -1
        except ValueError:
            return -2147483648
    else:
        try:
            return int(answer)
        except ValueError:
            return 2147483647

if __name__ == "__main__":
    dividend = int(sys.stdin.readline())
    divisor = int(sys.stdin.readline())

    try:
        result = divide(dividend, divisor)
        print("Result: " + str(result))
    except ArithmeticError as e:
        print("Error: " + e.message)

