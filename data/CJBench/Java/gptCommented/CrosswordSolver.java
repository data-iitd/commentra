import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Method to check if a word can be placed in the puzzle at a given position
    public static boolean isValid(char[][] puzzle, String word, int row, int col, boolean vertical) {
        for (int i = 0; i < word.length(); i++) {
            // Check if placing the word vertically
            if (vertical) {
                // Check if the position is within bounds and either empty or matches the word
                if (row + i >= puzzle.length || (puzzle[row + i][col] != ' ' && puzzle[row + i][col] != word.charAt(i))) {
                    return false; // Invalid position
                }
            } else {
                // Check if placing the word horizontally
                if (col + i >= puzzle[0].length || (puzzle[row][col + i] != ' ' && puzzle[row][col + i] != word.charAt(i))) {
                    return false; // Invalid position
                }
            }
        }
        return true; // Valid position
    }

    // Method to place a word in the puzzle at a given position
    public static void placeWord(char[][] puzzle, String word, int row, int col, boolean vertical) {
        for (int i = 0; i < word.length(); i++) {
            // Place the word vertically
            if (vertical) {
                puzzle[row + i][col] = word.charAt(i);
            } else {
                // Place the word horizontally
                puzzle[row][col + i] = word.charAt(i);
            }
        }
    }

    // Method to remove a word from the puzzle at a given position
    public static void removeWord(char[][] puzzle, String word, int row, int col, boolean vertical) {
        for (int i = 0; i < word.length(); i++) {
            // Remove the word vertically
            if (vertical) {
                puzzle[row + i][col] = ' ';
            } else {
                // Remove the word horizontally
                puzzle[row][col + i] = ' ';
            }
        }
    }

    // Method to solve the crossword puzzle using backtracking
    public static boolean solveCrossword(char[][] puzzle, List<String> words) {
        // Base case: if no words left to place, the puzzle is solved
        if (words.isEmpty()) {
            return true; 
        }
        // Remove the first word from the list to try placing it
        String word = words.remove(0); 
        // Iterate through each cell in the puzzle
        for (int row = 0; row < puzzle.length; row++) {
            for (int col = 0; col < puzzle[0].length; col++) {
                // Try placing the word both vertically and horizontally
                for (boolean vertical : new boolean[]{true, false}) {
                    // Check if the word can be placed
                    if (isValid(puzzle, word, row, col, vertical)) {
                        // Place the word in the puzzle
                        placeWord(puzzle, word, row, col, vertical);
                        // Recursively attempt to solve the rest of the puzzle
                        if (solveCrossword(puzzle, words)) {
                            return true; // Puzzle solved
                        }
                        // If not solved, remove the word and try the next position
                        removeWord(puzzle, word, row, col, vertical);
                    }
                }
            }
        }
        // If the word cannot be placed, add it back to the list and return false
        words.add(0, word); 
        return false; // No solution found
    }

    public static void main(String[] args) {
        // Initialize scanner for user input
        Scanner scanner = new Scanner(System.in);
        // Read the dimensions of the puzzle
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        // Create the puzzle grid
        char[][] puzzle = new char[rows][cols];
        // Read the puzzle input from the user
        for (int i = 0; i < rows; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < cols; j++) {
                puzzle[i][j] = line.charAt(j); // Fill the puzzle grid
            }
        }
        // Read the number of words to place in the puzzle
        int wordCount = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        List<String> words = new ArrayList<>();
        // Read each word from the user
        for (int i = 0; i < wordCount; i++) {
            words.add(scanner.nextLine());
        }
        // Attempt to solve the crossword puzzle
        if (solveCrossword(puzzle, words)) {
            // If solved, print the completed puzzle
            System.out.println("Solved Crossword:");
            for (char[] row : puzzle) {
                System.out.println(new String(row));
            }
        } else {
            // If no solution exists, inform the user
            System.out.println("No solution exists.");
        }
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
