
# Create a Scanner object to read input from the console
s = Scanner(sys.stdin)

# Read two strings from the input
s1 = s.next()
s2 = s.next()

# Validate the input strings; if invalid, print -1 and exit
if isValid(s1, s2) == False:
    print(-1)
else:
    # Create HashMaps to count the frequency of characters in both strings
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

    # Create a HashSet to track unique characters from the second string
    hs = set()

    # Calculate the minimum frequency of each character present in both strings
    for c in s2:
        if c not in hs:
            hs.add(c)
            x1 = m1[c] # Frequency in the first string
            x2 = m2[c] # Frequency in the second string
            x1 = min(x1, x2) # Take the minimum frequency
            ans += x1 # Add to the result

    # Print the final result
    print(ans)

# Method to check if the characters in s2 are all present in s1
def isValid(s1, s2):
    n1 = len(s1)
    n2 = len(s2)
    # Create a HashMap to store characters from the first string
    map = {}

    # Add all characters from the first string to the map
    for c in s1:
        map[c] = True

    # Check if all characters in the second string are present in the first string
    for c in s2:
        if c not in map:
            return False

    return True # All characters are valid

