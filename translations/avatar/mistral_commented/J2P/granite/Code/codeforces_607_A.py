

n = int(input())  # Reading the number of elements in the array from the console
beacon = [0] * 1000001  # Creating an integer array of size 1000001 to store the indices of beacons
dp = [0] * 1000001  # Creating an integer array of size 1000001 to store the length of the longest subsequence ending at each index

for i in range(n):  # Loop to read the elements and their indices from the console
    a, b = map(int, input().split())  # Reading the element and its index
    beacon[a] = b  # Storing the index of the beacon for the given element

if beacon[0]!= 0:
    dp[0] = 1  # If the first beacon exists, the length of the subsequence ending at index 0 is 1

for i in range(1, 1000001):  # Loop to calculate the length of the longest subsequence ending at each index
    if beacon[i]!= 0 and beacon[i] < i:
        dp[i] = dp[i - beacon[i] - 1] + 1  # If the beacon exists and its index is less than the current index, update the length of the subsequence
    elif beacon[i]!= 0:
        dp[i] = 1  # If the beacon exists but its index is greater than or equal to the current index, the length of the subsequence is 1
    else:
        dp[i] = dp[i - 1]  # If there is no beacon, the length of the subsequence remains the same as the previous index

print(n - max(dp))  # Printing the difference between the total number of elements and the maximum length of the subsequence

