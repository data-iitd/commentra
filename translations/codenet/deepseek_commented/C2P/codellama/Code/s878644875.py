#include <stdio.h>

int main(void):
    s = input("Enter a string: ")
    t = input("Enter another string: ")
    hit = 0
    for i in range(len(s)):
        if s[i] == t[i]:
            hit += 1
    print(hit)
    return 0

