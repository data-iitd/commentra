import sys
from collections import defaultdict

def is_valid(s1, s2):
    # Check if the given strings are valid
    char_map = defaultdict(bool)  # Create a dictionary to store the presence of characters in the first string

    for c in s1:  # Iterate through each character in the first string
        char_map[c] = True  # Mark the character as present in the dictionary

    for c in s2:  # Iterate through each character in the second string
        if c not in char_map:  # If the character is not present in the first string, return False
            return False

    return True  # If all characters in the second string are present in the first string, return True

def main():
    s1 = input().strip()  # Read the first string from the input
    s2 = input().strip()  # Read the second string from the input

    if not is_valid(s1, s2):  # Check if the given strings are valid
        print(-1)  # If not valid, print -1 and exit
    else:  # If the strings are valid, proceed with the computation
        m1 = defaultdict(int)  # Create a dictionary to store the frequency of characters in the first string
        m2 = defaultdict(int)  # Create a dictionary to store the frequency of characters in the second string

        for c in s1:  # Iterate through each character in the first string
            m1[c] += 1  # Increment the count of the character

        for c in s2:  # Iterate through each character in the second string
            m2[c] += 1  # Increment the count of the character

        ans = 0  # Initialize the answer variable to 0
        hs = set()  # Create a set to store unique characters in the second string

        for c in s2:  # Iterate through each character in the second string
            if c not in hs:  # If the character is not already in the set, add it and compute the answer
                hs.add(c)
                x1 = m1[c]  # Get the count of the character in the first string
                x2 = m2[c]  # Get the count of the character in the second string
                x1 = min(x1, x2)  # Take the minimum count
                ans += x1  # Add the minimum count to the answer

        print(ans)  # Print the answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
