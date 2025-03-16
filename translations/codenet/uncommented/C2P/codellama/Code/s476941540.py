#include <stdio.h>
#include <ctype.h>

def main():
    alpha = [0] * 26
    ch = ''

    for i in range(26):
        alpha[i] = 0

    while True:
        ch = getchar()
        if ch == EOF:
            break

        if isalpha(ch):
            if isupper(ch):
                alpha[ch - 65] += 1
            else:
                alpha[ch - 97] += 1

    ch = 'a'
    for i in range(26):
        print(ch, ':', alpha[i])
        ch = chr(ord(ch) + 1)

main()

