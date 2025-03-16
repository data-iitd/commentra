import java.util.*; // Importing necessary libraries for utility classes and collections.

class Trieac {
    public static final int ALPHABET_SIZE = 26; // Defining the size of the alphabet.

    // Nested TrieNode class representing each node in the Trie.
    static class TrieNode {
        TrieNode[] children = new TrieNode[ALPHABET_SIZE];
        boolean isWordEnd;
    }

    // Method to get a new TrieNode initialized with default values.
    static TrieNode getNode() {
        TrieNode pNode = new TrieNode();
        pNode.isWordEnd = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            pNode.children[i] = null;
        }
        return pNode;
    }

    // Method to insert a word into the Trie.
    static void insert(TrieNode root, final String key) {
        TrieNode pCrawl = root;
        for (int level = 0; level < key.length(); level++) {
            int index = (key.charAt(level) - 'a');
            if (pCrawl.children[index] == null) {
                pCrawl.children[index] = getNode();
            }
            pCrawl = pCrawl.children[index];
        }
        pCrawl.isWordEnd = true;
    }

    // Method to search for a word in the Trie.
    boolean search(TrieNode root, final String key) {
        int length = key.length();
        TrieNode pCrawl = root;
        for (int level = 0; level < length; level++) {
            int index = (key.charAt(level) - 'a');
            if (pCrawl.children[index] == null) {
                return false; // Word not found.
            }
            pCrawl = pCrawl.children[index];
        }
        return (pCrawl != null && pCrawl.isWordEnd); // Check if the word ends at this node.
    }

    // Method to check if a given node is the last node in the Trie.
    static boolean isLastNode(TrieNode root) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root.children[i] != null) {
                return false; // Node has children.
            }
        }
        return true; // Node has no children.
    }

    // Recursive method to generate suggestions from a given node.
    static void suggestionsRec(TrieNode root, String currPrefix) {
        if (root.isWordEnd) {
            System.out.println(currPrefix); // Print the word if it ends at this node.
        }
        if (isLastNode(root)) {
            return; // Stop recursion if this is the last node.
        }
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root.children[i] != null) {
                suggestionsRec(root.children[i], currPrefix + (char) (97 + i)); // Recursively call for each child.
            }
        }
    }

    // Method to print auto-suggestions based on a given prefix.
    static int printAutoSuggestions(TrieNode root, final String query) {
        TrieNode pCrawl = root;
        int level;
        int n = query.length();
        for (level = 0; level < n; level++) {
            int index = (query.charAt(level) - 'a');
            if (pCrawl.children[index] == null) {
                return 0; // Prefix not found.
            }
            pCrawl = pCrawl.children[index];
        }
        boolean isWord = (pCrawl.isWordEnd);
        boolean isLast = isLastNode(pCrawl);
        if (isWord && isLast) {
            System.out.println(query); // The entire word is a suggestion.
            return -1;
        }
        if (!isLast) {
            suggestionsRec(pCrawl, query); // Print suggestions for the remaining characters.
            return 1;
        }
        return 0;
    }

    // Main method to run the program.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); 
        TrieNode root = getNode();
        for (int i = 0; i < n; i++) {
            insert(root, sc.nextLine());
        }
        String prefix = sc.nextLine();
        int comp = printAutoSuggestions(root, prefix);
        if (comp == -1) {
            System.out.println("No other strings found with this prefix\n");
        } else if (comp == 0) {
            System.out.println("No string found with this prefix\n");
        }
        sc.close();
    }
}
