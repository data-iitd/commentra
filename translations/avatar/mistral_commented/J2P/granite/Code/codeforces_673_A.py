

n = int ( input ( ) ) # Reading the number of elements in the ArrayList from the standard input stream

a = [ ] # Creating an empty ArrayList named a

for i in range ( n ) : # Using a for loop to read and add each element to the ArrayList
    value = int ( input ( ) ) # Reading an integer value from the standard input stream
    a.append ( value ) # Adding the value to the ArrayList

result, pos = 0, 0 # Declaring and initializing the variables result, pos

if ( a [ 0 ] > 15 ) : # Checking if the first element in the ArrayList is greater than 15
    result = 15 # Assigning 15 to the result variable if the condition is true
else :
    for i in range ( 1, n ) : # Using a for loop to compare each element with the previous one
        if ( a [ i ] - a [ i - 1 ] > 15 ) : # Checking if the difference between two consecutive elements is greater than 15
            pos = i - 1 # Assigning the index of the previous element to the pos variable if the condition is true
            break # Exiting the loop if the condition is true

if ( pos!= 0 ) : # Checking if the pos variable is not equal to 0, indicating that the condition in the inner for loop was true
    result = a [ pos ] + 15 # Assigning the sum of the previous element and 15 to the result variable
else :
    result = a [ n - 1 ] + 15 # Assigning the sum of the last element and 15 to the result variable if the pos variable is 0

if ( result > 90 ) : result = 90 # Checking if the result is greater than 90 and assigning 90 to the result variable if it is

print ( result ) # Printing the result to the standard output stream

