def run():
    n, k = map(int, input().split())  # Read the number of elements and the target value
    a = list(map(int, input().split()))  # Read the elements into the list

    dp = [0] * (k + 1)  # Initialize the dynamic programming array

    # Iterate over each possible value from 1 to k
    for i in range(1, k + 1):
        win = 0  # Variable to determine if the current player can win

        # Check each element to see if it can lead to a winning position
        for j in range(n):
            if a[j] <= i and dp[i - a[j]] == 0:  # If there's a move leading to a losing position for the opponent
                win = 1  # Current player can win
                break  # No need to check further, we found a winning move

        dp[i] = win  # Store the result in the dp array

    # Output the result: "First" if the first player can win, otherwise "Second"
    print("First" if dp[k] else "Second")

# Main function to execute the program
if __name__ == "__main__":
    run()  # Call the run function to execute the game logic

# <END-OF-CODE>
