import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable 'n' and read its value from the standard input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Output the result, which is calculated as (n - 2) * 180
        System.out.println((n - 2) * 180);

        // Close the scanner
        scanner.close();
    }
}

// Indicate successful termination of the program by returning 0
// <END-OF-CODE>
