
import sys

def main():
    N, K = map(int, input().split())
    S = list(map(int, input().split()))
    ans = 10**18
    if K == 1:
        for i in range(N):
            temp = S[i]
            ans = min(abs(temp), ans)
        print(ans)
    else:
        for i in range(N - K + 1):
            min_val = S[i]
            max_val = S[i + K - 1]
            if min_val < 0 and max_val > 0:
                temp = min(2 * (-min_val) + max_val, (-min_val) + 2 * max_val)
            else:
                temp = max(abs(min_val), abs(max_val))
            ans = min(ans, temp)
        print(ans)

if __name__ == "__main__":
    main()

