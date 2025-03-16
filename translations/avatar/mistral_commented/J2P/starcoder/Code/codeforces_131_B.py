
import sys

# Initialize scanner object to read input from the console
scan = sys.stdin

# Read the number of test cases from the console
n = int(scan.readline())

# Define the maximum size of the array to avoid array out of bounds exception
N = 100005

# Initialize an array to store the count of each number
cnt = [0] * 21

# Read the numbers one by one and update the count array accordingly
for i in range(n):
    num = int(scan.readline()) # Read the next number
    cnt[num + 10] += 1 # Increment the count of the number

# Calculate the result using the given formula
res = 0
for i in range(10):
    res += cnt[i] * cnt[20 - i] # Calculate the sum of products of pairs of numbers with absolute difference i
res += (cnt[10] * (cnt[10] - 1)) / 2 # Calculate the sum of squares of numbers equal to 10 and add half of it

# Print the result to the console
print(res)

