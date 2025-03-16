# Package declaration, this file is the entry point of the program
import sys

# Import statements, importing the sys package

# Entry point of the program
def main():
	# Initialize a variable s of type string and read a string input from the standard input
	s = sys.stdin.readline().rstrip()

	# Initialize a variable ans with the string value "No"
	ans = "No"

	# Check if the index of the substring "C" in the string s is less than the index of the substring "F"
	if s.find("C") < s.rfind("F"):
		# If it is, then change the value of ans to "Yes"
		ans = "Yes"

	# Check if the index of the substring "C" in the string s is less than 0
	if s.find("C") < 0:
		# If it is, then do not change the value of ans
	# Print the value of ans to the standard output
	print(ans)

# End of the code

