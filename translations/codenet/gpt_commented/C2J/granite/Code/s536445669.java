
import java.util.Scanner;

public class s536445669{
    public static void main(String[] args) {
        // Declare two integer variables n and k
        int n, k;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read two integers from user input
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Check if n is divisible by k
        if (n % k == 0) {
            // If n is divisible by k, print 0
            System.out.println(0);
        } else {
            // If n is not divisible by k, print 1
            System.out.println(1);
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
