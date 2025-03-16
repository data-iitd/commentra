
# Define a function to solve the problem.
def solve(n, heights):
    # Initialize a table t to store the minimum cost to reach each index.
    t = [float('inf')] * (n + 1)
    # Set the initial value of the table to 0.
    t[0] = 0

    # Iterate through the array from index 1 to n-1.
    for i in range(1, n):
        # Calculate the cost to reach index i from the previous index.
        prevIndexCost = t[i - 1]
        # Update the cost to reach index i if the difference between heights is beneficial.
        if heightsDiff := heights[i] - heights[i - 1]; heightsDiff < 0:
            prevIndexCost += heightsDiff
        else:
            prevIndexCost -= heightsDiff
        # Update the cost to reach index i if the difference between previous index is beneficial.
        if prevIndex := i - 2; prevIndex >= 0:
            prevPrevIndexCost = t[prevIndex]
            heightsDiff = heights[i] - heights[prevIndex]
            if heightsDiff < 0:
                prevPrevIndexCost += heightsDiff
            else:
                prevPrevIndexCost -= heightsDiff
            if prevIndexCost < t[i]:
                t[i] = prevIndexCost
            if prevPrevIndexCost < t[i]:
                t[i] = prevPrevIndexCost
        else:
            # If the difference between previous index is not valid, only update the cost if the current difference is beneficial.
            if prevIndexCost < t[i]:
                t[i] = prevIndexCost

    # Return the minimum cost to reach the last index.
    return t[n - 1]

# Define the main function to read input and call the solve function.
def main():
    # Read the number of test cases and iterate through each test case.
    n = int(input())
    for i in range(n):
        # Read the number of heights and initialize an array to store them.
        heights = list(map(int, input().split()))
        # Call the solve function and print the result.
        ans = solve(n, heights)
        print(ans)

# The following comment can be added at the end of the code.


Translate the above Python code to C++ and end with comment "