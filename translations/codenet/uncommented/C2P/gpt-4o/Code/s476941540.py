import sys

alpha = [0] * 26

while True:
    ch = sys.stdin.read(1)
    if not ch:  # EOF
        break

    if ch.isalpha():
        if ch.isupper():
            alpha[ord(ch) - 65] += 1
        else:
            alpha[ord(ch) - 97] += 1

for i in range(26):
    print(f"{chr(97 + i)} : {alpha[i]}")

# <END-OF-CODE>
