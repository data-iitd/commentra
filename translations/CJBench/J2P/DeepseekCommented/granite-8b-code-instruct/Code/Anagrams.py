
import sys

def approach1(s, t):
    if len(s)!= len(t):
        return False
    c = sorted(s)
    d = sorted(t)
    return c == d

def approach2(s, t):
    if len(s)!= len(t):
        return False
    char_count = [0] * 26
    for i in range(len(s)):
        char_count[ord(s[i]) - ord('a')] += 1
        char_count[ord(t[i]) - ord('a')] -= 1
    return all(count == 0 for count in char_count)

def approach3(s, t):
    if len(s)!= len(t):
        return False
    char_count = [0] * 26
    for i in range(len(s)):
        char_count[ord(s[i]) - ord('a')] += 1
        char_count[ord(t[i]) - ord('a')] -= 1
    return all(count == 0 for count in char_count)

def approach4(s, t):
    if len(s)!= len(t):
        return False
    char_count_map = {}
    for c in s:
        char_count_map[c] = char_count_map.get(c, 0) + 1
    for c in t:
        if c not in char_count_map or char_count_map[c] == 0:
            return False
        char_count_map[c] -= 1
    return all(count == 0 for count in char_count_map.values())

def approach5(s, t):
    if len(s)!= len(t):
        return False
    freq = [0] * 26
    for i in range(len(s)):
        freq[ord(s[i]) - ord('a')] += 1
        freq[ord(t[i]) - ord('a')] -= 1
    return all(count == 0 for count in freq)

def main():
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
        sys.exit(1)
    print(f"Are the strings anagrams? {result}")

if __name__ == "__main__":
    main()

