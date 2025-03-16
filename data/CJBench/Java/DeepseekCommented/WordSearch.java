import java.util.Scanner;
public class Main {
    // Direction vectors for moving in four possible directions (right, left, down, up)
    private final int[] dx = {0, 0, 1, -1};
    private final int[] dy = {1, -1, 0, 0};
    
    // 2D array to keep track of visited cells during the DFS
    private boolean[][] visited;
    
    // 2D char array representing the board
    private char[][] board;
    
    // String representing the word to be searched
    private String word;
    
    // Method to check if a cell (x, y) is within the bounds of the board
    private boolean isValid(int x, int y) {
        return x >= 0 && x < board.length && y >= 0 && y < board[0].length;
    }
    
    // Depth-First Search (DFS) method to find the word in the board
    private boolean doDFS(int x, int y, int nextIdx) {
        // Mark the current cell as visited
        visited[x][y] = true;
        
        // If we have reached the end of the word, return true
        if (nextIdx == word.length()) {
            return true;
        }
        
        // Explore all four possible directions
        for (int i = 0; i < 4; ++i) {
            int xi = x + dx[i];
            int yi = y + dy[i];
            
            // Check if the new cell is within bounds, matches the next character of the word, and hasn't been visited
            if (isValid(xi, yi) && board[xi][yi] == word.charAt(nextIdx) && !visited[xi][yi]) {
                // Recursively call doDFS for the new cell
                boolean exists = doDFS(xi, yi, nextIdx + 1);
                if (exists) {
                    return true;
                }
            }
        }
        
        // Backtrack: unmark the current cell as visited
        visited[x][y] = false; 
        
        // Return false if the word cannot be formed from the current path
        return false;
    }
    
    // Method to check if the word exists in the board
    public boolean exist(char[][] board, String word) {
        this.board = board;
        this.word = word;
        
        // Iterate over each cell in the board to start a DFS search
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == word.charAt(0)) {
                    // Initialize the visited array for each DFS search
                    visited = new boolean[board.length][board[0].length];
                    
                    // Start DFS from the current cell
                    boolean exists = doDFS(i, j, 1);
                    if (exists) {
                        return true;
                    }
                }
            }
        }
        
        // Return false if the word does not exist in the board
        return false;
    }
    
    // Main method to read input, create an instance of Main, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the dimensions of the board
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        
        // Initialize the board with the given dimensions
        char[][] board = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            String row = scanner.next();
            board[i] = row.toCharArray();
        }
        
        // Read the word to be searched
        String word = scanner.next();
        
        // Create an instance of Main and check if the word exists in the board
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
