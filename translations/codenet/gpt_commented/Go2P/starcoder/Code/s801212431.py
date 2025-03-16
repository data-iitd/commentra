# Declare a variable to store the input string
S = input()

# Initialize counters for '0's and '1's
l0, l1 = 0, 0

# Loop through each character in the input string
for i in range(len(S)):
	if S[i] == '0':
		l0 += 1 # Increment the counter for '0'
	else:
		l1 += 1 # Increment the counter for '1'

# Print the result, which is twice the minimum count of '0's or '1's
print(2 * min(l0, l1))

