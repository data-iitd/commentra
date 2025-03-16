import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    // Cell class represents a position on the chessboard
    public static class Cell {
        private static final char[] CHARS = "abcdefgh".toCharArray(); // Character representation for columns
        private int x, y; // x and y coordinates of the cell

        // Constructor to initialize the cell's coordinates
        public Cell(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // Converts the cell's coordinates to a chess notation format
        public String convertToCheckMateCoordinateSystem() {
            return String.format("%s%d", CHARS[x], y + 1);
        }
    }

    // Solution class encapsulates the result of the knight's tour problem
    public static class Solution {
        private final boolean isFound; // Indicates if a solution was found
        private final boolean[][] cellsTaken; // Tracks which cells have been visited
        private final Deque<Cell> log; // Log of the cells visited in the solution

        // Constructor to initialize the solution's attributes
        public Solution(boolean isFound, boolean[][] cellsTaken, Deque<Cell> log) {
            this.isFound = isFound;
            this.cellsTaken = cellsTaken;
            this.log = log;
        }

        // Prints the log of the knight's tour if a solution is found
        public void printLog() {
            if (!isFound || log.size() != cellsTaken.length * cellsTaken.length) {
                System.out.println("No solution found!"); // No valid solution
                return;
            }
            int[][] board = new int[cellsTaken.length][cellsTaken.length]; // Initialize the board
            int positionNumber = 0; // Counter for the position number
            // Fill the board with the order of the knight's moves
            for (Cell cell : log.stream().collect(Collectors.toList())) {
                positionNumber++;
                board[cell.x][cell.y] = positionNumber;
            }
            // Print the board with the knight's move order
            for (int[] row : board) {
                for (int cell : row) {
                    System.out.print(cell + "\t"); // Print each cell with a tab space
                }
                System.out.println(); // New line after each row
            }
        }
    }

    // Solves the knight's tour problem for a given board size
    public Solution solve(int boardSize) {
        boolean[][] cellsTaken = new boolean[boardSize][boardSize]; // Track visited cells
        cellsTaken[0][0] = true; // Mark the starting cell as visited
        Deque<Cell> log = new ArrayDeque<>(); // Log of the knight's moves
        log.push(new Cell(0, 0)); // Start from the initial position
        // Start the recursive solution check
        boolean isFound = checkSolution(boardSize, cellsTaken, 1, 0, 0, log);
        return new Solution(isFound, cellsTaken, log); // Return the solution
    }

    // Recursively checks for a valid knight's tour solution
    public boolean checkSolution(int size, boolean[][] cellsTaken, int cellsVisited, int currX, int currY, Deque<Cell> log) {
        // If all cells have been visited, a solution is found
        if (cellsVisited == size * size) {
            return true;
        }
        // Possible knight moves
        final int[][] POSSIBLE_MOVES = {{-2, -1}, {-2, 1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
        // Try each possible move
        for (var move : POSSIBLE_MOVES) {
            int nextX = currX + move[0]; // Calculate next x position
            int nextY = currY + move[1]; // Calculate next y position
            // Check if the next position is within bounds and not visited
            if (nextX < 0 || nextX >= size || nextY < 0 || nextY >= size) {
                continue; // Skip out-of-bounds moves
            }
            if (cellsTaken[nextX][nextY]) {
                continue; // Skip already visited cells
            }
            cellsTaken[nextX][nextY] = true; // Mark the next cell as visited
            log.push(new Cell(nextX, nextY)); // Log the move
            // Recursively check for the next move
            if (checkSolution(size, cellsTaken, cellsVisited + 1, nextX, nextY, log)) {
                return true; // Solution found
            } else {
                log.pop(); // Backtrack if no solution found
                cellsTaken[nextX][nextY] = false; // Unmark the cell
            }
        }
        return false; // No solution found from this path
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int boardSize = scanner.nextInt(); // Read the board size from input
        scanner.close(); // Close the scanner
        Main horseWalk = new Main(); // Create an instance of Main
        Solution solution = horseWalk.solve(boardSize); // Solve the knight's tour problem
        solution.printLog(); // Print the solution log
    }
}
