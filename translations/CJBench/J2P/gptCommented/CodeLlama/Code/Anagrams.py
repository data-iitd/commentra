
# Import modules
import sys

# Main method to execute the program
def main():
    # Create a scanner to read input from the user
    scanner = sys.stdin
    # Read the first string
    s = scanner.readline().strip()
    # Read the second string
    t = scanner.readline().strip()
    # Read the approach number
    approach = int(scanner.readline().strip())
    result = False
    # Switch case to select the approach based on user input
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
        # Handle invalid approach number
        print("Invalid approach number.")
        return
    # Output the result of the anagram check
    print("Are the strings anagrams? " + str(result))
    # Close the scanner
    scanner.close()

# Approach 1: Check if two strings are anagrams by sorting
def approach1(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s) != len(t):
        return False
    # Convert strings to character arrays
    c = list(s)
    d = list(t)
    # Sort both character arrays
    c.sort()
    d.sort()
    # Check if sorted arrays are equal
    return c == d

# Approach 2: Check if two strings are anagrams using character count
def approach2(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s) != len(t):
        return False
    # Array to count occurrences of each character (assuming lowercase a-z)
    charCount = [0] * 26
    # Count characters in both strings
    for i in range(len(s)):
        charCount[ord(s[i]) - ord('a')] += 1
        charCount[ord(t[i]) - ord('a')] -= 1
    # Check if all counts are zero
    for count in charCount:
        if count != 0:
            return False
    return True

# Approach 3: Same as Approach 2 (duplicate code)
def approach3(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s) != len(t):
        return False
    # Array to count occurrences of each character (assuming lowercase a-z)
    charCount = [0] * 26
    # Count characters in both strings
    for i in range(len(s)):
        charCount[ord(s[i]) - ord('a')] += 1
        charCount[ord(t[i]) - ord('a')] -= 1
    # Check if all counts are zero
    for count in charCount:
        if count != 0:
            return False
    return True

# Approach 4: Check if two strings are anagrams using a HashMap
def approach4(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s) != len(t):
        return False
    # HashMap to count occurrences of each character
    charCountMap = {}
    # Count characters in the first string
    for c in s:
        charCountMap[c] = charCountMap.get(c, 0) + 1
    # Decrease counts based on characters in the second string
    for c in t:
        # If character is not found or count is zero, they are not anagrams
        if c not in charCountMap or charCountMap[c] == 0:
            return False
        charCountMap[c] -= 1
    # Check if all counts are zero
    return all(count == 0 for count in charCountMap.values())

# Approach 5: Same as Approach 2 but using a different method
def approach5(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s) != len(t):
        return False
    # Array to count occurrences of each character (assuming lowercase a-z)
    freq = [0] * 26
    # Count characters in both strings
    for i in range(len(s)):
        freq[ord(s[i]) - ord('a')] += 1
        freq[ord(t[i]) - ord('a')] -= 1
    # Check if all counts are zero
    for count in freq:
        if count != 0:
            return False
    return True

# Call the main method
main()

