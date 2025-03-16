import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read three integer inputs from the user
        int A1 = sc.nextInt(); // First input
        int A2 = sc.nextInt(); // Second input
        int A3 = sc.nextInt(); // Third input
        
        // Check if the sum of the three inputs is greater than or equal to 22
        if ((A1 + A2 + A3) >= 22) {
            // If the sum is 22 or more, print "bust"
            System.out.println("bust");
        } else {
            // If the sum is less than 22, print "win"
            System.out.println("win");
        }
    
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
