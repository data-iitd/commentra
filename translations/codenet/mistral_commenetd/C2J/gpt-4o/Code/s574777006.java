import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, q, sum = 0;
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array x
        n = scanner.nextInt();
        int[] x = new int[n];

        // Read each element of array x
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }

        // Read the number of queries
        q = scanner.nextInt();
        int[] y = new int[q];

        // Read each element of array y
        for (int i = 0; i < q; i++) {
            y[i] = scanner.nextInt();
        }

        // Initialize sum to zero
        sum = 0;

        // Check if each element of array y is present in array x and increment sum if found
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < n; j++) {
                // Check if current element of y is equal to current element of x
                if (y[i] == x[j]) {
                    // Increment sum if found
                    sum++;
                    // Break out of inner loop as soon as a match is found
                    break;
                }
            }
        }

        // Print the value of sum
        System.out.println(sum);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
