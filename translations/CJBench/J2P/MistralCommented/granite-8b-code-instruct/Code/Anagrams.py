

def approach1(s, t):
    if len(s)!= len(t):
        return False
    # Convert both strings to character arrays for sorting
    c = list(s)
    d = list(t)

    # Sort both character arrays using sorted() function
    c.sort()
    d.sort()

    # Compare both sorted character arrays using == operator
    return c == d

def approach2(s, t):
    if len(s)!= len(t):
        return False
    char_count = [0] * 26 # Initialize a list of size 26 to store character counts

    # Iterate through each character in string s and update its corresponding count in char_count list
    for char in s:
        char_count[ord(char) - ord('a')] += 1
        char_count[ord(t[s.index(char)]) - ord('a')] -= 1 # Decrement the count of corresponding character in string t

    # Iterate through each count in char_count list and check if any count is not zero, if yes return False
    for count in char_count:
        if count!= 0:
            return False
    # If all counts are zero, then both strings are anagrams
    return True

def approach3(s, t):
    # Same as approach2 but using collections.Counter instead of list
    if len(s)!= len(t):
        return False
    char_count = collections.Counter(s) # Initialize a Counter object to store character counts

    # Iterate through each character in string t and check if its count is zero in Counter object, if not return False
    for char in t:
        if char not in char_count or char_count[char] == 0:
            return False
        char_count[char] -= 1 # Decrement the count of corresponding character in Counter object

    # If all counts in Counter object are zero, then both strings are anagrams
    return all(count == 0 for count in char_count.values())

def approach4(s, t):
    if len(s)!= len(t):
        return False
    char_freq = [0] * 26 # Initialize a list of size 26 to store character frequencies

    # Iterate through each character in string s and increment its corresponding frequency in char_freq list
    for char in s:
        char_freq[ord(char) - ord('a')] += 1
        char_freq[ord(t[s.index(char)]) - ord('a')] -= 1 # Decrement the frequency of corresponding character in string t

    # Iterate through each frequency in char_freq list and check if any frequency is not zero, if yes return False
    for freq in char_freq:
        if freq!= 0:
            return False
    # If all frequencies are zero, then both strings are anagrams
    return True

def approach5(s, t):
    if len(s)!= len(t):
        return False
    # Similar to approach4 but using collections.Counter instead of list
    char_freq = collections.Counter(s)

    for char in t:
        char_freq[char] -= 1

    for freq in char_freq.values():
        if freq!= 0:
            return False

    return True

# Read the input strings and approach number from the console
s = input()
t = input()
approach = int(input())

# Call the appropriate approach based on the input approach number
if approach == 1:
    result = approach1(s, t)
elif approach == 2:
    result = approach2(s, t)
elif approach == 3:
    result = approach3(s, t)
elif approach == 4:
    result = approach4(s, t)
elif approach == 5:
    result = approach5(s, t)
else:
    print("Invalid approach number.") # Print an error message if the approach number is invalid
    exit()

# Print the result of the comparison to the console
print("Are the strings anagrams? " + str(result))

