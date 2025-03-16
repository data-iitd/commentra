def abs_value(a):
    return -a if a < 0 else a

def min_value(a):
    return min(a)

def main():
    # Read the number of elements
    N = int(input())
    # Read the heights into a list
    h = list(map(int, input().split()))

    # Initialize a dynamic programming list to store minimum costs
    dp = [0] * N
    
    # Base case: cost to jump from the first to the second height
    dp[1] = abs_value(h[0] - h[1])

    # Fill the dp list with minimum costs for each position
    for i in range(2, N):
        dp[i] = min_value([
            dp[i-1] + abs_value(h[i] - h[i-1]),  # Cost from the previous height
            dp[i-2] + abs_value(h[i] - h[i-2]),  # Cost from two heights back
        ])

    # Output the minimum cost to reach the last height
    print(dp[N-1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
