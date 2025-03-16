# Take a string as input from the user
S = input ()

# Import the Counter function from the collections module to count the frequency of each character in the string
from collections import Counter

# Create a set Sa from the list of characters in the string S
Sa = set ( list ( S ) )

# Check if the length of the set Sa is equal to 2
if len ( Sa ) != 2:
    # If not, print "No" and exit the program
    print ( "No" )
    exit ()

# Iterate through each character i in the set Sa
for i in Sa:
    # For each character i, check if its frequency in the string S is equal to 2 using the Counter dictionary c
    if c [ i ] != 2:
        # If the frequency of any character is not equal to 2, print "No" and exit the program
        print ( "No" )
        exit ()

# If all characters have a frequency of 2, print "Yes" to indicate that the string satisfies the condition
print ( "Yes" )
