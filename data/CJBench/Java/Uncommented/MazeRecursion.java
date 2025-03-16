
import java.util.Scanner;
public final class MazeRecursion {
    private MazeRecursion() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        int[][] maze = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maze[i][j] = scanner.nextInt();
            }
        }
        int strategy = scanner.nextInt();
        int[][] solvedMaze = null;
        if (strategy == 1) {
            solvedMaze = solveMazeUsingFirstStrategy(maze);
        } else if (strategy == 2) {
            solvedMaze = solveMazeUsingSecondStrategy(maze);
        } else {
            System.out.println("Invalid strategy choice.");
            return;
        }
        if (solvedMaze != null) {
            System.out.println("Solved maze:");
            for (int[] row : solvedMaze) {
                for (int cell : row) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("No solution exists.");
        }
        scanner.close();
    }
    public static int[][] solveMazeUsingFirstStrategy(int[][] map) {
        if (setWay(map, 1, 1)) {
            return map;
        }
        return null;
    }
    public static int[][] solveMazeUsingSecondStrategy(int[][] map) {
        if (setWay2(map, 1, 1)) {
            return map;
        }
        return null;
    }
    private static boolean setWay(int[][] map, int i, int j) {
        if (i == map.length - 2 && j == map[0].length - 2) {
            map[i][j] = 2;
            return true;
        }
        if (map[i][j] == 0) {
            map[i][j] = 2;
            if (setWay(map, i + 1, j)) {
                return true;
            }
            else if (setWay(map, i, j + 1)) {
                return true;
            }
            else if (setWay(map, i - 1, j)) {
                return true;
            }
            else if (setWay(map, i, j - 1)) {
                return true;
            }
            map[i][j] = 3; 
            return false;
        }
        return false;
    }
    private static boolean setWay2(int[][] map, int i, int j) {
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
