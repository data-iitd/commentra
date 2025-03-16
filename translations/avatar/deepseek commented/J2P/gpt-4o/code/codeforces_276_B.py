import sys
from collections import defaultdict

def main():
    # Read the input string from the user
    str_input = sys.stdin.readline().strip()

    # Create a dictionary to count the frequency of each character in the input string
    frequency_map = defaultdict(int)

    # Initialize a counter for characters with odd frequencies
    odd_count = 0

    # Iterate through the input string to populate the frequency map
    for ch in str_input:
        frequency_map[ch] += 1

    # Iterate through the map to count characters with odd frequencies
    for count in frequency_map.values():
        if count % 2 != 0:
            odd_count += 1

    # Determine the winner based on the count of characters with odd frequencies
    if odd_count <= 1 or odd_count % 2 != 0:
        print("First")
    else:
        print("Second")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
