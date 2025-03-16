
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
public final class KnightsTour {
    private KnightsTour() {}
    private static final int BASE = 12; 
    private static final int[][] MOVES = {
        {1, -2}, {2, -1}, {2, 1}, {1, 2},
        {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2},
    };
    static int[][] grid;
    static int total;
    public static void resetBoard(int size) {
        grid = new int[size + 4][size + 4];
        total = size * size;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (r < 2 || r >= grid.length - 2 || c < 2 || c >= grid[0].length - 2) {
                    grid[r][c] = -1; 
                }
            }
        }
    }
    static boolean solve(int row, int col, int count) {
        if (count > total) return true;
        List<int[]> neighbor = neighbors(row, col);
        if (neighbor.isEmpty() && count != total) return false;
        neighbor.sort(Comparator.comparingInt(a -> a[2]));
        for (int[] nb : neighbor) {
            int nextRow = nb[0];
            int nextCol = nb[1];
            grid[nextRow][nextCol] = count;
            if (!orphanDetected(count, nextRow, nextCol) && solve(nextRow, nextCol, count + 1)) {
                return true;
            }
            grid[nextRow][nextCol] = 0;
        }
        return false;
    }
    static List<int[]> neighbors(int row, int col) {
        List<int[]> neighbor = new ArrayList<>();
        for (int[] m : MOVES) {
            int x = row + m[0];
            int y = col + m[1];
            if (grid[x][y] == 0) {
                neighbor.add(new int[]{x, y, countNeighbors(x, y)});
            }
        }
        return neighbor;
    }
    static int countNeighbors(int row, int col) {
        int count = 0;
        for (int[] m : MOVES) {
            int x = row + m[0];
            int y = col + m[1];
            if (grid[x][y] == 0) count++;
        }
        return count;
    }
    static boolean orphanDetected(int count, int row, int col) {
        if (count < total - 1) {
            for (int[] nb : neighbors(row, col)) {
                if (countNeighbors(nb[0], nb[1]) == 0) {
                    return true;
                }
            }
        }
        return false;
    }
    public static void printSolution(int size) {
        for (int r = 2; r < size + 2; r++) {
            for (int c = 2; c < size + 2; c++) {
                System.out.printf("%3d", grid[r][c]);
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int startRow = scanner.nextInt();
        int startCol = scanner.nextInt();
        resetBoard(size);
        grid[startRow + 2][startCol + 2] = 1;
        if (solve(startRow + 2, startCol + 2, 2)) {
            System.out.println("Knight's tour solution:");
            printSolution(size);
        } else {
            System.out.println("No solution exists.");
        }
        scanner.close();
    }
}
