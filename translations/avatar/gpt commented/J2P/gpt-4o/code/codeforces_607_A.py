def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Initialize a variable to keep track of the maximum number of beacons
    max_beacons = 0
    
    # Read the number of beacons
    n = int(data[0])
    
    # Create a list to store the positions of the beacons
    beacon = [0] * 1000001
    
    # Create a dynamic programming list to store the maximum beacons that can be placed
    dp = [0] * 1000001
    
    # Read the beacon positions and their corresponding values
    index = 1
    for i in range(n):
        a = int(data[index])  # Read the position of the beacon
        beacon[a] = int(data[index + 1])  # Read the value associated with the beacon at that position
        index += 2
    
    # Initialize the dp list for the first position if there is a beacon
    if beacon[0] != 0:
        dp[0] = 1
    
    # Iterate through all possible positions to calculate the maximum beacons that can be placed
    for i in range(1, 1000001):
        # If there is a beacon at position i and its value is less than i
        if beacon[i] != 0 and beacon[i] < i:
            # Update the dp list based on the previous values
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

# <END-OF-CODE>
