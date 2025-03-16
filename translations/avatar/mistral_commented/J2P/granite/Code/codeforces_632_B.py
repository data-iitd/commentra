

import sys ; # Importing the sys module to access the standard input stream

def main ( ) : # Defining the main function
    n = int ( input ( ) ) ; # Reading the number of elements in the array from the standard input
    a = list ( map ( int, input ( ).split ( ) ) ; # Reading the array elements from the standard input and converting them to integers
    s = input ( ) ; # Reading the string from the standard input
    sum = 0 ; # Initializing the sum variable to zero

    for i in range ( len ( s ) ) : # Iterating through the string to calculate the sum of the array elements corresponding to the 'B' characters
        if ( s [ i ] == 'B' ) sum += a [ i ] ;

    ans = sum ; # Initializing the answer variable with the sum calculated above
    sum1 = sum ; # Initializing a temporary sum variable with the sum calculated above

    for i in range ( len ( s ) ) : # Iterating through the string to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
        if ( s [ i ] == 'A' ) sum1 += a [ i ] ;
        else sum1 -= a [ i ] ;
        ans = max ( ans, sum1 ) ;

    sum1 = sum ; # Resetting the temporary sum variable with the sum calculated at the beginning

    for i in range ( len ( s ) - 1, - 1, - 1 ) : # Iterating through the string in reverse order to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
        if ( s [ i ] == 'A' ) sum1 += a [ i ] ;
        else sum1 -= a [ i ] ;
        ans = max ( ans, sum1 ) ;

    print ( ans ) ; # Printing the maximum sum found

if __name__ == '__main__' : # Executing the main function if the script is run directly
    main ( ) ;

