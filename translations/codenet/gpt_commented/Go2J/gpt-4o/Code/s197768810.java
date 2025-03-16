import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a scanner to read input from standard input
        Scanner sc = new Scanner(System.in);

        // Read two integers n and m from input
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Initialize an array to hold m integers
        int[] a = new int[m];

        // Initialize a variable to hold the sum of the integers read
        int sum = 0;

        // Read m integers from input and calculate their sum
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt(); // Read an integer and store it in the array
            sum += a[i]; // Add the integer to the sum
        }

        // Check if the sum of the integers exceeds n
        if (sum > n) {
            System.out.println("-1"); // Print -1 if the sum is greater than n
            return; // Exit the function
        }

        // Print the difference between n and the sum of the integers
        System.out.println(n - sum);
        
        // Close the scanner
        sc.close();
    }
}
// <END-OF-CODE>
