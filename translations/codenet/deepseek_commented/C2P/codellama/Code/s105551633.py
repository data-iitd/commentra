#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

def digit(n):
    res = 0
    while n > 0:
        res += 1
        n //= 10
    return res

def run():
    n = int(input())
    min = digit(n)
    for i in range(1, int(sqrt(n)) + 1):
        if n % i != 0:
            continue
        a = i
        b = n // i
        min = min(min, max(digit(a), digit(b)))
    print(min)

run()

