// Include the standard input/output library
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        long n; // Declare a long integer variable to store the input number
        boolean flg = false; // Declare a boolean variable (flag) and initialize it to false

        // Read the input number
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();

        // Check if n is less than 4
        if( n<4 ) {
            System.out.println("No"); // Print "No" and exit the program
            return;
        }

        // Check if n can be represented as a sum of two integers, each a multiple of 4 and 7
        for( int i=0; i<=(n/4); i++ ) { // Outer loop: i from 0 to n/4
            for( int j=0; j<=(n/7); j++ ) { // Inner loop: j from 0 to n/7
                if( (i*4+j*7)==n ) { // Check if the sum of i*4 and j*7 equals n
                    flg = true; // Set the flag to true if found
                    break; // Exit both loops
                }
            }
            if(flg) break; // Exit the outer loop if flag is true
        }

        // Print the result
        if(flg) {
            System.out.println("Yes"); // Print "Yes" if n can be represented as a sum of two integers, each a multiple of 4 and 7
        } else {
            System.out.println("No"); // Print "No" otherwise
        }

        return; // Exit the program
    }
}

