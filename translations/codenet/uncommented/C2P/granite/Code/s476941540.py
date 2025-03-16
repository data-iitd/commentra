
import sys

alpha = [0] * 26

for ch in sys.stdin:
    if ch.isalpha():
        if ch.isupper():
            alpha[ord(ch) - 65] += 1
        else:
            alpha[ord(ch) - 97] += 1

for i in range(26):
    print(chr(i + 97), ":", alpha[i])

