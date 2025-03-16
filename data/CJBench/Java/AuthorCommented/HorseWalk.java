import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;
import java.util.stream.Collectors;

/**
 * Find solution for Horse Walk task: horse should visit each cell of NxN board one time
 *
 * @see <a href="https://youtu.be/keNYNcQi9o8">Video solution</a>
 */
public class HorseWalk {

    /**
     * Represents a cell on the chessboard.
     */
    public static class Cell {
        private static final char[] CHARS = "abcdefgh".toCharArray();
        private int x, y;

        public Cell(int x, int y) {
            this.x = x;
            this.y = y;
        }

        /**
         * Converts the cell coordinates to standard chessboard notation.
         *
         * @return The cell in chessboard format (e.g., "a1", "h8").
         */
        public String convertToCheckMateCoordinateSystem() {
            return String.format("%s%d", CHARS[x], y + 1);
        }
    }

    /**
     * Represents the solution to the Horse Walk task.
     */
    public static class Solution {
        private final boolean isFound;
        private final boolean[][] cellsTaken;
        private final Deque<Cell> log;

        public Solution(boolean isFound, boolean[][] cellsTaken, Deque<Cell> log) {
            this.isFound = isFound;
            this.cellsTaken = cellsTaken;
            this.log = log;
        }

        /**
         * Prints the solution as a sequence of moves and displays the board with move numbers.
         */
        public void printLog() {
            if (!isFound || log.size() != cellsTaken.length * cellsTaken.length) {
                System.out.println("No solution found!");
                return;
            }

            int[][] board = new int[cellsTaken.length][cellsTaken.length];
            int positionNumber = 0;
            for (Cell cell : log.stream().collect(Collectors.toList())) {
                positionNumber++;
                board[cell.x][cell.y] = positionNumber;
            }

            for (int[] row : board) {
                for (int cell : row) {
                    System.out.print(cell + "\t");
                }
                System.out.println();
            }
        }
    }

    /**
     * Solves the Horse Walk problem for a given board size.
     *
     * @param boardSize The size of the chessboard (NxN).
     * @return The solution to the Horse Walk problem.
     */
    public Solution solve(int boardSize) {
        boolean[][] cellsTaken = new boolean[boardSize][boardSize];
        cellsTaken[0][0] = true;

        Deque<Cell> log = new ArrayDeque<>();
        log.push(new Cell(0, 0));

        boolean isFound = checkSolution(boardSize, cellsTaken, 1, 0, 0, log);

        return new Solution(isFound, cellsTaken, log);
    }

    /**
     * Recursively attempts to find a solution using backtracking.
     *
     * @param size         The size of the chessboard.
     * @param cellsTaken   Tracks visited cells.
     * @param cellsVisited The number of cells visited so far.
     * @param currX        The current x-coordinate of the knight.
     * @param currY        The current y-coordinate of the knight.
     * @param log          The log of the knight's moves.
     * @return True if a solution is found, otherwise false.
     */
    public boolean checkSolution(int size, boolean[][] cellsTaken, int cellsVisited, int currX, int currY, Deque<Cell> log) {
        if (cellsVisited == size * size) {
            return true;
        }

        final int[][] POSSIBLE_MOVES = {{-2, -1}, {-2, 1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
        for (var move : POSSIBLE_MOVES) {
            int nextX = currX + move[0];
            int nextY = currY + move[1];
            if (nextX < 0 || nextX >= size || nextY < 0 || nextY >= size) {
                continue;
            }

            if (cellsTaken[nextX][nextY]) {
                continue;
            }

            cellsTaken[nextX][nextY] = true;
            log.push(new Cell(nextX, nextY));
            if (checkSolution(size, cellsTaken, cellsVisited + 1, nextX, nextY, log)) {
                return true;
            } else {
                log.pop();
                cellsTaken[nextX][nextY] = false;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int boardSize = scanner.nextInt();
        scanner.close();

        HorseWalk horseWalk = new HorseWalk();
        Solution solution = horseWalk.solve(boardSize);
        solution.printLog();
    }
}
