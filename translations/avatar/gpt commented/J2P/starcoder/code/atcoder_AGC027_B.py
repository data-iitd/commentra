import sys

class Main:
    # Define a constant for infinity, used for comparison
    INF = sys.maxsize

    def __init__(self):
        # Read the number of elements N and the multiplier X
        self.N = int(input())
        self.X = int(input())

        # Initialize an array to store the elements and a prefix sum array
        self.x = [0] * self.N
        self.xsum = [0] * (self.N + 1)

        # Read the elements into the array and compute the prefix sums
        for i in range(self.N):
            self.x[i] = int(input())
            self.xsum[i + 1] = self.xsum[i] + self.x[i]

        # Initialize the answer with the cost of processing all elements with the base cost
        self.ans = self.X * self.N + 5 * self.xsum[self.N]

        # Iterate through possible splits of the array
        for i in range(1, self.N):
            # Calculate the cost for the current split
            cost = self.X * i + 5 * (self.xsum[self.N] - self.xsum[self.N - i])

            # Incrementally add costs based on the current split
            for j in range(5, 0, -1):
                # If the current cost exceeds the best answer found, break out of the loop
                if cost > self.ans:
                    break

                # Update the cost based on the prefix sums
                cost += j * (self.xsum[self.N - i] - self.xsum[max(self.N - i - j, 0)])

            # Update the answer with the minimum cost found
            self.ans = min(self.ans, cost)

        # Output the final answer, which includes the base cost
        print(self.ans + self.N * self.X)

if __name__ == "__main__":
    Main()

