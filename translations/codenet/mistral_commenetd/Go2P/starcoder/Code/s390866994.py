
# Initialize scanner
import sys

# Function to read an integer from standard input
def getInt():
	return int(sys.stdin.readline())

# Function to read a string from standard input
def getString():
	return sys.stdin.readline()

# Function to find the maximum of two integers
def max(a, b):
	if a > b:
		return a
	return b

# Function to find the minimum of two integers
def min(a, b):
	if a < b:
		return a
	return b

# Function to find the absolute value of an integer
def abs(a):
	if a >= 0:
		return a
	return -a

# Main function
def main():
	# Read input: N, C, K
	N, C, K = getInt(), getInt(), getInt()

	# Initialize array t of size N
	t = [0] * N

	# Read input: t[i] for i from 0 to N-1
	for i in range(N):
		t[i] = getInt()

	# Sort array t in ascending order
	t.sort()

	# Initialize variables: answer counter ans, counter cnt, and end index end
	ans = 1
	cnt = 1
	end = t[0] + K

	# Iterate through array t from index 1 to N-1
	for i in range(1, N):
		# If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
		if cnt < C and t[i] <= end:
			cnt += 1
		else:
			# Reset counter cnt and update end index end to the current element t[i] plus K
			cnt = 1
			end = t[i] + K
			# Increment answer counter ans
			ans += 1

	# Print the final answer
	print(ans)

# 