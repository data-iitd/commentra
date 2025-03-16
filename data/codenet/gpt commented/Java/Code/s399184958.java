import java.util.*;

class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the user
        int A = sc.nextInt(); // Read the first integer
        int B = sc.nextInt(); // Read the second integer
        int C = sc.nextInt(); // Read the third integer
        
        // Check if all three integers are equal
        if (A == B && B == C && C == A) {
            // If all integers are equal, print "Yes"
            System.out.println("Yes");
        } else {
            // If any integer is different, print "No"
            System.out.println("No");
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
