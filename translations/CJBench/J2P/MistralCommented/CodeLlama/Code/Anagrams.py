
import sys

def approach1(s, t):
    if len(s) != len(t):
        return False
    c = list(s)
    d = list(t)
    c.sort()
    d.sort()
    return c == d

def approach2(s, t):
    if len(s) != len(t):
        return False
    char_count = [0] * 26
    for i in range(len(s)):
        char_count[ord(s[i]) - ord('a')] += 1
        char_count[ord(t[i]) - ord('a')] -= 1
    for count in char_count:
        if count != 0:
            return False
    return True

def approach3(s, t):
    if len(s) != len(t):
        return False
    char_count_map = {}
    for c in s:
        char_count_map[c] = char_count_map.get(c, 0) + 1
    for c in t:
        if c not in char_count_map or char_count_map[c] == 0:
            return False
        char_count_map[c] -= 1
    return all(count == 0 for count in char_count_map.values())

def approach4(s, t):
    if len(s) != len(t):
        return False
    char_freq = [0] * 26
    for i in range(len(s)):
        char_freq[ord(s[i]) - ord('a')] += 1
        char_freq[ord(t[i]) - ord('a')] -= 1
    for count in char_freq:
        if count != 0:
            return False
    return True

def approach5(s, t):
    if len(s) != len(t):
        return False
    char_freq = [0] * 26
    for i in range(len(s)):
        char_freq[ord(s[i]) - ord('a')] += 1
        char_freq[ord(t[i]) - ord('a')] -= 1
    for count in char_freq:
        if count != 0:
            return False
    return True

if __name__ == "__main__":
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()
    approach = int(sys.stdin.readline().strip())
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

# 