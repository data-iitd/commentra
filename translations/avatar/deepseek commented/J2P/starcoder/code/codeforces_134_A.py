
# Importing the necessary package for input
import sys

# Initialize the input stream
input = sys.stdin

# Read the size of the array
n = int(input.readline())

# Create an array of size n
arr = [0] * n

# Read n integers from the user and store them in the array arr
for i in range(n):
    arr[i] = int(input.readline())

# Initialize sum to 0
sum = 0

# Update the sum
for i in range(n):
    sum += arr[i]

# Initialize count of valid elements to remove
c = 0

# Create a StringBuilder to build the output string
sb = ""

# Iterate through the array arr to find elements that can be removed
for i in range(n):
    # Check if removing the current element keeps the average unchanged
    if ((sum - arr[i]) % (n - 1) == 0 and (sum - arr[i]) / (n - 1) == arr[i]):
        c += 1 # Increment the count
        sb += str(i + 1) + " " # Append the index (plus one) to the StringBuilder

# Print the count of valid elements and the indices of these elements
print(c)
print(sb)

