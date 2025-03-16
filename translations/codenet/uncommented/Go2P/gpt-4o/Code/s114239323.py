def next_int():
    return int(input().strip())

def next_ints(n):
    return list(map(int, input().strip().split()))[:n]

def abs_value(a):
    return -a if a < 0 else a

def min_value(a):
    return min(a)

def main():
    N = next_int()
    h = next_ints(N)
    
    dp = [0] * N
    dp[1] = abs_value(h[0] - h[1])
    
    for i in range(2, N):
        dp[i] = min_value([
            dp[i - 1] + abs_value(h[i] - h[i - 1]),
            dp[i - 2] + abs_value(h[i] - h[i - 2])
        ])
    
    print(dp[N - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
