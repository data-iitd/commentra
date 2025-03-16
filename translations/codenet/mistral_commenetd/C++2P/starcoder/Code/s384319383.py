
# Define a function to calculate the answer
def calc_ans(cnt):
	ans = 1 # Initialize the answer to 1
	for i in range(26): # Iterate through all the characters from 'a' to 'z'
		ans *= cnt[i] # Multiply the answer with the count of the current character
	return ans - 1 # Calculate the final answer by subtracting 1 from the initial answer

# Define a function to read the input
def read_input():
	n = int(input()) # Read the number of strings from the standard input
	cnt = [1] * 26 # Initialize the count vector to 1 for all the characters
	s = [] # Initialize the string vector
	for i in range(n): # Iterate through all the strings
		s.append(input()) # Read a string from the standard input and store it in the's' vector
	return n, cnt, s

# Define a function to print the output
def print_output(ans):
	print(ans) # Print the final answer to the standard output

# Define a function to run the program
def run():
	n, cnt, s = read_input() # Read the input
	for i in range(n): # Iterate through all the strings
		for c in s[i]: # Iterate through all the characters in the current string
			cnt[ord(c) - ord('a')] += 1 # Increment the count of the current character in the 'cnt' vector
	ans = calc_ans(cnt) # Calculate the answer
	print_output(ans) # Print the output

# Run the program
run()

