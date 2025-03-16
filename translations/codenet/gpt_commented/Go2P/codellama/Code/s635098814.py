
import sys

# Declare constants.
MOD = 1000000007
ALPHABET_NUM = 26
INF_INT64 = 1 << 60
INF_BIT60 = 1 << 60

# Declare memoization array and string variable.
memo = [0] * ALPHABET_NUM
str = ""

# Read input until EOF.
while True:
    str = sys.stdin.readline().rstrip()
    if len(str) == 0:
        break
    # Count occurrences of each letter.
    for c in str:
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
    print(chr(i + ord('a')), ":", memo[i])

# END-OF-CODE
