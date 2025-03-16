import java.util.Scanner ; // Importing the Scanner class for user input

public class Main { // Defining the Main class
    public static void main ( String [ ] args ) { // Defining the main method
        Scanner scan = new Scanner ( System.in ) ; // Creating a new Scanner object for user input
        int n = scan.nextInt ( ) ; // Reading the number of test cases from the user

        for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each test case
            int a = scan.nextInt ( ) ; // Reading the first number from the user
            int b = scan.nextInt ( ) ; // Reading the second number from the user
            System.out.println ( sub ( a , b ) ) ; // Printing the result of subtracting 'b' from 'a'
        }
    }

    public static int sub ( int a , int b ) { // Defining the sub method for subtracting two numbers
        int min = Math.min ( a , b ) ; // Finding the smaller number
        int max = Math.max ( a , b ) ; // Finding the larger number
        int result = 0 ; // Initializing the result variable

        while ( min > 0 ) { // Iterating as long as the smaller number is greater than zero
            result += max / min ; // Adding the quotient of the larger number divided by the smaller number to the result
            max = max % min ; // Updating the larger number by taking the remainder of the larger number with the smaller number
            int curr_min = Math.min ( min , max ) ; // Finding the current smaller number
            int curr_max = Math.max ( min , max ) ; // Finding the current larger number
            min = curr_min ; // Updating the smaller number
            max = curr_max ; // Updating the larger number
        }

        return result ; // Returning the final result
    }
}
