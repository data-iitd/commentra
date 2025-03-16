
import sys

def main():
    N, K = map(int, sys.stdin.readline().split())
    s = ten_to_n(N, K)
    print(len(s))

def ten_to_n(number, n):
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

