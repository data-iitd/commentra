import sys

class Main:
    # Define a constant for infinity, used for comparison
    INF = sys.maxsize

    def solve(self):
        # Initialize a Scanner to read input from the console
        sc = sys.stdin
        
        # Read the number of elements N and the multiplier X
        N = int(next(sc).strip())
        X = int(next(sc).strip())
        
        # Initialize an array to store the elements and a prefix sum array
        x = [0] * N
        xsum = [0] * (N + 1)
        
        # Read the elements into the array and compute the prefix sums
        for i in range(N):
            x[i] = int(next(sc).strip())
            xsum[i + 1] = xsum[i] + x[i]
        
        # Initialize the answer with the cost of processing all elements with the base cost
        ans = X * N + 5 * xsum[N]
        
        # Iterate through possible splits of the array
        for i in range(1, N):
            # Calculate the cost for the current split
            cost = X * i + 5 * (xsum[N] - xsum[N - i])
            
            # Incrementally add costs based on the current split
            for j in range(5, N - i + 1, 2):
                k = N - i - j + 5
                # If the current cost exceeds the best answer found, break out of the loop
                if cost > ans:
                    break
                # Update the cost based on the prefix sums
                cost += j * (xsum[k] - xsum[max(k - i, 0)])
            # Update the answer with the minimum cost found
            ans = min(ans, cost)
        
        # Output the final answer, which includes the base cost
        print(ans + N * X)

# Create an instance of Main and call the solve method to execute the program
Main().solve()
