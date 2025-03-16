import java.util.* ; // Importing the utility class Scanner from java.util package

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String arg [ ] ) {
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream
        int n = sc.nextInt ( ) ; // Reading the number of test cases from the standard input stream

        // Allocating an array of size 'n' to store characters
        char ch [ ] = new char [ n ] ;
        int s1 = 0 , s2 = 0 ; // Initializing two variables to keep track of the sum of x and y coordinates respectively
        int i , j = 0 , flag = 0 , dif = 0 ; // Declaring and initializing variables

        // Reading input for each test case
        for ( i=0 ; i<n ; i++ ) {
            int x = sc.nextInt ( ) ; // Reading the value of 'x' for the current test case
            int y = sc.nextInt ( ) ; // Reading the value of 'y' for the current test case

            int temp1 = s1 + x ; // Calculating the sum of 's1' and 'x'
            int temp2 = s2 + y ; // Calculating the sum of 's2' and 'y'

            // Checking if the difference between the sums is within the limit of 500
            if ( Math.abs ( temp1 - temp2 ) <= 500 ) {
                s1 += x ; // Updating the value of 's1'
                ch [ j ++ ] = 'A' ; // Adding 'A' to the character array 'ch'
                continue ; // Skipping the rest of the loop and moving to the next iteration
            }

            // Checking if the difference between the absolute values of the sums is within the limit of 500
            if ( Math.abs ( temp1 - s2 ) <= 500 ) {
                s2 += y ; // Updating the value of 's2'
                ch [ j ++ ] = 'G' ; // Adding 'G' to the character array 'ch'
                continue ; // Skipping the rest of the loop and moving to the next iteration
            }

            flag = 1 ; // Setting the flag to 1 if the difference between the sums is greater than 500
            break ; // Exiting the loop if the difference is greater than 500
        }

        // Checking if the flag is set to 1, indicating that the difference between the sums is greater than 500 for the current test case
        if ( flag == 1 )
            System.out.println ( - 1 ) ; // Printing -1 if the difference is greater than 500
        else {
            String ans = "" ; // Initializing an empty string to store the answer
            ans = ans.valueOf ( ch ) ; // Converting the character array 'ch' to a string 'ans'
            System.out.println ( ans ) ; // Printing the string 'ans' as the answer for the current test case
        }
    }
}
