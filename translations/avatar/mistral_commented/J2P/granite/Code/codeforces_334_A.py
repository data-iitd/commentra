

import sys

def main():
    n = int(input())
    square = n * n
    odd = []
    even = []

    for i in range(1, square + 1):
        if i % 2 == 0:
            even.append(i)
        else:
            odd.append(i)

    loop = square // n
    div = loop // 2

    for i in range(1, loop + 1):
        for j in range(div):
            if i % 2 == 1:
                sys.stdout.write(str(odd.pop(0)) + " " + str(even.pop()) + " ")
            else:
                sys.stdout.write(str(even.pop(0)) + " " + str(odd.pop()) + " ")
        sys.stdout.write("\n")

if __name__ == "__main__":
    main()

