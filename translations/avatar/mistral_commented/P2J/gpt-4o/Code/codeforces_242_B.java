import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of test cases
        int n = scanner.nextInt();

        // Initialize id variable to 0
        int id = 0;

        // Read left and right boundary values for the first test case
        int l = scanner.nextInt();
        int r = scanner.nextInt();

        // Iterate through the remaining test cases
        for (int i = 1; i < n; i++) {
            // Read left and right boundary values for the current test case
            int li = scanner.nextInt();
            int ri = scanner.nextInt();

            // Check if the current test case overlaps with the previously defined boundary values
            if (li <= l && r <= ri) {
                // Update id variable to the index of the current test case
                id = i;
            } 
            // If the current test case does not overlap, keep id as n
            else if (li < l || r < ri) {
                id = n;
            }

            // Update boundary values based on the current test case
            l = Math.min(l, li);
            r = Math.max(r, ri);
        }

        // Print the index of the test case that satisfies the condition, or -1 if no such test case exists
        System.out.println(id == n ? -1 : id + 1);
        
        scanner.close();
    }
}

// <END-OF-CODE>
