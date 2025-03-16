import sys
from collections import defaultdict

# Constants
MOD = 1000000000 + 7
ALPHABET_NUM = 26

def main():
    memo = [0] * ALPHABET_NUM

    for line in sys.stdin:
        line = line.strip()
        if not line:
            break
        for c in line:
            if 'a' <= c <= 'z':
                memo[ord(c) - ord('a')] += 1
            elif 'A' <= c <= 'Z':
                memo[ord(c) - ord('A')] += 1
            else:
                continue

    for i in range(ALPHABET_NUM):
        print(f"{chr(i + ord('a'))} : {memo[i]}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
