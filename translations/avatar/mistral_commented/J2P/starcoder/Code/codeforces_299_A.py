
import sys ; // Importing the sys module for reading input from the standard input stream

def main ( ):
    n = int ( sys.stdin.readline ( ) ) ; // Reading the number of elements in the array from the standard input stream
    a = [ int ( x ) for x in sys.stdin.readline ( ).split ( ) ] ; // Creating an integer array of size n

    a.sort ( ) ; // Sorting the array in ascending order using the sort() method

    min = a [ 0 ] ; // Assigning the minimum value in the array to the min variable

    # Checking if all the elements in the array are multiples of the minimum value
    for value in a :
        if value % min!= 0 : # Checking if the current element is not a multiple of the minimum value
            print ( - 1 ) ; # Printing -1 if any non-multiple of the minimum value is found
            return ; # Exiting the method if any non-multiple of the minimum value is found

    # Printing the minimum value if all elements are multiples of the minimum value
    print ( min ) ;

if __name__ == '__main__' :
    main ( ) ;

