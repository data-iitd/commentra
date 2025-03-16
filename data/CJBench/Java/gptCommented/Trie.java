import java.util.HashMap;
import java.util.Scanner;

// Class representing a node in the Trie
class MainNode {
    char value; // Character value of the node
    HashMap<Character, MainNode> child; // Children of the current node
    boolean end; // Indicates if the node marks the end of a word

    // Constructor to initialize a node with a given character
    MainNode(char value) {
        this.value = value;
        this.child = new HashMap<>();
        this.end = false; // Initially, the node does not end a word
    }
}

// Main class for the Trie data structure
public class Main {
    private static final char ROOT_NODE_VALUE = '*'; // Value for the root node
    private final MainNode root; // Root node of the Trie

    // Constructor to initialize the Trie with a root node
    public Main() {
        root = new MainNode(ROOT_NODE_VALUE);
    }

    // Method to insert a word into the Trie
    public void insert(String word) {
        MainNode currentNode = root; // Start from the root node
        for (int i = 0; i < word.length(); i++) {
            // Get the child node corresponding to the current character
            MainNode node = currentNode.child.getOrDefault(word.charAt(i), null);
            // If the node does not exist, create a new one
            if (node == null) {
                node = new MainNode(word.charAt(i));
                currentNode.child.put(word.charAt(i), node); // Add the new node to children
            }
            currentNode = node; // Move to the child node
        }
        currentNode.end = true; // Mark the end of the word
    }

    // Method to search for a word in the Trie
    public boolean search(String word) {
        MainNode currentNode = root; // Start from the root node
        for (int i = 0; i < word.length(); i++) {
            // Get the child node corresponding to the current character
            MainNode node = currentNode.child.getOrDefault(word.charAt(i), null);
            // If the node does not exist, the word is not in the Trie
            if (node == null) {
                return false;
            }
            currentNode = node; // Move to the child node
        }
        return currentNode.end; // Return true if the current node marks the end of a word
    }

    // Method to delete a word from the Trie
    public boolean delete(String word) {
        MainNode currentNode = root; // Start from the root node
        for (int i = 0; i < word.length(); i++) {
            // Get the child node corresponding to the current character
            MainNode node = currentNode.child.getOrDefault(word.charAt(i), null);
            // If the node does not exist, the word cannot be deleted
            if (node == null) {
                return false;
            }
            currentNode = node; // Move to the child node
        }
        // If the current node marks the end of a word, unmark it
        if (currentNode.end) {
            currentNode.end = false; // Mark the end as false
            return true; // Return true indicating successful deletion
        }
        return false; // Return false if the word was not found
    }

    // Method to count the total number of words in the Trie
    public int countWords() {
        return countWords(root); // Start counting from the root node
    }

    // Helper method to recursively count words from a given node
    private int countWords(MainNode node) {
        if (node == null) {
            return 0; // Base case: no node means no words
        }
        int count = 0; // Initialize word count
        if (node.end) {
            count++; // Increment count if the node marks the end of a word
        }
        // Recursively count words in all child nodes
        for (MainNode child : node.child.values()) {
            count += countWords(child);
        }
        return count; // Return the total count
    }

    // Method to check if any word in the Trie starts with a given prefix
    public boolean startsWithPrefix(String prefix) {
        MainNode currentNode = root; // Start from the root node
        for (int i = 0; i < prefix.length(); i++) {
            // Get the child node corresponding to the current character
            MainNode node = currentNode.child.getOrDefault(prefix.charAt(i), null);
            // If the node does not exist, no word starts with the prefix
            if (node == null) {
                return false;
            }
            currentNode = node; // Move to the child node
        }
        return true; // Return true if the prefix exists in the Trie
    }

    // Method to count the number of words that start with a given prefix
    public int countWordsWithPrefix(String prefix) {
        MainNode currentNode = root; // Start from the root node
        for (int i = 0; i < prefix.length(); i++) {
            // Get the child node corresponding to the current character
            MainNode node = currentNode.child.getOrDefault(prefix.charAt(i), null);
            // If the node does not exist, return 0 as no words match the prefix
            if (node == null) {
                return 0;
            }
            currentNode = node; // Move to the child node
        }
        return countWords(currentNode); // Count words from the current node
    }

    // Main method to run the Trie operations based on user input
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        Main trie = new Main(); // Initialize the Trie
        int n = scanner.nextInt(); // Read the number of operations
        scanner.nextLine(); // Consume the newline character
        for (int i = 0; i < n; i++) {
            String operation = scanner.next(); // Read the operation type
            // Perform the corresponding operation based on user input
            if (operation.equals("insert")) {
                String word = scanner.next();
                trie.insert(word); // Insert the word into the Trie
            } else if (operation.equals("search")) {
                String word = scanner.next();
                System.out.println(trie.search(word)); // Search for the word and print the result
            } else if (operation.equals("delete")) {
                String word = scanner.next();
                System.out.println(trie.delete(word)); // Delete the word and print the result
            } else if (operation.equals("countWords")) {
                System.out.println(trie.countWords()); // Print the total number of words in the Trie
            } else if (operation.equals("startsWith")) {
                String prefix = scanner.next();
                System.out.println(trie.startsWithPrefix(prefix)); // Check if any word starts with the prefix and print the result
            } else if (operation.equals("countWithPrefix")) {
                String prefix = scanner.next();
                System.out.println(trie.countWordsWithPrefix(prefix)); // Count words with the given prefix and print the result
            }
        }
        scanner.close(); // Close the scanner
    }
}
