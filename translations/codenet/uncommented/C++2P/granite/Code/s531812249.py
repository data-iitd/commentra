
import sys

def main():
    n, m = map(int, input().split())
    ans = 0
    # gu gu
    ans += n * (n - 1) // 2
    # kiki
    ans += m * (m - 1) // 2
    print(ans)

if __name__ == "__main__":
    main()

