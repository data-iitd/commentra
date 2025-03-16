
# Importing the required utility class Scanner from the Python standard library
import sys

# Main method is the entry point of the Python application
def main():

    # Creating a new Scanner object to read input from the standard input stream
    in = Scanner ( sys.stdin )

    # Reading the first integer input n from the user
    n = in.nextInt ( )

    # Reading the second integer input m from the user
    m = in.nextInt ( )

    # Creating an integer array arr of size n to store the input integers
    arr = [ 0 ] * n

    # Creating an integer array gen of size 11 to store the count of each integer occurrence
    gen = [ 0 ] * 11

    # Reading the input integers and storing them in the arr array
    for i in range ( n ) :
        arr [ i ] = in.nextInt ( )
        # Incrementing the count of the arr[i] in the gen array
        gen [ arr [ i ] ] += 1

    # Calculating the answer
    ans = 0
    for i in range ( 1, m + 1 ) :
        for k in range ( 1, m + 1 ) :
            # Skipping the case when i and k are equal to avoid double counting
            if ( i!= k ) :
                # Multiplying the count of i and k and adding it to the answer
                ans += gen [ i ] * gen [ k ]

    # Printing the answer divided by 2
    print ( ans // 2 )

# Calling the main method to execute the program
main()

