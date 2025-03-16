import sys

def read_int():
    return int(sys.stdin.readline().strip())

def read_float64():
    return float(sys.stdin.readline().strip())

def read_string():
    return sys.stdin.readline().strip()

def main():
    # Set the scanner to split input by whitespace
    sys.stdin.readline()

    # Read two integers n and m from input
    n, m = map(int, sys.stdin.readline().strip().split())

    # Initialize a list to hold m integers
    a = list(map(int, sys.stdin.readline().strip().split()))

    # Initialize a variable to hold the sum of the integers read
    sum_a = sum(a)

    # Check if the sum of the integers exceeds n
    if sum_a > n:
        print("-1") # Print -1 if the sum is greater than n
        return

    # Print the difference between n and the sum of the integers
    print(n - sum_a)

if __name__ == "__main__":
    main()

