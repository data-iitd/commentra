
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public final class Main {
    private Main() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int queens = scanner.nextInt(); // Read the number of queens from the user
        scanner.close(); // Close the scanner as we don't need it anymore
        List<List<String>> arrangements = getMainArrangements(queens); // Get all possible arrangements
        if (arrangements.isEmpty()) { // Check if there are no arrangements
            System.out.println("There is no way to place " + queens + " queens on a board of size " + queens + "x" + queens);
        } else { // If there are arrangements, print them
            System.out.println("Arrangements for placing " + queens + " queens:");
            for (List<String> arrangement : arrangements) {
                arrangement.forEach(System.out::println); // Print each arrangement
                System.out.println(); // Print a newline for separation
            }
        }
    }
    public static List<List<String>> getMainArrangements(int queens) {
        List<List<String>> arrangements = new ArrayList<>(); // Initialize the list of arrangements
        getSolution(queens, arrangements, new int[queens], 0); // Call the recursive method to find solutions
        return arrangements; // Return the list of arrangements
    }
    private static void getSolution(int boardSize, List<List<String>> solutions, int[] columns, int columnIndex) {
        if (columnIndex == boardSize) { // If all queens are placed
            List<String> solution = new ArrayList<>(); // Create a new solution list
            for (int i = 0; i < boardSize; i++) { // Iterate over each row
                StringBuilder row = new StringBuilder(); // Create a StringBuilder for the row
                for (int j = 0; j < boardSize; j++) { // Iterate over each column
                    row.append(j == columns[i] ? "Q" : "."); // Append 'Q' if it's a queen's position, else '.'
                }
                solution.add(row.toString()); // Add the row to the solution
            }
            solutions.add(solution); // Add the solution to the list of solutions
            return; // Return from the method
        }
        for (int rowIndex = 0; rowIndex < boardSize; rowIndex++) { // Try to place the queen in each row of the current column
            columns[columnIndex] = rowIndex; // Place the queen
            if (isPlacedCorrectly(columns, rowIndex, columnIndex)) { // Check if the placement is correct
                getSolution(boardSize, solutions, columns, columnIndex + 1); // Recursively try to place the next queen
            }
        }
    }
    private static boolean isPlacedCorrectly(int[] columns, int rowIndex, int columnIndex) {
        for (int i = 0; i < columnIndex; i++) { // Check all previous columns
            int diff = Math.abs(columns[i] - rowIndex); // Calculate the difference in rows
            if (diff == 0 || columnIndex - i == diff) { // If the same row or diagonal, return false
                return false;
            }
        }
        return true; // If no conflicts, return true
    }
}