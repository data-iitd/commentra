

s = input ( ) # Read the next line from the console and store it in the string's'

length = len ( s ) # Get the length of the string's'

ch ='' # Initialize a character variable 'ch' to store the first non-space and non-question mark character found in the string's'

for i in range ( length - 1, - 1, - 1 ) : # Iterate through the string's' from the end to the beginning
    if s [ i ]!='' and s [ i ]!= '?' : # Check if the current character is not a space or a question mark
        ch = s [ i ] # If yes, store the character in 'ch' and break out of the loop
        break

ch = ch.lower ( ) # Convert the character 'ch' to lowercase

if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'y' : # Check if the character 'ch' is a vowel or a y
    print ( "YES" ) # If yes, print "YES" to the console
else :
    print ( "NO" ) # If no, print "NO" to the console

