import sys

def main():
    N, K = map(int, input().split())
    s = tenToN(N, K)
    print(len(s))

def tenToN(number, n):
    s = ""
    tmp = number
    while True:
        s = str(tmp%n) + s
        if tmp < n:
            break
        tmp //= n
    return s

# 