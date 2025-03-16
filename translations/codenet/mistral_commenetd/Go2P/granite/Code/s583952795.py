
import sys

def main():
    N, K = map(int, input().split())
    s = ten_to_n(N, K)
    print(len(s))

def ten_to_n(number, n):
    s = ""
    tmp = number
    while tmp >= n:
        s = str(tmp % n) + s
        tmp //= n
    s = str(tmp) + s
    return s

if __name__ == "__main__":
    main()

