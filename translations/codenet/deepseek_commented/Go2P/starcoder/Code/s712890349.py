
# Declare variables for the number of characters, maximum allowed changes, and the answer
N, K = map(int, input().split())
S = input()

# Apply Run Length Encoding to the input string S
blocks = RunLength(S)

# Initialize variables for the sliding window approach
sum, zero, l = 0, 0, 0
for r in range(len(blocks)):
	sum += blocks[r][1] # Add the length of the current block to the sum
	if blocks[r][0] == '0':
		zero += 1 # Increment the count of '0' blocks
	# Adjust the window size if the number of '0' blocks exceeds K
	for K < zero:
		sum -= blocks[l][1] # Subtract the length of the block at the left of the window
		if blocks[l][0] == '0':
			zero -= 1 # Decrement the count of '0' blocks
		l += 1 # Move the left pointer to the right
	ans = max(ans, sum) # Update the answer if the current window sum is greater

print(ans) # Print the final answer

# RunLength performs run-length encoding on the input string
def RunLength(s):
	r = [] # Initialize a slice to store the encoded blocks
	if len(s) == 0:
		return r # Return an empty slice if the input string is empty
	t = [s[0], 1] # Initialize the first block
	for v in s[1:]:
		if t[0] == v:
			t[1] += 1 # Increment the length of the current block if the character is the same
		else:
			r.append(t) # Append the current block to the result slice
			t = [v, 1] # Initialize a new block for the new character
	r.append(t) # Append the last block to the result slice
	return r

# Max returns the maximum of two integers
def max(a, b):
	if b > a:
		return b
	return a

