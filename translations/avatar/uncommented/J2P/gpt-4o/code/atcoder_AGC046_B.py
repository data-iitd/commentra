MOD = 998244353
dp = [[0] * 3001 for _ in range(3001)]

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    A = int(data[0])
    B = int(data[1])
    C = int(data[2])
    D = int(data[3])
    
    dp[A][B] = 1
    
    for c in range(A, C + 1):
        for d in range(B, D + 1):
            if c == A and d == B:
                continue
            ans = 0
            if c > A:
                part = dp[c - 1][d]
                ans = (part * d) % MOD
            if d > B:
                part = dp[c][d - 1]
                ans = (ans + (part * c)) % MOD
            if c > A and d > B:
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))) % MOD
            
            dp[c][d] = (ans + MOD) % MOD
    
    print(dp[C][D])

if __name__ == "__main__":
    solve()
    
# <END-OF-CODE>
