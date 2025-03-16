
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // Initializes the scanner and reads the number of queens from the user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int queens = scanner.nextInt();
        scanner.close();

        // Calls the function to get all possible arrangements for the given number of queens
        List<List<String>> arrangements = getMainArrangements(queens);

        // Checks if there are any arrangements and prints the error message if not
        if (arrangements.isEmpty()) {
            System.out.println("There is no way to place " + queens + " queens on a board of size " + queens + "x" + queens);
        } else {
            // Prints the header message and the arrangements one by one
            System.out.println("Arrangements for placing " + queens + " queens:");
            for (List<String> arrangement : arrangements) {
                arrangement.forEach(System.out::println);
                System.out.println();
            }
        }
    }

    // Recursively calculates all possible arrangements for the given number of queens
    public static List<List<String>> getMainArrangements(int queens) {
        List<List<String>> arrangements = new ArrayList<>();
        getSolution(queens, arrangements, new int[queens], 0);
        return arrangements;
    }

    // The main recursive function to find all possible arrangements
    private static void getSolution(int boardSize, List<List<String>> solutions, int[] columns, int columnIndex) {
        // Base case: if all columns have been filled, add the current arrangement to the list of solutions
        if (columnIndex == boardSize) {
            List<String> solution = new ArrayList<>();
            // Creates a new string representation of the arrangement and adds it to the list of solutions
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

        // Iterates through all possible rows to place a queen
        for (int rowIndex = 0; rowIndex < boardSize; rowIndex++) {
            columns[columnIndex] = rowIndex;
            // Checks if the current placement is valid and recursively calls the function if it is
            if (isPlacedCorrectly(columns, rowIndex, columnIndex)) {
                getSolution(boardSize, solutions, columns, columnIndex + 1);
            }
        }
    }

    // Checks if the current placement of a queen is valid based on the previous placements
    private static boolean isPlacedCorrectly(int[] columns, int rowIndex, int columnIndex) {
        // Iterates through all previous columns to check if there is a conflict with the current placement
        for (int i = 0; i < columnIndex; i++) {
            int diff = Math.abs(columns[i] - rowIndex);
            // Checks for two possible conflicts: the queen is placed on the same row or diagonal
            if (diff == 0 || columnIndex - i == diff) {
                return false;
            }
        }
        // If no conflicts are found, the placement is valid
        return true;
    }
}