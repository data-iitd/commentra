import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Ask the user to input an integer value
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize a variable i and set its value to n
        for (int i = n; i > 0; i--) {
            // Check if n is divisible by the current value of i
            if (n % i == 0) {
                // If the condition is true, update the value of n to i
                n = i;
                // Print the current value of i
                System.out.print(i + " ");
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
