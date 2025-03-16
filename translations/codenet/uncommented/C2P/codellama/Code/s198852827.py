#include<stdio.h>

#define ABS(x) (((x)<(0))?(-(x)):(x))

def main():
    N = int(input())
    t = 0
    x = 0
    y = 0
    nx = 0
    ny = 0
    nt = 0
    for i in range(N):
        t, x, y = map(int, input().split())
        tmp = t - nt - (ABS(x - nx) + ABS(y - ny))
        if tmp < 0 or tmp % 2:
            print("No")
            return
    print("Yes")


