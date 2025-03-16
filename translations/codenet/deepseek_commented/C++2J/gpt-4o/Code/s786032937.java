import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 3: Read an integer input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Step 4: Perform a calculation
        // The formula (n - 2) * 180 calculates the sum of internal angles of an n-sided polygon
        System.out.println((n - 2) * 180);

        // Step 5: Output the result
        // The result is printed to the console

        // Step 6: Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
