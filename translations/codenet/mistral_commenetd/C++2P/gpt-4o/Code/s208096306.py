import sys
from math import gcd

# Function to find the greatest common divisor (GCD) of two integers
def gcd_custom(a, b):
    if a < b:
        a, b = b, a  # Swap 'a' and 'b' if 'a' is smaller than 'b'

    # Use Euclidean algorithm to find the GCD of 'a' and 'b'
    while (r := a % b) > 0:
        a, b = b, r

    return b  # Return the GCD of 'a' and 'b'

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of integers 'n' from the standard input

    ans = int(sys.stdin.readline().strip())  # Read the first integer 'ans' from the standard input

    # Read and process the remaining integers
    for _ in range(1, n):
        a = int(sys.stdin.readline().strip())  # Read the next integer 'a' from the standard input

        # Update the answer by finding the GCD of the current answer and the new integer 'a'
        ans = gcd_custom(ans, a)

    print(ans)  # Print the final answer to the standard output

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
