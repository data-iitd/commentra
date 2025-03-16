
import sys

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def main():
    n, k, q = map(int, input().split())
    point = [0] * n
    for _ in range(q):
        a = int(input())
        point[a - 1] += 1
    for i in range(n):
        if k - (q - point[i]) > 0:
            print("Yes")
        else:
            print("No")

if __name__ == "__main__":
    main()

