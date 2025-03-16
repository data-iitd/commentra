import java.util.Scanner;
public class Main {
    public static class Solution {
        private boolean isFound;
        private boolean[][] cellsTaken;
        public Solution(boolean isFound, boolean[][] cellsTaken) {
            this.isFound = isFound;
            this.cellsTaken = cellsTaken;
        }
        // This method prints the board in a readable format.
        // If no solution is found, it prints "No solution found."
        public void prettyPrint() {
            if (!isFound) {
                System.out.println("No solution found.");
                return;
            }
            int size = cellsTaken.length;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    System.out.print((cellsTaken[i][j] ? "Q" : ".") + " ");
                }
                System.out.println();
            }
        }
    }
    // This method initializes the board and starts the process to find a solution.
    public Solution solve(int boardSize) {
        boolean[][] cellsTaken = new boolean[boardSize][boardSize];
        boolean isFound = checkSolution(boardSize, cellsTaken, 0);
        return new Solution(isFound, cellsTaken);
    }
    // This recursive method attempts to place queens on the board.
    // It checks if the current state is legal and tries to place queens in each row.
    private boolean checkSolution(int size, boolean[][] cellsTaken, int queensPositioned) {
        if (!isLegal(size, cellsTaken)) { // Check if the current state is legal
            return false;
        }
        if (queensPositioned == size) { // If all queens are positioned, a solution is found
            return true;
        }
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (!cellsTaken[row][col]) { // Try to place a queen if the cell is empty
                    cellsTaken[row][col] = true;
                    if (checkSolution(size, cellsTaken, queensPositioned + 1)) { // Recursively check the next position
                        return true;
                    } else {
                        cellsTaken[row][col] = false; // Backtrack if placing a queen doesn't lead to a solution
                    }
                }
            }
        }
        return false;
    }
    // This method checks if the current board state is legal.
    // It ensures no two queens are in the same row, column, or diagonal.
    private boolean isLegal(int size, boolean[][] cellsTaken) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (cellsTaken[i][j]) {
                    for (int r = 1; r < size; r++) {
                        if (i + r < size && cellsTaken[i + r][j]) { // Check for same column
                            return false;
                        }
                        if (i - r >= 0 && cellsTaken[i - r][j]) { // Check for same column
                            return false;
                        }
                    }
                    for (int r = 1; r < size; r++) {
                        if (j + r < size && cellsTaken[i][j + r]) { // Check for same row
                            return false;
                        }
                        if (j - r >= 0 && cellsTaken[i][j - r]) { // Check for same row
                            return false;
                        }
                    }
                    for (int r = 1; r < size; r++) {
                        if (i + r < size && j + r < size && cellsTaken[i + r][j + r]) { // Check for diagonal
                            return false;
                        }
                        if (i + r < size && j - r >= 0 && cellsTaken[i + r][j - r]) { // Check for diagonal
                            return false;
                        }
                        if (i - r >= 0 && j + r < size && cellsTaken[i - r][j + r]) { // Check for diagonal
                            return false;
                        }
                        if (i - r >= 0 && j - r >= 0 && cellsTaken[i - r][j - r]) { // Check for diagonal
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int boardSize = scanner.nextInt();
        scanner.close();
        Main eightQueens = new Main();
        Solution solution = eightQueens.solve(boardSize);
        solution.prettyPrint();
    }
}
