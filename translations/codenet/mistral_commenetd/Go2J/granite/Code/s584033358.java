
// Import the "java.util.Scanner" class for reading input from the standard input
import java.util.Scanner;

public class s584033358{
    public static void main(String[] args) {
        // Create a new instance of the "Scanner" class to read input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Declare two integer variables "n" and "k"
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Check if the value of "k" is less than or equal to the middle index of the array "n"
        if (k <= (n + n % 2) / 2) {
            // If the condition is true, print "YES" to the standard output
            System.out.println("YES");
        } else {
            // If the condition is false, print "NO" to the standard output
            System.out.println("NO");
        }

        // Close the "Scanner" object to release system resources
        scanner.close();
    }
}

// End of the code