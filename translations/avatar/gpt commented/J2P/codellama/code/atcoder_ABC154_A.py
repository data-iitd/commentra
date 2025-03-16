import sys 

# Read a line of input, split it by spaces, and store it in an array
str = sys.stdin.readline().split() 

# Read another line of input and store it in variable 'u'
u = sys.stdin.readline() 

# Compare the string 'u' with the first element of the array 'str'
# Print the result based on the comparison
print(u.strip() == str[0], (int(str[0]) - 1) + " " + str[1], sep=" ") 

