
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Main method to start the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize Scanner to read input

        int rows = scanner.nextInt(); // Read number of rows from input
        int cols = scanner.nextInt(); // Read number of columns from input
        scanner.nextLine(); // Consume newline character left after reading integers

        char[][] puzzle = new char[rows][cols]; // Initialize 2D char array to represent the crossword puzzle

        // Read puzzle data from input
        for (int i = 0; i < rows; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < cols; j++) {
                puzzle[i][j] = line.charAt(j);
            }
        }

        int wordCount = scanner.nextInt(); // Read number of words to be placed in the puzzle from input
        scanner.nextLine(); // Consume newline character left after reading integer

        List<String> words = new ArrayList<>(); // Initialize ArrayList to store words to be placed in the puzzle

        // Read words to be placed in the puzzle from input
        for (int i = 0; i < wordCount; i++) {
            words.add(scanner.nextLine());
        }

        // Solve the crossword puzzle using given words
        if (solveCrossword(puzzle, words)) {
            System.out.println("Solved Crossword:"); // Print solved crossword puzzle
            for (char[] row : puzzle) {
                System.out.println(new String(row));
            }
        } else {
            System.out.println("No solution exists."); // Print message if no solution exists
        }

        scanner.close(); // Close Scanner to free system resources
    }

    // Method to check if a given word can be placed in the puzzle at a given position and orientation
    public static boolean isValid(char[][] puzzle, String word, int row, int col, boolean vertical) {
        // Check each character in the word against the puzzle grid
        for (int i = 0; i < word.length(); i++) {
            if (vertical) {
                // Check if character can be placed in the next row
                if (row + i >= puzzle.length || (puzzle[row + i][col] != ' ' && puzzle[row + i][col] != word.charAt(i))) {
                    return false;
                }
            } else {
                // Check if character can be placed in the next column
                if (col + i >= puzzle[0].length || (puzzle[row][col + i] != ' ' && puzzle[row][col + i] != word.charAt(i))) {
                    return false;
                }
            }
        }
        return true;
    }

    // Method to place a given word in the puzzle at a given position and orientation
    public static void placeWord(char[][] puzzle, String word, int row, int col, boolean vertical) {
        // Place each character in the word in the puzzle grid
        for (int i = 0; i < word.length(); i++) {
            if (vertical) {
                puzzle[row + i][col] = word.charAt(i);
            } else {
                puzzle[row][col + i] = word.charAt(i);
            }
        }
    }

    // Method to remove a given word from the puzzle at a given position and orientation
    public static void removeWord(char[][] puzzle, String word, int row, int col, boolean vertical) {
        // Remove each character in the word from the puzzle grid
        for (int i = 0; i < word.length(); i++) {
            if (vertical) {
                puzzle[row + i][col] = ' ';
            } else {
                puzzle[row][col + i] = ' ';
            }
        }
    }

    // Recursive method to solve the crossword puzzle using given words
    public static boolean solveCrossword(char[][] puzzle, List<String> words) {
        // Base case: no more words to place
        if (words.isEmpty()) {
            return true;
        }

        String word = words.remove(0); // Get the next word to place

        // Try placing the word in each possible orientation and position
        for (int row = 0; row < puzzle.length; row++) {
            for (int col = 0; col < puzzle[0].length; col++) {
                for (boolean vertical : new boolean[]{true, false}) {
                    // Check if the word can be placed at the current position and orientation
                    if (isValid(puzzle, word, row, col, vertical)) {
                        // Place the word in the puzzle and recursively try to solve the remaining puzzle
                        placeWord(puzzle, word, row, col, vertical);
                        if (solveCrossword(puzzle, words)) {
                            return true;
                        }
                        // Backtrack and remove the word if placement fails or recursion fails
                        removeWord(puzzle, word, row, col, vertical);
                    }
                }
            }
        }

        // If no placement was successful, add the word back to the list of words to try
        words.add(0, word);

        return false;
    }
}