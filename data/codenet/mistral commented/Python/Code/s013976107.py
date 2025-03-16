
# Import map function to convert input list to list of integers
# Import input function to read user input as a list of strings
import mapper, sys

# Read user input as a list of strings
input_list = sys.stdin.readline().strip().split()

# Assign the first two elements of the input list to variables A and B after converting them to integers
A, B = map(int, input_list)

# Read the entire input string as a list of characters and assign it to the variable S
S = list(sys.stdin.readline().strip())

# Check if the character at index A in the string S is equal to '-'
if S[A] == '-':
    # Check if the list S contains exactly one occurrence of the character '-'
    if S.count('-') == 1:
        # If both conditions are met, print "Yes"
        print("Yes")
    else:
        # If not, print "No"
        print("No")
else:
    # If the character at index A is not '-', print "No"
    print("No")