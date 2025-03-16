import sys

# Function to read the next word from the input
def next():
    return sys.stdin.readline().strip()

# Returns the minimum of two integers
def min(x, y):
    return x if x < y else y

# Main function to execute the program logic
def main():
    S = next()

    # Initialize counters for '0's and '1's
    l0, l1 = 0, 0
    for char in S:
        if char == '0':
            l0 += 1
        else:
            l1 += 1

    print(2 * min(l0, l1))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
