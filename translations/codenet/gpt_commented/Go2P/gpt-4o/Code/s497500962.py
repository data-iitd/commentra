import sys

def next_int():
    return int(sys.stdin.readline().strip())

def main():
    # Read the values for R, G, B, and N from standard input
    R = next_int()  # Number of red items
    G = next_int()  # Number of green items
    B = next_int()  # Number of blue items
    N = next_int()  # Total number of items to choose

    ans = 0  # Variable to store the count of valid combinations

    # Iterate over possible counts of red items (x)
    for x in range(N + 1):
        # Iterate over possible counts of green items (y)
        for y in range(N + 1):
            # Calculate the remaining items after choosing x red and y green
            tmp = N - R * x - G * y
            # Check if the remaining items can be fully represented by blue items
            if tmp >= 0 and tmp % B == 0:
                ans += 1  # Increment the count of valid combinations

    # Output the total count of valid combinations
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
