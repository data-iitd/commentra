import sys
from collections import defaultdict

def main():
    # Read a line of input from the user
    str_input = sys.stdin.readline().strip()
    
    # Create a dictionary to count occurrences of each character
    char_count = defaultdict(int)
    odd_count = 0  # Initialize counter for characters with odd occurrences
    
    # Iterate through each character in the input string
    for ch in str_input:
        char_count[ch] += 1  # Update the count of the character
    
    # Count how many characters have an odd number of occurrences
    for count in char_count.values():
        if count % 2 != 0:
            odd_count += 1
    
    # Determine the output based on the count of odd occurrences
    if odd_count <= 1 or odd_count % 2 != 0:
        print("First")  # Output "First" if conditions are met
    else:
        print("Second")  # Output "Second" otherwise

if __name__ == "__main__":
    main()

# <END-OF-CODE>
