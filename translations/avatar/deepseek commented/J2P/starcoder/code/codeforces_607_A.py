
import sys

def main():
    # Step 4: Create a Scanner object to read input
    sc = sys.stdin

    # Step 5: Initialize the maximum value in dp array
    max = 0

    # Step 6: Read the number of beacons
    n = int(sc.readline())

    # Step 5: Initialize the beacon array
    beacon = [0] * 1000001

    # Step 5: Initialize the dp array
    dp = [0] * 1000001

    # Step 6: Read the positions and strengths of the beacons
    for i in range(n):
        a = int(sc.readline())
        beacon[a] = int(sc.readline())

    # Step 7: Check if the first beacon's strength is not zero and initialize dp[0] to 1
    if beacon[0]!= 0:
        dp[0] = 1

    # Step 8: Iterate through the range of 1 to 1000000, updating the dp array based on the beacon strengths
    for i in range(1, 1000001):
        if beacon[i]!= 0 and beacon[i] < i:
            dp[i] = dp[i - beacon[i] - 1] + 1
        elif beacon[i]!= 0:
            dp[i] = 1
        else:
            dp[i] = dp[i - 1]

        max = max(max, dp[i]) # Step 9: Update the maximum value in dp array

    # Step 9: Print the result
    print(n - max)

if __name__ == "__main__":
    main()

# 