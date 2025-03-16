
n = int ( input ( ) ) # Reading the number of elements in the array from the standard input
arr = [ int ( x ) for x in input ( ).split ( ) ] # Reading the elements of the array from the standard input and storing them in a list
sum = sum ( arr ) # Calculating the sum of the elements in the array
c = 0 # Initializing the counter variable to 0
indices = [ ] # Creating an empty list to store the indices of the elements that satisfy the condition

for i in range ( n ) : # Starting a for loop to check if an element satisfies the condition
    if ( ( sum - arr [ i ] ) % ( n - 1 ) == 0 and ( sum - arr [ i ] ) / ( n - 1 ) == arr [ i ] ) : # Checking if the current element satisfies the condition
        c += 1 # Incrementing the counter variable if the condition is true
        indices.append ( i + 1 ) # Appending the index of the current element to the list

print ( c ) # Printing the number of elements that satisfy the condition
print ( " ".join ( map ( str, indices ) ) ) # Printing the indices of the elements that satisfy the condition separated by a space

