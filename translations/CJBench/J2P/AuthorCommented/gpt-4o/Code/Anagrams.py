import sys
from collections import defaultdict

class AnagramChecker:
    @staticmethod
    def approach1(s, t):
        if len(s) != len(t):
            return False
        return sorted(s) == sorted(t)

    @staticmethod
    def approach2(s, t):
        if len(s) != len(t):
            return False
        char_count = [0] * 26
        for i in range(len(s)):
            char_count[ord(s[i]) - ord('a')] += 1
            char_count[ord(t[i]) - ord('a')] -= 1
        return all(count == 0 for count in char_count)

    @staticmethod
    def approach3(s, t):
        return AnagramChecker.approach2(s, t)

    @staticmethod
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

    @staticmethod
    def approach5(s, t):
        return AnagramChecker.approach2(s, t)

if __name__ == "__main__":
    s = input().strip()
    t = input().strip()
    approach = int(input().strip())

    result = False
    if approach == 1:
        result = AnagramChecker.approach1(s, t)
    elif approach == 2:
        result = AnagramChecker.approach2(s, t)
    elif approach == 3:
        result = AnagramChecker.approach3(s, t)
    elif approach == 4:
        result = AnagramChecker.approach4(s, t)
    elif approach == 5:
        result = AnagramChecker.approach5(s, t)
    else:
        print("Invalid approach number.")
        sys.exit()

    print("Are the strings anagrams? " + str(result))

# <END-OF-CODE>
