

import sys ; # Step 1: Import the necessary Python utility classes.
def main ( ) : # Step 2: Define the main function.
    n = int ( input ( ) ) ; # Step 3: Read the size of the array from the user.
    arr = [ ] ; # Step 4: Create an empty list to store the elements of the array.
    for i in range ( n ) : # Step 5: Read the elements of the array from the user.
        arr. append ( int ( input ( ) ) ; 
    answer = abs ( arr [ 0 ] ) ; # Step 6: Initialize a variable to store the answer.
    for i in range ( 1, n ) : # Step 7: Calculate the absolute difference between consecutive elements and add it to the answer.
        answer += abs ( arr [ i ] - arr [ i - 1 ] ) ; 
    print ( answer ) ; # Step 8: Print the final answer.
if __name__ == "__main__" : # Step 9: Call the main function.
    main ( ) ;
