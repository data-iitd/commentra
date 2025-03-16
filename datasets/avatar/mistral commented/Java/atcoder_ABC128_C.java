
import java.util.* ; // Importing the utility class Scanner

public class Main { // Defining the Main class

    public static void main ( String [ ] args ) { // Main method to start the program
        Main main = new Main ( ) ; // Creating an instance of the Main class
        main.run ( ) ; // Calling the run method to execute the program
    }

    public void run ( ) { // Method to run the program
        Scanner sc = new Scanner ( System.in ) ; // Creating a Scanner object to read input

        int N = sc.nextInt ( ) ; // Reading the first integer from the input
        int M = sc.nextInt ( ) ; // Reading the second integer from the input

        ArrayList < Integer > a = new ArrayList < > ( ) ; // Creating an ArrayList of size N to store integers

        // Initializing the ArrayList with zeros
        for ( int i = 0 ; i < N ; i ++ ) {
            a.add ( 0 ) ;
        }

        // Reading the queries and updating the ArrayList accordingly
        for ( int i = 0 ; i < M ; i ++ ) {
            int k = sc.nextInt ( ) ; // Reading the number of elements to be updated

            for ( int j = 0 ; j < k ; j ++ ) { // Iterating through the elements to be updated
                int s = sc.nextInt ( ) ; // Reading the index of the element to be updated
                s -- ; // Decreasing the index by 1 as the ArrayList index starts from 0

                // Updating the value of the element at the given index
                a.set ( s , a.get ( s ) | ( 1 << i ) ) ;
            }
        }

        int p = 0 ; // Initializing a variable to store the XOR of all given integers

        // Reading the integers and computing their XOR
        for ( int i = 0 ; i < M ; i ++ ) {
            int x = sc.nextInt ( ) ; // Reading an integer from the input
            p |= ( x << i ) ; // Computing the XOR of the current integer with the previous result
        }

        int ans = 0 ; // Initializing a variable to store the count of valid answers

        // Iterating through all possible combinations of the ArrayList elements
        for ( int s = 0 ; s < ( 1 << N ) ; s ++ ) { // 1 << N represents 2^N
            int t = 0 ; // Initializing a variable to store the XOR of the current combination with the ArrayList elements

            // Computing the XOR of the current combination with the ArrayList elements
            for ( int i = 0 ; i < N ; i ++ ) {
                if ( ( ( s >> i ) & 1 ) == 1 ) { // Checking if the i-th bit of the current combination is set
                    t ^= a.get ( i ) ; // Updating the XOR of the current combination
                }
            }

            // Checking if the XOR of the current combination and the ArrayList elements is equal to the given integers
            if ( p == t ) {
                ans ++ ; // Incrementing the count of valid answers
            }
        }

        System.out.println ( ans ) ; // Printing the count of valid answers
        sc.close ( ) ; // Closing the Scanner object
    }
}

