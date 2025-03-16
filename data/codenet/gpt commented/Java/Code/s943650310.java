import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the first integer input (X)
        int X = sc.nextInt();
        
        // Read the second integer input (t)
        int t = sc.nextInt();
        
        // Check if the result of X - t is non-negative
        if(X - t >= 0) {
            // If non-negative, print the result of X - t
            System.out.println(X - t);
        } else {
            // If negative, print 0
            System.out.println(0);
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
