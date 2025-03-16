def min_value(*args):
    if len(args) == 0:
        raise ValueError("len == 0")  # Ensure there is at least one argument
    r = args[0]  # Initialize the result with the first argument
    # Iterate through the remaining arguments to find the minimum
    for i in range(1, len(args)):
        if args[i] <= r:
            r = args[i]  # Update the result if a smaller value is found
    return r  # Return the minimum value found

def main():
    H, N = map(int, input().split())  # Read the total height H and the number of items N
    
    # Initialize a dynamic programming array to store the minimum cost for each height
    dp = [2100000000] * (H + 10001)  # Represents a large value (infinity)
    
    amax = 0  # Variable to track the maximum height of items
    # Process each item
    for _ in range(N):
        A, B = map(int, input().split())  # Read the height A and cost B of the current item
        # Update amax if the current item's height is greater
        if A >= amax:
            amax = A
        # Update the minimum cost for achieving height A
        dp[A] = min_value(dp[A], B)
        # Update the minimum cost for all heights from A+1 to H+A+1
        for j in range(A + 1, H + amax + 2):
            dp[j] = min_value(dp[j], dp[j - A] + B)  # Calculate the minimum cost for height j
    
    # Print the minimum cost to achieve height H considering all possible heights up to amax
    print(min_value(*dp[H:H + amax + 1]))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
