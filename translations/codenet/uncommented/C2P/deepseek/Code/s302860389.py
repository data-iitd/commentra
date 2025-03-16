def main():
    input_numbers = input()
    a = int(input_numbers[0])
    b = int(input_numbers[1])
    c = int(input_numbers[2])
    d = int(input_numbers[3])

    for i in range(2):
        for j in range(2):
            for k in range(2):
                if i == 0:
                    sum = a + b
                    symbols = ['+', '+', '+']
                else:
                    sum = a - b
                    symbols = ['-', '-', '-']

                if j == 0:
                    sum += c
                    symbols[1] = '+'
                else:
                    sum -= c
                    symbols[1] = '-'

                if k == 0:
                    sum += d
                    symbols[2] = '+'
                else:
                    sum -= d
                    symbols[2] = '-'

                if sum == 7:
                    print(f"{a}{symbols[0]}{b}{symbols[1]}{c}{symbols[2]}{d}=7")
                    return


if __name__ == "__main__":
    main()
