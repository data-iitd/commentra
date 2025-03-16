
# Importing the utility class Scanner from the java.util package
import java.util.* ;

if __name__ == '__main__' :
    sc = Scanner ( ) ; # Creating a new Scanner object to read input from the standard input
    n = sc.nextInt ( ) ; # Reading the number of elements in the array from the standard input
    arr = [ ] ; # Creating an integer array of size n
    sum = 0 ; # Initializing the sum variable to 0

    for i in range ( n ) : # Starting a for loop to read and store the elements in the array
        arr.append ( sc.nextInt ( ) ) ; # Reading an integer value from the standard input and storing it in the current index of the array
        sum += arr [ i ] ; # Adding the current element to the sum variable

    c = 0 ; # Initializing the counter variable to 0
    sb = StringBuilder ( ) ; # Creating an empty StringBuilder object to store the indices of the elements that satisfy the condition

    for i in range ( n ) : # Starting a for loop to check if an element satisfies the condition
        if ( ( sum - arr [ i ] ) % ( n - 1 ) == 0 and ( sum - arr [ i ] ) / ( n - 1 ) == arr [ i ] ) : # Checking if the current element satisfies the condition
            c += 1 ; # Incrementing the counter variable if the condition is true
            sb.append ( ( i + 1 ) + " " ) ; # Appending the index of the current element to the StringBuilder object

    print ( c ) ; # Printing the number of elements that satisfy the condition
    print ( sb.toString ( ) ) ; # Printing the indices of the elements that satisfy the condition separated by a space

