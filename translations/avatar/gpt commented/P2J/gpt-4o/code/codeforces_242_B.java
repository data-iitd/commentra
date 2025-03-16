import java.util.Scanner;

public class IntervalChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of intervals
        int n = scanner.nextInt();
        int id = 0;

        // Read the first interval's bounds
        int l = scanner.nextInt();
        int r = scanner.nextInt();

        // Iterate through the remaining intervals
        for (int i = 1; i < n; i++) {
            // Read the current interval's bounds
            int li = scanner.nextInt();
            int ri = scanner.nextInt();

            // Check if the current interval completely contains the previous one
            if (li <= l && r <= ri) {
                id = i;  // Update the index to the current interval
            }
            // Check if the current interval overlaps with the previous one
            else if (li < l || r < ri) {
                id = n;  // Mark as overlapping by setting id to n
            }

            // Update the bounds of the union of intervals
            l = Math.min(l, li);  // Update the left bound
            r = Math.max(r, ri);  // Update the right bound
        }

        // Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
        System.out.println(id == n ? -1 : id + 1);
        
        scanner.close();
    }
}

// <END-OF-CODE>
