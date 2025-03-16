import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of rows (n) from user input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Read n rows of integers into a 2D list (matrix) m
        int[][] m = new int[n][];
        for (int i = 0; i < n; i++) {
            String[] line = scanner.nextLine().split(" ");
            m[i] = new int[line.length];
            for (int j = 0; j < line.length; j++) {
                m[i][j] = Integer.parseInt(line[j]);
            }
        }

        // Sort the matrix m in descending order based on the first element of each row
        Arrays.sort(m, (a, b) -> Integer.compare(b[0], a[0]));

        // Initialize a variable a with the first row of the sorted matrix
        int[] a = m[0];

        // Iterate through the remaining rows of the sorted matrix
        for (int i = 1; i < m.length; i++) {
            // Check if the second element of the current row is greater than the second element of the previous row
            if (m[i][1] > a[1]) {
                // If true, print 'Happy Alex' and exit the loop
                System.out.println("Happy Alex");
                return;
            }
            // Update a to the current row for the next iteration
            a = m[i];
        }

        // If the loop completes without finding a greater second element, print 'Poor Alex'
        System.out.println("Poor Alex");
    }
}
// <END-OF-CODE>
