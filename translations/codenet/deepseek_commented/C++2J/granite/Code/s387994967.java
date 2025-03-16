
import java.util.Scanner;

public class s387994967{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Declare two integer variables A and B to store user input
        int A, B;
        
        // Read two integers from the standard input (scanner) and store them in A and B
        A = scanner.nextInt();
        B = scanner.nextInt();
        
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
        
        // Close the Scanner object to release system resources
        scanner.close();
    }
}
