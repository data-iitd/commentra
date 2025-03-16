#include<stdio.h>

def main():
    a, b = map(int, input().split())
    ar = a * b
    le = 2 * (a + b)
    print(ar, le)

if __name__ == '__main__':
    main()

