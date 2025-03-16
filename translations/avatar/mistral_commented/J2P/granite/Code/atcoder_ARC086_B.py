

import sys ; # Importing the sys module to access the standard input and output streams

n = int ( input ( ) ) ; # Reading the first integer from the standard input stream and assigning it to the variable n
a = [ int ( x ) for x in input ( ).split ( ) ] ; # Reading the remaining integers from the standard input stream and assigning them to the list a
r = [ ] ; # Creating an empty list to store the output
m = 0 ; # Initializing the variable m to 0

for i in range ( 1, n ) : # Starting a for loop to iterate through the list a from the second element to the last one
    if abs ( a [ m ] ) > abs ( a [ i ] ) : # Comparing the absolute values of the first and current elements to find the index of the smallest absolute value
        m = i ; # Assigning the index of the smallest absolute value to the variable m

for i in range ( n ) : # Starting a for loop to iterate through the list a from the first element to the last one
    if ( a [ m ] >= 0 ) ^ ( a [ i ] >= 0 ) : # Checking if the signs of the elements at indices m and i are different
        r.append ( str ( m + 1 ) + " " + str ( i + 1 ) ) ; # Adding the pair (m+1, i+1) to the list r if the condition is true

if a [ m ] >= 0 : # Checking if the smallest absolute value is positive
    for i in range ( 1, n ) : # Starting a for loop to iterate through the list a from the second element to the last one
        r.append ( str ( i ) + " " + str ( i + 1 ) ) ; # Adding the pair (i, i+1) to the list r if the smallest absolute value is positive
else : # If the smallest absolute value is negative
    for i in range ( n - 1, 0, - 1 ) : # Starting a for loop to iterate through the list a from the last element to the second one
        r.append ( str ( i + 1 ) + " " + str ( i ) ) ; # Adding the pair (i, i-1) to the list r if the smallest absolute value is negative

print ( len ( r ) ) ; # Printing the length of the list r to the standard output stream
print ( "\n".join ( r ) ) ; # Printing each pair in the list r to the standard output stream using the join method.

