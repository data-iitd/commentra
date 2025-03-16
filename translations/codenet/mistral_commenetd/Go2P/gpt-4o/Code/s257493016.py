# Function to find minimum number in a list
def min_value(*args):
    if len(args) == 0:
        raise ValueError("len == 0")
    r = args[0]
    for i in range(1, len(args)):
        if args[i] <= r:
            r = args[i]
    return r

# Main function
def main():
    # Initialize variables for number of floors H, number of jumps N, and variables A and B for each jump
    H, N = map(int, input().split())

    # Initialize a list dp of size H+10001 with initial value 2100000000
    dp = [2100000000] * (H + 10001)

    # Initialize maximum reachable floor amax to 0
    amax = 0
    # Iterate through each jump
    for _ in range(N):
        # Read floor A and number of floors B that can be jumped from floor A
        A, B = map(int, input().split())

        # If the maximum reachable floor is less than A, update maximum reachable floor
        if A >= amax:
            amax = A

        # Update dp[A] with minimum of current dp[A] and B
        dp[A] = min_value(dp[A], B)

        # Iterate through floors from A+1 to H+A and update dp[j] with minimum of current dp[j] and dp[j-A]+B
        for j in range(A + 1, H + A + 2):
            dp[j] = min_value(dp[j], dp[j - A] + B)

    # Print the minimum number of jumps required to reach the last floor
    print(min_value(*dp[H:H + amax + 1]))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
