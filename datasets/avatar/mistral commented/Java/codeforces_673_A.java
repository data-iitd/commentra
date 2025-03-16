
import java.util.* ; // Importing the utility class Scanner from the java.util package

public class Main { // Defining the main class named Main

    public static void main ( String [ ] args ) { // Defining the main method that is executed when the program runs
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object named sc to read input from the standard input stream
        int n = sc.nextInt ( ) ; // Reading the number of elements in the ArrayList from the standard input stream

        ArrayList < Integer > a = new ArrayList < Integer > ( ) ; // Creating an empty ArrayList named a of type Integer

        for ( int i = 0 ; i < n ; i ++ ) { // Using a for loop to read and add each element to the ArrayList
            value = sc.nextInt ( ) ; // Reading an integer value from the standard input stream
            a.add ( value ) ; // Adding the value to the ArrayList
        }

        int result , pos = 0 , flag = 0 ; // Declaring and initializing the variables result, pos, and flag

        if ( a.get ( 0 ) > 15 ) { // Checking if the first element in the ArrayList is greater than 15
            result = 15 ; // Assigning 15 to the result variable if the condition is true
        } else {
            for ( int i = 1 ; i < n ; i ++ ) { // Using a for loop to compare each element with the previous one
                if ( a.get ( i ) - a.get ( i - 1 ) > 15 ) { // Checking if the difference between two consecutive elements is greater than 15
                    pos = i - 1 ; // Assigning the index of the previous element to the pos variable if the condition is true
                    flag = 1 ; // Assigning 1 to the flag variable to indicate that the condition is true
                    break ; // Exiting the loop if the condition is true
                }
            }
            if ( flag == 1 ) { // Checking if the flag variable is equal to 1, indicating that the condition in the inner for loop was true
                result = a.get ( pos ) + 15 ; // Assigning the sum of the previous element and 15 to the result variable
            } else {
                result = a.get ( n - 1 ) + 15 ; // Assigning the sum of the last element and 15 to the result variable if the flag variable is 0
            }
        }

        if ( result > 90 ) result = 90 ; // Checking if the result is greater than 90 and assigning 90 to the result variable if it is

        System.out.println ( result ) ; // Printing the result to the standard output stream