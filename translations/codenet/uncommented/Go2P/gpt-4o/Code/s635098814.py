import sys
from collections import defaultdict

def main():
    memo = [0] * 26  # To count occurrences of each letter
    input_stream = sys.stdin

    for line in input_stream:
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

    for i in range(26):
        print(f"{chr(i + ord('a'))} : {memo[i]}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
