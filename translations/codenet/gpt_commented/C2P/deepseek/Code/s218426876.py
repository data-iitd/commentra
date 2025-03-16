def main():
    while True:
        x = input()
        if x == '0':
            break
        sum_of_digits = sum(int(digit) for digit in x)
        print(sum_of_digits)

if __name__ == "__main__":
    main()

