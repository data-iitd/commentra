#include <stdio.h>

def main():
    a, b, n = map(int, input().split())
    a -= a // b * b
    sum = 0
    for i in range(1, n + 1):
        a *= 10
        for j in range(9, -1, -1):
            if b * j <= a:
                break
        a -= b * j
        sum += j
    print(sum)

if __name__ == "__main__":
    main()

