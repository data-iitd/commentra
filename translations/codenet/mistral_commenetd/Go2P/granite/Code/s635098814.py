

import sys

# Define constants for the program.
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = sys.maxsize
INF_BIT60 = 1 << 60

# Declare memoization array and string variable.
memo = [0] * ALPHABET_NUM
str = ""

def main():
    global str, memo

    # Read input until EOF.
    while True:
        line = input()
        if not line:
            break
        str = line
        S = list(str)
        if len(S) == 0:
            break
        # Count occurrences of each letter.
        for c in S:
            if 'a' <= c and c <= 'z':
                # Increment count for lowercase letters.
                memo[ord(c) - ord('a')] += 1
            elif 'A' <= c and c <= 'Z':
                # Increment count for uppercase letters.
                memo[ord(c) - ord('A')] += 1
            else:
                # Ignore non-alphabet characters.
                continue

    # Print the count of each letter.
    for i in range(ALPHABET_NUM):
        print(f"{chr(ord('a') + i)} : {memo[i]}")

if __name__ == "__main__":
    main()

