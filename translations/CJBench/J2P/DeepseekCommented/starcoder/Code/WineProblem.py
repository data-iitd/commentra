import sys; # Importing sys module for input

def wpbu(arr):
    if arr == None or len(arr) == 0:
        raise Exception("Input array cannot be null or empty.") # Check for null or empty array
    n = len(arr) # Get the length of the array
    strg = [[0 for i in range(n)] for j in range(n)] # Initialize a 2D array to store maximum profit
    for slide in range(0, n):
        for si in range(0, n - slide):
            ei = si + slide # Calculate end index for the current subarray
            year = (n - (ei - si + 1)) + 1 # Calculate the current year
            if si == ei:
                strg[si][ei] = arr[si] * year # Base case: single element subarray
            else:
                start = strg[si + 1][ei] + arr[si] * year # Calculate profit if starting from si
                end = strg[si][ei - 1] + arr[ei] * year # Calculate profit if ending at ei
                strg[si][ei] = max(start, end) # Store the maximum profit for the current subarray
    return strg[0][n - 1] # Return the maximum profit for the entire array

if __name__ == "__main__":
    n = int(input()) # Read the size of the array
    arr = [int(x) for x in input().split()] # Fill the array with n integers
    result = wpbu(arr) # Call the wpbu method to calculate the maximum profit
    print("Maximum profit: " + str(result)) # Print the maximum profit

