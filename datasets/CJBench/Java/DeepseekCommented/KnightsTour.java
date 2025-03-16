import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
public final class Main {
    private Main() {} // This constructor ensures the class cannot be instantiated.

    // Constants for the knight's moves and the base size of the board.
    private static final int BASE = 12; 
    private static final int[][] MOVES = {
        {1, -2}, {2, -1}, {2, 1}, {1, 2},
        {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2},
    };

    // Static variables for the grid and the total number of cells.
    static int[][] grid;
    static int total;

    // Initializes the board with the given size, setting boundaries and some cells to -1.
    public static void resetBoard(int size) {
        grid = new int[size + 4][size + 4];
        total = size * size;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (r < 2 || r >= grid.length - 2 || c < 2 || c >= grid[0].length - 2) {
                    grid[r][c] = -1; 
                }
            }
        }
    }

    // Attempts to solve the Knight's Tour problem using backtracking.
    static boolean solve(int row, int col, int count) {
        if (count > total) return true; // If all cells are visited, return true.
        List<int[]> neighbor = neighbors(row, col); // Get valid neighboring positions.
        if (neighbor.isEmpty() && count != total) return false; // If no neighbors and not all cells visited, return false.
        neighbor.sort(Comparator.comparingInt(a -> a[2])); // Sort neighbors by the number of neighbors.
        for (int[] nb : neighbor) {
            int nextRow = nb[0];
            int nextCol = nb[1];
            grid[nextRow][nextCol] = count; // Mark the cell as visited.
            if (!orphanDetected(count, nextRow, nextCol) && solve(nextRow, nextCol, count + 1)) {
                return true; // Recursively attempt to solve from the next position.
            }
            grid[nextRow][nextCol] = 0; // Backtrack: unmark the cell.
        }
        return false;
    }

    // Finds all valid neighboring positions for the knight and counts their neighbors.
    static List<int[]> neighbors(int row, int col) {
        List<int[]> neighbor = new ArrayList<>();
        for (int[] m : MOVES) {
            int x = row + m[0];
            int y = col + m[1];
            if (grid[x][y] == 0) {
                neighbor.add(new int[]{x, y, countNeighbors(x, y)});
            }
        }
        return neighbor;
    }

    // Counts the number of valid neighboring positions for a given cell.
    static int countNeighbors(int row, int col) {
        int count = 0;
        for (int[] m : MOVES) {
            int x = row + m[0];
            int y = col + m[1];
            if (grid[x][y] == 0) count++;
        }
        return count;
    }

    // Checks if a cell is an orphan (no valid moves from there).
    static boolean orphanDetected(int count, int row, int col) {
        if (count < total - 1) {
            for (int[] nb : neighbors(row, col)) {
                if (countNeighbors(nb[0], nb[1]) == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    // Prints the solution grid.
    public static void printSolution(int size) {
        for (int r = 2; r < size + 2; r++) {
            for (int c = 2; c < size + 2; c++) {
                System.out.printf("%3d", grid[r][c]);
            }
            System.out.println();
        }
    }

    // The entry point of the program. Initializes the board, solves the Knight's Tour problem, and prints the solution.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int startRow = scanner.nextInt();
        int startCol = scanner.nextInt();
        resetBoard(size);
        grid[startRow + 2][startCol + 2] = 1; // Mark the starting position.
        if (solve(startRow + 2, startCol + 2, 2)) {
            System.out.println("Knight's tour solution:");
            printSolution(size);
        } else {
            System.out.println("No solution exists.");
        }
        scanner.close();
    }
}
