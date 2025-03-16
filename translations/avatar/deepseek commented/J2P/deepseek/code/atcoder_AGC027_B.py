def solve():
    # Read the number of points N and the target value X
    N = int(input())
    X = int(input())

    # Initialize an array to store the positions of N points
    x = list(map(int, input().split()))
    xsum = [0] * (N + 1)

    # Read the positions of the points into the array x and calculate the cumulative sum
    for i in range(N):
        xsum[i + 1] = xsum[i] + x[i]

    # Initialize ans with a value calculated using the total sum of positions and the given X value
    ans = X * N + 5 * xsum[N]

    # Iterate over possible values of i, which represents the number of points to be removed
    for i in range(1, N):
        cost = X * i + 5 * (xsum[N] - xsum[N - i])

        # For each value of i, calculate the cost of removing i points and update ans if a better cost is found
        j = 5
        k = N - i
        while k >= 0:
            if cost > ans:
                break
            cost += j * (xsum[k] - xsum[max(k - i, 0)])
            j += 2
            k -= i
        ans = min(ans, cost)

    # Print the minimum cost found
    print(ans + N * X)


# Call the solve function
solve()
