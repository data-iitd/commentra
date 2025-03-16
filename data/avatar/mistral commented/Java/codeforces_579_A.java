
import java.util.* ; // Importing the necessary classes for using Scanner and ArrayList from the Java standard library.

public class Main { // Defining the main method, which is the entry point of the program.

    public static void main ( String [ ] args ) { // Starting the main method.
        Scanner str = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream.
        int n = str.nextInt ( ) ; // Reading the first integer input n from the user using the nextInt() method of the Scanner class.

        String s = "" ; // Initializing an empty string variable s to store the binary representation of the number n.

        while ( n > 0 ) { // Starting a while loop that continues as long as n is greater than zero.
            int x = n % 2 ; // Calculating the last bit of the binary representation of n by finding the remainder of n divided by 2.
            n /= 2 ; // Updating the value of n by dividing it by 2 to get the next bit of the binary representation.
            s += x + "" ; // Appending the calculated bit to the string s.
        }

        int ans = 0 ; // Initializing an integer variable ans to 0 to store the number of 1's in the binary representation of n.

        for ( int i = 0 ; i < s.length ( ) ; i ++ ) { // Starting a for loop that iterates through each character in the string s.
            if ( s.charAt ( i ) == '1' ) { // Checking if the current character is '1'.
                ans ++ ; // If the character is '1', incrementing the value of ans by 1.
            }
        }

        System.out.println ( ans ) ; // Printing the value of ans to the standard output stream using the println() method of the PrintStream class.

        str.close() ; // Closing the Scanner object to release the system resources.
    }
}