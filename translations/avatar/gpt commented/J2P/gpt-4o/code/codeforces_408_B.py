def is_valid(s1, s2):
    # Create a set to store characters from the first string
    char_set = set(s1)
    
    # Check if all characters in the second string are present in the first string
    for c in s2:
        if c not in char_set:
            return False
    return True  # All characters are valid

def main():
    # Read two strings from the input
    s1 = input().strip()
    s2 = input().strip()
    
    # Validate the input strings; if invalid, print -1 and exit
    if not is_valid(s1, s2):
        print(-1)
    else:
        # Create dictionaries to count the frequency of characters in both strings
        m1 = {}
        m2 = {}
        
        # Count the frequency of each character in the first string
        for c in s1:
            if c in m1:
                m1[c] += 1
            else:
                m1[c] = 1
        
        # Count the frequency of each character in the second string
        for c in s2:
            if c in m2:
                m2[c] += 1
            else:
                m2[c] = 1
        
        # Initialize a variable to hold the result
        ans = 0
        # Create a set to track unique characters from the second string
        hs = set()
        
        # Calculate the minimum frequency of each character present in both strings
        for c in s2:
            if c not in hs:
                hs.add(c)
                x1 = m1.get(c, 0)  # Frequency in the first string
                x2 = m2.get(c, 0)  # Frequency in the second string
                x1 = min(x1, x2)  # Take the minimum frequency
                ans += x1  # Add to the result
        
        # Print the final result
        print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
