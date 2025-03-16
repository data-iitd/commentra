
import sys ; # Step 1: Import the necessary Python utility classes.
n = int ( input ( ) ) # Step 2: Read the size of the array from the user.
arr = [ int ( x ) for x in input ( ).split ( ) ] # Step 3: Create an array to store the elements of the array.
answer = abs ( arr [ 0 ] ) # Step 4: Initialize a variable to store the answer.
for i in range ( 1, n ) : # Step 5: Calculate the absolute difference between consecutive elements and add it to the answer.
    answer += abs ( arr [ i ] - arr [ i - 1 ] )
print ( answer ) # Step 6: Print the final answer.
# 