
import java.util.* ; // Importing the utility class Java.util.Scanner

public class Main { // Defining the class Main
    static long min ; // Initializing the minimum value to Long.MAX_VALUE

    public static void main ( String [ ] args ) { // Starting the main method
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input
        min = Long.MAX_VALUE ; // Setting the initial value of min to Long.MAX_VALUE
        ArrayList < Long > arr = new ArrayList < > ( ) ; // Creating an empty ArrayList of Long type to store the input numbers

        for ( int i = 0 ; i < 4 ; i ++ ) { // Reading 4 numbers from the standard input and storing them in the ArrayList
            arr.add ( sc.nextLong ( ) ) ;
        }

        String [ ] ops = new String [ 3 ] ; // Creating an array of String type to store the operators

        for ( int i = 0 ; i < 3 ; i ++ ) { // Reading 3 operators from the standard input and storing them in the array
            ops [ i ] = sc.next ( ) ;
        }

        util ( arr , ops , 0 ) ; // Calling the util method with the ArrayList, the array of operators, and the index of the first operator

        System.out.println ( min ) ; // Printing the minimum value found during the execution
    }

    public static void util ( ArrayList < Long > arr , String [ ] ops , int idx ) { // Starting the util method
        if ( idx == 3 ) { // Checking if the index of the operator is equal to 3 (the last operator)
            min = Math.min ( min , arr.get ( 0 ) ) ; // Updating the minimum value with the first number in the ArrayList
            return ; // Exiting the method
        }

        for ( int i = 0 ; i < arr.size ( ) ; i ++ ) { // Iterating through the ArrayList to find two numbers for the current operator
            for ( int j = i + 1 ; j < arr.size ( ) ; j ++ ) {
                ArrayList < Long > a = new ArrayList < > ( ) ; // Creating a new ArrayList to store the result of the current operation

                for ( int k = 0 ; k < arr.size ( ) ; k ++ ) { // Iterating through the ArrayList to exclude the current and previous numbers
                    if ( k != j && k != i ) {
                        a.add ( arr.get ( k ) ) ; // Adding the excluded number to the new ArrayList
                    }
                }

                long res ; // Initializing the result variable

                if ( idx < 3 && ops [ idx ].equals ( "+" ) ) { // Checking if the current operator is '+'
                    res = arr.get ( i ) + arr.get ( j ) ; // Performing the addition operation
                } else { // Else, the current operator is '*'
                    res = arr.get ( i ) * arr.get ( j ) ; // Performing the multiplication operation
                }

                a.add ( res ) ; // Adding the result to the new ArrayList
                util ( a , ops , idx + 1 ) ; // Recursively calling the util method with the new ArrayList, the array of operators, and the index of the next operator
            }
        }
    }
}

These comments should provide a clear understanding of the code logic for each block. Let me know if you need any further assistance.