import sys

def main():
    # Read the number of elements in the array from the input
    N = int(sys.stdin.readline().strip())
    # Allocate memory for two arrays X and Y of size N
    X = [0] * N
    Y = [0] * N

    # Read N integers from the input and store them in X and Y arrays
    for i in range(N):
        X[i] = int(sys.stdin.readline().strip())
        # Store the current element of X in Y array for sorting
        Y[i] = X[i]

    # Sort the Y array in ascending order
    Y.sort()

    # Find the median of Y array
    m1 = Y[N // 2 - 1]
    m2 = Y[N // 2]

    # Iterate through each element of X array and print the corresponding median value
    for i in range(N):
        if X[i] <= m1:
            # If X[i] is smaller than m1, print m2 as the answer
            print(m2)
        else:
            # If X[i] is greater than m1, print m1 as the answer
            print(m1)

# Function to read an integer from the input
def scan_int():
    return int(sys.stdin.readline().strip())

# Function to read a float from the input
def scan_float():
    return float(sys.stdin.readline().strip())

# Function to read a text from the input
def scan_text():
    return sys.stdin.readline().strip()

# Function to find the maximum of two integers
def max_value(a, b):
    return b if a < b else a

# Function to find the minimum of two integers
def min_value(a, b):
    return b if a > b else a

# Function to find the absolute value of an integer
def abs_value(a):
    return -a if a < 0 else a

if __name__ == "__main__":
    main()

# <END-OF-CODE>
