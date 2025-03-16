
import sys

def TenToN(number, n):
    s = ""
    tmp = number
    while tmp > 0:
        s = str(tmp % n) + s
        tmp //= n
    return s

def main():
    N, K = map(int, input().split())
    s = TenToN(N, K)
    print(len(s))

if __name__ == "__main__":
    main()
