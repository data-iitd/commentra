# Importing required modules
import sys

def main():
    # Reading the number of elements in the array from the console
    n = int(sys.stdin.readline().strip())
    
    # Creating a list to store the indices of beacons and a list for the length of the longest subsequence
    beacon = [0] * 1000001
    dp = [0] * 1000001
    
    # Loop to read the elements and their indices from the console
    for _ in range(n):
        a, index = map(int, sys.stdin.readline().strip().split())
        beacon[a] = index  # Storing the index of the beacon for the given element

    max_length = 0  # Initializing max_length variable to store the maximum length of a subsequence

    # If the first beacon exists, the length of the subsequence ending at index 0 is 1
    if beacon[0] != 0:
        dp[0] = 1

    # Loop to calculate the length of the longest subsequence ending at each index
    for i in range(1, 1000001):
        if beacon[i] != 0 and beacon[i] < i:
            dp[i] = dp[i - beacon[i] - 1] + 1  # Update the length of the subsequence
        elif beacon[i] != 0:
            dp[i] = 1  # Length of the subsequence is 1
        else:
            dp[i] = dp[i - 1]  # Length remains the same as the previous index
        
        max_length = max(max_length, dp[i])  # Updating the maximum length of the subsequence

    # Printing the difference between the total number of elements and the maximum length of the subsequence
    print(n - max_length)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
