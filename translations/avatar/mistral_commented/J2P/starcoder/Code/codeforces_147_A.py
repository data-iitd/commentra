#######
# Importing necessary Python libraries for reading input from the console and writing output to the console
import sys
import io

# Creating a function to check if a character is a Latin letter
def isLatinLetter ( c ) :
    # Check if the character falls within the ASCII range of Latin letters
    return c >= 'a' and c <= 'z'

# Creating a function to check if a character is a punctuation mark
def isPunctuation ( c ) :
    # Check if the character is a dot, comma, exclamation mark, or question mark
    if ( c == '.' ) : return True
    if ( c == ',' ) : return True
    if ( c == '!' ) : return True
    if ( c == '?' ) : return True
    # If none of the above conditions are met, return false
    return False

# Creating a function to read input from the console
def readInput ( ) :
    # Creating a variable to store the input
    s = input ( )
    # Returning the input
    return s

# Creating a function to write output to the console
def writeOutput ( s ) :
    # Writing the output to the console
    print ( s )

# Creating a function to translate the input string
def translate ( s ) :
    # Creating a StringBuilder to store the output
    sb = ''
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
        elif ( isPunctuation ( c ) ) :
            sb += c
    # Returning the output
    return sb

# Creating a function to run the program
def run ( ) :
    # Reading a line of input from the console
    s = readInput ( )
    # Translating the input string
    s = translate ( s )
    # Writing the output to the console
    writeOutput ( s )

# Running the program
run ( )

# Writing the end of code comment
writeOutput ( "