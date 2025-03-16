

n = int(input()) # Read the size of the string from the standard input
s = input() # Read the string from the standard input
cnt = 0 # Initialize a counter variable 'cnt' to 0

# Beginning of the first for loop
for i in range(n): # Loop through each character in the string's'
	cnt += 1 # Increment the counter variable 'cnt'
	j = i + 1 # Initialize a variable 'j' to check for the next character

	# Beginning of the inner for loop
	while j < n: # Compare the current character with the next characters in the string
		if s[i]!= s[j]: # If the current character is not equal to the next character
			break # Exit the inner for loop
		j += 1 # If the current character is repeated, update the index 'j' to the next index
	i = j - 1 # Update the index 'i' to the previous index

# Output the result
print(cnt) # Print the value of the counter variable 'cnt' to the standard output
