import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        Scanner scanner = new Scanner(System.in);
        int n;
        int[] a = new int[100];
        int[] b = new int[100];
        long sum = 0; // Use long for large integers

        // Read the number of elements
        n = scanner.nextInt();

        // Input the first array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Input the second array 'b' and calculate the sum of positive differences
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt(); // Read each element of array 'b'
            
            // Check if the difference between corresponding elements of 'a' and 'b' is positive
            if (a[i] - b[i] > 0) {
                // If positive, add the difference to 'sum'
                sum += a[i] - b[i];
            }
        }

        // Output the final sum of positive differences
        System.out.println(sum);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
