#include <stdio.h>
#include <ctype.h>

def main():
    alpha = [0] * 26
    ch = 'a'
    while True:
        ch = getchar()
        if ch == 'EOF':
            break
        if isalpha(ch):
            if isupper(ch):
                alpha[ord(ch) - ord('A')] += 1
            else:
                alpha[ord(ch) - ord('a')] += 1
    for i in range(26):
        print(chr(ord('a') + i), ':', alpha[i])

# 