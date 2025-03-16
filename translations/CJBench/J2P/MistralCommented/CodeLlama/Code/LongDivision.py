
def divide(dividend, divisor):
    new_dividend = dividend
    new_divisor = divisor

    if divisor == 0:
        raise ArithmeticError("Division by zero")

    if dividend < 0:
        new_dividend = new_dividend * -1

    if divisor < 0:
        new_divisor = new_divisor * -1

    if dividend == 0 or new_dividend < new_divisor:
        return 0

    answer = ""
    dividend_string = str(new_dividend)
    last_index = 0
    remainder = ""

    for i in range(len(dividend_string)):
        part_v1 = remainder + dividend_string[last_index:i + 1]
        part_1 = int(part_v1)

        if part_1 >= new_divisor:
            quotient = 0
            while part_1 >= new_divisor:
                part_1 = part_1 - new_divisor
                quotient += 1
            answer += str(quotient)
        else:
            answer += "0"

        remainder = part_1 == 0 and "" or str(part_1)
        last_index += 1

    if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
        try:
            return int(answer) * (-1)
        except ValueError:
            return -2147483648

    try:
        return int(answer)
    except ValueError:
        return 2147483647

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

