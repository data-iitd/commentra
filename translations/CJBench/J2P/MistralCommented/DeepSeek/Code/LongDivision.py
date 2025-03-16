class Main:
    @staticmethod
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
        dividend_str = str(new_dividend)
        last_index = 0
        remainder = ""

        for i in range(len(dividend_str)):
            part_v1 = remainder + dividend_str[last_index:i + 1]
            part1 = int(part_v1)

            if part1 >= new_divisor:
                quotient = 0
                while part1 >= new_divisor:
                    part1 -= new_divisor
                    quotient += 1
                answer += str(quotient)
            else:
                answer += "0"

            remainder = "0" if part1 == 0 else str(part1)
            last_index += 1

        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
            return -int(answer)

        return int(answer)

    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        dividend = int(data[0])
        divisor = int(data[1])

        try:
            result = Main.divide(dividend, divisor)
            print("Result:", result)
        except ArithmeticError as e:
            print("Error:", e)


Main.main()
