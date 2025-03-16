def min(*args):
    if len(args) == 0:
        raise Exception("len == 0")
    r = args[0]
    for i in range(1, len(args)):
        if args[i] <= r:
            r = args[i]
    return r

H, N = map(int, input().split())
dp = [2100000000] * (H + 10001)
amax = 0
for i in range(N):
    A, B = map(int, input().split())
    if A >= amax:
        amax = A
    dp[A] = min(dp[A], B)
    for j in range(A + 1, H + amax + 1):
        dp[j] = min(dp[j], dp[j - A] + B)
print(min(*dp[H:H + amax + 1]))

