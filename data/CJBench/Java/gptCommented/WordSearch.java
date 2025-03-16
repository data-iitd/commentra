import java.util.Scanner;

public class Main {
    // Direction vectors for moving up, down, left, and right
    private final int[] dx = {0, 0, 1, -1};
    private final int[] dy = {1, -1, 0, 0};
    
    // 2D array to track visited cells
    private boolean[][] visited;
    
    // 2D character array representing the board
    private char[][] board;
    
    // The word we are searching for
    private String word;

    // Method to check if the given coordinates are within the bounds of the board
    private boolean isValid(int x, int y) {
        return x >= 0 && x < board.length && y >= 0 && y < board[0].length;
    }

    // Depth-First Search (DFS) method to explore the board for the word
    private boolean doDFS(int x, int y, int nextIdx) {
        // Mark the current cell as visited
        visited[x][y] = true;

        // Check if we have found the entire word
        if (nextIdx == word.length()) {
            return true;
        }

        // Explore all four possible directions
        for (int i = 0; i < 4; ++i) {
            int xi = x + dx[i]; // New x coordinate
            int yi = y + dy[i]; // New y coordinate
            
            // Check if the next cell is valid, matches the next character in the word, and is not visited
            if (isValid(xi, yi) && board[xi][yi] == word.charAt(nextIdx) && !visited[xi][yi]) {
                // Recursively call doDFS for the next character in the word
                boolean exists = doDFS(xi, yi, nextIdx + 1);
                if (exists) {
                    return true; // If the word exists, return true
                }
            }
        }

        // Unmark the current cell as visited (backtrack)
        visited[x][y] = false; 
        return false; // Return false if the word is not found
    }

    // Main method to check if the word exists in the board
    public boolean exist(char[][] board, String word) {
        this.board = board; // Initialize the board
        this.word = word;   // Initialize the word
        
        // Iterate through each cell in the board
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                // If the current cell matches the first character of the word
                if (board[i][j] == word.charAt(0)) {
                    // Initialize the visited array for a new search
                    visited = new boolean[board.length][board[0].length];
                    // Start DFS from the current cell for the next character
                    boolean exists = doDFS(i, j, 1);
                    if (exists) {
                        return true; // If the word exists, return true
                    }
                }
            }
        }
        return false; // Return false if the word is not found in the board
    }

    // Main entry point of the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the dimensions of the board
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        
        // Initialize the board
        char[][] board = new char[rows][cols];
        
        // Read the board input from the user
        for (int i = 0; i < rows; i++) {
            String row = scanner.next();
            board[i] = row.toCharArray(); // Convert each row to a character array
        }
        
        // Read the word to search for
        String word = scanner.next();
        
        // Create an instance of Main to use the exist method
        Main wordSearch = new Main();
        
        // Check if the word exists in the board
        boolean result = wordSearch.exist(board, word);
        
        // Output the result
        if (result) {
            System.out.println("The word exists in the board.");
        } else {
            System.out.println("The word does not exist in the board.");
        }
        
        // Close the scanner
        scanner.close();
    }
}
