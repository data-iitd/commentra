

n = int(input()) # Read the number of strings from the standard input
cnt = [1] * 26 # Initialize the count vector with all elements set to 1
s = [] # Initialize an empty list to store the strings

for i in range(n): # Iterate through all the strings
	c = input() # Read a character from the standard input and store it in the 'c' variable
	s.append(c) # Append the character to the's' list
	cnt[ord(c) - ord('a')] += 1 # Increment the count of the character in the 'cnt' vector

ans = 1 # Initialize the answer to 1
for i in range(26): # Iterate through all the characters from 'a' to 'z'
	ans *= cnt[i] # Multiply the answer with the count of the current character

ans -= 1 # Calculate the final answer by subtracting 1 from the initial answer

print(ans) # Print the final answer to the standard output

