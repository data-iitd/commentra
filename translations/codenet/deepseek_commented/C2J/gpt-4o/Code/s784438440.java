import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a, b;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read two integers a and b from the user
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Compute a value based on these inputs
        System.out.println((b - 1 + (a - 2)) / (a - 1));

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
