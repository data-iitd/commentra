
import array
import collections

def approach1(s, t):
    if len(s)!= len(t):
        return False
    c = array.array('i', [0] * 26)
    d = array.array('i', [0] * 26)
    for i in range(len(s)):
        c[ord(s[i]) - ord('a')] += 1
        d[ord(t[i]) - ord('a')] += 1
    return c == d

def approach2(s, t):
    if len(s)!= len(t):
        return False
    char_count = collections.Counter(s)
    for c in t:
        if c not in char_count or char_count[c] == 0:
            return False
        char_count[c] -= 1
    return all(count == 0 for count in char_count.values())

def approach3(s, t):
    if len(s)!= len(t):
        return False
    char_count = collections.Counter(s)
    for c in t:
        if c not in char_count or char_count[c] == 0:
            return False
        char_count[c] -= 1
    return all(count == 0 for count in char_count.values())

def approach4(s, t):
    if len(s)!= len(t):
        return False
    char_count = collections.Counter(s)
    for c in t:
        if c not in char_count or char_count[c] == 0:
            return False
        char_count[c] -= 1
    return all(count == 0 for count in char_count.values())

def approach5(s, t):
    if len(s)!= len(t):
        return False
    freq = [0] * 26
    for i in range(len(s)):
        freq[ord(s[i]) - ord('a')] += 1
        freq[ord(t[i]) - ord('a')] -= 1
    return all(count == 0 for count in freq)

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
        exit(1)

    print("Are the strings anagrams? " + str(result))

