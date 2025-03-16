import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of cells (n) and the target cell (t) from input
        int n = scanner.nextInt();
        int t = scanner.nextInt();

        // Read the list of jumps for each cell
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        // Initialize the current cell position
        int currentCell = 1; // Start from cell 1 (1-based index)

        // Loop until the current cell exceeds the target cell
        while (currentCell <= t) {
            // Move to the next cell based on the jump value from the current cell
            currentCell += s[currentCell - 1];

            // Check if the current cell is exactly the target cell
            if (currentCell == t) {
                System.out.println("YES"); // Print "YES" if the target cell is reached
                return; // Exit the program
            }
        }

        // If the loop ends without reaching the target cell, print "NO"
        System.out.println("NO");
    }
}
// <END-OF-CODE>
