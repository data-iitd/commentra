import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and m from input, representing the number of rows and columns
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Initialize a 2D character array to store the resulting grid
        char[][] grid = new char[n][m];
        
        // Iterate over each row index i from 0 to n-1
        for (int i = 0; i < n; i++) {
            // Read a string input for the current row
            String s = scanner.nextLine();
            
            // Iterate over each column index j from 0 to m-1
            for (int j = 0; j < m; j++) {
                // Check if the current cell is empty (represented by '.')
                if (s.charAt(j) == '.') {
                    // Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
                    if ((i + j) % 2 == 1) {
                        grid[i][j] = 'W';  // Assign 'W' for odd sums
                    } else {
                        grid[i][j] = 'B';  // Assign 'B' for even sums
                    }
                } else {
                    // If the cell is not empty, keep the original character
                    grid[i][j] = s.charAt(j);
                }
            }
        }
        
        // Print each row of the grid as a string
        for (int i = 0; i < n; i++) {
            System.out.println(grid[i]);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
