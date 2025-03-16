
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object to read input from the user

        int rows = scanner.nextInt(); // Read the number of rows in the maze from the user
        int cols = scanner.nextInt(); // Read the number of columns in the maze from the user

        int[][] maze = new int[rows][cols]; // Create a 2D integer array to represent the maze

        for (int i = 0; i < rows; i++) { // Iterate through each row in the maze
            for (int j = 0; j < cols; j++) { // Iterate through each column in the maze
                maze[i][j] = scanner.nextInt(); // Read the cell value of the current position from the user
            }
        }

        int strategy = scanner.nextInt(); // Read the strategy number from the user

        int[][] solvedMaze = null; // Initialize the solved maze as null

        if (strategy == 1) { // If the user chooses the first strategy
            solvedMaze = solveMazeUsingFirstStrategy(maze); // Call the function to solve the maze using the first strategy
        } else if (strategy == 2) { // If the user chooses the second strategy
            solvedMaze = solveMazeUsingSecondStrategy(maze); // Call the function to solve the maze using the second strategy
        } else { // If the user chooses an invalid strategy
            System.out.println("Invalid strategy choice."); // Print an error message and exit the program
            return;
        }

        if (solvedMaze != null) { // If a solution was found
            System.out.println("Solved maze:"); // Print a message to indicate that the solved maze will be displayed

            for (int[] row : solvedMaze) { // Iterate through each row in the solved maze
                for (int cell : row) { // Iterate through each cell in the current row
                    System.out.print(cell + " "); // Print the cell value to the console
                }
                System.out.println(); // Move to the next line after printing the current row
            }
        } else { // If no solution was found
            System.out.println("No solution exists."); // Print a message to indicate that no solution was found
        }

        scanner.close(); // Close the Scanner object to free up system resources
    }

    public static int[][] solveMazeUsingFirstStrategy(int[][] map) {
        // Function to solve the maze using the first strategy
        if (setWay(map, 1, 1)) { // Call the setWay function to try and find a solution starting from the first cell
            return map; // Return the solved maze if a solution was found
        }
        return null; // Return null if no solution was found
    }

    public static int[][] solveMazeUsingSecondStrategy(int[][] map) {
        // Function to solve the maze using the second strategy
        if (setWay2(map, 1, 1)) { // Call the setWay2 function to try and find a solution starting from the first cell
            return map; // Return the solved maze if a solution was found
        }
        return null; // Return null if no solution was found
    }

    private static boolean setWay(int[][] map, int i, int j) {
        // Function to try and find a solution by setting the current cell as visited and recursively exploring the neighbors
        if (i == map.length - 2 && j == map[0].length - 2) { // If the current cell is the exit cell
            map[i][j] = 2; // Set the exit cell as visited (solved)
            return true; // Return true to indicate that a solution was found
        }

        if (map[i][j] == 0) { // If the current cell is unvisited
            map[i][j] = 2; // Set the current cell as visited

            if (setWay(map, i + 1, j)) { // Try to find a solution by moving down
                return true;
            }

            else if (setWay(map, i, j + 1)) { // Try to find a solution by moving right
                return true;
            }

            else if (setWay(map, i - 1, j)) { // Try to find a solution by moving up
                return true;
            }

            else if (setWay(map, i, j - 1)) { // Try to find a solution by moving left
                return true;
            }

            map[i][j] = 3; // Set the current cell back to unvisited if no solution was found in any direction
            return false;
        }

        return false; // Return false if the current cell is already visited
    }

    private static boolean setWay2(int[][] map, int i, int j) {
        // Function identical to setWay, but with different variable names for readability
        if (i == map.length - 2 && j == map[0].length - 2) {
            map[i][j] = 2;
            return true;
        }

        if (map[i][j] == 0) {
            map[i][j] = 2;

            if (setWay2(map, i - 1, j)) {
                return true;
            }

            else if (setWay2(map, i, j + 1)) {
                return true;
            }

            else if (setWay2(map, i + 1, j)) {
                return true;
            }

            else if (setWay2(map, i, j - 1)) {
                return true;
            }

            map[i][j] = 3;
            return false;
        }

        return false;
    }
}