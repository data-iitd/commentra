import sys

def main():
    input = sys.stdin.readline
    n = int(input())
    p = list(map(int, input().split()))
    ans = 0

    for i in range(n - 2):
        if p[i] > p[i+1] and p[i+1] > p[i+2]:
            ans += 1
        if p[i] < p[i+1] and p[i+1] < p[i+2]:
            ans += 1

    print(ans)

if __name__ == "__main__":
    main()
