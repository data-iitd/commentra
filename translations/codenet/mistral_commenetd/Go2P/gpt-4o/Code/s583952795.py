import sys

# Function to convert an integer to its string representation
def i2s(i):
    return str(i)

# Function to convert a number to its base-10 string representation with digit count K
def ten_to_n(number, n):
    s = ""
    tmp = number  # Initialize temporary variable

    # Repeat the following process until the number becomes less than N
    while True:
        # Append the remainder of the division by N to the result string
        s = i2s(tmp % n) + s

        # If the number is less than N, break the loop
        if tmp < n:
            break

        # Divide the number by N
        tmp //= n

    # Return the result string
    return s

# Main function entry point
def main():
    # Read input numbers N and K
    N, K = map(int, sys.stdin.readline().split())

    # Calculate the base-10 representation of N up to digit count K
    s = ten_to_n(N, K)

    # Print the length of the calculated string
    print(len(s))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
