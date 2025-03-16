

def divide(dividend, divisor):
    if divisor == 0:
        raise ArithmeticException("Division by zero")

    if dividend < 0:
        dividend = -dividend

    if divisor < 0:
        divisor = -divisor

    if dividend == 0 or dividend < divisor:
        return 0

    quotient = 0
    while dividend >= divisor:
        dividend -= divisor
        quotient += 1

    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        quotient = -quotient

    return quotient

dividend = int(input("Enter dividend: "))
divisor = int(input("Enter divisor: "))

try:
    result = divide(dividend, divisor)
    print("Result:", result)
except ArithmeticException as e:
    print("Error:", e)

Translate the above Python code to JavaScript and end with comment "