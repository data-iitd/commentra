
import java.util.Scanner;

public class Main {
    public static class Solution {
        // Class to store the solution and its validity flag
        private boolean isFound;
        private boolean[][] cellsTaken;

        public Solution(boolean isFound, boolean[][] cellsTaken) {
            this.isFound = isFound;
            this.cellsTaken = cellsTaken;
        }

        public void prettyPrint() {
            // Print the solution if it exists
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

    public Solution solve(int boardSize) {
        // Initialize the cellsTaken array and call the checkSolution method
        boolean[][] cellsTaken = new boolean[boardSize][boardSize];
        boolean isFound = checkSolution(boardSize, cellsTaken, 0);

        // Return a new Solution object with the found solution and its flag
        return new Solution(isFound, cellsTaken);
    }

    private boolean checkSolution(int size, boolean[][] cellsTaken, int queensPositioned) {
        // Check if the current positioning of queens is legal
        if (!isLegal(size, cellsTaken)) {
            return false;
        }

        // If all queens have been placed, return true
        if (queensPositioned == size) {
            return true;
        }

        // Try placing a queen in each empty cell and recursively call checkSolution
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (!cellsTaken[row][col]) {
                    cellsTaken[row][col] = true;
                    boolean result = checkSolution(size, cellsTaken, queensPositioned + 1);
                    cellsTaken[row][col] = false;

                    // If a solution was found, return true
                    if (result) {
                        return true;
                    }
                }
            }
        }

        // If no solution was found, return false
        return false;
    }

    private boolean isLegal(int size, boolean[][] cellsTaken) {
        // Check if the current positioning of queens is legal by checking the conditions
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (cellsTaken[i][j]) {
                    // Check the conditions for the queen at (i, j)
                    for (int r = 1; r < size; r++) {
                        if (i + r < size && cellsTaken[i + r][j]) {
                            return false;
                        }
                        if (i - r >= 0 && cellsTaken[i - r][j]) {
                            return false;
                        }
                    }

                    for (int r = 1; r < size; r++) {
                        if (j + r < size && cellsTaken[i][j + r]) {
                            return false;
                        }
                        if (j - r >= 0 && cellsTaken[i][j - r]) {
                            return false;
                        }
                    }

                    for (int r = 1; r < size; r++) {
                        if (i + r < size && j + r < size && cellsTaken[i + r][j + r]) {
                            return false;
                        }
                        if (i + r < size && j - r >= 0 && cellsTaken[i + r][j - r]) {
                            return false;
                        }
                        if (i - r >= 0 && j + r < size && cellsTaken[i - r][j + r]) {
                            return false;
                        }
                        if (i - r >= 0 && j - r >= 0 && cellsTaken[i - r][j - r]) {
                            return false;
                        }
                    }
                }
            }
        }

        // If all conditions are met, return true
        return true;
    }

    public static void main(String[] args) {
        // Read the board size from the user input and call the solve method
        Scanner scanner = new Scanner(System.in);
        int boardSize = scanner.nextInt();
        scanner.close();

        Main eightQueens = new Main();
        Solution solution = eightQueens.solve(boardSize);

        // Print the solution using the prettyPrint method
        solution.prettyPrint();
    }
}

