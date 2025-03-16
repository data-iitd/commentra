
import sys

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    # 変数未使用エラー回避
    a[0] = 0

    sum = k
    ans = 1
    while sum < n:
        sum = sum - 1 + k
        ans += 1
    print(ans)

if __name__ == "__main__":
    main()

