import sys
from collections import defaultdict

class AnagramChecker:
    @staticmethod
    def approach1(s, t):
        # If lengths are not equal, they cannot be anagrams
        if len(s) != len(t):
            return False
        # Sort both strings and check if they are equal
        return sorted(s) == sorted(t)

    @staticmethod
    def approach2(s, t):
        # If lengths are not equal, they cannot be anagrams
        if len(s) != len(t):
            return False
        # Array to count occurrences of each character (assuming lowercase a-z)
        char_count = [0] * 26
        # Count characters in both strings
        for i in range(len(s)):
            char_count[ord(s[i]) - ord('a')] += 1
            char_count[ord(t[i]) - ord('a')] -= 1
        # Check if all counts are zero
        return all(count == 0 for count in char_count)

    @staticmethod
    def approach4(s, t):
        # If lengths are not equal, they cannot be anagrams
        if len(s) != len(t):
            return False
        # HashMap to count occurrences of each character
        char_count_map = defaultdict(int)
        # Count characters in the first string
        for c in s:
            char_count_map[c] += 1
        # Decrease counts based on characters in the second string
        for c in t:
            if char_count_map[c] == 0:
                return False
            char_count_map[c] -= 1
        # Check if all counts are zero
        return all(count == 0 for count in char_count_map.values())

    @staticmethod
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
        return all(count == 0 for count in freq)

def main():
    # Read the first string
    s = input().strip()
    # Read the second string
    t = input().strip()
    # Read the approach number
    approach = int(input().strip())
    result = False

    # Switch case to select the approach based on user input
    if approach == 1:
        result = AnagramChecker.approach1(s, t)
    elif approach == 2:
        result = AnagramChecker.approach2(s, t)
    elif approach == 4:
        result = AnagramChecker.approach4(s, t)
    elif approach == 5:
        result = AnagramChecker.approach5(s, t)
    else:
        print("Invalid approach number.")
        return

    # Output the result of the anagram check
    print("Are the strings anagrams?", result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
