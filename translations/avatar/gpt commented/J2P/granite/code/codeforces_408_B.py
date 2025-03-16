
import sys

def isValid(s1, s2):
    # Create a set to store characters from the first string
    set1 = set(s1)
    # Check if all characters in the second string are present in the first string
    for c in s2:
        if c not in set1:
            return False
    return True

def main():
    # Read two strings from the input
    s1 = input()
    s2 = input()
    # Validate the input strings; if invalid, print -1 and exit
    if isValid(s1, s2) == False:
        print(-1)
    else:
        # Create a dictionary to count the frequency of characters in both strings
        d1 = {}
        d2 = {}
        # Count the frequency of each character in the first string
        for c in s1:
            if c in d1:
                d1[c] += 1
            else:
                d1[c] = 1
        # Count the frequency of each character in the second string
        for c in s2:
            if c in d2:
                d2[c] += 1
            else:
                d2[c] = 1
        # Initialize a variable to hold the result
        ans = 0
        # Create a set to track unique characters from the second string
        set2 = set(s2)
        # Calculate the minimum frequency of each character present in both strings
        for c in s2:
            if c in set2:
                set2.remove(c)
                x1 = d1[c] # Frequency in the first string
                x2 = d2[c] # Frequency in the second string
                x1 = min(x1, x2) # Take the minimum frequency
                ans += x1 # Add to the result
        # Print the final result
        print(ans)

if __name__ == "__main__":
    main()
