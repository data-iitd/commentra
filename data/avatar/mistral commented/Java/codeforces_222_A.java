import java.util.* ; // Importing the Java Util library for Scanner class

public class Main { // Defining the main class
    public static void main ( String [ ] args ) { // Defining the main method
        Scanner in = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input

        int n = in.nextInt ( ) ; // Reading the first integer from the input
        int k = in.nextInt ( ) ; // Reading the second integer from the input
        int l = 0 , c = 1 ; // Initializing the variables l and c with values 0 and 1 respectively

        for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop that iterates n times
            int a = in.nextInt ( ) ; // Reading the next integer from the input and assigning it to variable a

            if ( a == l ) c += 1 ; // If the current integer is equal to the previous one, increment the counter c by 1
            else c = 1 ; // Otherwise, reset the counter c to 1

            l = a ; // Assigning the current integer to the previous integer variable l
        }

        if ( c + k > n ) { // Checking if the sum of counter c and integer k is greater than the total number of integers n
            System.out.println ( n - c ) ; // If true, print the difference between n and c
        } else {
            System.out.println ( - 1 ) ; // If false, print -1
        }
    }
}
