
import sys

# Reading the number of elements in the list from the input
n = int ( input ( ) )

# Creating an empty list to store the elements
list = [ ]

# Reading 'n' elements from the input and adding them to the list
for i in range ( n ) :
    list.append ( int ( input ( ) ) )

# Sorting the list in ascending order using the sort() method
list.sort ( )

# Initializing a variable 'c' to keep track of the number of distinct elements
c = 1

# Iterating through the list to find the number of distinct elements
for i in range ( n ) :
    # If the current element is greater than or equal to the current count 'c', increment the count
    if ( list [ i ] >= c ) :
        c += 1

# Writing the result to the output
print ( c )

# Closing the print writer object
sys.stdout.close ( )

# Debugging method to print the deep toString representation of an object
def debug ( *obj ) :
    print ( obj )

