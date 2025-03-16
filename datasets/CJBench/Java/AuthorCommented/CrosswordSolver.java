import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * A class to solve a crossword puzzle using backtracking with dynamic input.
 */
public class CrosswordSolver {

    /**
     * Checks if a word can be placed at the specified position in the crossword.
     */
    public static boolean isValid(char[][] puzzle, String word, int row, int col, boolean vertical) {
        for (int i = 0; i < word.length(); i++) {
            if (vertical) {
                if (row + i >= puzzle.length || (puzzle[row + i][col] != ' ' && puzzle[row + i][col] != word.charAt(i))) {
                    return false;
                }
            } else {
                if (col + i >= puzzle[0].length || (puzzle[row][col + i] != ' ' && puzzle[row][col + i] != word.charAt(i))) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * Places a word at the specified position in the crossword.
     */
    public static void placeWord(char[][] puzzle, String word, int row, int col, boolean vertical) {
        for (int i = 0; i < word.length(); i++) {
            if (vertical) {
                puzzle[row + i][col] = word.charAt(i);
            } else {
                puzzle[row][col + i] = word.charAt(i);
            }
        }
    }

    /**
     * Removes a word from the specified position in the crossword.
     */
    public static void removeWord(char[][] puzzle, String word, int row, int col, boolean vertical) {
        for (int i = 0; i < word.length(); i++) {
            if (vertical) {
                puzzle[row + i][col] = ' ';
            } else {
                puzzle[row][col + i] = ' ';
            }
        }
    }

    /**
     * Solves the crossword puzzle using backtracking.
     */
    public static boolean solveCrossword(char[][] puzzle, List<String> words) {
        if (words.isEmpty()) {
            return true; // All words placed successfully
        }

        String word = words.remove(0); // Take the first word from the list
        for (int row = 0; row < puzzle.length; row++) {
            for (int col = 0; col < puzzle[0].length; col++) {
                for (boolean vertical : new boolean[]{true, false}) {
                    if (isValid(puzzle, word, row, col, vertical)) {
                        placeWord(puzzle, word, row, col, vertical);
                        if (solveCrossword(puzzle, words)) {
                            return true;
                        }
                        removeWord(puzzle, word, row, col, vertical);
                    }
                }
            }
        }
        words.add(0, word); // Backtrack by adding the word back to the list
        return false;
    }

    /**
     * Main method to take input dynamically and solve the crossword puzzle.
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        char[][] puzzle = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < cols; j++) {
                puzzle[i][j] = line.charAt(j);
            }
        }

        int wordCount = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        List<String> words = new ArrayList<>();
        for (int i = 0; i < wordCount; i++) {
            words.add(scanner.nextLine());
        }

        if (solveCrossword(puzzle, words)) {
            System.out.println("Solved Crossword:");
            for (char[] row : puzzle) {
                System.out.println(new String(row));
            }
        } else {
            System.out.println("No solution exists.");
        }

        scanner.close();
    }
}
