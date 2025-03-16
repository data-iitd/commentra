
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

    // Define a Cell class to represent a cell on the board
    public static class Cell {
        private static final char[] CHARS = "abcdefgh".toCharArray();
        private int x, y;

        // Constructor for Cell
        public Cell(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // Method to convert a Cell to its coordinate in the checkmate coordinate system
        public String convertToCheckMateCoordinateSystem() {
            return String.format("%s%d", CHARS[x], y + 1);
        }
    }

    // Define a Solution class to store the solution and its log
    public static class Solution {
        private final boolean isFound;
        private final boolean[][] cellsTaken;
        private final Deque<Cell> log;

        // Constructor for Solution
        public Solution(boolean isFound, boolean[][] cellsTaken, Deque<Cell> log) {
            this.isFound = isFound;
            this.cellsTaken = cellsTaken;
            this.log = log;
        }

        // Method to print the solution log
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

    // Main method to solve the problem and print the solution
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int boardSize = scanner.nextInt();
        scanner.close();
        Main horseWalk = new Main();
        Solution solution = horseWalk.solve(boardSize);
        solution.printLog();
    }

    // Method to solve the problem and find a solution
    public Solution solve(int boardSize) {
        boolean[][] cellsTaken = new boolean[boardSize][boardSize];
        cellsTaken[0][0] = true;
        Deque<Cell> log = new ArrayDeque<>();
        log.push(new Cell(0, 0));
        boolean isFound = checkSolution(boardSize, cellsTaken, 1, 0, 0, log);
        return new Solution(isFound, cellsTaken, log);
    }

    // Recursive method to check if a solution exists
    public boolean checkSolution(int size, boolean[][] cellsTaken, int cellsVisited, int currX, int currY, Deque<Cell> log) {
        if (cellsVisited == size * size) {
            // Base case: if all cells have been visited, a solution has been found
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
                // Recursive call: if a solution is found, return true
                return true;
            } else {
                log.pop();
                cellsTaken[nextX][nextY] = false;
            }
        }
        // If no solution is found, return false
        return false;
    }
}