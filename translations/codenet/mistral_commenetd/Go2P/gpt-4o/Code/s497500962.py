import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Main function is the entry point of the program
def main():
    # Initialize variables R, G, B, and N with next integers
    R = next_int()
    G = next_int()
    B = next_int()
    N = next_int()

    # Initialize variable ans with zero
    ans = 0

    # Nested for loops to iterate through all possible combinations of x and y within the range of N
    for x in range(N + 1):
        for y in range(N + 1):
            # Calculate temporary variable tmp
            tmp = N - R * x - G * y

            # Check if tmp is non-negative and the remainder of tmp when divided by B is zero
            if tmp >= 0 and tmp % B == 0:
                # Increment the value of ans if the condition is true
                ans += 1

    # Print the value of ans
    print(ans)

# Entry point of the script
if __name__ == "__main__":
    main()

# <END-OF-CODE>
