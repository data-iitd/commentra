import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the dimensions of the grid and the number of operations
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize a count grid with all elements set to 0
        int[][] count = new int[n][n];
        
        // Initialize the answer to -1
        int ans = -1;
        
        // Loop through each operation
        for (int k = 0; k < m; k++) {
            // Read the coordinates of the operation
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            
            // Adjust the coordinates to zero-based index
            x -= 1;
            y -= 1;
            
            // Flag to check if a cell in the 3x3 grid reaches a count of 9
            boolean found = false;
            
            // Check the 3x3 grid centered at (x, y)
            for (int i = x - 2; i <= x + 1; i++) {
                for (int j = y - 2; j <= y + 1; j++) {
                    if (i >= 0 && i < n && j >= 0 && j < n) {
                        count[i][j] += 1;
                        if (count[i][j] == 9) {
                            found = true;
                        }
                    }
                }
            }
            
            // If a cell in the 3x3 grid reaches a count of 9, update ans and break
            if (found) {
                ans = k + 1;
                break;
            }
        }
        
        // Print the result
        System.out.println(ans);
    }
}

