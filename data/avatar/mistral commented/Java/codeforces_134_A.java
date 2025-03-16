import java.util.* ; // Importing the utility class Scanner from the java.util package

public class Main { // Defining the Main class

    public static void main ( String [ ] args ) { // Starting the main method
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input
        int n = sc.nextInt ( ) ; // Reading the number of elements in the array from the standard input
        int [ ] arr = new int [ n ] ; // Creating an integer array of size n
        int sum = 0 ; // Initializing the sum variable to 0

        for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop to read and store the elements in the array
            arr [ i ] = sc.nextInt ( ) ; // Reading an integer value from the standard input and storing it in the current index of the array
            sum += arr [ i ] ; // Adding the current element to the sum variable
        }

        int c = 0 ; // Initializing the counter variable to 0
        StringBuilder sb = new StringBuilder ( ) ; // Creating an empty StringBuilder object to store the indices of the elements that satisfy the condition

        for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop to check if an element satisfies the condition
            if ( ( sum - arr [ i ] ) % ( n - 1 ) == 0 && ( sum - arr [ i ] ) / ( n - 1 ) == arr [ i ] ) { // Checking if the current element satisfies the condition
                c ++ ; // Incrementing the counter variable if the condition is true
                sb.append ( ( i + 1 ) + " " ) ; // Appending the index of the current element to the StringBuilder object
            }
        }

        System.out.println ( c ) ; // Printing the number of elements that satisfy the condition
        System.out.println ( sb.toString ( ) ) ; // Printing the indices of the elements that satisfy the condition separated by a space
    }
}