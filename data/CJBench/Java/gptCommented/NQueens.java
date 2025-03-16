import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of queens (and the size of the board)
        int queens = scanner.nextInt();
        
        // Close the scanner to prevent resource leaks
        scanner.close();
        
        // Get all arrangements for placing the queens on the board
        List<List<String>> arrangements = getMainArrangements(queens);
        
        // Check if there are no arrangements found
        if (arrangements.isEmpty()) {
            System.out.println("There is no way to place " + queens + " queens on a board of size " + queens + "x" + queens);
        } else {
            // Print the arrangements found
            System.out.println("Arrangements for placing " + queens + " queens:");
            for (List<String> arrangement : arrangements) {
                arrangement.forEach(System.out::println); // Print each arrangement
                System.out.println(); // Print a blank line between arrangements
            }
        }
    }

    // Method to get all main arrangements of queens on the board
    public static List<List<String>> getMainArrangements(int queens) {
        List<List<String>> arrangements = new ArrayList<>(); // List to store valid arrangements
        getSolution(queens, arrangements, new int[queens], 0); // Start the recursive solution finding
        return arrangements; // Return the list of arrangements found
    }

    // Recursive method to find all solutions for placing queens on the board
    private static void getSolution(int boardSize, List<List<String>> solutions, int[] columns, int columnIndex) {
        // Base case: if all queens are placed
        if (columnIndex == boardSize) {
            List<String> solution = new ArrayList<>(); // List to store the current solution
            for (int i = 0; i < boardSize; i++) {
                StringBuilder row = new StringBuilder(); // Build each row of the board
                for (int j = 0; j < boardSize; j++) {
                    // Place 'Q' for queen and '.' for empty space
                    row.append(j == columns[i] ? "Q" : ".");
                }
                solution.add(row.toString()); // Add the constructed row to the solution
            }
            solutions.add(solution); // Add the complete solution to the list of solutions
            return; // Exit the method
        }

        // Try placing a queen in each row of the current column
        for (int rowIndex = 0; rowIndex < boardSize; rowIndex++) {
            columns[columnIndex] = rowIndex; // Place queen at the current rowIndex in the current column
            // Check if the placement is valid
            if (isPlacedCorrectly(columns, rowIndex, columnIndex)) {
                // Recursively attempt to place queens in the next column
                getSolution(boardSize, solutions, columns, columnIndex + 1);
            }
        }
    }

    // Method to check if the queen can be placed in the current position
    private static boolean isPlacedCorrectly(int[] columns, int rowIndex, int columnIndex) {
        // Check previous columns for conflicts
        for (int i = 0; i < columnIndex; i++) {
            int diff = Math.abs(columns[i] - rowIndex); // Calculate the row difference
            // Check for same row or diagonal conflicts
            if (diff == 0 || columnIndex - i == diff) {
                return false; // Placement is not valid
            }
        }
        return true; // Placement is valid
    }
}
