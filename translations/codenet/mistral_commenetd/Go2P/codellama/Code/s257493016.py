
# Function to find minimum number in a list
def min(n):
    if len(n) == 0:
        # Panic if the list is empty
        raise ValueError("len == 0")
    r = n[0]
    # Initialize minimum value with first element of the list
    for i in range(1, len(n)):
        # Compare current element with minimum value and update minimum value if current element is smaller
        if n[i] <= r:
            r = n[i]
    # Return the minimum value
    return r

# Main function
def main():
    # Initialize variables for number of floors H, number of jumps N, and variables A and B for each jump
    H, N = map(int, input().split())

    # Initialize a list dp of size H+10001 with initial value 2100000000
    dp = [2100000000] * (H+10001)

    # Initialize maximum reachable floor amax to 0
    amax = 0
    # Iterate through each jump
    for i in range(N):
        # Read floor A and number of floors B that can be jumped from floor A
        A, B = map(int, input().split())

        # If the maximum reachable floor is less than A, update maximum reachable floor
        if A >= amax:
            amax = A

        # Update dp[A] with minimum of current dp[A] and B
        dp[A] = min([dp[A], B])

        # Iterate through floors from A+1 to H+A and update dp[j] with minimum of current dp[j] and dp[j-A]+B
        for j in range(A+1, H+A+1):
            dp[j] = min([dp[j], dp[j-A]+B])

    # Print the minimum number of jumps required to reach the last floor
    print(min(dp[H:H+amax+1]))

# End of code