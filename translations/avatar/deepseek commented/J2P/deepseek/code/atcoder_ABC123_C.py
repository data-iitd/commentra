import math
import sys

def main():
    # Read the value of N
    N = int(input())

    # Initialize min to 0 and find the minimum of the first five inputs
    min_val = 0
    for i in range(5):
        if i == 0:
            min_val = int(input())
        else:
            min_val = min(min_val, int(input()))

    # Calculate the result and print it
    print(math.ceil(N / min_val) + 4)

if __name__ == "__main__":
    main()

