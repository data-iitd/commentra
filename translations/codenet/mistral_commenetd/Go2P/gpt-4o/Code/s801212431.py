import sys

# Function to find minimum of two integers
def min(x, y):
    return y if x > y else x

# Main function
def main():
    # Read input string S
    S = sys.stdin.read().strip()

    # Initialize variables l0 and l1 to store count of '0' and '1' respectively
    l0, l1 = 0, 0

    # Iterate through each character in string S
    for char in S:
        # If current character is '0', increment l0
        if char == '0':
            l0 += 1
        else:
            # Otherwise, increment l1
            l1 += 1

    # Print result which is twice the minimum of l0 and l1
    print(2 * min(l0, l1))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
