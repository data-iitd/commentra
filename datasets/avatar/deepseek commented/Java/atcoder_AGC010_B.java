
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner scanner = new Scanner ( System.in ) ; // Create a Scanner object to read input from the user
        int N = scanner.nextInt ( ) ; // Read the number of elements N from the user
        int [ ] A = new int [ N ] ; // Create an array A to store the elements
        for ( int i = 0 ; i < N ; i ++ ) A [ i ] = scanner.nextInt ( ) ; // Read N integers from the user and store them in the array A
        if ( possible ( N , A ) ) { // Call the possible method to check if the array A can be rearranged to satisfy a certain condition
            System.out.println ( "YES" ) ; // Print "YES" if the condition is satisfied
        } else { 
            System.out.println ( "NO" ) ; // Print "NO" if the condition is not satisfied
        } 
    } 

    private static boolean possible ( int N , int [ ] A ) { 
        long sum = 0 ; // Initialize sum to store the sum of the elements in the array A
        for ( int i = 0 ; i < N ; i ++ ) sum += A [ i ] ; // Calculate the sum of the elements in the array A
        long NS = ( long ) N * ( N + 1 ) / 2 ; // Calculate the sum of the first N natural numbers (NS)
        if ( sum % NS != 0 ) return false ; // Check if the sum of the array A is divisible by NS. If not, return false
        long K = sum / NS ; // Calculate the value of K, which is the average of the differences between consecutive elements in the array A
        for ( int i = 0 ; i < N ; i ++ ) { 
            int j = i == 0 ? N - 1 : i - 1 ; // Calculate the index of the previous element in the array A
            long d = K - ( A [ i ] - A [ j ] ) ; // Calculate the difference between the current element and the previous element
            if ( d < 0 || d % N != 0 ) return false ; // Check if the difference is negative or not divisible by N. If so, return false
        } 
        return true ; // If all elements satisfy the condition, return true
    } 
}

