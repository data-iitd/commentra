
import java.util.* ; // Importing the utility class Scanner from the Java standard library

public class Main { // Defining the main class named Main

    public static void main ( String [ ] args ) { // Defining the main method that is executed when the program runs
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream

        int n = sc.nextInt ( ) ; // Reading the first integer value n from the standard input stream
        long k = sc.nextLong ( ) ; // Reading the long integer value k from the standard input stream

        long [ ] arr = new long [ n ] ; // Creating an array named arr of length n to store long integer values
        HashSet < Long > set = new HashSet < > ( ) ; // Creating an empty HashSet named set to store unique long integer values

        for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the array arr from index 0 to n-1
            arr [ i ] = sc.nextLong ( ) ; // Reading a long integer value from the standard input stream and storing it in the arr[i] index
        }

        Arrays.sort ( arr ) ; // Sorting the arr array in ascending order using the Arrays.sort() method

        int count = 0 ; // Initializing the count variable to 0

        for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the sorted arr array from index 0 to n-1
            if ( arr [ i ] % k != 0 ) { // Checking if the arr[i] value is not divisible by k
                count ++ ; // Incrementing the count variable if the condition is true
                set.add ( arr [ i ] ) ; // Adding the arr[i] value to the set if it is not already present
            } else if ( ! set.contains ( arr [ i ] / k ) ) { // Checking if the arr[i] value is divisible by k and if its quotient is not present in the set
                count ++ ; // Incrementing the count variable if the condition is true
                set.add ( arr [ i ] ) ; // Adding the arr[i] value to the set if it is not already present
            }
        }

        System.out.println ( count ) ; // Printing the count value to the standard output stream
    }
}

These comments should provide a clear understanding of the code's functionality and logic.