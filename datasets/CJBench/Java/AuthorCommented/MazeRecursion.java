
import java.util.Scanner;

/**
 * This class contains methods to solve a maze using recursive backtracking.
 * The maze is represented as a 2D array where walls, paths, and visited/dead
 * ends are marked with different integers.
 */
public final class MazeRecursion {

    private MazeRecursion() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input maze dimensions
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();

        int[][] maze = new int[rows][cols];

        // Input maze grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maze[i][j] = scanner.nextInt();
            }
        }

        // Choose strategy
        int strategy = scanner.nextInt();

        int[][] solvedMaze = null;
        if (strategy == 1) {
            solvedMaze = solveMazeUsingFirstStrategy(maze);
        } else if (strategy == 2) {
            solvedMaze = solveMazeUsingSecondStrategy(maze);
        } else {
            System.out.println("Invalid strategy choice.");
            return;
        }

        // Output the result
        if (solvedMaze != null) {
            System.out.println("Solved maze:");
            for (int[] row : solvedMaze) {
                for (int cell : row) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("No solution exists.");
        }

        scanner.close();
    }

    /**
     * This method solves the maze using the "down -> right -> up -> left"
     * movement strategy.
     *
     * @param map The 2D array representing the maze (walls, paths, etc.)
     * @return The solved maze with paths marked, or null if no solution exists.
     */
    public static int[][] solveMazeUsingFirstStrategy(int[][] map) {
        if (setWay(map, 1, 1)) {
            return map;
        }
        return null;
    }

    /**
     * This method solves the maze using the "up -> right -> down -> left"
     * movement strategy.
     *
     * @param map The 2D array representing the maze (walls, paths, etc.)
     * @return The solved maze with paths marked, or null if no solution exists.
     */
    public static int[][] solveMazeUsingSecondStrategy(int[][] map) {
        if (setWay2(map, 1, 1)) {
            return map;
        }
        return null;
    }

    /**
     * Attempts to find a path through the maze using a "down -> right -> up -> left"
     * movement strategy. The path is marked with '2' for valid paths and '3' for dead ends.
     *
     * @param map The 2D array representing the maze (walls, paths, etc.)
     * @param i   The current x-coordinate of the ball (row index)
     * @param j   The current y-coordinate of the ball (column index)
     * @return True if a path is found to (6,5), otherwise false
     */
    private static boolean setWay(int[][] map, int i, int j) {
        if (i == map.length - 2 && j == map[0].length - 2) {
            map[i][j] = 2;
            return true;
        }

        if (map[i][j] == 0) {
            map[i][j] = 2;

            // Move down
            if (setWay(map, i + 1, j)) {
                return true;
            }
            // Move right
            else if (setWay(map, i, j + 1)) {
                return true;
            }
            // Move up
            else if (setWay(map, i - 1, j)) {
                return true;
            }
            // Move left
            else if (setWay(map, i, j - 1)) {
                return true;
            }

            map[i][j] = 3; // Mark as dead end (3) if no direction worked
            return false;
        }
        return false;
    }

    /**
     * Attempts to find a path through the maze using an alternative movement
     * strategy "up -> right -> down -> left".
     *
     * @param map The 2D array representing the maze (walls, paths, etc.)
     * @param i   The current x-coordinate of the ball (row index)
     * @param j   The current y-coordinate of the ball (column index)
     * @return True if a path is found to (6,5), otherwise false
     */
    private static boolean setWay2(int[][] map, int i, int j) {
        if (i == map.length - 2 && j == map[0].length - 2) {
            map[i][j] = 2;
            return true;
        }

        if (map[i][j] == 0) {
            map[i][j] = 2;

            // Move up
            if (setWay2(map, i - 1, j)) {
                return true;
            }
            // Move right
            else if (setWay2(map, i, j + 1)) {
                return true;
            }
            // Move down
            else if (setWay2(map, i + 1, j)) {
                return true;
            }
            // Move left
            else if (setWay2(map, i, j - 1)) {
                return true;
            }

            map[i][j] = 3; // Mark as dead end (3) if no direction worked
            return false;
        }
        return false;
    }
}
