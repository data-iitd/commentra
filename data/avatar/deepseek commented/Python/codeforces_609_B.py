
def _input ( ) : return map ( int , input ( ).split ( ) )
# Read the values of n and m
n , m = _input ( )
# Read the list of elements
lst = list ( _input ( ) )
# Initialize a dictionary to store the frequency of elements
l = { }
# Populate the dictionary with the frequency of each element in the list
for i in range ( n ) :
    if lst [ i ] not in l :
        l [ lst [ i ] ] = 1
    else : l [ lst [ i ] ] += 1
# Initialize the result variable to store the final result
res = 0
# Iterate over the list to calculate the result
for i in range ( n ) :
    if l [ lst [ i ] ] > 1 :
        # Calculate the number of pairs that can be formed with the current element
        res += n - i - l [ lst [ i ] ]
        # Decrement the frequency of the current element in the dictionary
        l [ lst [ i ] ] -= 1
    else :
        # If the frequency is not greater than 1, calculate the number of pairs
        res += n - i - 1
# Print the final result
print ( res )

