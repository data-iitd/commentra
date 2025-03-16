import sys

def main():
    input = sys.stdin.readline
    N, X = map(int, input().split())

    ans = 0
    min_cost = float('inf')
    for _ in range(N):
        tmp = int(input())
        X -= tmp
        ans += 1
        if tmp < min_cost:
            min_cost = tmp

    ans += X // min_cost

    print(ans)

if __name__ == "__main__":
    main()
