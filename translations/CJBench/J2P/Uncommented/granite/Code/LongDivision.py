

def divide(dividend, divisor):
    if divisor == 0:
        raise ArithmeticError("Division by zero")
    if dividend < 0:
        dividend = dividend * -1
    if divisor < 0:
        divisor = divisor * -1
    if dividend == 0 or dividend < divisor:
        return 0
    answer = []
    dividend_string = str(dividend)
    last_index = 0
    remainder = ""
    for i in range(len(dividend_string)):
        part_v1 = remainder + dividend_string[last_index:i + 1]
        part_1 = int(part_v1)
        if part_1 >= divisor:
            quotient = 0
            while part_1 >= divisor:
                part_1 = part_1 - divisor
                quotient += 1
            answer.append(str(quotient))
        else:
            answer.append("0")
        remainder = part_1 == 0? "" : str(part_1)
        last_index += 1
    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        result = int("".join(answer)) * (-1)
    else:
        result = int("".join(answer))
    return result

dividend = int(input("Enter dividend: "))
divisor = int(input("Enter divisor: "))
try:
    result = divide(dividend, divisor)
    print("Result: ", result)
except ArithmeticError as e:
    print("Error: ", e)

