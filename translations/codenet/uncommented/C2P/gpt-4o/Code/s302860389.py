def main():
    input_numbers = input("Enter four digits: ")
    
    a = int(input_numbers[0])
    b = int(input_numbers[1])
    c = int(input_numbers[2])
    d = int(input_numbers[3])
    
    symbols = ['+', '-']
    
    for i in range(2):
        for j in range(2):
            for k in range(2):
                if i == 0:
                    sum_result = a + b
                    symbol1 = symbols[0]
                else:
                    sum_result = a - b
                    symbol1 = symbols[1]

                if j == 0:
                    sum_result += c
                    symbol2 = symbols[0]
                else:
                    sum_result -= c
                    symbol2 = symbols[1]

                if k == 0:
                    sum_result += d
                    symbol3 = symbols[0]
                else:
                    sum_result -= d
                    symbol3 = symbols[1]

                if sum_result == 7:
                    print(f"{a}{symbol1}{b}{symbol2}{c}{symbol3}{d}=7")
                    return

if __name__ == "__main__":
    main()

# <END-OF-CODE>
