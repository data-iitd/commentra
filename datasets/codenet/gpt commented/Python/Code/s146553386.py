# Read the number of elements in the input arrays
n = int(input())

# Initialize a list to hold two arrays
a = []

# Read two lines of input and convert them into lists of integers
for i in range(2):
    a.append(list(map(int, input().split())))

# Reverse the second array to facilitate the calculation
a[1] = a[1][::-1]

# Import numpy for efficient numerical operations
import numpy

# Calculate the cumulative sum of the first array
res_0 = numpy.cumsum(a[0])

# Calculate the cumulative sum of the reversed second array
res_1 = numpy.cumsum(a[1])

# Initialize a variable to keep track of the maximum sum found
ans = 0

# Iterate through each index to calculate the maximum possible sum
for i in range(n):
    # Calculate the sum of the cumulative values from both arrays
    check = res_0[i] + res_1[n-1-i]
    
    # Update the maximum sum if the current sum is greater
    ans = max(ans, check)

# Print the maximum sum found
print(ans)
