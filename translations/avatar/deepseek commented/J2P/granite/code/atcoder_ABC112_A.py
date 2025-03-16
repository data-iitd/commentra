

import sys

def main():
    # Reading the number of inputs
    n = int(input())

    # Processing the input based on the value of n
    if n == 1:
        # Outputting "Hello World" if n is 1
        print("Hello World")
    else:
        # Reading two strings and calculating their sum if n is not 1
        strs = input().split()
        print(int(strs[0]) + int(strs[1]))

if __name__ == "__main__":
    main()

