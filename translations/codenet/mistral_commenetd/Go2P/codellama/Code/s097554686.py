// Package declaration and importing required library
import sys

// Function definition for main function
def main():
    # Variable declaration and initialization for number of queries and time interval
    n, t = map(int, input().split())

    # Initializing memory slice with zero values
    mem = [0] * (t + 1)

    # Iterating through each query in the input
    for i in range(n):
        # Reading input values for start and end time intervals
        l, r = map(int, input().split())

        # Updating memory slice values for start and end time intervals
        mem[l] += 1
        mem[r] -= 1

    # Initializing variable for answer
    ans = mem[0]

    # Iterating through each time interval in the memory slice
    for i in range(1, t + 1):
        # Updating memory slice values by adding previous value
        mem[i] += mem[i - 1]

        # Updating answer if current memory slice value is greater than previous answer
        if ans < mem[i]:
            ans = mem[i]

    # Printing the final answer
    print(ans)

# End of code

