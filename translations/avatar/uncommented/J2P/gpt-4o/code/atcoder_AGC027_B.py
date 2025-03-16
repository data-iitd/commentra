import sys

class Main:
    INF = float('inf')

    def solve(self):
        input = sys.stdin.read
        data = input().split()
        
        N = int(data[0])
        X = int(data[1])
        x = list(map(int, data[2:N + 2]))
        
        xsum = [0] * (N + 1)
        for i in range(N):
            xsum[i + 1] = xsum[i] + x[i]
        
        ans = X * N + 5 * xsum[N]
        
        for i in range(1, N):
            cost = X * i + 5 * (xsum[N] - xsum[N - i])
            for j, k in zip(range(5, 5 + 2 * (N - i) // i + 1, 2), range(N - i, -1, -i)):
                if cost > ans:
                    break
                cost += j * (xsum[k] - xsum[max(k - i, 0)])
            ans = min(ans, cost)
        
        print(ans + N * X)

if __name__ == "__main__":
    Main().solve()
    
# <END-OF-CODE>
