
L = [ ]
# Initialize an empty list L to store the results.
input ( )
# Take the first input from the user.
r = 1
# Initialize the variable r to 1.
for k in input ( ).split ( ) :
    # Split the first input into a list of strings and iterate over each string.
    L += [ r ] * int ( k )
    # Multiply the string '1' by the integer value of the string and append the result to the list L.
    r += 1
    # Increment r by 1 for the next iteration.
input ( )
# Take the second input from the user.
for j in input ( ).split ( ) :
    # Split the second input into a list of strings and iterate over each string.
    print ( L [ int ( j ) - 1 ] )
    # For each string, print the element at the index specified by the integer value of the string minus one from the list L.

