# Import the "fmt" package for formatted I/O
import fmt

# Define the main function, entry point of our program
def main():
	# Declare two variables, s and t, both of type string
	s, t = "", ""

	# Use the "fmt.Scan" function to read input from the standard input (keyboard)
	# and store it in variables s and t respectively
	fmt.Scan(s, t)

	# Print the concatenated string of t and s using the "fmt.Println" function
	fmt.Println(t + s)

# Call the main function
main()

# 