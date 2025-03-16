import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    T = int(data[1])
    
    AB = []
    index = 2
    for i in range(N):
        time = int(data[index])
        value = int(data[index + 1])
        AB.append((time, value))
        index += 2
    
    AB.sort(key=lambda x: x[0])
    
    dp = [[0] * 6001 for _ in range(N + 1)]
    
    for i in range(1, N + 1):
        for timeAfterEat in range(6001):
            dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat])
            time = AB[i - 1][0]
            value = AB[i - 1][1]
            if 0 <= timeAfterEat - time < T:
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value)
    
    print(max(dp[N]))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
