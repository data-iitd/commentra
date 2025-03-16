
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
    charCount = [0] * 26
    for i in range(len(s)):
        charCount[ord(s[i]) - ord('a')] += 1
        charCount[ord(t[i]) - ord('a')] -= 1
    for count in charCount:
        if count != 0:
            return False
    return True

def approach3(s, t):
    if len(s) != len(t):
        return False
    charCount = [0] * 26
    for i in range(len(s)):
        charCount[ord(s[i]) - ord('a')] += 1
        charCount[ord(t[i]) - ord('a')] -= 1
    for count in charCount:
        if count != 0:
            return False
    return True

def approach4(s, t):
    if len(s) != len(t):
        return False
    charCountMap = {}
    for c in s:
        charCountMap[c] = charCountMap.get(c, 0) + 1
    for c in t:
        if not charCountMap.get(c, 0):
            return False
        charCountMap[c] -= 1
    return all(count == 0 for count in charCountMap.values())

def approach5(s, t):
    if len(s) != len(t):
        return False
    freq = [0] * 26
    for i in range(len(s)):
        freq[ord(s[i]) - ord('a')] += 1
        freq[ord(t[i]) - ord('a')] -= 1
    for count in freq:
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

# 