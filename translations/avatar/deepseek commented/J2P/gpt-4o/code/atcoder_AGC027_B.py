import sys

class Main:
    INF = float('inf')

    def solve(self):
        # Read the number of points N and the target value X
        N = int(sys.stdin.readline().strip())
        X = int(sys.stdin.readline().strip())

        # Initialize a list to store the positions of N points
        x = [0] * N
        xsum = [0] * (N + 1)

        # Read the positions of the points into the list x and calculate the cumulative sum
        for i in range(N):
            x[i] = int(sys.stdin.readline().strip())
            xsum[i + 1] = xsum[i] + x[i]

        # Initialize ans with a value calculated using the total sum of positions and the given X value
        ans = X * N + 5 * xsum[N]

        # Iterate over possible values of i, which represents the number of points to be removed
        for i in range(1, N):
            cost = X * i + 5 * (xsum[N] - xsum[N - i])

            # For each value of i, calculate the cost of removing i points and update ans if a better cost is found
            for j in range(5, 5 + 2 * (N - i), 2):
                k = N - i
                if k < 0:
                    break
                if cost > ans:
                    break
                cost += j * (xsum[k] - xsum[max(k - i, 0)])

            ans = min(ans, cost)

        # Print the minimum cost found
        print(ans + N * X)

if __name__ == "__main__":
    Main().solve()
# <END-OF-CODE>
