
import java.util.* ; // Importing the utility class Scanner from the Java standard library

public class Main { // Defining the main class

    public static void main ( String [ ] $ ) { // Starting point of the program, main method with an empty String array as argument
        Scanner s = new Scanner ( System.in ) ; // Creating an instance of the Scanner class to read input from the standard input stream
        int n = s.nextInt ( ) ; // Reading the first integer from the standard input stream and assigning it to the variable n
        int [ ] a = new int [ n ] ; // Creating an integer array of size n
        Arrays.setAll ( a , i -> s.nextInt ( ) ) ; // Setting all elements of the array a to the integers read from the standard input stream
        ArrayList < String > r = new ArrayList < > ( ) ; // Creating an empty ArrayList of Strings to store the output
        int m = 0 ; // Initializing the variable m to 0

        for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the second element to the last one
            if ( Math.abs ( a [ m ] ) < Math.abs ( a [ i ] ) ) { // Comparing the absolute values of the first and current elements to find the index of the smallest absolute value
                m = i ; // Assigning the index of the smallest absolute value to the variable m
            }
        }

        for ( int i = 0 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the first element to the last one
            if ( a [ m ] >= 0 ^ a [ i ] >= 0 ) { // Checking if the signs of the elements at indices m and i are different
                r.add ( m + 1 + " " + ( i + 1 ) ) ; // Adding the pair (m+1, i+1) to the ArrayList r if the condition is true
            }
        }

        if ( a [ m ] >= 0 ) { // Checking if the smallest absolute value is positive
            for ( int i = 1 ; i < n ; ++ i ) { // Starting a for loop to iterate through the array a from the second element to the last one
                r.add ( i + " " + ( i + 1 ) ) ; // Adding the pair (i, i+1) to the ArrayList r if the smallest absolute value is positive
            }
        } else { // If the smallest absolute value is negative
            for ( int i = n ; i > 1 ; -- i ) { // Starting a for loop to iterate through the array a from the last element to the second one
                r.add ( i + " " + ( i - 1 ) ) ; // Adding the pair (i, i-1) to the ArrayList r if the smallest absolute value is negative
            }
        }

        System.out.println ( r.size ( ) ) ; // Printing the size of the ArrayList r to the standard output stream
        r.forEach ( System.out :: println ) ; // Printing each pair in the ArrayList r to the standard output stream using a lambda expression.