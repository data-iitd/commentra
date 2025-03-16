def group(n): # Function to determine group based on input number n
	if n == 4 or n == 6 or n == 9 or n == 11: # Check if number belongs to group B
		return "B"
	else:
		return "A"

def main(): # Main function
	x, y = map(int, input().split()) # Read input values of x and y from standard input

	if x == 2 or y == 2: # Check if either x or y is equal to 2
		print("No") # If yes, print "No" and exit
		return

	xg = group(x) # Determine group of number x
	yg = group(y) # Determine group of number y

	if xg == yg: # Check if both numbers belong to the same group
		print("Yes") # If yes, print "Yes"
	else:
		print("No") # If not, print "No"

main() # Run main function

