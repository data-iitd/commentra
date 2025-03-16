#include <stdio.h>
#include <string.h>
def main():
    s = input()
    i = 0
    flag = 0
    while i < len(s):
        if i % 2 == 0:
            if s[i] == 'R' or s[i] == 'U' or s[i] == 'D':
                i += 1
            else:
                flag = 1
                break
        else:
            if s[i] == 'L' or s[i] == 'U' or s[i] == 'D':
                i += 1
            else:
                flag = 1
                break
    if flag == 0:
        print("Yes")
    else:
        print("No")

