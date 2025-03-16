
import sys ; // Importing the sys module to read input from the standard input stream

def main ( ):
    n = int ( sys.stdin.readline ( ) ) ; // Reading the first integer value n from the standard input stream
    k = int ( sys.stdin.readline ( ) ) ; // Reading the long integer value k from the standard input stream

    arr = [ ] ; // Creating an empty array named arr to store long integer values
    set = set ( ) ; // Creating an empty set named set to store unique long integer values

    for i in range ( n ) :
        arr.append ( int ( sys.stdin.readline ( ) ) ) ; // Reading a long integer value from the standard input stream and storing it in the arr[i] index

    arr.sort ( ) ; // Sorting the arr array in ascending order using the sort() method

    count = 0 ; // Initializing the count variable to 0

    for i in range ( n ) :
        if ( arr [ i ] % k!= 0 ) :
            count += 1 ; // Incrementing the count variable if the condition is true
            set.add ( arr [ i ] ) ; // Adding the arr[i] value to the set if it is not already present
        elif ( arr [ i ] / k not in set ) :
            count += 1 ; // Incrementing the count variable if the condition is true
            set.add ( arr [ i ] / k ) ; // Adding the arr[i] value to the set if it is not already present

    print ( count ) ; // Printing the count value to the standard output stream

main ( ) ; // Executing the main function

These comments should provide a clear understanding of the code's functionality and logic.

