import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read two integers n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize a variable to hold the sum of the integers read
        int sum = 0;

        // Read m integers from input and calculate their sum
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt(); // Read an integer
            sum += a; // Add the integer to the sum
        }

        // Check if the sum of the integers exceeds n
        if (sum > n) {
            System.out.println("-1"); // Print -1 if the sum is greater than n
        } else {
            // Print the difference between n and the sum of the integers
            System.out.println(n - sum);
        }
    }
}
