import java.util.Scanner;

public class GridOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the dimensions of the grid (n) and the number of operations (m)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize a 2D array to keep track of counts for each cell in the grid
        int[][] count = new int[n][n];
        
        int ans = -1; // Initialize the answer variable to -1 (indicating no solution found)
        
        // Process each operation
        for (int k = 0; k < m; k++) {
            // Read the coordinates for the current operation and adjust for 0-based indexing
            int x = scanner.nextInt() - 1;
            int y = scanner.nextInt() - 1;
            
            boolean found = false; // Flag to indicate if a cell has reached the count of 9
            
            // Iterate over the 3x3 grid centered at (x, y)
            for (int i = x - 2; i <= x + 2; i++) {
                for (int j = y - 2; j <= y + 2; j++) {
                    // Check if the indices are within the bounds of the grid
                    if (i >= 0 && i < n && j >= 0 && j < n) {
                        count[i][j] += 1; // Increment the count for the current cell
                        
                        // Check if the count for this cell has reached 9
                        if (count[i][j] == 9) {
                            found = true; // Mark that we found a cell with count 9
                        }
                    }
                }
            }
            
            // If a cell with count 9 was found, update the answer and break the loop
            if (found) {
                ans = k + 1; // Store the 1-based index of the operation
                break;
            }
        }
        
        // Print the result: the operation number where a cell reached count 9, or -1 if none did
        System.out.println(ans);
        
        scanner.close();
    }
}
