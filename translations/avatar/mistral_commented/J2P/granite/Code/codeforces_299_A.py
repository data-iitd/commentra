

n = int ( input ( ) ) # Reading the number of elements in the array from the user input
a = [ int ( input ( ) ) for _ in range ( n ) ] # Creating a list of n integers and initializing it with user input

a.sort ( ) # Sorting the list in ascending order using the built-in sort() method

min = a [ 0 ] # Assigning the minimum value in the list to the min variable

# Checking if all the elements in the list are multiples of the minimum value
for value in a:
    if value % min!= 0: # Checking if the current element is not a multiple of the minimum value
        print ( - 1 ) # Printing -1 if any non-multiple of the minimum value is found
        break # Exiting the loop if any non-multiple of the minimum value is found
else:
    print ( min ) # Printing the minimum value if all elements are multiples of the minimum value

