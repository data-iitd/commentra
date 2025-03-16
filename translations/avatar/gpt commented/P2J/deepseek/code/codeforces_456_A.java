import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of rows (n) from user input
        int n = scanner.nextInt();
        
        // Read n rows of integers into a 2D list (matrix) m
        List<int[]> m = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int[] row = new int[2];
            row[0] = scanner.nextInt();
            row[1] = scanner.nextInt();
            m.add(row);
        }
        
        // Sort the matrix m in descending order based on the first element of each row
        Collections.sort(m, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]) * -1; // Multiply by -1 for descending order
            }
        });
        
        // Initialize a variable a with the first row of the sorted matrix
        int[] a = m.get(0);
        
        // Iterate through the remaining rows of the sorted matrix
        for (int i = 1; i < m.size(); i++) {
            int[] currentRow = m.get(i);
            // Check if the second element of the current row is greater than the second element of the previous row
            if (currentRow[1] > a[1]) {
                // If true, print 'Happy Alex' and exit the loop
                System.out.println("Happy Alex");
                return;
            }
            // Update a to the current row for the next iteration
            a = currentRow;
        }
        
        // If the loop completes without finding a greater second element, print 'Poor Alex'
        System.out.println("Poor Alex");
    }
}
