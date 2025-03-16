import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read an integer input from the user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Iterate from n down to 1
        for (int i = n; i > 0; i--) {
            // Check if i is a divisor of n
            if (n % i == 0) {
                // Update n to the current divisor i
                n = i;
                // Print the divisor followed by a space
                System.out.print(i + " ");
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
