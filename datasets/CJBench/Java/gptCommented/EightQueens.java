import java.util.Scanner;

public class Main {
    // Inner class to represent the solution of the N-Queens problem
    public static class Solution {
        private boolean isFound; // Indicates if a solution was found
        private boolean[][] cellsTaken; // 2D array to represent the board and the positions of queens

        // Constructor to initialize the solution object
        public Solution(boolean isFound, boolean[][] cellsTaken) {
            this.isFound = isFound;
            this.cellsTaken = cellsTaken;
        }

        // Method to print the board in a pretty format
        public void prettyPrint() {
            // If no solution was found, print a message
            if (!isFound) {
                System.out.println("No solution found.");
                return;
            }
            int size = cellsTaken.length; // Get the size of the board
            // Loop through each cell of the board
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    // Print 'Q' for a queen and '.' for an empty cell
                    System.out.print((cellsTaken[i][j] ? "Q" : ".") + " ");
                }
                System.out.println(); // Move to the next line after each row
            }
        }
    }

    // Method to solve the N-Queens problem for a given board size
    public Solution solve(int boardSize) {
        boolean[][] cellsTaken = new boolean[boardSize][boardSize]; // Initialize the board
        boolean isFound = checkSolution(boardSize, cellsTaken, 0); // Start checking for solutions
        return new Solution(isFound, cellsTaken); // Return the solution object
    }

    // Recursive method to check for a valid solution
    private boolean checkSolution(int size, boolean[][] cellsTaken, int queensPositioned) {
        // Check if the current board configuration is legal
        if (!isLegal(size, cellsTaken)) {
            return false; // If not legal, return false
        }
        // If all queens are positioned, a solution is found
        if (queensPositioned == size) {
            return true;
        }
        // Try to place a queen in each cell of the board
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (!cellsTaken[row][col]) { // If the cell is empty
                    cellsTaken[row][col] = true; // Place a queen
                    // Recursively check if placing the queen leads to a solution
                    if (checkSolution(size, cellsTaken, queensPositioned + 1)) {
                        return true; // If a solution is found, return true
                    } else {
                        cellsTaken[row][col] = false; // Backtrack if no solution found
                    }
                }
            }
        }
        return false; // Return false if no valid position is found
    }

    // Method to check if the current board configuration is legal
    private boolean isLegal(int size, boolean[][] cellsTaken) {
        // Loop through each cell to check for conflicts
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (cellsTaken[i][j]) { // If there is a queen in the cell
                    // Check vertical and horizontal conflicts
                    for (int r = 1; r < size; r++) {
                        if (i + r < size && cellsTaken[i + r][j]) {
                            return false; // Vertical conflict
                        }
                        if (i - r >= 0 && cellsTaken[i - r][j]) {
                            return false; // Vertical conflict
                        }
                    }
                    // Check horizontal conflicts
                    for (int r = 1; r < size; r++) {
                        if (j + r < size && cellsTaken[i][j + r]) {
                            return false; // Horizontal conflict
                        }
                        if (j - r >= 0 && cellsTaken[i][j - r]) {
                            return false; // Horizontal conflict
                        }
                    }
                    // Check diagonal conflicts
                    for (int r = 1; r < size; r++) {
                        if (i + r < size && j + r < size && cellsTaken[i + r][j + r]) {
                            return false; // Diagonal conflict
                        }
                        if (i + r < size && j - r >= 0 && cellsTaken[i + r][j - r]) {
                            return false; // Diagonal conflict
                        }
                        if (i - r >= 0 && j + r < size && cellsTaken[i - r][j + r]) {
                            return false; // Diagonal conflict
                        }
                        if (i - r >= 0 && j - r >= 0 && cellsTaken[i - r][j - r]) {
                            return false; // Diagonal conflict
                        }
                    }
                }
            }
        }
        return true; // Return true if no conflicts are found
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int boardSize = scanner.nextInt(); // Read the size of the board from input
        scanner.close(); // Close the scanner
        Main eightQueens = new Main(); // Create an instance of Main
        Solution solution = eightQueens.solve(boardSize); // Solve the N-Queens problem
        solution.prettyPrint(); // Print the solution
    }
}
