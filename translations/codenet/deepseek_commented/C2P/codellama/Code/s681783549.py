#include <stdio.h>
#include <stdlib.h>

int main():
	# Declare an integer variable to be used as a loop counter
	i = 0
	
	# Declare a character array to store the input string
	S = []
	
	# Read a string input from the user and store it in S
	S = input()
	
	# Loop through each character in the string S
	for i in range(len(S)):
		# Check if the current character is 'A' and the next character is 'C'
		if S[i] == 'A' and S[i + 1] == 'C':
			# If the condition is met, print "Yes" and exit the program
			print("Yes")
			return 0
	
	# If the condition is not met after the loop completes, print "No" and exit the program
	print("No")
	return 0

