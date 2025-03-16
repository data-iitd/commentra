

import sys ; # Importing the sys module to access the standard input and output streams

def main ( ) :
    x = int ( input ( ) ) ; # Reading the first number from the standard input stream and storing it in the variable x
    list = [ ] ; # Creating an empty list to store digits
    pow = 0 ; # Initializing the variable pow to 0 to be used as the power of 10 in the calculation of the new number
    newNumber = 0 ; # Initializing the variable newNumber to 0 to store the final number after calculating the digits in reverse order

    # The following while loop runs as long as the number x is greater than zero
    while ( x > 0 ) :
        r = x % 10 ; # Storing the last digit of the number x in the variable r

        # The following if statement checks if the difference between 9 and the last digit r is less than r itself
        if ( 9 - r < r ) :
            # The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
            if ( x // 10 == 0 and 9 - r == 0 ) :
                list.append ( r ) ; # Adding the last digit r to the list if it is the only digit in the number x or if it is the last digit of a number greater than zero and the difference between 9 and the last digit is zero
            else :
                list.append ( 9 - r ) ; # Adding the number 9 minus the last digit r to the list if the difference between 9 and the last digit is greater than the last digit itself
        else :
            list.append ( r ) ; # Adding the last digit r to the list if the difference between 9 and the last digit is less than or equal to the last digit itself

        x = x // 10 ; # Dividing the number x by 10 to get the next digit

    # The following for loop runs through each digit in the list and calculates the new number by adding the digit multiplied by the power of 10 to the variable newNumber
    for i in range ( len ( list ) ) :
        newNumber = newNumber + list [ i ] * ( 10 ** pow ) ;
        pow = pow + 1 ;

    print ( newNumber ) ; # Printing the final number to the standard output stream

