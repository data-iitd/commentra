import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables A and B to hold input values
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        
        // Declare a variable to hold the result
        int ans = 0;
        
        // Check if A is between 6 and 12 (inclusive)
        if (6 <= A && A <= 12) {
            // If A is in the range, set ans to half of B
            ans = B / 2;
        } else if (A > 12) {
            // If A is greater than 12, set ans to the value of B
            ans = B;
        }
        
        // Print the result
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
