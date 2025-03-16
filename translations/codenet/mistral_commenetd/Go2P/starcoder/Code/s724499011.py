
# Initialize variables
n = int(input()) # Read the number of elements in the string's'
s = input() # Read the string's'
ns = [0] * n # Create a slice 'ns' of length 'n' to store the color index for each character in's'

# Read the string's' into 'ns'
for i in range(n):
	# Assign color index to 'ns' based on the character in's'
	if s[i] == 'R':
		ns[i] = 0
	elif s[i] == 'G':
		ns[i] = 1
	elif s[i] == 'B':
		ns[i] = 2

# Initialize 'rgb' slice with zeros
rgb = [[0, 0, 0]] * (n + 1)
rgb[0] = [0, 0, 0] # First row of 'rgb' slice to store the total RGB values for each color
for i in range(1, n + 1):
	# Initialize each inner row of 'rgb' slice with zeros
	rgb[i] = [0, 0, 0]
	for j in range(3):
		rgb[i][j] = rgb[i - 1][j] # Initialize each cell with the value of the corresponding cell in the previous row
	# Increment the value of the cell in the current row and column based on the color index of the previous character
	rgb[i][ns[i - 1]] += 1

# Calculate the sum of differences between adjacent rows in 'rgb' slice
sum = 0
for i in range(n - 2):
	for j in range(i + 1, n - 1):
		# Check if the characters in the current and next indices have different colors
		if ns[i]!= ns[j]:
			# Calculate the total difference between the corresponding cells in the 'rgb' slice
			tn = 3 - ns[i] - ns[j]
			sum += rgb[n][tn] # Get the total RGB value of the last cell in the last row with the complementary color
			sum -= rgb[j + 1][tn] # Subtract the total RGB value of the first cell in the next row with the complementary color

			# Check if there is a character with the same color index between the current and next indices
			k = 2 * j - i
			if k < n and ns[k] == tn:
				sum -= 1 # Decrease the sum if there is a character with the same color index between the current and next indices
		# End of the code

# Print the final result
print(sum)

