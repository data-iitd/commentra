
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public final class Main {
    private Main() {}

    // Set the base size of the board
    private static final int BASE = 12;

    // Initialize the moves that a knight can make
    private static final int[][] MOVES = {
        {1, -2}, {2, -1}, {2, 1}, {1, 2},
        {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2},
    };

    // Initialize the grid and total number of cells
    static int[][] grid;
    static int total;

    // Reset the board with given size
    public static void resetBoard(int size) {
        grid = new int[size + 4][size + 4]; // Allocate memory for the grid
        total = size * size; // Calculate the total number of cells
        for (int r = 0; r < grid.length; r++) { // Iterate through rows
            for (int c = 0; c < grid[0].length; c++) { // Iterate through columns
                if (r < 2 || r >= grid.length - 2 || c < 2 || c >= grid[0].length - 2) { // If cell is on the border
                    grid[r][c] = -1; // Set it to -1 (out of bounds)
                }
            }
        }
    }

    // Solve the knight's tour problem using depth-first search
    public static boolean solve(int row, int col, int count) {
        if (count > total) return true; // If all cells have been filled, return true

        List<int[]> neighbor = neighbors(row, col); // Get the list of neighbors
        if (neighbor.isEmpty() && count != total) return false; // If the current cell has no neighbors and the tour is not complete, return false

        neighbor.sort(Comparator.comparingInt(a -> a[2])); // Sort neighbors based on the number of neighbors they have
        for (int[] nb : neighbor) { // Iterate through neighbors
            int nextRow = nb[0];
            int nextCol = nb[1];

            grid[nextRow][nextCol] = count; // Place the knight on the neighboring cell
            if (!orphanDetected(count, nextRow, nextCol) && solve(nextRow, nextCol, count + 1)) { // Recursively call the solve function
                return true;
            }
            grid[nextRow][nextCol] = 0; // Backtrack and remove the knight from the neighboring cell
        }
        return false; // If no neighboring cell can be filled, return false
    }

    // Find the neighbors of a given cell
    static List<int[]> neighbors(int row, int col) {
        List<int[]> neighbor = new ArrayList<>(); // Initialize an empty list to store neighbors
        for (int[] m : MOVES) { // Iterate through all possible moves
            int x = row + m[0]; // Calculate the next row
            int y = col + m[1]; // Calculate the next column
            if (grid[x][y] == 0) { // If the neighboring cell is empty
                neighbor.add(new int[]{x, y, countNeighbors(x, y)}); // Add the neighbor to the list along with its number of neighbors
            }
        }
        return neighbor;
    }

    // Count the number of neighbors for a given cell
    static int countNeighbors(int row, int col) {
        int count = 0; // Initialize the count to 0
        for (int[] m : MOVES) { // Iterate through all possible moves
            int x = row + m[0]; // Calculate the next row
            int y = col + m[1]; // Calculate the next column
            if (grid[x][y] == 0) count++; // Increment the count if the neighboring cell is empty
        }
        return count;
    }

    // Check if an orphan cell exists in the given position
    static boolean orphanDetected(int count, int row, int col) {
        if (count < total - 1) { // If the current cell has not been filled yet and the tour is not complete
            for (int[] nb : neighbors(row, col)) { // Iterate through the neighbors of the current cell
                if (countNeighbors(nb[0], nb[1]) == 0) { // If a neighbor has no remaining neighbors
                    return true; // Return true, indicating an orphan cell has been found
                }
            }
        }
        return false; // If no orphan cell is found, return false
    }

    // Print the solution on the console
    public static void printSolution(int size) {
        for (int r = 2; r < size + 2; r++) { // Iterate through rows
            for (int c = 2; c < size + 2; c++) { // Iterate through columns
                System.out.printf("%3d", grid[r][c]); // Print the cell value
            }
            System.out.println(); // Move to the next row
        }
    }

    // Main method to read input and start the algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner to read input
        int size = scanner.nextInt(); // Read the size of the board
        int startRow = scanner.nextInt(); // Read the starting row
        int startCol = scanner.nextInt(); // Read the starting column

        resetBoard(size); // Initialize the board with the given size
        grid[startRow + 2][startCol + 2] = 1; // Place the knight on the starting cell

        if (solve(startRow + 2, startCol + 2, 2)) { // Try to find a solution starting from the starting cell
            System.out.println("Knight's tour solution:"); // Print the solution header
            printSolution(size); // Print the solution on the console
        } else {
            System.out.println("No solution exists."); // Print the error message if no solution is found
        }

        scanner.close(); // Close the Scanner
    }
}