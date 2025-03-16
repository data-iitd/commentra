
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public final class NQueens {
    private NQueens() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int queens = scanner.nextInt();
        scanner.close();
        List<List<String>> arrangements = getNQueensArrangements(queens);
        if (arrangements.isEmpty()) {
            System.out.println("There is no way to place " + queens + " queens on a board of size " + queens + "x" + queens);
        } else {
            System.out.println("Arrangements for placing " + queens + " queens:");
            for (List<String> arrangement : arrangements) {
                arrangement.forEach(System.out::println);
                System.out.println();
            }
        }
    }
    public static List<List<String>> getNQueensArrangements(int queens) {
        List<List<String>> arrangements = new ArrayList<>();
        getSolution(queens, arrangements, new int[queens], 0);
        return arrangements;
    }
    private static void getSolution(int boardSize, List<List<String>> solutions, int[] columns, int columnIndex) {
        if (columnIndex == boardSize) {
            List<String> solution = new ArrayList<>();
            for (int i = 0; i < boardSize; i++) {
                StringBuilder row = new StringBuilder();
                for (int j = 0; j < boardSize; j++) {
                    row.append(j == columns[i] ? "Q" : ".");
                }
                solution.add(row.toString());
            }
            solutions.add(solution);
            return;
        }
        for (int rowIndex = 0; rowIndex < boardSize; rowIndex++) {
            columns[columnIndex] = rowIndex;
            if (isPlacedCorrectly(columns, rowIndex, columnIndex)) {
                getSolution(boardSize, solutions, columns, columnIndex + 1);
            }
        }
    }
    private static boolean isPlacedCorrectly(int[] columns, int rowIndex, int columnIndex) {
        for (int i = 0; i < columnIndex; i++) {
            int diff = Math.abs(columns[i] - rowIndex);
            if (diff == 0 || columnIndex - i == diff) {
                return false;
            }
        }
        return true;
    }
}
