
import java.util.Scanner;

public class Main {
    // Declare 2D arrays for visited cells and the board
    private final int[] dx = {0, 0, 1, -1};
    private final int[] dy = {1, -1, 0, 0};
    private boolean[][] visited;
    private char[][] board;
    
    // Declare a string variable for the given word
    private String word;
    
    // Helper method to check if given coordinates are valid
    private boolean isValid(int x, int y) {
        return x >= 0 && x < board.length && y >= 0 && y < board[0].length;
    }
    
    // Depth-First Search (DFS) helper method to find a word in the board
    private boolean doDFS(int x, int y, int nextIdx) {
        // Mark the current cell as visited
        visited[x][y] = true;
        
        // Base case: if we have visited all characters in the word
        if (nextIdx == word.length()) {
            return true;
        }
        
        // Iterate through all possible directions
        for (int i = 0; i < 4; ++i) {
            int xi = x + dx[i];
            int yi = y + dy[i];
            
            // Check if the new coordinates are valid and the character matches the word
            if (isValid(xi, yi) && board[xi][yi] == word.charAt(nextIdx) && !visited[xi][yi]) {
                // Recursive call to search for the next character in the word
                boolean exists = doDFS(xi, yi, nextIdx + 1);
                
                // If the recursive call returns true, we have found the word
                if (exists) {
                    return true;
                }
            }
        }
        
        // Backtrack: mark the current cell as unvisited
        visited[x][y] = false;
        
        // Return false if we haven't found the word
        return false;
    }
    
    // Main method to check if the given word exists in the board
    public boolean exist(char[][] board, String word) {
        // Initialize the board and word variables
        this.board = board;
        this.word = word;
        
        // Iterate through all cells in the board
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                // If we find the first character of the word, start the DFS search
                if (board[i][j] == word.charAt(0)) {
                    visited = new boolean[board.length][board[0].length];
                    boolean exists = doDFS(i, j, 1);
                    
                    // If the DFS search returns true, we have found the word
                    if (exists) {
                        return true;
                    }
                }
            }
        }
        
        // If we haven't found the word, return false
        return false;
    }
    
    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the dimensions of the board and initialize it
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        char[][] board = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            String row = scanner.next();
            board[i] = row.toCharArray();
        }
        
        // Read the word to search for
        String word = scanner.next();
        
        // Create an instance of the Main class and call the exist method
        Main wordSearch = new Main();
        boolean result = wordSearch.exist(board, word);
        
        // Print the result
        if (result) {
            System.out.println("The word exists in the board.");
        } else {
            System.out.println("The word does not exist in the board.");
        }
        
        // Close the scanner
        scanner.close();
    }
}