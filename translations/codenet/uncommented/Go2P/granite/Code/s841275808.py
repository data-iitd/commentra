
import sys
import bisect

def main():
    N = int(input())
    X = [int(x) for x in input().split()]
    Y = sorted(X)
    m1 = Y[N // 2 - 1]
    m2 = Y[N // 2]
    for x in X:
        if x <= m1:
            print(m2)
        else:
            print(m1)

if __name__ == '__main__':
    main()

