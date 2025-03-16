import sys

def main():
    INF = 1000000000000000
    sc = sys.stdin
    number = sc.readline().strip()
    digits = [0] * (len(number) + 1)
    for i in range(len(number)):
        digits[i] = int(number[len(number) - 1 - i])
    bills = 0
    for i in range(len(digits)):
        if digits[i] == 10:
            digits[i + 1] += 1
            digits[i] = 0
        if digits[i] < 5:
            bills += digits[i]
        elif digits[i] == 5:
            if digits[i + 1] >= 5:
                digits[i + 1] += 1
            bills += 5
        else:
            digits[i + 1] += 1
            bills += 10 - digits[i]
    print(bills)

if __name__ == "__main__":
    main()

