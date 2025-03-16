
import sys

# Initialize scanner object to read input from the console
scanner = sys.stdin

# Read the number of test cases from the console
n = int(scanner.readline())

# Define the maximum size of the array to avoid array out of bounds exception
N = 100005

# Initialize an array to store the count of each number
cnt = [0] * 21

# Read the numbers one by one and update the count array accordingly
for i in range(n):
    num = int(scanner.readline())
    cnt[num + 10] += 1

# Calculate the result using the given formula
res = 0
for i in range(10):
    res += cnt[i] * cnt[20 - i]
res += (cnt[10] * (cnt[10] - 1)) // 2

# Print the result to the console
print(res)

