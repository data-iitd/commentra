
import java.util.Scanner;

public class s860368733{
    public static void main(String[] args) {
        // Declare variables for the number of elements (n) and the number of comparisons (m)
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Create a 1-based array to hold the heights of n elements
        int[] h = new int[n + 1];

        // Read the heights of the n elements from standard input
        for (int i = 1; i <= n; i++) {
            h[i] = scanner.nextInt();
        }

        // Declare variables for the two elements to compare (a and b)
        int a, b;

        // Create a map to keep track of unique elements that are involved in comparisons
        boolean[] counter = new boolean[n + 1];

        // Loop through m comparisons
        for (int i = 0; i < m; i++) {
            // Read the indices of the two elements to compare
            a = scanner.nextInt();
            b = scanner.nextInt();

            // Compare the heights of the two elements
            if (h[a] < h[b]) {
                // If height of a is less than height of b, add a to the counter
                counter[a] = true;
            } else if (h[a] > h[b]) {
                // If height of a is greater than height of b, add b to the counter
                counter[b] = true;
            } else if (h[a] == h[b]) {
                // If heights are equal, add both a and b to the counter
                counter[a] = true;
                counter[b] = true;
            }
        }

        // Print the number of elements that were not involved in any comparisons
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!counter[i]) {
                count++;
            }
        }
        System.out.println(count);
    }
}
