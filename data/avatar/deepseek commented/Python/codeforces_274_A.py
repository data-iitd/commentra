
num , k = [ int ( x ) for x in input ( ).split ( ) ]  # Read the number of elements and the divisor
arr = [ int ( x ) for x in input ( ).split ( ) ]  # Read the array of integers
different = set ( )  # Initialize a set to keep track of unique elements not divisible by k
temp = 0  # Initialize a variable to store the maximum length of the set
arr.sort ( )  # Sort the array

# Iterate through each element in the sorted array
for x in arr :
    if ( x % k != 0 or not x // k in different ) :  # Check if x is not divisible by k or x//k is not in the set
        different.add ( x )  # Add x to the set if the condition is true
    temp = max ( len ( different ) , temp )  # Update temp with the maximum length of the set

print ( temp )  # Print the maximum number of unique elements not divisible by k