
n = int(input()) # Step 1: Read the input values
s = input() # The integer `n` represents the length of the string `s`.
cnt = 0 # Step 2: Initialize a counter
for i in range(n): # Step 3: Iterate through the string
	cnt += 1 # Increment the counter for each distinct character
	j = i + 1
	while j < n: # Step 4: Count distinct characters
		if s[i]!= s[j]: # Check if the current character is different from the next one
			break # If a different character is found, break the inner loop
		j += 1
	i = j - 1 # Step 5: Update the loop index
print(cnt) # Step 6: Output the result
