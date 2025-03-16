def run():
    # Read the number of elements and the target value from input
    n, k = map(int, input().split())
    
    # Read the elements into the array
    a = list(map(int, input().split()))
    
    # Allocate memory for the dynamic programming array
    dp = [0] * (k + 1)
    
    # Iterate over each possible value from 1 to k
    for i in range(1, k + 1):
        win = False  # Variable to determine if the current player can win
        
        # Check each element to see if it can lead to a winning position
        for j in range(n):
            if a[j] <= i and dp[i - a[j]] == 0:
                win = True  # Current player can win
                break  # No need to check further
        
        # Store the result in the dp array: True if the current player can win, False otherwise
        dp[i] = win
    
    # Output the result: "First" if the first player can win, otherwise "Second"
    print("First" if dp[k] else "Second")

# Main function to execute the program
if __name__ == "__main__":
    run()  # Call the run function to execute the game logic
