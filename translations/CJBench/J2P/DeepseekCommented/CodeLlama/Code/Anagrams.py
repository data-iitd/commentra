import sys

def approach1(s, t):
    if len(s) != len(t): # Check if lengths are different
        return False
    c = list(s) # Convert s to list
    d = list(t) # Convert t to list
    c.sort() # Sort the list c
    d.sort() # Sort the list d
    return c == d # Compare sorted lists

def approach2(s, t):
    if len(s) != len(t): # Check if lengths are different
        return False
    charCount = [0] * 26 # Frequency array for characters
    for i in range(len(s)): # Iterate through the strings
        charCount[ord(s[i]) - ord('a')] += 1 # Increment count for character in s
        charCount[ord(t[i]) - ord('a')] -= 1 # Decrement count for character in t
    for count in charCount: # Check if all counts are zero
        if count != 0:
            return False
    return True

def approach3(s, t):
    if len(s) != len(t): # Check if lengths are different
        return False
    charCount = [0] * 26 # Frequency array for characters
    for i in range(len(s)): # Iterate through the strings
        charCount[ord(s[i]) - ord('a')] += 1 # Increment count for character in s
        charCount[ord(t[i]) - ord('a')] -= 1 # Decrement count for character in t
    for count in charCount: # Check if all counts are zero
        if count != 0:
            return False
    return True

def approach4(s, t):
    if len(s) != len(t): # Check if lengths are different
        return False
    charCountMap = {} # HashMap to count characters
    for c in s: # Count characters in s
        charCountMap[c] = charCountMap.get(c, 0) + 1
    for c in t: # Check characters in t
        if not charCountMap.get(c, 0) or charCountMap[c] == 0:
            return False
        charCountMap[c] -= 1 # Decrement count
    return all(charCountMap[c] == 0 for c in charCountMap) # Check if all counts are zero

def approach5(s, t):
    if len(s) != len(t): # Check if lengths are different
        return False
    freq = [0] * 26 # Frequency array for characters
    for i in range(len(s)): # Iterate through the strings
        freq[ord(s[i]) - ord('a')] += 1 # Increment count for character in s
        freq[ord(t[i]) - ord('a')] -= 1 # Decrement count for character in t
    for count in freq: # Check if all counts are zero
        if count != 0:
            return False
    return True

if __name__ == "__main__":
    s = input()
    t = input()
    approach = int(input())
    result = False
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
        print("Invalid approach number.")
        sys.exit()
    print("Are the strings anagrams? " + str(result))

