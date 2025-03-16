
import java.util.ArrayList ;  // Importing ArrayList class from java.util package
import java.util.List ;   // Importing List interface
import java.util.Scanner ; // Importing Scanner class from java.util package

public class Main {

    public static void main ( String args [ ] ) {
        Scanner sc = new Scanner ( System.in ) ; // Creating a Scanner object to read input from the standard input stream
        List < Long > list = new ArrayList < > ( ) ; // Creating an empty ArrayList to store digits
        long x = sc.nextLong ( ) ; // Reading the first number from the standard input stream and storing it in the variable x

        // The following while loop runs as long as the number x is greater than zero
        while ( x > 0 ) {
            long r = x % 10 ; // Storing the last digit of the number x in the variable r

            // The following if statement checks if the difference between 9 and the last digit r is less than r itself
            if ( 9 - r < r ) {
                // The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
                if ( x / 10 == 0 && 9 - r == 0 ) {
                    list.add ( r ) ; // Adding the last digit r to the ArrayList if it is the only digit in the number x or if it is the last digit of a number greater than zero and the difference between 9 and the last digit is zero
                } else {
                    list.add ( 9 - r ) ; // Adding the number 9 minus the last digit r to the ArrayList if the difference between 9 and the last digit is greater than the last digit itself
                }
            } else {
                list.add ( r ) ; // Adding the last digit r to the ArrayList if the difference between 9 and the last digit is less than or equal to the last digit itself
            }

            x = x / 10 ; // Dividing the number x by 10 to get the next digit
        }

        int pow = 0 ; // Initializing the variable pow to 0 to be used as the power of 10 in the calculation of the new number
        long newNumber = 0 ; // Initializing the variable newNumber to 0 to store the final number after calculating the digits in reverse order

        // The following for loop runs through each digit in the ArrayList and calculates the new number by adding the digit multiplied by the power of 10 to the variable newNumber
        for ( int i = 0 ; i < list.size ( ) ; i ++ ) {
            newNumber = newNumber + list.get ( i ) * ( long ) Math.pow ( 10 , pow ) ;
            pow ++ ;
        }

        System.out.println ( newNumber ) ; // Printing the final number to the standard output stream