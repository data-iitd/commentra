# We import the sys module for reading input from standard input
import sys

# We import the re module for regular expressions
import re

# We import the math module for mathematical functions
import math

# We import the itertools module for iterating through the string
import itertools

# We define a main function
def main():
	# We read the first line of input as a string
	N = sys.stdin.readline()
	# We read the second line of input as a string
	P = sys.stdin.readline()
	# We read the third line of input as a string
	S = sys.stdin.readline()
	# We call the checkSubNumbers function with N, P, and S as arguments and store the result in answer variable
	answer = checkSubNumbers(N, P, S)
	# We print the answer
	print(answer)

# checkSubNumbers function checks if any subnumber of given string S is divisible by prime number P
def checkSubNumbers(N, P, S):
	# We check if P is equal to 2 or 5
	if P == "2" or P == "5":
		# If P is equal to 2 or 5, we call the checkTwoOrFive function
		return checkTwoOrFive(N, P, S)
	else:
		# If P is not equal to 2 or 5, we call the checkNotTwoNorFive function
		return checkNotTwoNorFive(N, P, S)

# checkTwoOrFive function checks if any subnumber of given string S is divisible by prime number P equal to 2 or 5
def checkTwoOrFive(N, P, S):
	answer = 0 # We initialize answer variable as 0
	# We iterate through the string S from the last character to the first character
	for i in range(len(S) - 1, -1, -1):
		# We check if the substring from i to i+1 is divisible by P
		if int(S[i]) % int(P) == 0:
			# If the substring from i to i+1 is divisible by P, we add its index to the answer variable
			answer += i + 1
	return answer

# checkNotTwoNorFive function checks if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
def checkNotTwoNorFive(N, P, S):
	answer = 0 # We initialize answer variable as 0
	# We iterate through the string S from the last character to the first character
	for i in range(len(S) - 1, -1, -1):
		# We get the digit from the string S at the current index i
		digit = int(S[i])
		# We get the count of the current digit from the string S
		count = S.count(str(digit))
		# We add the count to the answer variable
		answer += count
	return answer

# We call the main function
if __name__ == "__main__":
	main()

