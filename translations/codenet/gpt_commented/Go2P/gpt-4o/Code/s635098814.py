import sys
from collections import defaultdict

# Constants
ALPHABET_NUM = 26

def main():
    # Initialize a dictionary to count occurrences of each letter
    memo = defaultdict(int)

    # Read input until EOF
    for line in sys.stdin:
        line = line.strip()
        if not line:
            break
        
        # Count occurrences of each letter
        for c in line:
            if 'a' <= c <= 'z':
                memo[c] += 1
            elif 'A' <= c <= 'Z':
                memo[c] += 1
            else:
                continue

    # Print the count of each letter
    for i in range(ALPHABET_NUM):
        print(f"{chr(i + ord('a'))} : {memo[chr(i + ord('a'))]}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
