from collections import Counter, defaultdict
import sys

def is_valid(s1, s2):
    for c in s2:
        if c not in s1:
            return False
    return True

def main():
    # Read two strings from the input
    s1 = input().strip()
    s2 = input().strip()
    
    # Validate the input strings; if invalid, print -1 and exit
    if not is_valid(s1, s2):
        print(-1)
    else:
        # Count the frequency of each character in both strings
        counter1 = Counter(s1)
        counter2 = Counter(s2)
        
        # Initialize a variable to hold the result
        ans = 0
        
        # Create a defaultdict to track unique characters from the second string
        hs = defaultdict(int)
        
        # Calculate the minimum frequency of each character present in both strings
        for c in s2:
            if hs[c] == 0:
                hs[c] += 1
                x1 = counter1[c]  # Frequency in the first string
                x2 = counter2[c]  # Frequency in the second string
                x1 = min(x1, x2)  # Take the minimum frequency
                ans += x1  # Add to the result
        
        # Print the final result
        print(ans)

if __name__ == "__main__":
    main()
