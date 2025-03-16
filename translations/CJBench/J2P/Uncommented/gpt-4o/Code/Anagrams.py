import sys
from collections import defaultdict

def approach1(s, t):
    if len(s) != len(t):
        return False
    return sorted(s) == sorted(t)

def approach2(s, t):
    if len(s) != len(t):
        return False
    char_count = [0] * 26
    for i in range(len(s)):
        char_count[ord(s[i]) - ord('a')] += 1
        char_count[ord(t[i]) - ord('a')] -= 1
    return all(count == 0 for count in char_count)

def approach3(s, t):
    if len(s) != len(t):
        return False
    char_count = [0] * 26
    for i in range(len(s)):
        char_count[ord(s[i]) - ord('a')] += 1
        char_count[ord(t[i]) - ord('a')] -= 1
    return all(count == 0 for count in char_count)

def approach4(s, t):
    if len(s) != len(t):
        return False
    char_count_map = defaultdict(int)
    for c in s:
        char_count_map[c] += 1
    for c in t:
        if char_count_map[c] == 0:
            return False
        char_count_map[c] -= 1
    return all(count == 0 for count in char_count_map.values())

def approach5(s, t):
    if len(s) != len(t):
        return False
    freq = [0] * 26
    for i in range(len(s)):
        freq[ord(s[i]) - ord('a')] += 1
        freq[ord(t[i]) - ord('a')] -= 1
    return all(count == 0 for count in freq)

def main():
    s = input().strip()
    t = input().strip()
    approach = int(input().strip())
    
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
        return
    
    print("Are the strings anagrams? " + str(result))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
