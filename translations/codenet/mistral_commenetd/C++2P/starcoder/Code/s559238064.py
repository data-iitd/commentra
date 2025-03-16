# Initialize input/output streams and read input data
a = input()
# Assign size of the string to variable 'a'
a = len(a)
# Check if there are any consecutive identical characters in the string
for i in range(a - 1):
	# Check if current character is same as next character
	if a[i] == a[i + 1]:
		# If yes, print "Bad" and exit the program
		print("Bad")
		exit()
# If no consecutive identical characters are found, print "Good"
print("Good")

