
# Import the required libraries
import math

# Initialize the variables and read the input
n = int(input())
arrA = list(map(int, input().split()))

# Create an array of size n+1 to store cumulative sum
cumSumA = [0] * (n + 1)

# Iterate through the array and calculate cumulative sum
for i, a in enumerate(arrA):
    cumSumA[i + 1] = cumSumA[i] + a

# Initialize variable to store the answer
ans = 1e12

# Iterate through the array to find the answer
for i in range(1, n):
    temp = float(cumSumA[n]) - float(cumSumA[i]) * 2
    if abs(temp) < ans:
        ans = temp

# Print the answer
print(int(ans))

# End of the code
