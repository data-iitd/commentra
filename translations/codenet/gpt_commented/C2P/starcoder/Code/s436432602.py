#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// Function to determine the winner of the game
def run():
    n, k = map(int, input().split()) # Declare variables for the number of elements and the target value
    a = list(map(int, input().split())) # Array to store the elements
    dp = [0] * (k + 1) # Allocate memory for the dynamic programming array

    # Iterate over each possible value from 1 to k
    for i in range(1, k + 1):
        win = 0 # Variable to determine if the current player can win

        # Check each element to see if it can lead to a winning position
        for j in range(n):
            if a[j] <= i and dp[i - a[j]] == 0:
                win = 1 # Current player can win

        # Store the result in the dp array: 1 if the current player can win, 0 otherwise
        dp[i] = win

    # Output the result: "First" if the first player can win, otherwise "Second"
    print("First" if dp[k] else "Second")

# Main function to execute the program
if __name__ == "__main__":
    run() # Call the run function to execute the game logic

