
import java.util.*;

class Trieac {
    // Class to represent a node in Trie
    public static final int ALPHABET_SIZE = 26;
    static class TrieNode {
        TrieNode[] children = new TrieNode[ALPHABET_SIZE];
        boolean isWordEnd;

        // Constructor for TrieNode
        TrieNode() {
            isWordEnd = false;
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                children[i] = null;
            }
        }
    }

    // Function to get a new TrieNode
    static TrieNode getNode() {
        return new TrieNode();
    }

    // Function to insert a word into Trie
    static void insert(TrieNode root, final String key) {
        TrieNode currentNode = root;
        for (int level = 0; level < key.length(); level++) {
            int index = key.charAt(level) - 'a';
            if (currentNode.children[index] == null) {
                currentNode.children[index] = getNode();
            }
            currentNode = currentNode.children[index];
        }
        currentNode.isWordEnd = true;
    }

    // Function to search a word in Trie
    boolean search(TrieNode root, final String key) {
        TrieNode currentNode = root;
        for (int level = 0; level < key.length(); level++) {
            int index = key.charAt(level) - 'a';
            if (currentNode.children[index] == null) {
                return false;
            }
            currentNode = currentNode.children[index];
        }
        return currentNode != null && currentNode.isWordEnd;
    }

    // Function to check if the current node is the last node
    static boolean isLastNode(TrieNode root) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root.children[i] != null) {
                return false;
            }
        }
        return true;
    }

    // Function to print suggestions based on the given prefix
    static void suggestionsRec(TrieNode root, String currPrefix) {
        if (root.isWordEnd) {
            System.out.println(currPrefix);
        }
        if (isLastNode(root)) {
            return;
        }
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root.children[i] != null) {
                suggestionsRec(root.children[i], currPrefix + (char) (97 + i));
            }
        }
    }

    // Function to print auto-suggestions based on the given prefix
    static int printAutoSuggestions(TrieNode root, final String query) {
        TrieNode currentNode = root;
        int level;
        int n = query.length();
        for (level = 0; level < n; level++) {
            int index = query.charAt(level) - 'a';
            if (currentNode.children[index] == null) {
                return 0;
            }
            currentNode = currentNode.children[index];
        }
        boolean isWord = currentNode.isWordEnd;
        boolean isLast = isLastNode(currentNode);
        if (isWord && isLast) {
            System.out.println(query);
            return -1;
        }
        if (!isLast) {
            suggestionsRec(currentNode, query);
            return 1;
        }
        return 0;
    }

    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize Scanner to read input
        int n = sc.nextInt(); // Read the number of words to be inserted into Trie
        sc.nextLine(); // Read the newline character left after reading integer

        TrieNode root = getNode(); // Create the root node of Trie

        // Insert words into Trie
        for (int i = 0; i < n; i++) {
            String word = sc.nextLine(); // Read a word from the input
            insert(root, word); // Insert the word into Trie
        }

        String prefix = sc.nextLine(); // Read the prefix for suggestions
        int suggestionsCount = printAutoSuggestions(root, prefix); // Print auto-suggestions based on the prefix

        if (suggestionsCount == -1) {
            System.out.println("No other strings found with this prefix\n"); // If the prefix is a word and there are no other words with the same prefix
        } else if (suggestionsCount == 0) {
            System.out.println("No string found with this prefix\n"); // If there is no word with the given prefix
        }

        sc.close(); // Close the Scanner
    }
}