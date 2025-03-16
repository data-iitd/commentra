

# Read a string from the standard input and store it in's'
s = input()

# Get the size of the string's' and store it in 'n'
n = len(s)

# Declare and initialize an integer array 'v' of size 26 with zeroes
v = [0] * 26

# Read each character of the string's' and increment the corresponding index in array 'v'
for i in range(n):
	v[ord(s[i]) - ord('a')] += 1

# Initialize answer string to "Yes"
ans = "Yes"

# Check if all elements in array 'v' are even
for i in range(26):
	if v[i] % 2!= 0: # Check if the current index in array 'v' is odd
		ans = "No" # If so, set the answer string to "No"
		break # Exit the loop as soon as an odd number is found

# Print the answer
print(ans)

