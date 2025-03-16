
import sys

MOD = 1000000007

def main():
    # Optimize input/output operations
    sys.stdin.sync_with_stdio(False)
    sys.stdin.buffer.readline = lambda: sys.stdin.buffer.read().split()
    input = lambda: sys.stdin.buffer.readline().rstrip()

    n = int(input())
    p = list(map(int, input().split()))
    ans = 0

    for i in range(n - 2):
        if p[i] > p[i + 1] > p[i + 2]:
            ans += 1
        if p[i] < p[i + 1] < p[i + 2]:
            ans += 1

    print(ans)

if __name__ == "__main__":
    main()

