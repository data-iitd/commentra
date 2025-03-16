def main():
    x = int(input())
    digits = []
    while x > 0:
        r = x % 10
        if 9 - r < r:
            if x // 10 == 0 and 9 - r == 0:
                digits.append(r)
            else:
                digits.append(9 - r)
        else:
            digits.append(r)
        x = x // 10
    digits.reverse()
    new_number = 0
    for i in range(len(digits)):
        new_number += digits[i] * (10 ** i)
    print(new_number)

if __name__ == "__main__":
    main()
