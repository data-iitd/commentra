import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n, k; // Declare two integer variables n and k
        long l = 0, r = 0; // Initialize l and r to zero

        n = scanner.nextInt(); // Read integer n from input
        k = scanner.nextInt(); // Read integer k from input

        if (k % 2 == 0) { // Check if k is even
            for (int i = 1; i <= n; i++) { // Iterate through the numbers from 1 to n
                if (i % k == k / 2) { // Check if the remainder of i divided by k is equal to k/2
                    l++; // If it is, increment the variable l by 1
                } else if (i % k == 0) { // Else if the remainder of i divided by k is equal to 0
                    r++; // Increment the variable r by 1
                }
            }
            System.out.println(l * l * l + r * r * r); // Calculate and print the result
        } else { // Else if k is odd
            for (int i = 1; i <= n; i++) { // Iterate through the numbers from 1 to n
                if (i % k == 0) { // Check if the remainder of i divided by k is equal to 0
                    r++; // If it is, increment the variable r by 1
                }
            }
            System.out.println(r * r * r); // Calculate and print the result
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
