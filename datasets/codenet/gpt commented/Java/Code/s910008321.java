import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the user: h (height) and a (step size)
        int h = scanner.nextInt();
        int a = scanner.nextInt();
        
        // Check if the height is exactly divisible by the step size
        if (h % a == 0) {
            // If divisible, print the number of steps required (h divided by a)
            System.out.println(h / a);
        } else {
            // If not divisible, print the number of steps required (h divided by a) plus one
            // This accounts for the remaining height that requires an additional step
            System.out.println(h / a + 1);
        }
        
        // Close the scanner to prevent resource leaks (optional but good practice)
        scanner.close();
    }
}
