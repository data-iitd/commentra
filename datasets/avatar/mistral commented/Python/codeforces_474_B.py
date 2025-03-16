
# Initialize an empty list `L`
L = [ ]

# Read the first input, which is the number of elements to add to the list
input ( )

# Use a for loop to iterate through each integer in the input
for k in input ( ).split ( ) :
    # Add `r` elements to the list `L` with the value `r`
    L += [ r ] * int ( k )
    # Increment the value of `r` by 1 to prepare for the next iteration
    r += 1

# Read the second input, which represents the indices of the elements to print from the list
input ( )

# Use another for loop to iterate through each integer in the input
for j in input ( ).split ( ) :
    # Print the element at the given index using the index as an offset from the beginning of the list
    print ( L [ int ( j ) - 1 ] )