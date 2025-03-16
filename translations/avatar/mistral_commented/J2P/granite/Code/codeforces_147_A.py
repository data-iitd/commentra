
#######
# Importing necessary Python libraries for reading input from the console and writing output to the console
import sys

# Method to check if a character is a Latin letter
def isLatinLetter ( c ) :
    # Check if the character is a lowercase Latin letter
    return c >= 'a' and c <= 'z'

# Method to check if a character is a punctuation mark
def isPunctuation ( c ) :
    # Check if the character is a dot, comma, exclamation mark, or question mark
    if ( c == '.' ) : return True
    if ( c == ',' ) : return True
    if ( c == '!' ) : return True
    if ( c == '?' ) : return True
    # If none of the above conditions are met, return False
    return False

# Reading a line of input from the console
s = input ( )

# Creating a StringBuilder to store the output
sb = ""

# Finding the length of the input string
n = len ( s )

# Appending the first character of the input string to the StringBuilder
sb += s [ 0 ]

# Iterating through the rest of the characters in the input string
for i in range ( 1, n ) :
    # Getting the current character from the input string
    c = s [ i ]

    # If the current character is a Latin letter, append it to the StringBuilder with a space before it if the previous character was not a Latin letter
    if ( isLatinLetter ( c ) ) :
        if ( not isLatinLetter ( s [ i - 1 ] ) ) :
            sb +=''
        sb += c
    # If the current character is a punctuation mark, append it directly to the StringBuilder without a space
    else if ( isPunctuation ( c ) ) :
        sb += c

# Writing the output to the console
print ( sb )

# End of code
