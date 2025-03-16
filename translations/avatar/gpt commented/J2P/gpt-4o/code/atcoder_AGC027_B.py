import sys

class Main:
    # Define a constant for infinity, used for comparison
    INF = float('inf')

    def solve(self):
        # Read the number of elements N and the multiplier X
        N = int(input())
        X = int(input())
        
        # Initialize a list to store the elements and a prefix sum list
        x = [0] * N
        xsum = [0] * (N + 1)
        
        # Read the elements into the list and compute the prefix sums
        for i in range(N):
            x[i] = int(input())
            xsum[i + 1] = xsum[i] + x[i]
        
        # Initialize the answer with the cost of processing all elements with the base cost
        ans = X * N + 5 * xsum[N]
        
        # Iterate through possible splits of the array
        for i in range(1, N):
            # Calculate the cost for the current split
            cost = X * i + 5 * (xsum[N] - xsum[N - i])
            
            # Incrementally add costs based on the current split
            for j in range(5, N - i + 1, 2):
                k = N - i
                while k >= 0:
                    # If the current cost exceeds the best answer found, break out of the loop
                    if cost > ans:
                        break
                    # Update the cost based on the prefix sums
                    cost += j * (xsum[k] - xsum[max(k - i, 0)])
                    k -= i
            
            # Update the answer with the minimum cost found
            ans = min(ans, cost)
        
        # Output the final answer, which includes the base cost
        print(ans + N * X)

if __name__ == "__main__":
    Main().solve()

# <END-OF-CODE>
