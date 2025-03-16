
import java.util.*;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

public class Main {
    public static class Trie {
        // Trie node
        private String value;
        private boolean isKey;
        private final Map<Character, Trie> children = new HashMap<>();

        // Check if the trie has a child with the given character
        public boolean hasChild(char ch) {
            return children.containsKey(ch);
        }

        // Add a new child to the trie with the given character
        public void addChild(char ch) {
            children.put(ch, new Trie());
        }

        // Get the child of the trie with the given character
        public Trie getChild(char ch) {
            return children.get(ch);
        }

        // Insert a new word into the trie
        public void insert(String word) {
            var node = this;
            for (var ch : word.toCharArray()) {
                if (!node.hasChild(ch)) {
                    node.addChild(ch);
                }
                node = node.getChild(ch);
            }
            node.value = word;
            node.isKey = true;
        }
    }

    // Find all the words in the given board that are present in the list of words
    public List<String> findWords(char[][] board, String[] words) {
        // Create a set of unique words from the given list of words
        Set<String> uniqueWords = new HashSet<>(Arrays.asList(words));

        // Initialize the trie data structure
        Trie trie = new Trie();

        // Insert all the unique words into the trie
        uniqueWords.forEach(trie::insert);

        // Initialize an empty set to store the result
        Set<String> result = new HashSet<>();

        // Get the dimensions of the board
        int m = board.length;
        int n = board[0].length;

        // Iterate through each character in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize a 2D boolean array to keep track of the visited cells
                boolean[][] visited = new boolean[m][n];

                // Set the current cell as visited and start the traversal
                visited[i][j] = true;
                traverse(board, i, j, trie, visited, result);
            }
        }

        // Convert the set to a list and return it as the result
        return new ArrayList<>(result);
    }

    // A recursive method to traverse the board and find all the words that can be formed from the current cell and its neighbors
    private void traverse(char[][] board, int i, int j, Trie trie, boolean[][] visited, Set<String> result) {
        // Get the character at the current cell
        char ch = board[i][j];

        // If the trie has a child with the current character, then it might be the start of a valid word
        if (trie.hasChild(ch)) {
            Trie child = trie.getChild(ch);

            // If the current word is a valid word, add it to the result
            if (child.isKey) {
                result.add(child.value);
            }

            // Traverse to the neighboring cells and check if they can form a valid word
            checkNewPos(board, i - 1, j, child, visited, result);
            checkNewPos(board, i, j - 1, child, visited, result);
            checkNewPos(board, i + 1, j, child, visited, result);
            checkNewPos(board, i, j + 1, child, visited, result);
        }
    }

    // A helper method to check if the given position is within the bounds of the board and has not been visited before
    private void checkNewPos(char[][] board, int i, int j, Trie trie, boolean[][] visited, Set<String> result) {
        // Get the dimensions of the board
        int m = board.length;
        int n = board[0].length;

        // Check if the given position is valid and has not been visited before
        if (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j]) {
            visited[i][j] = true;

            // Traverse to the neighboring cell and check if it can form a valid word
            traverse(board, i, j, trie, visited, result);

            visited[i][j] = false;
        }
    }

    // Main method to read the input and call the findWords method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the dimensions of the board and the number of words
        int rows = scanner.nextInt();
        int cols = scanner.nextInt();
        scanner.nextLine();

        // Read the characters of the board
        char[][] board = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            board[i] = scanner.nextLine().toCharArray();
        }

        // Read the number of words and their characters
        int wordCount = scanner.nextInt();
        scanner.nextLine();

        // Read the words and store them in an array
        String[] words = new String[wordCount];
        for (int i = 0; i < wordCount; i++) {
            words[i] = scanner.nextLine();
        }

        // Create an instance of the Main class and call the findWords method
        Main wordSearch = new Main();
        List<String> result = wordSearch.findWords(board, words);

        // Print the result
        result.forEach(System.out::println);

        // Close the scanner
        scanner.close();
    }
}