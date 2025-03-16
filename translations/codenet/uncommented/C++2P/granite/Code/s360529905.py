
import sys

def main():
    N = int(input())
    a = list(map(int, input().split()))
    b = sorted(a)
    frontHalf = b[N//2-1]
    backHalf = b[N//2]
    for i in range(N):
        if a[i] < backHalf:
            print(backHalf)
        else:
            print(frontHalf)

if __name__ == "__main__":
    main()
