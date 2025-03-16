import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare variables
        int n, i, j, q;
        int[] x = new int[10000];
        int[] y = new int[500];
        int sum = 0;

        // Read the number of elements in the array x
        n = scanner.nextInt();

        // Allocate memory for array x
        for (i = 0; i < n; i++) {
            // Read each element of array x
            x[i] = scanner.nextInt();
        }

        // Read the number of queries
        q = scanner.nextInt();

        // Allocate memory for array y
        for (i = 0; i < q; i++) {
            // Read each element of array y
            y[i] = scanner.nextInt();
        }

        // Initialize sum to zero
        sum = 0;

        // Check if each element of array y is present in array x and increment sum if found
        for (i = 0; i < q; i++) {
            for (j = 0; j < n; j++) {
                // Check if current element of y is equal to current element of x
                if (y[i] == x[j]) {
                    // Increment sum if found
                    sum = sum + 1;
                    // Break out of inner loop as soon as a match is found
                    break;
                }
            }
        }

        // Print the value of sum
        System.out.println(sum);

        // Return 0 to indicate successful execution
