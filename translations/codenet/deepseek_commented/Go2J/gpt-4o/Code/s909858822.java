import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables A and B
        int A, B;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the standard input and assign them to A and B
        A = scanner.nextInt();
        B = scanner.nextInt();
        
        // Declare a variable to store the result
        int ans = 0;
        
        // Check if A is between 6 and 12 inclusive
        if (6 <= A && A <= 12) {
            // Calculate the half of B and assign it to ans
            ans = B / 2;
        } else if (A > 12) {
            // Assign B to ans if A is greater than 12
            ans = B;
        }
        
        // Print the value of ans
        System.out.println(ans);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
