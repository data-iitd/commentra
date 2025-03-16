import sys
import math

def scan_int():
    return int(sys.stdin.readline().strip())

def scan_float64():
    return float(sys.stdin.readline().strip())

def scan_text():
    return sys.stdin.readline().strip()

def max_of_two(a, b):
    return b if a < b else a

def min_of_two(a, b):
    return b if a > b else a

def abs_of_int(a):
    return -a if a < 0 else a

def main():
    # Read the number of elements in the array from the input
    N = scan_int()
    # Read N integers from the input and store them in X and Y arrays
    X = [scan_int() for _ in range(N)]
    Y = X[:]

    # Sort the Y array in ascending order
    Y.sort()

    # Find the median of Y array
    m1 = Y[N//2 - 1]
    m2 = Y[N//2]

    # Iterate through each element of X array and print the corresponding median value
    for x in X:
        if x <= m1:
            # If x is smaller than m1, print m2 as the answer
            print(m2)
        else:
            # If x is greater than m1, print m1 as the answer
            print(m1)

if __name__ == "__main__":
    main()
