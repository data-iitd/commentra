import java.util.*;
import java.util.HashMap;

public class Main {
    // Trie data structure to store words for efficient prefix searching
    public static class Trie {
        private String value; // The word stored at this node
        private boolean isKey; // Indicates if this node represents the end of a valid word
        private final Map<Character, Trie> children = new HashMap<>(); // Children nodes

        // Check if the current node has a child for the given character
        public boolean hasChild(char ch) {
            return children.containsKey(ch);
        }

        // Add a child node for the given character
        public void addChild(char ch) {
            children.put(ch, new Trie());
        }

        // Retrieve the child node for the given character
        public Trie getChild(char ch) {
            return children.get(ch);
        }

        // Insert a word into the Trie
        public void insert(String word) {
            var node = this; // Start from the root node
            for (var ch : word.toCharArray()) { // Iterate through each character of the word
                if (!node.hasChild(ch)) { // If the character is not already a child
                    node.addChild(ch); // Add it as a child
                }
                node = node.getChild(ch); // Move to the child node
            }
            node.value = word; // Set the value of the node to the word
            node.isKey = true; // Mark this node as a key (end of a valid word)
        }
    }

    // Find all words from the given list that can be formed on the board
    public List<String> findWords(char[][] board, String[] words) {
        // Create a set of unique words to avoid duplicates
        Set<String> uniqueWords = new HashSet<>(Arrays.asList(words));
        Trie trie = new Trie(); // Create a new Trie
        uniqueWords.forEach(trie::insert); // Insert all unique words into the Trie

        Set<String> result = new HashSet<>(); // Set to store found words
        int m = board.length; // Number of rows in the board
        int n = board[0].length; // Number of columns in the board

        // Traverse each cell in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boolean[][] visited = new boolean[m][n]; // Track visited cells
                visited[i][j] = true; // Mark the starting cell as visited
                traverse(board, i, j, trie, visited, result); // Start the traversal
            }
        }
        return new ArrayList<>(result); // Return the found words as a list
    }

    // Recursive function to traverse the board and search for words in the Trie
    private void traverse(char[][] board, int i, int j, Trie trie, boolean[][] visited, Set<String> result) {
        char ch = board[i][j]; // Get the character at the current position
        if (trie.hasChild(ch)) { // Check if the Trie has a child for this character
            Trie child = trie.getChild(ch); // Get the child node
            if (child.isKey) { // If this child node represents a valid word
                result.add(child.value); // Add the word to the result set
            }
            // Check all four possible directions (up, left, down, right)
            checkNewPos(board, i - 1, j, child, visited, result); // Up
            checkNewPos(board, i, j - 1, child, visited, result); // Left
            checkNewPos(board, i + 1, j, child, visited, result); // Down
            checkNewPos(board, i, j + 1, child, visited, result); // Right
        }
    }

    // Check if the new position is valid and not visited
    private void checkNewPos(char[][] board, int i, int j, Trie trie, boolean[][] visited, Set<String> result) {
        int m = board.length; // Number of rows in the board
        int n = board[0].length; // Number of columns in the board
        // Check if the new position is out of bounds
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return; // Exit if out of bounds
        }
        // If the position is not visited, mark it as visited and continue traversal
        if (!visited[i][j]) {
            visited[i][j] = true; // Mark the cell as visited
            traverse(board, i, j, trie, visited, result); // Continue traversal
            visited[i][j] = false; // Unmark the cell after traversal
        }
    }

    // Main method to run the word search
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int rows = scanner.nextInt(); // Read number of rows
        int cols = scanner.nextInt(); // Read number of columns
        scanner.nextLine(); // Consume the newline character
        char[][] board = new char[rows][cols]; // Initialize the board

        // Read the board input
        for (int i = 0; i < rows; i++) {
            board[i] = scanner.nextLine().toCharArray(); // Convert each line to a char array
        }

        int wordCount = scanner.nextInt(); // Read the number of words
        scanner.nextLine(); // Consume the newline character
        String[] words = new String[wordCount]; // Initialize the words array

        // Read the words input
        for (int i = 0; i < wordCount; i++) {
            words[i] = scanner.nextLine(); // Read each word
        }

        Main wordSearch = new Main(); // Create an instance of Main
        List<String> result = wordSearch.findWords(board, words); // Find words on the board
        result.forEach(System.out::println); // Print each found word
        scanner.close(); // Close the scanner
    }
}
