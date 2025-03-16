
import java.util.* ; // Step 1: Import the necessary Java utility classes.
public class Main { // Step 2: Define the Main class.
    public static void main ( String [ ] args ) { // Step 3: Implement the main method.
        Scanner scan = new Scanner ( System.in ) ; // Step 4: Create a Scanner object to read input from the user.
        int n = scan.nextInt ( ) ; // Step 5: Read the size of the array from the user.
        long [ ] arr = new long [ n ] ; // Step 6: Create an array to store the elements of the array.
        for ( int i = 0 ; i < n ; i ++ ) { // Step 7: Read the elements of the array from the user.
            arr [ i ] = scan.nextInt ( ) ; 
        }
        long answer = Math.abs ( arr [ 0 ] ) ; // Step 8: Initialize a variable to store the answer.
        for ( int i = 1 ; i < n ; i ++ ) { // Step 9: Calculate the absolute difference between consecutive elements and add it to the answer.
            answer += Math.abs ( arr [ i ] - arr [ i - 1 ] ) ; 
        }
        System.out.println ( answer ) ; // Step 10: Print the final answer.
    }
}
