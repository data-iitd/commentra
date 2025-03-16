import java.util.* ; // Importing the Java Utility package for Scanner class

public class Main { // Defining the main class named Main

    public static void main ( String args [ ] ) { // Defining the main method that runs the program

        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the console

        int q = sc.nextInt ( ) ; // Reading the number of test cases from the console

        while ( q -- > 0 ) { // Starting a while loop that runs q times

            int n = sc.nextInt ( ) ; // Reading the integer 'n' from the console

            long s = 0 ; // Initializing the long variable 's' with zero value

            int x = ( int ) ( Math.log ( n ) / Math.log ( 2 ) ) ; // Calculating the integer 'x' using the logarithmic formula

            x ++ ; // Incrementing the value of 'x' by 1

            s = - 1 * ( long ) Math.pow ( 2 , x ) + 2 + ( ( long ) n * ( long ) ( n + 1 ) ) / 2 - ( long ) Math.pow ( 2 , x ) ; // Calculating the value of 's' using the given formula

            System.out.println ( s ) ; // Printing the value of 's' to the console
        }
    }
}
