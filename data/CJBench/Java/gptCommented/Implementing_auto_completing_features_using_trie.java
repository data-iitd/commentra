import java.util.*;

class Trieac {
    // Constant representing the size of the alphabet (26 letters)
    public static final int ALPHABET_SIZE = 26;

    // TrieNode class representing each node in the Trie
    static class TrieNode {
        // Array of children nodes
        TrieNode[] children = new TrieNode[ALPHABET_SIZE];
        // Boolean flag to indicate if the node marks the end of a word
        boolean isWordEnd;
    }

    // Method to create and initialize a new TrieNode
    static TrieNode getNode() {
        TrieNode pNode = new TrieNode();
        pNode.isWordEnd = false; // Initially, it is not the end of a word
        // Initialize all children to null
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            pNode.children[i] = null;
        }
        return pNode;
    }

    // Method to insert a new key (word) into the Trie
    static void insert(TrieNode root, final String key) {
        TrieNode pCrawl = root; // Start from the root node
        // Iterate through each character of the key
        for (int level = 0; level < key.length(); level++) {
            int index = (key.charAt(level) - 'a'); // Calculate index for the character
            // If the child node does not exist, create a new node
            if (pCrawl.children[index] == null) {
                pCrawl.children[index] = getNode();
            }
            // Move to the child node
            pCrawl = pCrawl.children[index];
        }
        // Mark the end of the word
        pCrawl.isWordEnd = true;
    }

    // Method to search for a key (word) in the Trie
    boolean search(TrieNode root, final String key) {
        int length = key.length();
        TrieNode pCrawl = root; // Start from the root node
        // Iterate through each character of the key
        for (int level = 0; level < length; level++) {
            int index = (key.charAt(level) - 'a'); // Calculate index for the character
            // If the child node does not exist, return false
            if (pCrawl.children[index] == null) {
                return false; // Key not found
            }
            // Move to the child node
            pCrawl = pCrawl.children[index];
        }
        // Return true if the current node marks the end of a word
        return (pCrawl != null && pCrawl.isWordEnd);
    }

    // Method to check if the current node is the last node (no children)
    static boolean isLastNode(TrieNode root) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            // If any child exists, return false
            if (root.children[i] != null) {
                return false;
            }
        }
        return true; // No children exist
    }

    // Recursive method to find and print suggestions based on the current prefix
    static void suggestionsRec(TrieNode root, String currPrefix) {
        // If the current node marks the end of a word, print the prefix
        if (root.isWordEnd) {
            System.out.println(currPrefix);
        }
        // If the current node is the last node, return
        if (isLastNode(root)) {
            return;
        }
        // Iterate through all possible children nodes
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            // If the child node exists, recursively call suggestionsRec
            if (root.children[i] != null) {
                suggestionsRec(root.children[i], currPrefix + (char) (97 + i));
            }
        }
    }

    // Method to print auto-suggestions for a given query
    static int printAutoSuggestions(TrieNode root, final String query) {
        TrieNode pCrawl = root; // Start from the root node
        int level;
        int n = query.length();
        // Traverse the Trie according to the characters in the query
        for (level = 0; level < n; level++) {
            int index = (query.charAt(level) - 'a'); // Calculate index for the character
            // If the child node does not exist, return 0 (no suggestions)
            if (pCrawl.children[index] == null) {
                return 0;
            }
            // Move to the child node
            pCrawl = pCrawl.children[index];
        }
        // Check if the current node is a word and if it is the last node
        boolean isWord = (pCrawl.isWordEnd);
        boolean isLast = isLastNode(pCrawl);
        // If the query is a word and also the last node, print it and return -1
        if (isWord && isLast) {
            System.out.println(query);
            return -1;
        }
        // If not the last node, print suggestions
        if (!isLast) {
            suggestionsRec(pCrawl, query);
            return 1; // Suggestions found
        }
        return 0; // No suggestions found
    }

    // Main method to run the Trie operations
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the number of words to insert
        sc.nextLine(); // Consume the newline character
        TrieNode root = getNode(); // Create the root node of the Trie
        // Insert each word into the Trie
        for (int i = 0; i < n; i++) {
            insert(root, sc.nextLine());
        }
        String prefix = sc.nextLine(); // Read the prefix for suggestions
        int comp = printAutoSuggestions(root, prefix); // Get suggestions based on the prefix
        // Handle the output based on the suggestions found
        if (comp == -1) {
            System.out.println("No other strings found with this prefix\n");
        } else if (comp == 0) {
            System.out.println("No string found with this prefix\n");
        }
        sc.close(); // Close the scanner
    }
}
