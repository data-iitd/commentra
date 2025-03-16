
# Declare variables
n = 0
arrA = []
cumSumA = []
ans = 1e12

# Read input
n = int(input())
arrA = [int(x) for x in input().split()]

# Initialize cumulative sum array
cumSumA = [0] * (n+1)
cumSumA[0] = 0
for i in range(n):
	cumSumA[i+1] = cumSumA[i] + arrA[i]

# Iterate through the array to find the answer
for i in range(1, n):
	temp = cumSumA[n] - 2*cumSumA[i]
	if abs(temp) < ans:
		ans = temp

# Print the answer
print(int(ans))

