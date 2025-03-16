import java.util.*;

public class Kansu {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a, b, n, x, y;
        int[][] suu = new int[17][17];
        int[][] kouji = new int[17][17];
        
        // Read the dimensions of the grid (a x b)
        a = in.nextInt();
        b = in.nextInt();
        
        // Continue processing until both dimensions are zero
        while(a!= 0 && b!= 0) {
            // Read the number of obstacles
            n = in.nextInt();
            
            // Initialize the kouji array to mark all cells as free (0)
            for(int i = 1; i <= a; i++) {
                for(int j = 1; j <= b; j++) {
                    kouji[i][j] = 0;
                }
            }
            
            // Read the positions of obstacles and mark them in the kouji array
            for(int i = 0; i < n; i++) {
                x = in.nextInt();
                y = in.nextInt();
                kouji[x][y] = 1; // Mark the cell as an obstacle (1)
            }
            
            // Calculate the number of paths to each cell in the grid
            for(int i = 1; i <= a; i++) {
                for(int j = 1; j <= b; j++) {
                    // If the cell is an obstacle, set paths to 0
                    if(kouji[i][j] == 1) {
                        suu[i][j] = 0;
                    }
                    else {
                        // If at the starting cell, initialize paths to 1
                        if(i == 1 && j == 1) {
                            suu[i][j] = 1;
                        }
                        else {
                            // If in the first row, inherit paths from the left cell
                            if(i == 1) {
                                suu[i][j] = suu[i][j - 1];
                            }
                            // If in the first column, inherit paths from the above cell
                            else if(j == 1) {
                                suu[i][j] = suu[i - 1][j];
                            }
                            // For other cells, sum paths from the left and above cells
                            else {
                                suu[i][j] = suu[i][j - 1] + suu[i - 1][j];
                            }
                        }
                    }
                }
            }
            
            // Output the total number of paths to the bottom-right cell
            System.out.println(suu[a][b]);
            
            // Read the next set of dimensions
            a = in.nextInt();
            b = in.nextInt();
        }
    }
}

