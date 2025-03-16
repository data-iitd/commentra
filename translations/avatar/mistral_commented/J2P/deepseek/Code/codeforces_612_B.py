# Importing the Scanner class for reading input from the console
import sys

# Reading the number of test cases from the standard input
n = int(sys.stdin.readline().strip())

# Declaring an integer array dp of size 200001 to store the position of each number in the sequence
dp = [0] * 200001

# Initializing a long variable ans to store the answer
ans = 0

# Reading the sequence of numbers from the standard input
nums = list(map(int, sys.stdin.readline().strip().split()))

# Storing the position of the number in the dp array
for i, num in enumerate(nums):
    dp[num] = i

# Calculating the answer by iterating through the dp array and finding the absolute difference between the positions of consecutive numbers
for i in range(2, n + 1):
    # Adding the absolute difference to the answer
    ans += abs(dp[i] - dp[i - 1])

# Printing the answer to the console
print(ans)
