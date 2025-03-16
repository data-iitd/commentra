
# Importing the sys module for reading input from the user
import sys

# Reading the number of elements in the array from the user
n = int ( input ( ) )

# Creating an integer array of size n
a = [ ]

# Initializing the array with user input
for i in range ( n ) :
  a.append ( int ( input ( ) ) )

# Sorting the array in ascending order
a.sort ( )

# Checking if there is any pair of adjacent elements that satisfy the condition
for i in range ( n - 1 ) :
  # Checking if the next element is less than twice the current element and they are not the same
  if ( a [ i + 1 ] < a [ i ] * 2 and a [ i ]!= a [ i + 1 ] ) :
    print ( "YES" ) # Printing "YES" if a pair is found
    sys.exit ( ) # Exiting the method if a pair is found

# If no pair is found, printing "NO"
print ( "NO" )

