
# Initialize variables
N, K, R, S, P = 0, 0, 0, 0, 0
T = ""

# Read input from standard input
N, K, R, S, P = map(int, input().split())
T = input()

# Initialize dictionary to store the count of each character
dict = {"r": 0, "s": 0, "p": 0}

# Initialize boolean arrays to represent the state of each character
char = ""
s = [True] * K
r = [True] * K
p = [True] * K

# Initialize all characters to be in the 'on' state
for i in range(K):
	s[i] = True

# Iterate through each character in the input string
for i in range(len(T)):
	# Assign the current character to a variable
	char = T[i : i+1]

	# Check if we have reached the window size
	if i >= K:
		# If the current character is a substring of the previous K characters, toggle the state of the character
		if char == T[i-K:i+1-K]:
			if char == "s":
				# Toggle the state of the character at index i%K
				if s[i%K]:
					s[i%K] = False
					continue
				else:
					s[i%K] = True

			if char == "r":
				# Toggle the state of the character at index i%K
				if r[i%K]:
					r[i%K] = False
					continue
				else:
					r[i%K] = True

			if char == "p":
				# Toggle the state of the character at index i%K
				if p[i%K]:
					p[i%K] = False
					continue
				else:
					p[i%K] = True

		# If the current character is not a substring of the previous K characters, update the state of the characters accordingly
		else:
			if char == "s":
				# Set the state of the character at index i%K to 'on'
				s[i%K] = True
			if char == "r":
				# Set the state of the character at index i%K to 'on'
				r[i%K] = True
			if char == "p":
				# Set the state of the character at index i%K to 'on'
				p[i%K] = True

	# Update the dictionary with the count of the current character
	if char == "s":
		dict["s"] = dict["s"] + 1
	if char == "r":
		dict["r"] = dict["r"] + 1
	if char == "p":
		dict["p"] = dict["p"] + 1

# Calculate and print the result
res = P*dict["r"] + S*dict["p"] + R*dict["s"]
print(res)

# 