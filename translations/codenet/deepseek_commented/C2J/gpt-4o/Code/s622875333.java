import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, r, p, c;
        int[] a = new int[100];
        int[] b = new int[100];

        while (true) {
            // Read the values of n and r
            n = scanner.nextInt();
            r = scanner.nextInt();
            // Break the loop if both n and r are zero
            if (n == 0 && r == 0) break;

            // Initialize array a with values from n down to 1
            for (int i = 0; i < n; i++) {
                a[i] = n - i;
            }

            // For each round of r
            for (int i = 0; i < r; i++) {
                // Copy array a to array b
                for (int j = 0; j < n; j++) {
                    b[j] = a[j];
                }
                // Read the values of p and c
                p = scanner.nextInt();
                c = scanner.nextInt();

                // Perform the shift operation on array a
                for (int j = 0; j < c; j++) {
                    a[j] = b[p - 1 + j];
                }

                // Fill the remaining positions in array a
                for (int j = c; j < c + p - 1; j++) {
                    a[j] = b[j - c];
                }
            }
            // Print the first element of array a
            System.out.println(a[0]);
        }
        scanner.close();
    }
}
// <END-OF-CODE>
