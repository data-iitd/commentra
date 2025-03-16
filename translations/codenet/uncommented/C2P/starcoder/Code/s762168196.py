
#include <stdio.h>

def main():
    n = int(raw_input())
    a = []
    sum = 0
    for i in range(n):
        a.append(int(raw_input()))
        sum += a[i]
    max = min = a[0]
    for i in range(1, n):
        if a[i] > max:
            max = a[i]
        if a[i] < min:
            min = a[i]
    print min, max, sum

main()

