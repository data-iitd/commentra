import java.util.* ; // Importing the Java Util library to use Scanner class

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String [ ] args ) {
        Scanner stdIn = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream

        int N = stdIn.nextInt ( ) ; // Reading the first integer value from the standard input stream and assigning it to the variable 'N'

        int count = 0 ; // Initializing the counter variable 'count' to zero
        int temp = N ; // Assigning the value of 'N' to the variable 'temp'

        // The following while loop calculates the number of digits in the given integer 'N'
        while ( temp > 0 ) {
            temp /= 10 ; // Dividing the current value of 'temp' by 10 to get the last digit
            count ++ ; // Incrementing the counter variable 'count' by 1
        }

        for ( int i = 1 ; i <= count ; i ++ ) { // The following for loop iterates through each digit of the given integer 'N'
            if ( i == count ) { // If the current digit is the last digit
                if ( i % 2 == 1 ) { // If the last digit is odd
                    ans += ( N - Math.pow ( 10 , i - 1 ) + 1 ) ; // Adding the sum of digits before the last odd digit to the answer
                }
            } else { // If the current digit is not the last digit
                if ( i == 1 ) { // If the current digit is the first digit
                    ans += 9 ; // Adding the number of digits after the first digit to the answer
                } else if ( i % 2 == 1 ) { // If the current digit is odd
                    ans += ( Math.pow ( 10 , i ) - Math.pow ( 10 , i - 1 ) ) ; // Adding the difference between the 10 raised to the power of the current digit and the 10 raised to the power of the previous digit to the answer
                }
            }
        }

        System.out.println ( ans ) ; // Printing the final answer to the standard output stream
    }
}
