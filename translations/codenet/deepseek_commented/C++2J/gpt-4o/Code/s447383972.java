import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 7: Main function
        int n = scanner.nextInt(); // Read the size of the array.
        long[] a = new long[n];
        long[] q = new long[n];
        int tot = 0;

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong(); // Read the elements of the array.
        }

        Arrays.sort(a); // Sort the array.

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && a[i] == a[i + 1]) {
                q[tot++] = a[i]; // Remove duplicates from the array.
                i++; // Skip the next element since it's a duplicate.
            }
        }

        // Print the product of the two largest distinct elements.
        System.out.println(q[tot - 1] * q[tot - 2]);
        
        scanner.close();
    }
}
// <END-OF-CODE>
