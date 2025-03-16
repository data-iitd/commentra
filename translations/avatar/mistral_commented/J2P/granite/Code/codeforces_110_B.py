

n = int ( input ( ) ) # Read an integer `n` from the standard input
c = [ 'a' ] * n # Create a new character array `c` of size `n` and initialize all elements to the character 'a'
p = 'a' # Declare a character variable `p` to store the current character to be added to the array

for i in range ( 4 ) : # Use a for loop to iterate through the first four elements of the array
  for j in range ( i, n, 4 ) : # Use a nested for loop to populate every fourth element of the array with the next character
    c [ j ] = p # Set the current element of the array to the current character
    p = chr ( ord ( p ) + 1 ) # Increment the character to be added to the next element

print ( ''.join ( c ) ) # Print each character in the array to the standard output

# 