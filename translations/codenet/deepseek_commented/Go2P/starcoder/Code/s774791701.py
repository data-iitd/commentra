
# Declare a string variable to store user input
s = ""
# Read input from the user and store it in the variable `s`
s = input()

# Initialize the price variable with a starting value of 700
price = 700
# Loop through each character in the string `s`
for c in s:
	# Check if the current character is 'o'
	if c == 'o':
		# If the character is 'o', add 100 to the price
		price += 100
# Print the final value of the price
print(price)

