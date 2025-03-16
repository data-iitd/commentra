import java.util.Scanner;

/**
 * Place N Queens to NxN board
 * <p>
 * Used Rod Stephens - 'Essential Algorithms' book
 *
 * @see <a href="https://youtu.be/v9kctJiD4KQ">Video solution</a>
 */
public class EightQueens {

    /**
     * A class to represent the solution of the N-Queens problem.
     */
    public static class Solution {
        private boolean isFound;
        private boolean[][] cellsTaken;

        public Solution(boolean isFound, boolean[][] cellsTaken) {
            this.isFound = isFound;
            this.cellsTaken = cellsTaken;
        }

        /**
         * Prints the chessboard with the queens placed.
         * 'Q' represents a queen, and '.' represents an empty cell.
         */
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

    /**
     * Solves the N-Queens problem for a given board size.
     * 
     * @param boardSize The size of the chessboard (N x N).
     * @return A `Solution` object containing the result.
     */
    public Solution solve(int boardSize) {
        boolean[][] cellsTaken = new boolean[boardSize][boardSize];
        boolean isFound = checkSolution(boardSize, cellsTaken, 0);

        return new Solution(isFound, cellsTaken);
    }

    /**
     * Attempts to place queens on the board using backtracking.
     * 
     * @param size            The size of the chessboard.
     * @param cellsTaken      The current state of the chessboard.
     * @param queensPositioned The number of queens successfully placed so far.
     * @return True if a solution is found, false otherwise.
     */
    private boolean checkSolution(int size, boolean[][] cellsTaken, int queensPositioned) {
        if (!isLegal(size, cellsTaken)) {
            return false;
        }
        if (queensPositioned == size) {
            return true;
        }

        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (!cellsTaken[row][col]) {
                    cellsTaken[row][col] = true;

                    if (checkSolution(size, cellsTaken, queensPositioned + 1)) {
                        return true;
                    } else {
                        cellsTaken[row][col] = false;
                    }
                }
            }
        }
        return false;
    }

    /**
     * Validates whether the current board configuration is valid.
     * Ensures no two queens threaten each other.
     * 
     * @param size       The size of the chessboard.
     * @param cellsTaken The current state of the chessboard.
     * @return True if the configuration is valid, false otherwise.
     */
    private boolean isLegal(int size, boolean[][] cellsTaken) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (cellsTaken[i][j]) {
                    // check rows
                    for (int r = 1; r < size; r++) {
                        if (i + r < size && cellsTaken[i + r][j]) {
                            return false;
                        }
                        if (i - r >= 0 && cellsTaken[i - r][j]) {
                            return false;
                        }
                    }

                    // check columns
                    for (int r = 1; r < size; r++) {
                        if (j + r < size && cellsTaken[i][j + r]) {
                            return false;
                        }
                        if (j - r >= 0 && cellsTaken[i][j - r]) {
                            return false;
                        }
                    }

                    // check diagonals
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
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int boardSize = scanner.nextInt();
        scanner.close();

        EightQueens eightQueens = new EightQueens();
        Solution solution = eightQueens.solve(boardSize);

        solution.prettyPrint();
    }
}
