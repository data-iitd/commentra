import sys

def main():
    # Read the number of beacons
    n = int(input().strip())
    
    # Initialize a variable to keep track of the maximum number of beacons
    max_beacons = 0
    
    # Create an array to store the positions of the beacons
    beacon = [0] * 1000001
    
    # Create a dynamic programming array to store the maximum beacons that can be placed
    dp = [0] * 1000001
    
    # Read the beacon positions and their corresponding values
    for _ in range(n):
        a = int(input().strip())  # Read the position of the beacon
        b = int(input().strip())  # Read the value associated with the beacon at that position
        beacon[a] = b
    
    # Initialize the dp array for the first position if there is a beacon
    if beacon[0] != 0:
        dp[0] = 1
    
    # Iterate through all possible positions to calculate the maximum beacons that can be placed
    for i in range(1, 1000001):
        # If there is a beacon at position i and its value is less than i
        if beacon[i] != 0 and beacon[i] < i:
            # Update the dp array based on the previous values
            dp[i] = dp[i - beacon[i] - 1] + 1
        # If there is a beacon at position i but its value is greater than or equal to i
        elif beacon[i] != 0:
            dp[i] = 1  # Only this beacon can be placed
        # If there is no beacon at position i
        else:
            dp[i] = dp[i - 1]  # Carry forward the previous maximum
        # Update the maximum number of beacons found so far
        max_beacons = max(max_beacons, dp[i])
    
    # Output the minimum number of beacons that need to be removed
    print(n - max_beacons)

if __name__ == "__main__":
    main()
