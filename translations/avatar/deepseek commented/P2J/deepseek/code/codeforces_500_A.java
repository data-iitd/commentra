import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of cells (n) and the target cell (t)
        int n = scanner.nextInt();
        int t = scanner.nextInt();

        // Read the list of cells that can be jumped from each cell
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        // Initialize the current cell to 0
        int currentCell = 0;

        // Loop until the current cell exceeds the target cell
        while (currentCell <= t) {
            // Update the current cell by adding the value of the cell it's currently on
            currentCell += s[currentCell - 1];

            // Check if the current cell is the target cell
            if (currentCell == t) {
                // If yes, print "YES" and exit the program
                System.out.println("YES");
                return;
            }
        }

        // If the loop finishes without finding the target cell, print "NO"
        System.out.println("NO");
    }
}

