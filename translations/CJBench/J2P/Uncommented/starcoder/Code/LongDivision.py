
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
    while dividend >= divisor:
        dividend = dividend - divisor
        answer = answer + "1"
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        answer = answer * -1
    return int(answer)

if __name__ == "__main__":
    try:
        dividend = int(input("Enter dividend: "))
        divisor = int(input("Enter divisor: "))
        result = divide(dividend, divisor)
        print("Result: " + str(result))
    except ValueError:
        print("Error: Invalid input")
    except ArithmeticError as e:
        print("Error: " + e.args[0])

