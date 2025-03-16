import sys

# Function to return the minimum of two integers
def min(x, y):
    return y if x > y else x

# Main function where the program execution begins
def main():
    S = sys.stdin.read().strip()  # Read the input string

    l0, l1 = 0, 0  # Initialize counters for '0's and '1's
    # Loop through each character in the input string
    for char in S:
        if char == '0':
            l0 += 1  # Increment the counter for '0'
        else:
            l1 += 1  # Increment the counter for '1'
    
    # Print the result, which is twice the minimum count of '0's or '1's
    print(2 * min(l0, l1))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
