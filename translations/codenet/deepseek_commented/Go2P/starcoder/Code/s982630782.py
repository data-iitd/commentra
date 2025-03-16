
import sys

# Create a map to store the counts of integers
m = {}

# Read the number of initial elements (N) and the number of operations (M)
N, M = map(int, input().split())

# Read N integers and store their counts in the map
for i in range(N):
	m[int(input())] = m.get(int(input()), 0) + 1

# Perform M operations to update the map with new integers and their counts
for i in range(M):
	B, C = map(int, input().split())
	m[C] = m.get(C, 0) + B

# Create a slice of integers from the map keys
ints = list(m.keys())

# Sort the slice of integers in descending order
ints.sort(reverse=True)

# Initialize variables to keep track of the remaining elements and the sum
rest = N
sum = 0

# Iterate through the sorted integers and calculate the sum based on the conditions
for i in ints:
	num = m[i]
	if num >= rest:
		sum += rest * i
		break
	sum += num * i
	rest -= num

# Print the calculated sum
print(sum)

# 