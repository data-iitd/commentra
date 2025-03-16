

a = int ( input ( ) ) # Read the first integer value from user input
b = int ( input ( ) ) # Read the second integer value from user input

res = a # Initialize the result variable with the value of 'a'

while ( a >= b ) : # Start a while loop that continues as long as 'a' is greater than or equal to 'b'
    res += ( a // b ) # Increment the result variable by the result of dividing 'a' by 'b'
    
    a = ( a // b ) + ( a % b ) # Update the value of 'a' with the result of the division and the remainder

print ( res ) # Print the value of the result variable to the standard output stream

