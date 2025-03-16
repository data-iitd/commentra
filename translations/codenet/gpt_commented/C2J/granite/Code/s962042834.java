
import java.util.Scanner;

public class s962042834{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b;

        // Read the dimensions of the grid (a x b)
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Continue processing until both dimensions are zero
        while (a!= 0 && b!= 0) {
            // Call the function to calculate paths in the grid
            kansu(a, b);

            // Read the next set of dimensions
            a = scanner.nextInt();
            b = scanner.nextInt();
        }
    }

    // Function to calculate the number of paths in a grid with obstacles
    public static void kansu(int a, int b) {
        int i, j, x, y, n;
        int[][] suu = new int[17][17]; // Array to store the number of paths to each cell
        int[][] kouji = new int[17][17]; // Array to mark obstacles in the grid

        // Read the number of obstacles
        n = scanner.nextInt();

        // Initialize the kouji array to mark all cells as free (0)
        for (i = 1; i <= a; i++) {
            for (j = 1; j <= b; j++) {
                kouji[i][j] = 0;
            }
        }

        // Read the positions of obstacles and mark them in the kouji array
        for (i = 0; i < n; i++) {
            x = scanner.nextInt();
            y = scanner.nextInt();
            kouji[x][y] = 1; // Mark the cell as an obstacle (1)
        }

        // Calculate the number of paths to each cell in the grid
        for (i = 1; i <= a; i++) {
            for (j = 1; j <= b; j++) {
                // If the cell is an obstacle, set paths to 0
                if (kouji[i][j] == 1) {
                    suu[i][j] = 0;
                } else {
                    // If at the starting cell, initialize paths to 1
                    if (i == 1 && j == 1) {
                        suu[i][j] = 1;
                    } else {
                        // If in the first row, inherit paths from the left cell
                        if (i == 1) {
                            suu[i][j] = suu[i][j - 1];
                        }
                        // If in the first column, inherit paths from the above cell
                        else if (j == 1) {
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
    }
}

