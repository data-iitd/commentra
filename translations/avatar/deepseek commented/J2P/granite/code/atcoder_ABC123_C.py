

import sys

def main():
    # Read the value of N
    N = int(input())

    # Initialize min to 0 and find the minimum of the first five inputs
    min = 0
    for i in range(5):
        if i == 0:
            min = int(input())
        else:
            min = min(min, int(input()))

    # Calculate the result and print it
    print(str((N + min - 1) // min + 4))

if __name__ == "__main__":
    main()

