import sys

# Define the main function, which is the entry point of the program
def main ( ):
    # Create a Scanner object to read input from the standard input
    in = sys.stdin
    # Create a PrintWriter object to write output to the standard output
    pw = sys.stdout

    # Read the number of elements N from the standard input
    N = int ( in.readline ( ) )
    # Create an integer array A of size N to store the elements
    A = [ ]
    # Use a for loop to read each element from the standard input and store it in the corresponding index of the array A
    for n in range ( N ):
        A.append ( int ( in.readline ( ) ) )

    # Use the sort() method to sort the elements in the array A in ascending order
    A.sort ( )

    # Initialize two variables, min and max, to store the minimum and maximum elements in the array A, respectively
    min = A [ 0 ]
    max = A [ N - 1 ]

    # Use a for-each loop to iterate through each element in the array A and perform some checks
    for value in A:
        if value == min: # If the current element is equal to the minimum element min, increment the variable mins by 1
            mins += 1
        if value == max: # If the current element is equal to the maximum element max, increment the variable maxs by 1
            maxs += 1

    # Check if the minimum and maximum elements are the same
    if min == max:
        # Calculate the difference between the minimum and maximum elements, plus 1
        result = ( max - min ) + 1
        # Multiply the result by the number of occurrences of the minimum element
        result *= mins
        # Subtract the number of combinations of pairs of minimum elements
        result -= mins * ( mins - 1 ) / 2
    else:
        # Calculate the difference between the minimum and maximum elements
        result = ( max - min )
        # Multiply the result by the number of occurrences of the minimum element
        result *= mins
        # Multiply the result by the number of occurrences of the maximum element
        result *= maxs

    # Print the output
    print ( result )

    # Close the PrintWriter object to flush the output buffer and close the connection to the standard output
    pw.close ( )

# Define a static debug method to print the contents of an array or other objects for debugging purposes
def debug ( *obj ):
    print ( obj )

# Call the main function
if __name__ == "__main__":
    main ( )

