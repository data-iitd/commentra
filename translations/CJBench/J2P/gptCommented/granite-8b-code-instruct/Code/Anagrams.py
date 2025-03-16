
import sys

def approach1(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s)!= len(t):
        return False
    # Convert strings to character arrays
    c = list(s)
    d = list(t)
    # Sort both character arrays
    c.sort()
    d.sort()
    # Check if sorted arrays are equal
    return c == d

def approach2(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s)!= len(t):
        return False
    # Array to count occurrences of each character (assuming lowercase a-z)
    char_count = [0] * 26
    # Count characters in both strings
    for i in range(len(s)):
        char_count[ord(s[i]) - ord('a')] += 1
        char_count[ord(t[i]) - ord('a')] -= 1
    # Check if all counts are zero
    for count in char_count:
        if count!= 0:
            return False
    return True

def approach3(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s)!= len(t):
        return False
    # Array to count occurrences of each character (assuming lowercase a-z)
    char_count = [0] * 26
    # Count characters in both strings
    for i in range(len(s)):
        char_count[ord(s[i]) - ord('a')] += 1
        char_count[ord(t[i]) - ord('a')] -= 1
    # Check if all counts are zero
    for count in char_count:
        if count!= 0:
            return False
    return True

def approach4(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s)!= len(t):
        return False
    # HashMap to count occurrences of each character
    char_count_map = {}
    # Count characters in the first string
    for c in s:
        char_count_map[c] = char_count_map.get(c, 0) + 1
    # Decrease counts based on characters in the second string
    for c in t:
        # If character is not found or count is zero, they are not anagrams
        if c not in char_count_map or char_count_map[c] == 0:
            return False
        char_count_map[c] -= 1
    # Check if all counts are zero
    return all(count == 0 for count in char_count_map.values())

def approach5(s, t):
    # If lengths are not equal, they cannot be anagrams
    if len(s)!= len(t):
        return False
    # Array to count occurrences of each character (assuming lowercase a-z)
    freq = [0] * 26
    # Count characters in both strings
    for i in range(len(s)):
        freq[ord(s[i]) - ord('a')] += 1
        freq[ord(t[i]) - ord('a')] -= 1
    # Check if all counts are zero
    for count in freq:
        if count!= 0:
            return False
    return True

def main():
    # Read the first string
    s = input()
    # Read the second string
    t = input()
    # Read the approach number
    approach = int(input())
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
        sys.exit(1)
    # Output the result of the anagram check
    print("Are the strings anagrams? " + str(result))

if __name__ == "__main__":
    main()

