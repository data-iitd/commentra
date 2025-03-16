
import sys ; // Importing the utility module

n = int ( sys.stdin.readline ( ) ) ; // Reading the first integer input 'n'
levels = int ( sys.stdin.readline ( ) ) ; // Reading the second integer input 'levels'

sum = 0 ; // Initializing sum variable to 0
sum2 = 0 ; // Initializing sum2 variable to 0
sum3 = 0 ; // Initializing sum3 variable to 0
arr = [ ] ; // Creating an integer array 'arr' of size 'levels'
count = 0 ; // Initializing count variable to 0

for i in range ( levels ) : // Loop to read 'levels' number of integers and store them in 'arr'
    arr.append ( int ( sys.stdin.readline ( ) ) )

level2 = int ( sys.stdin.readline ( ) ) ; // Reading the third integer input 'level2'
level3 = levels + level2 ; // Calculating the size of 'arr2'
arr2 = [ ] ; // Creating an integer array 'arr2' of size 'level3'

for i in range ( arr.length ) : // Loop to copy elements of 'arr' to 'arr2'
    arr2.append ( arr [ i ] )

for i in range ( level2 ) : // Loop to read 'level2' number of integers and store them in 'arr2'
    arr2.append ( int ( sys.stdin.readline ( ) ) )

arr3 = [ ] ; // Creating an integer array 'arr3' of size 'n'
j = 0 ; // Initializing 'j' variable to 0

for i in range ( n ) : // Loop to initialize 'arr3' with numbers from 1 to 'n'
    arr3.append ( j + 1 )
    j += 1

for i in range ( n ) : # Outer loop to compare each element of 'arr3' with 'arr2'
    for x in range ( arr2.length ) : # Inner loop to find a match between 'arr3[i]' and 'arr2[x]'
        if ( arr3 [ i ] == arr2 [ x ] ) : # If a match is found
            count += 1 # Increment the count variable
            break # Exit the inner loop

if ( count == n ) : # If all elements of 'arr3' are present in 'arr2'
    print ( "I become the guy." ) # Print the message
else : # Otherwise
    print ( "Oh, my keyboard!" ) # Print the error message

