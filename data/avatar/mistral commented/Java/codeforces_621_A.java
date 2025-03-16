
import java.util.* ; // Importing the utility class Scanner from java.util package

public class Main { // Defining the main class named Main

    public static void main ( String [ ] args ) { // Defining the main method that is executed when the program runs
        Scanner sc = new Scanner ( System.in ) ; // Creating an instance of Scanner class to read input from the standard input
        int n = sc.nextInt ( ) ; // Reading the number of elements in the list from the standard input

        List < Long > list = new ArrayList < > ( ) ; // Creating an empty ArrayList of Long type with the default capacity to store n elements

        for ( int i = 0 ; i < n ; i ++ ) // Iterating through the input to add each element to the ArrayList
            list.add ( sc.nextLong ( ) ) ;

        List < Long > odd = new ArrayList < > ( ) ; // Creating an empty ArrayList of Long type to store odd numbers
        long sum = 0 ; // Initializing the sum variable to 0

        for ( long i : list ) { // Iterating through each element in the ArrayList
            if ( i % 2 == 0 ) // Checking if the current element is even
                sum += i ; // Adding the even number to the sum
            else
                odd.add ( i ) ; // Adding the odd number to the odd ArrayList
        }

        Collections.sort ( odd ) ; // Sorting the odd ArrayList in ascending order

        for ( long i : odd ) // Iterating through each odd number in the sorted odd ArrayList
            sum += i ; // Adding the odd number to the sum

        if ( odd.size ( ) % 2 != 0 ) // Checking if the size of the odd ArrayList is odd
            sum -= odd.get ( 0 ) ; // Subtracting the first odd number if the size is odd

        System.out.println ( sum ) ; // Printing the final sum to the standard output
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!