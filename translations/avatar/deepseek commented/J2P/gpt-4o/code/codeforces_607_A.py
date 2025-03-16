def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Step 6: Read the number of beacons
    beacon = [0] * 1000001  # Step 5: Initialize the beacon array
    dp = [0] * 1000001  # Step 5: Initialize the dp array
    max_value = 0  # Step 5: Initialize the maximum value in dp array

    # Step 6: Read the positions and strengths of the beacons
    index = 1
    for i in range(n):
        a = int(data[index])
        beacon[a] = int(data[index + 1])
        index += 2

    # Step 7: Check if the first beacon's strength is not zero and initialize dp[0] to 1
    if beacon[0] != 0:
        dp[0] = 1

    # Step 8: Iterate through the range of 1 to 1000000, updating the dp array based on the beacon strengths
    for i in range(1, 1000001):
        if beacon[i] != 0 and beacon[i] < i:
            dp[i] = dp[i - beacon[i] - 1] + 1
        elif beacon[i] != 0:
            dp[i] = 1
        else:
            dp[i] = dp[i - 1]
        max_value = max(max_value, dp[i])  # Step 9: Update the maximum value in dp array

    # Step 9: Print the result
    print(n - max_value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
