#include<stdio.h>
def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    t = 0
    for i in range(n):
        s = 0
        for j in range(n):
            if j <= i:
                continue
            m = a[i] * a[j]
            s = s + m
        t = t + s
    print(t)

