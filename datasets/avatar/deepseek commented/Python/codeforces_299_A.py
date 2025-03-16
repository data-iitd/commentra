
num_inp = lambda : int ( input ( ) )
# This function reads an integer input from the user.
arr_inp = lambda : list ( map ( int , input ( ).split ( ) ) )
# This function reads a list of integers from the input.
sp_inp = lambda : map ( int , input ( ).split ( ) )
# This function reads a map of integers from the input.

# Read the entire input, split the second line into a list of integers, and sort them.
a = sorted ( map ( int , [ * open ( 0 ) ] [ 1 ].split ( ) ) )

# Print the first element of the sorted list if it is divisible by any other element in the list, otherwise print -1.
print ( [ a [ 0 ] , - 1 ] [ any ( x % a [ 0 ] for x in a ) ] )
# This logic checks if the smallest element in the list is divisible by any other element in the list.
# If it is, it prints the smallest element; otherwise, it prints -1.