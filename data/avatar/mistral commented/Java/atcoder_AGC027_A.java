
import java.util.* ; // Importing the utility class Scanner from the java.util package

public class Main { // Defining the main class named Main

    public static void main ( String [ ] args ) { // Defining the main method that is executed when the program runs
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input

        int N = sc.nextInt ( ) ; // Reading the number of elements in the list from the standard input
        long x = sc.nextInt ( ) ; // Reading the target value from the standard input

        List < Long > sweet = new ArrayList < Long > ( ) ; // Creating an empty ArrayList of Long type named sweet to store the elements

        for ( int i = 0 ; i < N ; i ++ ) { // A for loop to read and add N elements to the ArrayList
            long a = sc.nextInt ( ) ; // Reading an element from the standard input
            sweet.add ( a ) ; // Adding the element to the ArrayList
        }

        Collections.sort ( sweet ) ; // Sorting the ArrayList in ascending order using the Collections.sort() method

        int num = 0 ; // Initializing a variable named num to keep track of the number of elements that can be subtracted from x

        for ( int i = 0 ; i < N ; i ++ ) { // A for loop to find the number of elements that can be subtracted from x
            if ( x - sweet.get ( num ) >= 0 ) { // Checking if x is greater than or equal to the current element in the ArrayList
                x = x - sweet.get ( num ) ; // Subtracting the current element from x
                num ++ ; // Incrementing the num variable
            } else { // If x is less than the current element in the ArrayList
                break ; // Exiting the for loop
            }
        }

        if ( ( num == N ) && ( x > 0 ) ) { // Checking if all the elements in the ArrayList have been subtracted from x and x is still greater than 0
            num -= 1 ; // Decrementing the num variable by 1 as the last element that was subtracted from x is not included in the count
        }

        System.out.println ( num ) ; // Printing the number of elements that can be subtracted from x
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance.