
#include <stdio.h>
#include <stdlib.h>

def main():
    inputNumbers = raw_input()
    temp = ""
    a = 0
    b = 0
    c = 0
    d = 0
    sum = 0
    symbols = ""

    temp = inputNumbers[0]
    a = int(temp)
    temp = inputNumbers[1]
    b = int(temp)
    temp = inputNumbers[2]
    c = int(temp)
    temp = inputNumbers[3]
    d = int(temp)

    for i in range(2):
        for j in range(2):
            for k in range(2):
                if i == 0:
                    sum = a + b
                    symbols = "+"
                else:
                    sum = a - b
                    symbols = "-"

                if j == 0:
                    sum = sum + c
                    symbols = symbols + "+"
                else:
                    sum = sum - c
                    symbols = symbols + "-"

                if k == 0:
                    sum = sum + d
                    symbols = symbols + "+"
                else:
                    sum = sum - d
                    symbols = symbols + "-"

                if sum == 7:
                    print a, symbols, b, symbols, c, symbols, d, "= 7"
                    return 0

    return 0

main()

