import sys
from collections import defaultdict

def main():
    # Read the input string
    str_input = sys.stdin.readline().strip()

    # Initialize a dictionary to store character counts
    char_count = defaultdict(int)

    # Count occurrences of each character
    for ch in str_input:
        char_count[ch] += 1

    # Count how many characters have an odd count
    odd_count = sum(1 for count in char_count.values() if count % 2 != 0)

    # Determine the output based on the odd count
    if odd_count <= 1 or odd_count % 2 != 0:
        print("First")  # Output "First" if the odd count is 1 or odd
    else:
        print("Second")  # Output "Second" if the odd count is even

if __name__ == "__main__":
    main()

# <END-OF-CODE>
