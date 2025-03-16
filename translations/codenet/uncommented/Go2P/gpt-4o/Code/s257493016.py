def min_value(*args):
    if len(args) == 0:
        raise ValueError("len == 0")
    return min(args)

def main():
    H, N = map(int, input().split())
    dp = [2100000000] * (H + 10001)
    
    amax = 0
    for _ in range(N):
        A, B = map(int, input().split())
        if A >= amax:
            amax = A
        dp[A] = min_value(dp[A], B)
        for j in range(A + 1, H + A + 2):
            dp[j] = min_value(dp[j], dp[j - A] + B)
    
    print(min_value(*dp[H:H + amax + 1]))

if __name__ == "__main__":
    main()
# <END-OF-CODE>
