import java.util.Scanner;
public class EightQueens {
    public static class Solution {
        private boolean isFound;
        private boolean[][] cellsTaken;
        public Solution(boolean isFound, boolean[][] cellsTaken) {
            this.isFound = isFound;
            this.cellsTaken = cellsTaken;
        }
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
    public Solution solve(int boardSize) {
        boolean[][] cellsTaken = new boolean[boardSize][boardSize];
        boolean isFound = checkSolution(boardSize, cellsTaken, 0);
        return new Solution(isFound, cellsTaken);
    }
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
    private boolean isLegal(int size, boolean[][] cellsTaken) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (cellsTaken[i][j]) {
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
