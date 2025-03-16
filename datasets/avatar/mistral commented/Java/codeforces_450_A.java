
import java.util.* ; // Importing the utility class Scanner from the java.util package

public class Main { // Defining the Main class

    public static void main ( String [ ] args ) { // Starting the main method
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input
        int n = sc.nextInt ( ) ; // Reading the first integer n from the standard input
        int m = sc.nextInt ( ) ; // Reading the second integer m from the standard input

        Queue < Integer > q1 = new LinkedList < > ( ) ; // Creating an empty queue q1 of type Integer using LinkedList implementation
        Queue < Integer > q2 = new LinkedList < > ( ) ; // Creating an empty queue q2 of type Integer using LinkedList implementation

        for ( int i = 1 ; i <= n ; i ++ ) { // Iterating through the input values from 1 to n
            q1.add ( sc.nextInt ( ) ) ; // Adding the next integer value to the queue q1
            q2.add ( i ) ; // Adding the current index value to the queue q2
        }

        int ans = 0 ; // Initializing the answer variable to 0
        while ( ! q1.isEmpty ( ) ) { // Starting the while loop to process the queues until both are empty
            if ( q1.peek ( ) <= m ) { // Checking if the next value in q1 is less than or equal to m
                q1.poll ( ) ; // Removing the next value from q1
                ans = q2.poll ( ) ; // Removing the corresponding index value from q2 and assigning it to the answer variable
            } else if ( q1.peek ( ) > m ) { // Checking if the next value in q1 is greater than m
                int x = q1.poll ( ) ; // Removing the next value from q1
                int val = x - m ; // Calculating the new value by subtracting m from the next value
                q1.add ( val ) ; // Adding the new value back to the queue q1
                int val2 = q2.poll ( ) ; // Removing the corresponding index value from q2
                q2.add ( val2 ) ; // Adding the index value back to the queue q2
            }
        }

        System.out.println ( ans ) ; // Printing the final answer
    }
}

These comments should provide a clear understanding of the code logic for each block.