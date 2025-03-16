
import sys
import io
import os

def main():
    n = int(input())
    k = int(input())
    a = list(map(int, input().split()))
    a.sort()
    ans = sum(a[:k])
    print(ans)

if __name__ == "__main__":
    main()
