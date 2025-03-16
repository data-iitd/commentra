import java.util.Scanner;

public class ChessBoard {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and m from input, representing the number of rows and columns
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize an empty 2D array to store the resulting grid
        char[][] l = new char[n][m];
        
        // Read each row and fill the 2D array
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            for (int j = 0; j < m; j++) {
                l[i][j] = s.charAt(j);
            }
        }
        
        // Iterate over each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check if the current cell is empty (represented by '.')
                if (l[i][j] == '.') {
                    // Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
                    if ((i + j) % 2 == 0) {
                        l[i][j] = 'B';  // Assign 'B' for even sums
                    } else {
                        l[i][j] = 'W';  // Assign 'W' for odd sums
                    }
                }
            }
        }
        
        // Print each row of the grid as a string
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(l[i][j]);
            }
            System.out.println();
        }
        
        scanner.close();
    }
}
