def main():
    while True:
        x = input("Enter a string of digits separated by spaces or newline: ")
        sum_of_digits = 0
        for digit in x:
            if digit == ' ':
                continue
            elif digit == '\n':
                break
            else:
                sum_of_digits += int(digit)
        print("Sum of digits in previous string: {}".format(sum_of_digits))
        if x[0] == '0':
            break

if __name__ == "__main__":
    main()
