import sys

# Function to convert a number from base 10 to base N
def ten_to_n(number, n):
    s = ""  # String to hold the result
    tmp = number  # Temporary variable to hold the current number
    while True:
        # Prepend the remainder of the division to the result string
        s = str(tmp % n) + s
        if tmp < n:  # If the temporary number is less than the base, exit the loop
            break
        tmp //= n  # Divide the temporary number by the base
    return s  # Return the converted string

# Function to read an integer from input
def read_int():
    return int(sys.stdin.readline().strip())  # Read and convert input to integer

def main():
    # Read two integers N and K from input
    N = read_int()
    K = read_int()
    # Convert the number N from base 10 to base K
    s = ten_to_n(N, K)
    # Print the length of the resulting string
    print(len(s))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
