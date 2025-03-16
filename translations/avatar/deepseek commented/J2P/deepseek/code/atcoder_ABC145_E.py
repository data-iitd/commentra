def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    T = int(data[1])
    
    AB = []
    index = 2
    for i in range(N):
        A = int(data[index])
        B = int(data[index + 1])
        AB.append((A, B))
        index += 2
    
    AB.sort(key=lambda x: x[0])
    
    dp = [[0] * (6001) for _ in range(N + 1)]
    
    for i in range(1, N + 1):
        for time_after_eat in range(6001):
            dp[i][time_after_eat] = max(dp[i][time_after_eat], dp[i - 1][time_after_eat])
            
            time, value = AB[i - 1]
            
            if 0 <= time_after_eat - time < T:
                dp[i][time_after_eat] = max(dp[i][time_after_eat], dp[i - 1][time_after_eat - time] + value)
    
    print(max(dp[N]))

main()
