
# Import the "fmt" package for formatted I/O
import fmt

# Declare a variable named "s" of type string
s = ""

# Use the "fmt.Scan" function to read a string input from the standard input
fmt.Scan(s)

# Check if the length of the string "s" is greater than or equal to 4
# and if its first four characters are "YAKI"
if len(s) >= 4 and s[0:4] == "YAKI":
	# If the condition is true, print the word "Yes" to the standard output
	fmt.Println("Yes")
else:
	# If the condition is false, print the word "No" to the standard output
	fmt.Println("No")

# 