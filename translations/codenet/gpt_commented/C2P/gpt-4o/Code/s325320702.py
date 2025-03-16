# Import necessary libraries
import sys
import math

# Define type aliases for convenience
ll = int
ld = float

# Function to read a long long integer
def cin():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    # Read input values for l, r, and d
    l = cin()
    r = cin()
    d = cin()

    # Count the multiples of d in the range [l, r]
    ans = 0
    for i in range(l, r + 1):
        if i % d == 0:
            ans += 1

    # Output the result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
