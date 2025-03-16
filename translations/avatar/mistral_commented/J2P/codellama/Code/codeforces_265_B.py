# Import necessary libraries for file I/O and collections
import sys

# Read the first integer n representing the size of the array
n = int(input())

# Create an integer array arr of size n
arr = list(map(int, input().split()))

# Initialize a variable ans with the first element of the array and add 1 to it
ans = arr[0] + 1

# Use another for loop to iterate through the remaining elements of the array arr
for i in range(1, len(arr)):
    # Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
    ans += abs(arr[i] - arr[i - 1]) + 2

# Finally, print the value of ans to the standard output
print(ans)

