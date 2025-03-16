import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of rows and columns for the maze
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        
        // Initialize the maze with the specified dimensions
        int[][] maze = new int[rows][cols];
        
        // Populate the maze with input values
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maze[i][j] = scanner.nextInt();
            }
        }
        
        // Read the strategy choice for solving the maze
        int strategy = scanner.nextInt();
        int[][] solvedMaze = null;

        // Determine which strategy to use for solving the maze
        if (strategy == 1) {
            solvedMaze = solveMazeUsingFirstStrategy(maze);
        } else if (strategy == 2) {
            solvedMaze = solveMazeUsingSecondStrategy(maze);
        } else {
            // Handle invalid strategy choice
            System.out.println("Invalid strategy choice.");
            return;
        }

        // Output the solved maze or indicate that no solution exists
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
        
        // Close the scanner to free resources
        scanner.close();
    }

    // Method to solve the maze using the first strategy
    public static int[][] solveMazeUsingFirstStrategy(int[][] map) {
        // Attempt to find a way through the maze starting from (1, 1)
        if (setWay(map, 1, 1)) {
            return map; // Return the solved maze if successful
        }
        return null; // Return null if no solution is found
    }

    // Method to solve the maze using the second strategy
    public static int[][] solveMazeUsingSecondStrategy(int[][] map) {
        // Attempt to find a way through the maze starting from (1, 1)
        if (setWay2(map, 1, 1)) {
            return map; // Return the solved maze if successful
        }
        return null; // Return null if no solution is found
    }

    // Recursive method to find a path in the maze using the first strategy
    private static boolean setWay(int[][] map, int i, int j) {
        // Check if the exit is reached
        if (i == map.length - 2 && j == map[0].length - 2) {
            map[i][j] = 2; // Mark the exit
            return true; // Exit found
        }
        
        // Check if the current cell is open (0)
        if (map[i][j] == 0) {
            map[i][j] = 2; // Mark the cell as part of the path
            // Recursively explore the neighboring cells
            if (setWay(map, i + 1, j) || 
                setWay(map, i, j + 1) || 
                setWay(map, i - 1, j) || 
                setWay(map, i, j - 1)) {
                return true; // Path found
            }
            map[i][j] = 3; // Mark the cell as visited (dead end)
            return false; // No path found
        }
        return false; // Cell is not open
    }

    // Recursive method to find a path in the maze using the second strategy
    private static boolean setWay2(int[][] map, int i, int j) {
        // Check if the exit is reached
        if (i == map.length - 2 && j == map[0].length - 2) {
            map[i][j] = 2; // Mark the exit
            return true; // Exit found
        }
        
        // Check if the current cell is open (0)
        if (map[i][j] == 0) {
            map[i][j] = 2; // Mark the cell as part of the path
            // Recursively explore the neighboring cells in a different order
            if (setWay2(map, i - 1, j) || 
                setWay2(map, i, j + 1) || 
                setWay2(map, i + 1, j) || 
                setWay2(map, i, j - 1)) {
                return true; // Path found
            }
            map[i][j] = 3; // Mark the cell as visited (dead end)
            return false; // No path found
        }
        return false; // Cell is not open
    }
}
