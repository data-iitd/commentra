
import sys ; // Importing the sys module for reading input from the user

n = int ( sys.stdin.readline ( ) ) ; // Reading the first integer input 'n' from the user
k = int ( sys.stdin.readline ( ) ) ; // Reading the second integer input 'k' from the user
arr = [ int ( x ) for x in sys.stdin.readline ( ).split ( ) ] ; // Creating an integer array 'arr' of size 'n'

res = "" ; // Creating a string variable'res' to store the output string
o = 0 ; // Initializing an integer variable 'o' to 0
e = 0 ; // Initializing an integer variable 'e' to 0

# Counting the number of 1's and 0's in the array 'arr'
for i in range ( n ) :
    if ( arr [ i ] == 1 ) : o += 1 ; # Incrementing the variable 'o' when the current element in the array is 1
    else : e += 1 ; # Incrementing the variable 'e' when the current element in the array is 0

# Processing the user queries
for i in range ( k ) :
    l = int ( sys.stdin.readline ( ) ) ; # Reading the left index 'l' of the query from the user
    r = int ( sys.stdin.readline ( ) ) ; # Reading the right index 'r' of the query from the user

    if ( ( r - l + 1 ) % 2 == 1 ) : res += "0\n" ; # If the length of the query is odd, appending '0' to the output string followed by a newline character
    else : # If the length is even
        if ( ( r - l + 1 ) / 2 <= o ) : res += "1\n" ; # If half of the length is less than or equal to the number of 1's in the array, appending '1' to the output string followed by a newline character
        else : res += "0\n" ; # Otherwise, appending '0' to the output string followed by a newline character

print ( res ) ; # Printing the final output string

