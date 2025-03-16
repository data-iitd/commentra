#include <stdio.h>

# Global variables to hold the weight limit (W) and number of items (N)
W, N = 0, 0
# Array to store the input items with their weights and values
input = [[0, 0] for i in range(1024)]

def main():
    # Infinite loop to process multiple test cases
    for t in range(1000000000):
        # Initialize the ans and input arrays to zero for each test case
        ans = [[0, 0] for i in range(1024)]
        for i in range(1024):
            input[i][0], input[i][1] = 0, 0

        # Read the weight limit (W) and number of items (N)
        W, N = map(int, input().split())
        # Break the loop if the weight limit is zero (end of input)
        if W == 0:
            break

        # Read the value and weight of each item
        for i in range(N):
            input[i][0], input[i][1] = map(int, input().split(','))

        # Dynamic programming to calculate the maximum value for each capacity
        for i in range(N):
            # Traverse the capacities in reverse to avoid overwriting results
            for j in range(1023, input[i][1] - 1, -1):
                # Check if including the current item increases the maximum value
                if ans[j][0] < input[i][0] + ans[j - input[i][1]][0]:
                    # Update the maximum value and corresponding weight
                    ans[j][0] = input[i][0] + ans[j - input[i][1]][0]
                    ans[j][1] = input[i][1] + ans[j - input[i][1]][1]

        # Find the maximum value and corresponding weight for the exact weight limit
        for j in range(1024):
            if ans[W][0] == ans[W - j - 1][0]:
                break

        # Print the results for the current test case
        print("Case %d:" % (t + 1))
        print("%d" % ans[W - j][0])
        print("%d" % ans[W - j][1])

    return 0  # Return success


