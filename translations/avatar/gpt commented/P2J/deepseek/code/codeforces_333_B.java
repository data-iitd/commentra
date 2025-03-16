import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the values of n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize an array b of size 2*n with all elements set to 1
        // This array will represent the state of the cells (1 for unblocked, 0 for blocked)
        int[] b = new int[n * 2];
        for (int i = 0; i < b.length; i++) {
            b[i] = 1;
        }

        // Set specific positions in the array b to 0 to indicate they are blocked
        // The first and last elements of the first half and the last half are blocked
        b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;

        // Process each blocked cell based on user input
        for (int i = 0; i < m; i++) {
            // Read the row (r) and column (c) of the blocked cell
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            // Mark the corresponding positions in the array b as blocked (0)
            b[r - 1] = b[n + c - 1] = 0;
        }

        // If n is odd and the middle cells are unblocked, block them
        if (n % 2 == 1 && b[n / 2] == 1 && b[n + n / 2] == 1) {
            b[n / 2] = 0;
        }

        // Output the total number of unblocked cells by summing the array b
        int sum = 0;
        for (int value : b) {
            sum += value;
        }
        System.out.println(sum);
    }
}
