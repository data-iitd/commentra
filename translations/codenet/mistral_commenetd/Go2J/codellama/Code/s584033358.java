// Import the "java.util.Scanner" class for reading input from the standard input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables "n" and "k"
        int n, k;

        // Create a new Scanner object for reading input from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read the values of "n" and "k" from the standard input
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Check if the value of "k" is less than or equal to the middle index of the array "n"
        if (k <= (n+n%2)/2) {
            // If the condition is true, print "YES" to the standard output
            System.out.println("YES");
        } else {
            // If the condition is false, print "NO" to the standard output
            System.out.println("NO");
        }
    }
}

// End of the code 