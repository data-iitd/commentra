import sys

def solve():
    INF = sys.maxsize  # Initializing INF with the maximum value of a long integer

    # Reading input from stdin
    N = int(input().strip())
    X = int(input().strip())
    x = list(map(int, input().strip().split()))
    
    # Calculating the prefix sum of the array x
    xsum = [0] * (N + 1)
    for i in range(N):
        xsum[i + 1] = xsum[i] + x[i]
    
    # Initializing the answer with the first calculation
    ans = X * N + 5 * xsum[N]
    
    # Loop to find the minimum cost
    for i in range(1, N):
        cost = X * i + 5 * (xsum[N] - xsum[N - i])
        j = 5
        k = N - i
        while k >= 0:
            if cost > ans:
                break
            cost += j * (xsum[k] - xsum[max(k - i, 0)])
            j += 2
            k -= i
        ans = min(ans, cost)
    
    # Printing the final answer
    print(ans + N * X)

# Calling the solve function
solve()
