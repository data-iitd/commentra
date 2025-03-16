
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Problem statement: Given a N x N chess board. Return all arrangements in
 * which N queens can be placed on the board such no two queens attack each
 * other. Ex. N = 6 Solution= There are 4 possible ways Arrangement: 1 ".Q....",
 * "...Q..", ".....Q", "Q.....", "..Q...", "....Q."
 *
 * Arrangement: 2 "..Q...", ".....Q", ".Q....", "....Q.", "Q.....", "...Q.."
 *
 * Arrangement: 3 "...Q..", "Q.....", "....Q.", ".Q....", ".....Q", "..Q..."
 *
 * Arrangement: 4 "....Q.", "..Q...", "Q.....", ".....Q", "...Q..", ".Q...."
 *
 * Solution: Brute Force approach:
 *
 * Generate all possible arrangement to place N queens on N*N board. Check each
 * board if queens are placed safely. If it is safe, include arrangement in
 * solution set. Otherwise, ignore it
 *
 * Optimized solution: This can be solved using backtracking in below steps
 *
 * Start with first column and place queen on first row Try placing queen in a
 * row on second column If placing second queen in second column attacks any of
 * the previous queens, change the row in second column otherwise move to next
 * column and try to place next queen In case if there is no rows where a queen
 * can be placed such that it doesn't attack previous queens, then go back to
 * previous column and change row of previous queen. Keep doing this until last
 * queen is not placed safely. If there is no such way then return an empty list
 * as solution
 */
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

    /**
     * Gets all possible N-Queens arrangements.
     *
     * @param queens Number of queens
     * @return List of arrangements
     */
    public static List<List<String>> getNQueensArrangements(int queens) {
        List<List<String>> arrangements = new ArrayList<>();
        getSolution(queens, arrangements, new int[queens], 0);
        return arrangements;
    }

    /**
     * Backtracking function to place queens recursively.
     *
     * @param boardSize Size of chess board
     * @param solutions List to store all possible arrangements
     * @param columns columns[i] = rowId where queen is placed in ith column
     * @param columnIndex Current column being processed
     */
    private static void getSolution(int boardSize, List<List<String>> solutions, int[] columns, int columnIndex) {
        if (columnIndex == boardSize) {
            // All queens are placed
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

        // Try placing queen in each row of the current column
        for (int rowIndex = 0; rowIndex < boardSize; rowIndex++) {
            columns[columnIndex] = rowIndex;
            if (isPlacedCorrectly(columns, rowIndex, columnIndex)) {
                getSolution(boardSize, solutions, columns, columnIndex + 1);
            }
        }
    }

    /**
     * Checks if a queen can be placed at the specified position.
     *
     * @param columns columns[i] = rowId where queen is placed in ith column
     * @param rowIndex Row index of the queen
     * @param columnIndex Column index of the queen
     * @return true if safe, false otherwise
     */
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
