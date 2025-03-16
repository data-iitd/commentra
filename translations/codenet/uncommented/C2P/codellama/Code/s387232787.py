#include <stdio.h>

c = [0] * 26

def main():
    str = ""
    while scanf("%s", str) > 0:
        for p in str:
            if 'a' <= p <= 'z':
                c[ord(p) - ord('a')] += 1
            elif 'A' <= p <= 'Z':
                c[ord(p) - ord('A')] += 1

    for i in range(26):
        printf("%c : %d\n", 'a' + i, c[i])

main()

