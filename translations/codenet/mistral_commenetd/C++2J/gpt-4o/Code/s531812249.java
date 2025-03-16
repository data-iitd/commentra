import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int n = scanner.nextInt(); // Read input value of n
        int m = scanner.nextInt(); // Read input value of m

        int ans = 0; // Initialize answer variable ans to 0

        // Calculate the sum of pairs for n
        ans += n * (n - 1) / 2; // Calculate the sum of numbers from 1 to n-1 and add it to the answer

        // Calculate the sum of pairs for m
        ans += m * (m - 1) / 2; // Calculate the sum of numbers from 1 to m-1 and add it to the answer

        System.out.println(ans); // Print the answer to the standard output

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
