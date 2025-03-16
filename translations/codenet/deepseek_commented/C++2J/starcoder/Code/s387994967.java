
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Declare two integer variables A and B to store user input
        int A, B;
        
        // Read two integers from the standard input (cin) and store them in A and B
        Scanner sc = new Scanner(System.in);
        A = sc.nextInt();
        B = sc.nextInt();
        
        // Check if A is between 6 and 12 (inclusive)
        if(A<13 && A>=6){
            // If true, calculate B/2 and print the result
            System.out.println(B/2);
        }
        
        // Check if A is less than 6
        if(A<6){
            // If true, print 0
            System.out.println(0);
        }
        
        // Check if A is 13 or more
        if(A>=13){
            // If true, print the value of B
            System.out.println(B);        
        }
    }
}
