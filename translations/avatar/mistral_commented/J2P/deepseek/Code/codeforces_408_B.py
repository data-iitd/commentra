import sys
from collections import defaultdict, Counter

def isValid(s1, s2):
    char_set = set(s1)
    return all(char in char_set for char in s2)

def main():
    # Read the input from stdin
    s1 = input().strip()
    s2 = input().strip()

    if not isValid(s1, s2):
        print(-1)
    else:
        # Count the frequency of characters in both strings
        m1 = Counter(s1)
        m2 = Counter(s2)

        ans = 0
        seen = set()

        for char in s2:
            if char not in seen:
                seen.add(char)
                x1 = m1[char]
                x2 = m2[char]
                x1 = min(x1, x2)
                ans += x1

        print(ans)

if __name__ == "__main__":
    main()
