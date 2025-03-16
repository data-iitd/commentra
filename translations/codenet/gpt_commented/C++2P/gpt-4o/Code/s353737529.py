# Direction vectors for moving in 4 directions (up, right, down, left)
dy = [-1, 0, +1, 0]
dx = [0, +1, 0, -1]

# Constants for infinity and modulo operations
INF = 1 << 60
MOD = int(1e9 + 7)

# Function to compute the greatest common divisor (GCD) using recursion
def gcd(a, b):
    if b == 0:
        return a  # Base case: if b is 0, return a
    return gcd(b, a % b)  # Recursive case

#-----------------------ここから-----------

if __name__ == "__main__":
    n = int(input())  # Read an integer from standard input

    # Initialize an empty string to hold the binary representation
    s = ""

    # Special case: if the input number is 0, output '0' and exit
    if n == 0:
        print('0')
    else:
        # Loop to convert the number to its binary representation in a specific format
        while n != 0:
            # Check if the current number is even or odd
            if n % 2 == 0:
                s += '0'  # Append '0' for even numbers
            else:
                s += '1'  # Append '1' for odd numbers

            # Adjust the number for the next iteration
            n -= abs(n % 2)  # Reduce n by 1 if it's odd
            n //= -2  # Divide n by -2 to continue the conversion

        # Reverse the string to get the correct binary representation
        s = s[::-1]

        # Output the final binary string
        print(s)

# <END-OF-CODE>
