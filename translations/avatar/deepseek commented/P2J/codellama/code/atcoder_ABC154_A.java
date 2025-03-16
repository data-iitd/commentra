
import java.util.Scanner;
public class Main {
    public static void solve ( String S , String T , int A , int B , String U ) {
        // Check if the string S is equal to the string U
        if ( S.equals ( U ) ) {
            // Decrement the count of A by 1
            A -= 1;
        }
        // Check if the string T is equal to the string U
        if ( T.equals ( U ) ) {
            // Decrement the count of B by 1
            B -= 1;
        }
        // Print the updated counts of A and B
        System.out.println ( A + " " + B );
    }
    public static void main ( String[] args ) {
        Scanner sc = new Scanner ( System.in );
        // Read the string S
        String S = sc.next ( );
        // Read the string T
        String T = sc.next ( );
        // Read the integer A
        int A = sc.nextInt ( );
        // Read the integer B
        int B = sc.nextInt ( );
        // Read the string U
        String U = sc.next ( );
        // Call the solve function with the read inputs
        solve ( S , T , A , B , U );
    }
}
