import sys
from collections import defaultdict

def is_valid(s1, s2):
    n1 = len(s1)
    n2 = len(s2)
    char_map = {}

    # Populate the map with characters from s1
    for c in s1:
        char_map[c] = True

    # Check if all characters of s1 are present in s2
    for c in s2:
        if c not in char_map:
            return False

    return True

def main():
    s1 = input()  # Read first string
    s2 = input()  # Read second string

    # Check if the strings are valid using the is_valid method
    if not is_valid(s1, s2):
        print(-1)  # Print -1 if strings are not valid
    else:
        m1 = defaultdict(int)  # Create defaultdict for s1
        m2 = defaultdict(int)  # Create defaultdict for s2

        # Populate the defaultdict with the frequency of each character in s1
        for c in s1:
            m1[c] += 1

        # Populate the defaultdict with the frequency of each character in s2
        for c in s2:
            m2[c] += 1

        ans = 0  # Initialize answer variable
        hs = set()  # Create set to track processed characters

        # Iterate over the characters of s2
        for c in s2:
            if c not in hs:
                hs.add(c)  # Mark character as processed
                x1 = m1[c]  # Get frequency of character in s1
                x2 = m2[c]  # Get frequency of character in s2
                x1 = min(x1, x2)  # Calculate minimum frequency
                ans += x1  # Add minimum frequency to answer

        print(ans)  # Print the final answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
