import sys

# Function to read an integer from standard input
def scan_int():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    # Read the number of arms, n
    n = scan_int()

    # Initialize a list of arm structures
    arms = []

    # Read and initialize each arm structure in the list
    for _ in range(n):
        x = scan_int()
        l = scan_int()
        # Append a tuple (left, right) to the arms list
        arms.append((x - l, x + l))

    # Sort the list based on the right field of the arm structures
    arms.sort(key=lambda arm: arm[1])

    # Initialize answer variable, ans, and right variable, r
    ans = 1
    r = arms[0][1]

    # Iterate through the list and update the answer and right variable accordingly
    for i in range(1, n):
        if arms[i][0] >= r:  # Check if the left end of the current arm is greater than or equal to the right end of the previous arm
            ans += 1  # Increment the answer if it is
            r = arms[i][1]  # Update the right variable with the right end of the current arm

    # Print the answer
    print(ans)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
