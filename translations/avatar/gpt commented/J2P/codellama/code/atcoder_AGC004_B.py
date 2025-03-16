import math
import os
import random
import re
import sys

# Complete the minimumCost function below.
def minimumCost(N, x, C):
    # Initialize a 2D list to store costs
    costList = [[0 for i in range(N)] for j in range(N)]

    # Populate the costList with minimum values based on the C
    for i in range(N):
        # Set the first column of costList to the corresponding values from C
        costList[i][0] = C[i]
        # Calculate the minimum costs for each subsequent column
        for j in range(1, N):
            costList[i][j] = min(costList[i][j - 1], C[(i - j + N) % N])

    # Initialize a list to store the final results
    result = [0 for i in range(N)]

    # Calculate the result for each index based on the costs and the value of x
    for i in range(N):
        result[i] = i * x + sum(costList[i])

    # Print the minimum value from the result list
    print(min(result))

if __name__ == '__main__':
    # Read the number of elements (N) and a long value (x) from input
    N, x = map(int, input().split())

    # Read N long values into the C
    C = list(map(int, input().split()))

    # Call the minimumCost function
    minimumCost(N, x, C)

    # Print "