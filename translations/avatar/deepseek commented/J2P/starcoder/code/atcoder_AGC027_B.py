
import sys

class Main:
    def __init__(self):
        self.INF = sys.maxint

    def solve(self):
        # Read the number of points N and the target value X
        N = int(raw_input())
        X = long(raw_input())

        # Initialize an array to store the positions of N points
        x = [0] * N

        # Read the positions of the points into the array x and calculate the cumulative sum
        xsum = [0] * (N + 1)
        for i in range(N):
            x[i] = int(raw_input())
            xsum[i + 1] = xsum[i] + x[i]

        # Initialize ans with a value calculated using the total sum of positions and the given X value
        ans = X * N + 5 * xsum[N]

        # Iterate over possible values of i, which represents the number of points to be removed
        for i in range(1, N):
            cost = X * i + 5 * (xsum[N] - xsum[N - i])

            # For each value of i, calculate the cost of removing i points and update ans if a better cost is found
            for j in range(5, 0, -1):
                if cost > ans:
                    break
                cost += j * (xsum[N - i] - xsum[max(N - i - i, 0)])
            ans = min(ans, cost)

        # Print the minimum cost found
        print ans + N * X

if __name__ == "__main__":
    obj = Main()
    obj.solve()

