import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int r, D, x; // Declare integer variables for radius, D, and x
        r = scanner.nextInt(); // Read radius from standard input
        D = scanner.nextInt(); // Read D from standard input
        x = scanner.nextInt(); // Read x from standard input

        for (int i = 1; i <= 10; i++) { // Loop 10 times
            System.out.println(r * x - D); // Print the result of the calculation
            x = r * x - D; // Update x for the next iteration
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
