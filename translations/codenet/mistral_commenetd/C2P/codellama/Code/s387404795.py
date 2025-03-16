
#include <stdio.h>
#include <string.h>

def main():
    str = input()
    p = input()
    tmp = str
    str += tmp
    slen = len(str)
    plen = len(p)
    flag = 0
    for i in range(slen - plen):
        if str[i:i+plen] == p:
            flag = 1
    if flag:
        print("Yes")
    else:
        print("No")

