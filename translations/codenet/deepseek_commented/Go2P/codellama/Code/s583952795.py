
import sys

def main():
    # Read two integers N and K from standard input
    N, K = map(int, sys.stdin.readline().split())

    # Convert N to base K and print the length of the resulting string
    s = TenToN(N, K)
    print(len(s))

def TenToN(number, n):
    s = ''
    tmp = number
    while True:
        s = str(tmp % n) + s
        if tmp < n:
            break
        tmp //= n
    return s

if __name__ == '__main__':
    main()

