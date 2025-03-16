
import sys

def main():
    # Reading the number of elements in the array from the console
    n = int(input())
    # Creating an integer array of size 1000001 to store the indices of beacons
    beacon = [0] * 1000001
    # Creating an integer array of size 1000001 to store the length of the longest subsequence ending at each index
    dp = [0] * 1000001
    # Initializing max variable to store the maximum length of a subsequence
    max = 0
    # Loop to read the elements and their indices from the console
    for i in range(n):
        # Reading the element
        a = int(input())
        # Storing the index of the beacon for the given element
        beacon[a] = int(input())
    # If the first beacon exists, the length of the subsequence ending at index 0 is 1
    if beacon[0]!= 0:
        dp[0] = 1
    # Loop to calculate the length of the longest subsequence ending at each index
    for i in range(1, 1000001):
        # If the beacon exists and its index is less than the current index, update the length of the subsequence
        if beacon[i]!= 0 and beacon[i] < i:
            dp[i] = dp[i - beacon[i] - 1] + 1
        # If the beacon exists but its index is greater than or equal to the current index, the length of the subsequence is 1
        elif beacon[i]!= 0:
            dp[i] = 1
        # If there is no beacon, the length of the subsequence remains the same as the previous index
        else:
            dp[i] = dp[i - 1]
        # Updating the maximum length of the subsequence
        max = max(max, dp[i])
    # Printing the difference between the total number of elements and the maximum length of the subsequence
    print(n - max)

if __name__ == "__main__":
    main()

